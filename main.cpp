#include <QCoreApplication>
#include "QXbee/QXbee.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QTime>
#include <QFile>
#include <QString>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

	QXbee *xb = new QXbee(serial);
    QObject::connect(xb, SIGNAL(receivedATCommandResponse(ATCommandResponse*)), xb, SLOT(displayATCommandResponse(ATCommandResponse*)));
    QObject::connect(xb, SIGNAL(receivedModemStatus(ModemStatus*)), xb, SLOT(displayModemStatus(ModemStatus*)));
    QObject::connect(xb, SIGNAL(receivedTransmitStatus(TransmitStatus*)), xb, SLOT(displayTransmitStatus(TransmitStatus*)));
    QObject::connect(xb, SIGNAL(receivedRXIndicator(RXIndicator*)), xb, SLOT(displayRXIndicator(RXIndicator*)));
    QObject::connect(xb, SIGNAL(receivedRXIndicatorExplicit(RXIndicatorExplicit*)), xb, SLOT(displayRXIndicatorExplicit(RXIndicatorExplicit*)));
    QObject::connect(xb, SIGNAL(receivedNodeIdentificationIndicator(NodeIdentificationIndicator*)), xb, SLOT(displayNodeIdentificationIndicator(NodeIdentificationIndicator*)));
	QObject::connect(xb, SIGNAL(receivedRemoteCommandResponse(ATCommandResponseRemote*)), xb, SLOT(displayRemoteCommandResponse(ATCommandResponseRemote*)));

    // QByteArray address = QByteArray::fromHex("0013a20040a53581");
    // QString data = "Hello World";

	ATCommand *teste = new ATCommand;
	teste->setFrameID(0x01);
    teste->setATCommand("ND");

    xb->send(teste);

    forever{
        // xb->broadcast(data);
        QTime dieTime= QTime::currentTime().addMSecs(500);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    return a.exec();
}
