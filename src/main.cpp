#include <QCoreApplication>
#include "QXBee.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QTime>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <signal.h>
#include <unistd.h>
#include <functional>

void handler (int sig) {
    qDebug() << "\nquit the application (user request signal =" << sig << ")\n";
    QCoreApplication::quit();
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    signal(SIGINT, handler);
    QSerialPort *serial = new QSerialPort();

    QFile in("device.cfg");
    if(!in.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Couldn't open file device.cfg";
        return 1;
    }
    QTextStream device(&in);
    serial->setPortName(device.readLine());
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    QXBee *xb = new QXBee(serial);
	QObject::connect(xb, SIGNAL(dataReceived(XBeePacket*)), xb, SLOT(displayData(XBeePacket*)));

    // QByteArray address = QByteArray::fromHex("0013a20040a53581");
    // QString data = "Hello World";

	ATCommand *teste = new ATCommand;
	teste->setFrameID(0x01);
    teste->setATCommand("ND");

    xb->send(teste);

    return a.exec();
}
