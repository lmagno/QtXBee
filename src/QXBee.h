#ifndef QXBee_H
#define QXBee_H

#include <QObject>
#include <QByteArray>
#include <QString>
#include <QtSerialPort/QSerialPort>

#include "typedef.h"
#include "XBeeFrame/XBeeFrame.h"
#include "XBeeFrame/ATCommand.h"
#include "XBeeFrame/ATCommandQueue.h"
#include "XBeeFrame/TXRequest.h"
#include "XBeeFrame/TXRequestExplicit.h"
#include "XBeeFrame/ATCommandRemote.h"
#include "XBeeFrame/ATCommandResponse.h"
#include "XBeeFrame/ModemStatus.h"
#include "XBeeFrame/TransmitStatus.h"
#include "XBeeFrame/RXIndicator.h"
#include "XBeeFrame/RXIndicatorExplicit.h"
#include "XBeeFrame/NodeIdentificationIndicator.h"
#include "XBeeFrame/ATCommandResponseRemote.h"

class QXBee : public QObject
{
    Q_OBJECT
public:
    explicit QXBee(QObject *parent = 0);
    QXBee(QSerialPort *ser);
	void send(XBeeFrame *request);
    void broadcast(QString data);
    void unicast(QByteArray address, QString data);
    ~QXBee();

signals:
    void receivedATCommandResponse(ATCommandResponse *response);
    void receivedModemStatus(ModemStatus *response);
    void receivedTransmitStatus(TransmitStatus *response);
    void receivedRXIndicator(RXIndicator *response);
    void receivedRXIndicatorExplicit(RXIndicatorExplicit *response);
    void receivedNodeIdentificationIndicator(NodeIdentificationIndicator *response);
	void receivedRemoteCommandResponse(ATCommandResponseRemote *response);

// Remove public slots on final version
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
    byte protocolMode;
    QByteArray buffer;
    void processPacket(QByteArray packet);
};

#endif
