#include <QCoreApplication>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <signal.h>

#include "QXBee.h"

void handler(int) { QCoreApplication::quit(); }

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QSerialPort serial;
	signal(SIGINT, handler);

	QFile in("device.cfg");
	if(!in.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Couldn't open file device.cfg";
		return 1;
	}
	QTextStream device(&in);

	serial.setPortName(device.readLine());
	serial.setBaudRate(QSerialPort::Baud9600);
	serial.setDataBits(QSerialPort::Data8);
	serial.setParity(QSerialPort::NoParity);
	serial.setStopBits(QSerialPort::OneStop);
	serial.setFlowControl(QSerialPort::NoFlowControl);

	QXBee xb(&serial);
	QObject::connect(&xb, SIGNAL(dataReceived(XBeePacket*)), &xb, SLOT(displayData(XBeePacket*)));

	ATCommand teste;
	teste.setATCommand("ND");

	xb.send(&teste);

	return a.exec();
}
