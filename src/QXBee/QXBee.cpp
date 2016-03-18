#include <QDebug>

#include "QXBee.h"

QXBee::QXBee(QSerialPort *ser){
	xbeeFound = false;
	serial = ser;
	QByteArray data;
	APIMode = 0;

	// Get API mode
	if (serial->open(QIODevice::ReadWrite) && serial->isOpen())
	{
		// Enter AT command mode
		serial->write("+++");

		// Wait for OK
		while (serial->waitForReadyRead(1500)) data += serial->readAll();

		if (data.startsWith("OK")) {
			data.clear();
			// Request protocol mode
			serial->write("ATAP\r");
			// Wait for answer
			while (serial->waitForReadyRead(100)) data += serial->readAll();
			if (data.length() > 0) APIMode = data[0]-'0';
			qDebug() << "Protocol mode: " << APIMode;
			// Exit AT command mode
			serial->write("ATCN\r");
		}

		if (APIMode > 0) {
			xbeeFound = true;
			connect(serial, SIGNAL(readyRead()), SLOT(readData()));
			qDebug() << "XBEE: Connected successfully";
			qDebug() << "XBEE: Serial Port Name: " << serial->portName();
		} else {
			qDebug() << "XBEE: Device not in API protocol mode";
		}
	}
	else
	{
		qDebug() << "XBEE: Serial Port could not be opened";
	}

}

QXBee::~QXBee()
{
	if(serial->isOpen())
	{
		serial->close();
		qDebug() << "XBEE: Serial Port closed successfully";
	}
}

void QXBee::send(XBeePacket *request)
{
	union {
		uint16_t i;
		uint8_t b[2];
	} dataLength;
	uint8_t chksm = 0;
	QByteArray frame, data;

	data = request->getFrameData();
	dataLength.i = data.length();
	// Assemble frame (must verify API mode)
	frame[0] = 0x7E;
	frame[1] = dataLength.b[1];
	frame[2] = dataLength.b[0];
	frame += data;
	// Calculate checksum
	for (int i = 0; i < data.length(); i++) chksm += data[i];
	chksm = 0xFF - chksm;
	frame[frame.length()] = chksm;

	if(xbeeFound && serial->isOpen())
	{
		qDebug() << "Transmit: " << frame.toHex();
		serial->write(frame);
		serial->flush();
	}
	else
	{
		qDebug() << "XBEE: Cannot write to Serial Port - closed";
	}
}

void QXBee::broadcast(QString data)
{
	TXRequest request;
	request.setTransmitingData(data.toLatin1());
	send(&request);
}

void QXBee::unicast(QByteArray address, QString data){
	TXRequest request;
	request.setDestinationAddress64(address);
	request.setTransmitingData(data.toLatin1());
	send(&request);
}

void QXBee::readData()
{
	const uint8_t startDelimiter = 0x7E;
	const uint8_t escapeCharacter = 0x7D;
	int i;
	uint8_t chksm;
	union {
		uint16_t i;
		uint8_t b[2];
	} frameLength;

	// Read serial data and unescape if necessary.
	switch (APIMode) {
		case 1:
			cleanBuffer += serial->readAll();
			break;
		case 2:
			rawBuffer += serial->readAll();
			for (i = 0; i < rawBuffer.size(); i++) {
				if ((uint8_t)rawBuffer[i] != escapeCharacter)
					cleanBuffer += rawBuffer[i];
				else if (rawBuffer.length() > i+1)
					cleanBuffer += rawBuffer[++i]^0x20;
				else break;
			}
			rawBuffer.remove(0, i);
	}

	// Ignore any bytes not belonging to a frame.
	for (i = 0; i < cleanBuffer.size(); i++)
		if ((uint8_t)cleanBuffer[i] == startDelimiter) break;
	cleanBuffer.remove(0, i);

	// Leave if we don't have the minimum frame size.
	if (cleanBuffer.size() < 6) return;

	// Process frame
	while (cleanBuffer.size() > 0) {

		// Get frame length
		frameLength.b[1] = (uint8_t)cleanBuffer[1];
		frameLength.b[0] = (uint8_t)cleanBuffer[2];

		// Leave if we don't have a full frame
		if(cleanBuffer.size()-4 < frameLength.i) return;

		// Verify frame checksum
		chksm = 0;
		for (i = 3; i < frameLength.i+3; i++) chksm += cleanBuffer[i];
		chksm = 0xFF - chksm;

		// Save frame
		if (chksm == (uint8_t)cleanBuffer[frameLength.i+3]) {
			processPacket(cleanBuffer.mid(3,frameLength.i));
		} else qDebug() << "Checksum Error: " << cleanBuffer.mid(3,frameLength.i).toHex();
		cleanBuffer.remove(0, frameLength.i+4);
	}
}

void QXBee::processPacket(QByteArray frame){
	XBeePacket *packet = 0;
	switch ((uint8_t)frame[0]) {
	case XBeePacket::pATCommandResponse:{
		packet = new ATCommandResponse;
		packet->setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::pModemStatus:{
		packet = new ModemStatus;
		packet->setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::pTransmitStatus:{
		packet = new TransmitStatus;
		packet->setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::pRXIndicator:{
		packet = new RXIndicator;
		packet->setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::pRXIndicatorExplicit:{
		packet = new RXIndicatorExplicit;
		packet->setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::pNodeIdentificationIndicator:{
		packet = new NodeIdentificationIndicator;
		packet->setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::pATCommandResponseRemote:{
		packet = new ATCommandResponseRemote;
		packet->setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	default:
		qDebug() << "Error:  Unknown Packet: " << frame.toHex();
	}
}
