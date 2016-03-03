#ifndef TXREQUEST_H
#define TXREQUEST_H

#include "XBeePacket.h"
#include <QByteArray>

class TXRequest : public XBeePacket
{
	unsigned char frameID;
	QByteArray destAddr64;
	QByteArray destAddr16;
	unsigned broadcastRadius;
	unsigned transmitOptions;
	QByteArray data;
public:
	TXRequest();
	virtual unsigned char getApiID() const;
	unsigned char getFrameID();
	QByteArray getDestAddr64();
	QByteArray getDestAddr16();
	unsigned getBroadcastRadius();
	unsigned getTransmitOptions();
	QByteArray getData();
	QByteArray getFrameData();
	void setFrameID(unsigned char);
	void setBroadcastRadius(int rad);
	void setTransmitOptions(unsigned to);
	void setDestAddr64(QByteArray da64);
	void setDestAddr16(QByteArray da16);
	void setData(QByteArray d);
	void setFrameData(QByteArray);
};

#endif // TXREQUEST_H
