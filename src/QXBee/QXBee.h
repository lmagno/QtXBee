#ifndef QXBee_H
#define QXBee_H

#include <QObject>
#include <QByteArray>
#include <QString>
#include <QtSerialPort/QSerialPort>

#include "XBeePacket/XBeePacket.h"
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

class QXBee : public QObject
{
    Q_OBJECT
	QSerialPort *serial;
	bool xbeeFound;
	uint8_t APIMode;
	QByteArray rawBuffer, cleanBuffer;
	void processPacket(QByteArray packet);

public:
    explicit QXBee(QObject *parent = 0);
    QXBee(QSerialPort *ser);
	void send(XBeePacket *request);
    void broadcast(QString data);
	void unicast(QByteArray address, QString data);
    ~QXBee();

signals:
	void dataReceived(XBeePacket *);

private slots:
	void readData();

// Remove public slots on final version
public slots:
	void displayData(XBeePacket *);

};

#endif
