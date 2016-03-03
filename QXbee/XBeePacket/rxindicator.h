#ifndef RXINDICATOR_H
#define RXINDICATOR_H

#include "xbeepacket.h"
#include <QByteArray>

class RXIndicator : public XBeePacket
{
	QByteArray srcAddr64;
	QByteArray srcAddr16;
	unsigned receiveOptions;
	QByteArray data;
public:
	RXIndicator();
	virtual unsigned char getApiID() const;
	QByteArray getSrcAddr64();
	QByteArray getSrcAddr16();
	unsigned getReceiveOptions();
	QByteArray getData();
	QByteArray getFrameData();
	void readPacket(QByteArray rx);
	void setSrcAddr64(QByteArray sa64);
	void setSrcAddr16(QByteArray sa16);
	void setReceiveOptions(unsigned ro);
	void setData(QByteArray d);
	void setFrameData(QByteArray);
};

#endif // RXINDICATOR_H
