#include "qtxb.h"

#include "qtxb/digimeshpacket.h"

#include "qtxb/atcommand.h"
#include "qtxb/atcommandqueueparam.h"
#include "qtxb/txrequest.h"
#include "qtxb/txrequestexplicit.h"
#include "qtxb/remotecommandrequest.h"

#include "qtxb/atcommandresponse.h"
#include "qtxb/modemstatus.h"
#include "qtxb/transmitstatus.h"
#include "qtxb/rxindicator.h"
#include "qtxb/rxindicatorexplicit.h"
#include "qtxb/nodeidentificationindicator.h"
#include "qtxb/remotecommandresponse.h"


#include <QDebug>
#include <QList>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QCoreApplication>

QTXB::QTXB(QObject *parent) :
	QObject(parent)
{
}
QTXB::QTXB(QSerialPort *ser){
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


QTXB::~QTXB()
{
	if(serial->isOpen())
	{
		serial->close();
		qDebug() << "XBEE: Serial Port closed successfully";
	}
}
void QTXB::displayATCommandResponse(ATCommandResponse *digiMeshPacket){
	ATCommandResponse *response = new ATCommandResponse(this);
	response->readPacket(digiMeshPacket->getPacket());
	qDebug() << "Received ATCommandResponse: " << digiMeshPacket->getPacket().toHex();
}
void QTXB::displayModemStatus(ModemStatus *digiMeshPacket){
	qDebug() << "Received ModemStatus: " << digiMeshPacket->getPacket().toHex();
}
void QTXB::displayTransmitStatus(TransmitStatus *digiMeshPacket){
	qDebug() << "Received TransmitStatus: " << digiMeshPacket->getPacket().toHex();
}
void QTXB::displayRXIndicator(RXIndicator *digiMeshPacket){
	qDebug() << "Received RXIndicator: " << digiMeshPacket->getData().toHex();
}
void QTXB::displayRXIndicatorExplicit(RXIndicatorExplicit *digiMeshPacket){
	qDebug() << "Received RXIndicatorExplicit: " << digiMeshPacket->getPacket().toHex();
}
void QTXB::displayNodeIdentificationIndicator(NodeIdentificationIndicator *digiMeshPacket){
	qDebug() << "Received NodeIdentificationIndicator: " << digiMeshPacket->getPacket().toHex();
}
void QTXB::displayRemoteCommandResponse(RemoteCommandResponse *digiMeshPacket){
	qDebug() << "Received RemoteCommandResponse: " << digiMeshPacket->getPacket().toHex();
}

void QTXB::send(DigiMeshPacket *request)
{
	request->assemblePacket();
	if(xbeeFound && serial->isOpen())
	{
		qDebug() << "Transmit: " << request->getPacket().toHex();
		serial->write(request->getPacket());

		serial->flush();
	}
	else
	{
		qDebug() << "XBEE: Cannot write to Serial Port - closed";
	}
}
void QTXB::broadcast(QString data)
{
	TXRequest *request = new TXRequest(this);
	request->setData(data.toLatin1());
	send(request);
}
void QTXB::unicast(QByteArray address, QString data){
	TXRequest *request = new TXRequest(this);
	request->setDestAddr64(address);
	request->setData(data.toLatin1());
	send(request);
}

void QTXB::readData()
{
	const char startDelimiter = 0x7E;
	const char escapeCharacter = 0x7D;
	int i, frameIndex, frameLength, packetLength;
	unsigned char chksm;
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
	if (chksm == (unsigned char)frame[frameLength-1])
		processPacket(frame);
}

void QTXB::processPacket(QByteArray packet){

	unsigned packetType = (unsigned char)packet[3];
	switch (packetType) {
	case pATCommandResponse:{
		ATCommandResponse *response = new ATCommandResponse(this);
		response->readPacket(packet);
		emit receivedATCommandResponse(response);
		break;
	}
	case pModemStatus:{
		ModemStatus *response = new ModemStatus(this);
		response->readPacket(packet);
		emit receivedModemStatus(response);
		break;
	}
	case pTransmitStatus:{
		TransmitStatus *response = new TransmitStatus(this);
		response->readPacket(packet);
		emit receivedTransmitStatus(response);
		break;
	}
	case pRXIndicator:{
		RXIndicator *response = new RXIndicator(this);
		response->readPacket(packet);
		emit receivedRXIndicator(response);
		break;
	}
	case pRXIndicatorExplicit:{
		RXIndicatorExplicit *response = new RXIndicatorExplicit(this);
		response->readPacket(packet);
		emit receivedRXIndicatorExplicit(response);
		break;
	}
	case pNodeIdentificationIndicator:{
		NodeIdentificationIndicator *response = new NodeIdentificationIndicator(this);
		response->readPacket(packet);
		emit receivedNodeIdentificationIndicator(response);
		break;
	}
	case pRemoteCommandResponse:{
		RemoteCommandResponse *response = new RemoteCommandResponse(this);
		response->readPacket(packet);
		emit receivedRemoteCommandResponse(response);
		break;
	}
	default:
		qDebug() << "Error:  Unknown Packet: " << packet.toHex();


	}

}
