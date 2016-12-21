#include <QDebug>

#include "QXBee.h"

QXBee::QXBee(QSerialPort& port){
	xbeeFound = false;
	serial = &port;
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
            qDebug() << "QXBee: Protocol mode: " << APIMode;
			// Exit AT command mode
			serial->write("ATCN\r");
		}

		if (APIMode > 0) {
			xbeeFound = true;
			connect(serial, SIGNAL(readyRead()), SLOT(readData()));
            qDebug() << "QXBee: Connected successfully.";
            qDebug() << "QXBee: Serial Port Name: " << serial->portName();
		} else {
            qWarning() << "QXBee: Warning - Device not in API protocol mode.";
		}
	}
	else
	{
        qCritical() << "QXBee: Error - Serial Port could not be opened.";
	}

}

QXBee::~QXBee()
{
    if(serial->isOpen())
    {
        serial->close();
        qDebug() << "QXbee: Serial Port closed successfully.";
    }
}

void QXBee::send(XBeePacket &packet)
{
    union {
        uint16_t i;
        uint8_t b[2];
    } dataLength;
    uint8_t chksm = 0;
    QByteArray frame, data;

    data = packet.getFrameData();
    dataLength.i = data.length();

    // Calculate checksum
    for (int i = 0; i < data.length(); i++) chksm += data[i];
    chksm = 0xFF - chksm;

    // Assemble frame
    frame += startDelimiter;
    if (APIMode == 2) {
        frame += escape(dataLength.b[1]);
        frame += escape(dataLength.b[0]);
        frame += escape(data);
        frame += escape(chksm);
    } else {
        frame += dataLength.b[1];
        frame += dataLength.b[0];
        frame += data;
        frame += chksm;
    }

	if(xbeeFound && serial->isOpen())
	{
        qDebug() << "QXBee: Transmit: " << frame.toHex();
		serial->write(frame);
		serial->flush();
	}
	else
	{
        qWarning() << "QXBee: Warning - Could not write to Serial Port.";
	}
}

void QXBee::broadcast(QString data)
{
	TXRequest packet;
	packet.setTransmitingData(data.toLatin1());
	send(packet);
}

void QXBee::unicast(QByteArray address, QString data){
	TXRequest packet;
	packet.setDestinationAddress64(address);
	packet.setTransmitingData(data.toLatin1());
	send(packet);
}

void QXBee::readData()
{
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
        } else qDebug() << "QXBee: Frame checksum Error: " << cleanBuffer.mid(3,frameLength.i).toHex();
		cleanBuffer.remove(0, frameLength.i+4);
	}
}

void QXBee::processPacket(QByteArray frame){
	switch ((uint8_t)frame[0]) {
	case XBeePacket::ATCommandResponse:{
		ATCommandResponse packet;
		packet.setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::ModemStatus:{
		ModemStatus packet;
		packet.setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::TransmitStatus:{
		TransmitStatus packet;
		packet.setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::RXIndicator:{
		RXIndicator packet;
		packet.setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::RXIndicatorExplicit:{
		RXIndicatorExplicit packet;
		packet.setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::NodeIdentificationIndicator:{
		NodeIdentificationIndicator packet;
		packet.setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	case XBeePacket::ATCommandResponseRemote:{
		ATCommandResponseRemote packet;
		packet.setFrameData(frame);
		emit dataReceived(packet);
		break;
	}
	default:
        qDebug() << "QXBee: Unknown Packet: " << frame.toHex();
	}
}

QByteArray QXBee::escape(QByteArray data) {
    QByteArray escapedData;

    for (int i = 0; i < data.length(); i++) {
        if ((uint8_t)data[i] == startDelimiter || (uint8_t)data[i] == escapeCharacter || (uint8_t)data[i] == XONCharacter || (uint8_t)data[i] == XOFFCharacter) {
            escapedData.append(escapeCharacter);
            escapedData.append(data[i]^0x20);
        } else {
            escapedData.append(data[i]);
        }
    }
    return escapedData;
}

QByteArray QXBee::escape(uint8_t data) {
    QByteArray escapedData;
    escapedData += data;
    return escape(escapedData);
}
