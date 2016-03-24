#ifndef SAMPLE_H
#define SAMPLE_H

#include <QObject>

#include "QXBee.h"

class Sample : public QObject
{
	Q_OBJECT
	QXBee *xb;
	QSerialPort serial;
public:
	explicit Sample(QObject *parent = 0);
	~Sample();
public slots:
	void displayData(XBeePacket * const);

};

#endif // SAMPLE_H
