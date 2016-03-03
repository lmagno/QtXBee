#ifndef QXBEE_H
#define QXBEE_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "XBeePacket/XBeeFrame.h"
#include "XBeePacket/ATCommand.h"
#include "XBeePacket/ATCommandQueue.h"
#include "XBeePacket/TXRequest.h"
#include "XBeePacket/TXRequestExplicit.h"
#include "XBeePacket/ATCommandRemote.h"
#include "XBeePacket/ATCommandResponse.h"
#include "XBeePacket/ModemStatus.h"
#include "XBeePacket/TransmitStatus.h"
#include "XBeePacket/RXIndicator.h"
#include "XBeePacket/RXIndicatorExplicit.h"
#include "XBeePacket/NodeIdentificationIndicator.h"
#include "XBeePacket/ATCommandResponseRemote.h"

class QXbee : public QObject
{
    Q_OBJECT
public:
	explicit QXbee(QObject *parent = 0);
	QXbee(QSerialPort *ser);
	void send(XBeePacket *request);
    void broadcast(QString data);
    void unicast(QByteArray address, QString data);
	~QXbee();

signals:
    void receivedATCommandResponse(ATCommandResponse *response);
    void receivedModemStatus(ModemStatus *response);
    void receivedTransmitStatus(TransmitStatus *response);
    void receivedRXIndicator(RXIndicator *response);
    void receivedRXIndicatorExplicit(RXIndicatorExplicit *response);
    void receivedNodeIdentificationIndicator(NodeIdentificationIndicator *response);
	void receivedRemoteCommandResponse(ATCommandResponseRemote *response);

public slots:
    void displayATCommandResponse(ATCommandResponse *digiMeshPacket);
    void displayModemStatus(ModemStatus *digiMeshPacket);
    void displayTransmitStatus(TransmitStatus *digiMeshPacket);
    void displayRXIndicator(RXIndicator *digiMeshPacket);
    void displayRXIndicatorExplicit(RXIndicatorExplicit *digiMeshPacket);
    void displayNodeIdentificationIndicator(NodeIdentificationIndicator *digiMeshPacket);
	void displayRemoteCommandResponse(ATCommandResponseRemote *digiMeshPacket);

private slots:
    void readData();

private:
    QSerialPort *serial;
    bool xbeeFound;
    unsigned char protocolMode;
    QByteArray buffer;
    void processPacket(QByteArray packet);
};

#endif
