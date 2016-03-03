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
	static const unsigned char pATCommand = 0x08;
	static const unsigned char pATCommandQueue = 0x09;
	static const unsigned char pTXRequest = 0x10;
	static const unsigned char pTXRequestExplicit = 0x11;
	static const unsigned char pATCommandRemote = 0x17;
	static const unsigned char pATCommandResponse = 0x88;
	static const unsigned char pModemStatus = 0x8A;
	static const unsigned char pTransmitStatus = 0x8B;
	static const unsigned char pRXIndicator = 0x90;
	static const unsigned char pRXIndicatorExplicit = 0x91;
	static const unsigned char pNodeIdentificationIndicator = 0x95;
	static const unsigned char pATCommandResponseRemote = 0x97;

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
