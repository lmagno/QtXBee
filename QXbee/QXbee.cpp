#include <QDebug>
#include <QList>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QCoreApplication>

#include "QXbee.h"

QXbee::QXbee(QObject *parent) :
	QObject(parent)
{
}

QXbee::QXbee(QSerialPort *ser){
	xbeeFound = false;
	serial = ser;
	QByteArray data;
	protocolMode = 0;

	if (serial->open(QIODevice::ReadWrite) && serial->isOpen())
	{
		// Enter AT command mode
		serial->write("+++");

		// Wait for OK
		while (serial->waitForReadyRead(2000)) data += serial->readAll();

		if (data.startsWith("OK")) {
			data.clear();
			// Request protocol mode
			serial->write("ATAP\r");
			// Wait for answer
			while (serial->waitForReadyRead(2000)) data += serial->readAll();
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


QXbee::~QXbee()
{
	if(serial->isOpen())
	{
		serial->close();
		qDebug() << "XBEE: Serial Port closed successfully";
	}
}
void QXbee::displayATCommandResponse(ATCommandResponse *packet){
	qDebug() << "Received ATCommandResponse: " << packet->getFrameData().toHex();
}
void QXbee::displayModemStatus(ModemStatus *digiMeshPacket){
	qDebug() << "Received ModemStatus: " << digiMeshPacket->getFrameData().toHex();
}
void QXbee::displayTransmitStatus(TransmitStatus *digiMeshPacket){
	qDebug() << "Received TransmitStatus: " << digiMeshPacket->getFrameData().toHex();
}
void QXbee::displayRXIndicator(RXIndicator *digiMeshPacket){
	qDebug() << "Received RXIndicator: " << digiMeshPacket->getFrameData().toHex();
}
void QXbee::displayRXIndicatorExplicit(RXIndicatorExplicit *digiMeshPacket){
	qDebug() << "Received RXIndicatorExplicit: " << digiMeshPacket->getFrameData().toHex();
}
void QXbee::displayNodeIdentificationIndicator(NodeIdentificationIndicator *digiMeshPacket){
	qDebug() << "Received NodeIdentificationIndicator: " << digiMeshPacket->getFrameData().toHex();
}
void QXbee::displayRemoteCommandResponse(ATCommandResponseRemote *digiMeshPacket){
	qDebug() << "Received RemoteCommandResponse: " << digiMeshPacket->getFrameData().toHex();
}

void QXbee::send(XBeeFrame *request)
{
	union {
		unsigned short value;
		quint8 byte[2];
	} frameLength;
	quint8 chksm = 0;
	QByteArray frame;

	// Assemble frame
	frame[0] = 0x7E;
	frame.insert(3, request->getFrameData());
	frameLength.value = frame.length() + 1;
	frame[1] = frameLength.byte[1];
	frame[2] = frameLength.byte[0];
	// Calculate checksum
	for (int i = 3; i < frameLength.value-1; i++) chksm += frame[i];
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

void QXbee::broadcast(QString data)
{
	TXRequest *request = new TXRequest;
	request->setData(data.toLatin1());
	send(request);
}

void QXbee::unicast(QByteArray address, QString data){
	TXRequest *request = new TXRequest;
	request->setDestAddr64(address);
	request->setData(data.toLatin1());
	send(request);
}

void QXbee::readData()
{
	const char startDelimiter = 0x7E;
	const char escapeCharacter = 0x7D;
	int i, frameIndex, frameLength, packetLength;
	quint8 chksm;
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

		// Extract frame
		switch (protocolMode) {
		case 1:
			// Calculate frame length
			frameLength = (int)buffer[1] << 8;
			frameLength += (int)buffer[2] + 4;

			// Leave if we don't have a full frame
			if(buffer.size() < frameLength) return;

			// Save frame
			frame = buffer.left(frameLength);
			buffer.remove(0, frameLength);

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
	}

	// Verify packet checksum
	chksm = 0;
	for (i = 3; i < frameLength-1; i++) chksm += frame[i];
	chksm = 0xFF - chksm;

	// Process packet
	if (chksm == (quint8)frame[frameLength-1])
		processPacket(frame);
}

void QXbee::processPacket(QByteArray packet){
	switch (packet[0]) {
	case XBeeFrame::pATCommandResponse:{
		ATCommandResponse *response = new ATCommandResponse;
		response->setFrameData(packet);
		emit receivedATCommandResponse(response);
		break;
	}
	case XBeeFrame::pModemStatus:{
		ModemStatus *response = new ModemStatus;
		response->setFrameData(packet);
		emit receivedModemStatus(response);
		break;
	}
	case XBeeFrame::pTransmitStatus:{
		TransmitStatus *response = new TransmitStatus;
		response->setFrameData(packet);
		emit receivedTransmitStatus(response);
		break;
	}
	case XBeeFrame::pRXIndicator:{
		RXIndicator *response = new RXIndicator;
		response->setFrameData(packet);
		emit receivedRXIndicator(response);
		break;
	}
	case XBeeFrame::pRXIndicatorExplicit:{
		RXIndicatorExplicit *response = new RXIndicatorExplicit;
		response->setFrameData(packet);
		emit receivedRXIndicatorExplicit(response);
		break;
	}
	case XBeeFrame::pNodeIdentificationIndicator:{
		NodeIdentificationIndicator *response = new NodeIdentificationIndicator;
		response->setFrameData(packet);
		emit receivedNodeIdentificationIndicator(response);
		break;
	}
	case XBeeFrame::pATCommandResponseRemote:{
		ATCommandResponseRemote *response = new ATCommandResponseRemote;
		response->setFrameData(packet);
		emit receivedRemoteCommandResponse(response);
		break;
	}
	default:
		qDebug() << "Error:  Unknown Packet: " << packet.toHex();


	}

}
