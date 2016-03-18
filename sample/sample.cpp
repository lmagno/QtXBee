#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QFile>
#include <QTextStream>

#include "sample.h"

Sample::Sample(QObject *parent) : QObject(parent)
{

	 QFile in("device.cfg");
	 if(!in.open(QIODevice::ReadOnly | QIODevice::Text)) {
		 qDebug() << "Couldn't open file device.cfg";
		 return;
	 }
	 QTextStream device(&in);

	 serial.setPortName(device.readLine());
	 serial.setBaudRate(QSerialPort::Baud9600);
	 serial.setDataBits(QSerialPort::Data8);
	 serial.setParity(QSerialPort::NoParity);
	 serial.setStopBits(QSerialPort::OneStop);
	 serial.setFlowControl(QSerialPort::NoFlowControl);

	 xb = new QXBee(&serial);
	 QObject::connect(xb, SIGNAL(dataReceived(XBeePacket*)), this, SLOT(displayData(XBeePacket*)));

	 ATCommand teste;
	 teste.setATCommand("ND");

	 xb->send(&teste);
 }

 void Sample::displayData(XBeePacket *packet){
	 static int count = 1;
	 int idx;
	 uint8_t frameType = packet->getFrameType();
	 switch (frameType) {
		 case XBeePacket::pATCommandResponse:
		 {
			 QByteArray data = ((ATCommandResponse *)packet)->getCommandData();
			 idx = data.indexOf((char)0x00, 10);
			 qDebug() << count++ << "Raw data: " << packet->getFrameData().toHex() << " - " << data.mid(2, 8).toHex() << " - " << data.mid(10,idx-10);
			 //qDebug() << "Command: " << ((ATCommandResponse *)packet)->getATCommand();
			 //qDebug() << "Status: " << ((ATCommandResponse *)packet)->getCommandStatus();
			 //qDebug() << "Remote Address: " << data.mid(2, 8).toHex();
			 //idx += 3;
			 //qDebug() << "Device type: " << (uint8_t)data[idx];
			 //qDebug() << "Profile ID: " << data.mid(idx+2, 2).toHex();
			 //qDebug() << "Manufacturer: " << data.mid(idx+4, 2).toHex();
			 //qDebug() << "";
		 }
		 break;
		 case XBeePacket::pRXIndicator:
		 {
			 qDebug() << "Received Data: " << packet->getFrameData().toHex();
			 qDebug() << "Mensagem: " << ((RXIndicator *)packet)->getReceivedData();
		 }
		 break;
		 default:
		 {
			 qDebug() << "Received Data: " << packet->getFrameData().toHex();
		 }
	 }
	 delete (packet);
 }

 Sample::~Sample() {
	 delete xb;
 }
