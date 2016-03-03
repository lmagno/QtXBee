#ifndef QXBEE_H
#define QXBEE_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "XBeePacket/xbeepacket.h"
#include "XBeePacket/atcommand.h"
#include "XBeePacket/atcommandqueue.h"
#include "XBeePacket/txrequest.h"
#include "XBeePacket/txrequestexplicit.h"
#include "XBeePacket/atcommandremote.h"
#include "XBeePacket/atcommandresponse.h"
#include "XBeePacket/modemstatus.h"
#include "XBeePacket/transmitstatus.h"
#include "XBeePacket/rxindicator.h"
#include "XBeePacket/rxindicatorexplicit.h"
#include "XBeePacket/nodeidentificationindicator.h"
#include "XBeePacket/atcommandresponseremote.h"

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
