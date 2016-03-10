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
	byte frameType = packet->getFrameType();
	switch (frameType) {
		case XBeePacket::pATCommandResponse:
		{
			int idx = 0;
			QByteArray data = ((ATCommandResponse *)packet)->getCommandData();
			qDebug() << "Raw data: " << ((ATCommandResponse *)packet)->getFrameData().toHex();
			qDebug() << "Command: " << ((ATCommandResponse *)packet)->getATCommand();
			qDebug() << "Status: " << ((ATCommandResponse *)packet)->getCommandStatus();
			qDebug() << "Remote Address: " << data.mid(2, 8).toHex();
			idx = data.indexOf((char)0x00, 10);
			qDebug() << "Name: " << data.mid(10,idx-10);
			idx += 3;
			qDebug() << "Device type: " << (byte)data[idx];
			qDebug() << "Profile ID: " << data.mid(idx+2, 2).toHex();
			qDebug() << "Manufacturer: " << data.mid(idx+4, 2).toHex();
			qDebug() << "";
		}
		break;
		case XBeePacket::pRXIndicator:
		{
			qDebug() << "Received Data: " << packet->getFrameData();
			qDebug() << "Mensagem: " << ((RXIndicator *)packet)->getReceivedData();
		}
		break;
		default:
		{
			qDebug() << "Received Data: " << packet->getFrameData();
		}
	}
	delete (packet);
}

void QXBee::send(XBeePacket *request)
{
	union {
		unsigned short i;
		byte b[2];
	} dataLength;
	byte chksm = 0;
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
	TXRequest *request = new TXRequest;
	request->setTransmitingData(data.toLatin1());
	send(request);
}

void QXBee::unicast(QByteArray address, QString data){
	TXRequest *request = new TXRequest;
	request->setDestinationAddress64(address);
	request->setTransmitingData(data.toLatin1());
	send(request);
}

void QXBee::readData()
{
	const char startDelimiter = 0x7E;
	const char escapeCharacter = 0x7D;
	int i, frameIndex, frameLength, packetLength;
	byte chksm, blah;
	QByteArray frame;

	i = frameIndex = frameLength = packetLength = 0;

	buffer += serial->readAll();

	// Clean buffer
	for (i = 0; i < buffer.size(); i++)
		if (buffer[i] == startDelimiter) break;
	buffer.remove(0, i);

	// Leave if we don't have the minimum possible size of one frame.
	if (buffer.size() < 5) return;

	while (buffer.size() > 0) {

		frame.clear();

		// Extract frame
		switch (protocolMode) {
		case 1:
			// Calculate frame length
			frameLength = (int)buffer[1] << 8;
			frameLength += (int)buffer[2];

			// Leave if we don't have a full frame
			if(buffer.size()-4 < frameLength) return;

			// Verify frame checksum
			chksm = 0;
			for (i = 3; i < frameLength+3; i++) chksm += buffer[i];
			chksm = 0xFF - chksm;

			// Save frame
			blah = buffer[frameLength+3];
			if (chksm == blah) {
				frame = buffer.mid(3,frameLength);
				buffer.remove(0, frameLength+4);
			}
			break;

		case 2:
			frameIndex = 1;
			// Calculate frame length
			if (buffer[frameIndex] == escapeCharacter) {
				frameLength = (int)(buffer[++frameIndex]^0x20) << 8;
			}
			else
				frameLength = (int)buffer[frameIndex] << 8;
			if (buffer[++frameIndex] == escapeCharacter)
				frameLength += (int)(buffer[++frameIndex]^0x20) + 4;
			else
				frameLength += buffer[frameIndex]+4;

			// Leave if we don't have the minimum length for a frame
			if(buffer.size() < (frameLength+frameIndex-2)) return;

			// Remove escaped characters and save frame
			packetLength = frameLength - 3;
			while ((buffer.size() > ++frameIndex) && (frame.size() != packetLength)) {
				if (buffer[frameIndex] != escapeCharacter) {
					frame += buffer[frameIndex];
				} else {
					if (buffer.size() < ++frameIndex) return; // exit if not enough bytes
					frame += buffer[frameIndex]^0x20;
				}
			}
			if (frame.size() != packetLength) return;
			buffer.remove(0, frameIndex);
		}

		// Process packet
		if (!frame.isEmpty()) processPacket(frame);
	}
}

void QXBee::processPacket(QByteArray frame){
	XBeePacket *packet = 0;
	switch ((byte)frame[0]) {
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
