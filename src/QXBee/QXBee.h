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

/** @brief The QXBee class provides bi-directional communication with a XBee device thru serial port.
 *
 * This class can send and receive data using Digi's XBee API protocol mode 1 or 2.
 * There are also included two helper functions, that can easily unicast or broadcast data to XBee devices.
 * This class uses QObject signals and slots, and emits a signal whenever a new packet arrive, it also needs a previously setup QSerialPort for communication.
 *
 * Example:
 * @code
 * QSerialPort serial;
 * serial.setPortName("/dev/ttyUSB1");
 * serial.setBaudRate(QSerialPort::Baud9600);
 * serial.setDataBits(QSerialPort::Data8);
 * serial.setParity(QSerialPort::NoParity);
 * serial.setStopBits(QSerialPort::OneStop);
 * serial.setFlowControl(QSerialPort::NoFlowControl);
 *
 * QXBee xbee(serial);
 * xbee.broadcast("Hello World!");
 *
 * @endcode
 */
class QXBee : public QObject
{
    Q_OBJECT
	QSerialPort *serial;
	bool xbeeFound;
	uint8_t APIMode;
	QByteArray rawBuffer, cleanBuffer;
	void processPacket(QByteArray);

public:
	QXBee(QSerialPort& port);
	void send(XBeePacket& packet);						///< @brief This function sends a packet to the XBee module.
	void broadcast(QString data);						///< @brief This function broadcasts a string to any acessible XBee device.
	void unicast(QByteArray address, QString data);		///< @brief This function sends a string to a single XBee device specified by it's address.
    ~QXBee();

signals:
	void dataReceived(XBeePacket&);						///< @brief This signal is emited whenever a packet arrives.

private slots:
	void readData();

};

#endif
