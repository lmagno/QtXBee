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
#include <QTimer>
#include <QTime>
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

    connect(serial, SIGNAL(readyRead()), SLOT(readData()));

    if (serial->open(QIODevice::ReadWrite) && serial->isOpen())
    {
        qDebug() << "XBEE: Connected successfully";
        qDebug() << "XBEE: Serial Port Name: " << serial->portName();
        xbeeFound = true;
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
    //qDebug() << "Received ATCommandResponse (data): " << response->getData().toHex();
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
    int length;

    buffer.append(serial->readAll());

    QByteArray packet;

    // Clean buffer
    for (length = 0; length < buffer.length(); length++)
        if ((buffer.at(length) == startDelimiter) && length > 0) break;
        
    buffer.remove(0,length);

    // If we have a data frame
    if (buffer.length() > 2) {
        // Get packet size
        length = (int)buffer.at(1) << 8;
        length += buffer.at(2)+4;
        // Fetch packet
        if(buffer.size() >= length){
            packet.append(buffer.left(length));
            processPacket(packet);
            buffer.remove(0, length);
        }
    }
}

void QTXB::processPacket(QByteArray packet){

    unsigned packetType = (unsigned char)packet.at(3);
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
