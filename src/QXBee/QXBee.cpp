#include <QDebug>

#include "QXBee.h"

QXBee::QXBee(QObject *parent) :
	QObject(parent)
{
}

QXBee::QXBee(QSerialPort *ser){
	xbeeFound = false;
	serial = ser;
	QByteArray data;
	protocolMode = 0;

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
			if (data.length() > 0) protocolMode = data[0]-'0';
			qDebug() << "Protocol mode: " << protocolMode;
			// Exit AT command mode
			serial->write("ATCN\r");
		}

		if (protocolMode > 0) {
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
void QXBee::displayData(XBeePacket *packet){
	uint8_t frameType = packet->getFrameType();
	switch (frameType) {
		case XBeePacket::pATCommandResponse:
		{
			//int idx = 0;
			//qDebug() << "Raw data: " << packet->getFrameData().toHex();
			/*qDebug() << "Command: " << ((ATCommandResponse *)packet)->getATCommand();
			qDebug() << "Status: " << ((ATCommandResponse *)packet)->getCommandStatus();
			QByteArray data = ((ATCommandResponse *)packet)->getCommandData();
			qDebug() << "Remote Address: " << data.mid(2, 8).toHex();
			idx = data.indexOf((char)0x00, 10);
			qDebug() << "Name: " << data.mid(10,idx-10);
			idx += 3;
			qDebug() << "Device type: " << (uint8_t)data[idx];
			qDebug() << "Profile ID: " << data.mid(idx+2, 2).toHex();
			qDebug() << "Manufacturer: " << data.mid(idx+4, 2).toHex();
			qDebug() << "";*/
		}
		break;
		case XBeePacket::pRXIndicator:
		{
			qDebug() << "Received Data: " << packet->getFrameData().toHex();
			qDebug() << "Mensagem: " << ((RXIndicator *)packet)->getReceivedData();
		}
		break;
		default:
		{
			qDebug() << "Received Data: " << packet->getFrameData().toHex();
		}
	}
	delete (packet);
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
	int i, frameIndex, frameLength, packetLength;
	uint8_t chksm, blah;
	QByteArray frame;

	i = frameIndex = frameLength = packetLength = 0;

	 rawBuffer += serial->readAll();

	// Unescape characters if necessary
	switch (protocolMode) {
		case 1:
			cleanBuffer += rawBuffer;
		break;
		case 2:
		{
			for (i = 0; i < rawBuffer.size()-1; i++) {
				if ((uint8_t)rawBuffer[i] != escapeCharacter)
					cleanBuffer += rawBuffer[i];
				else {
					i++;
					cleanBuffer += rawBuffer[i]^0x20;
				}
			}
			rawBuffer.remove(0, i);
			if (!rawBuffer.isEmpty() && (uint8_t)rawBuffer[0] != escapeCharacter)
				cleanBuffer += rawBuffer[0];
		}
	}
	rawBuffer.clear();
	// Clean Buffer
	for (i = 0; i < cleanBuffer.size(); i++)
		if ((uint8_t)cleanBuffer[i] == startDelimiter) break;
	cleanBuffer.remove(0, i);

	// Leave if we don't have the minimum possible size of one frame.
	if (cleanBuffer.size() < 5) return;

	while (cleanBuffer.size() > 0) {

		// Calculate frame length
		frameLength = (int)cleanBuffer[1] << 8;
		frameLength += (int)cleanBuffer[2];

		// Leave if we don't have a full frame
		if(cleanBuffer.size()-4 < frameLength) return;

		// Verify frame checksum
		chksm = 0;
		for (i = 3; i < frameLength+3; i++) chksm += cleanBuffer[i];
		chksm = 0xFF - chksm;

		// Save frame
		blah = cleanBuffer[frameLength+3];
		frame = cleanBuffer.mid(3,frameLength);
		if (chksm == blah) {
			processPacket(frame);
		} else qDebug() << "Frame pr: " << frame.toHex() << "\n";
		cleanBuffer.remove(0, frameLength+4);
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
