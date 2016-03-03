#ifndef TXREQUEST_H
#define TXREQUEST_H

#include <QByteArray>

#include "XBeeFrame.h"

class TXRequest : public XBeeFrame
{
	quint8 frameID;
	QByteArray destAddr64;
	QByteArray destAddr16;
	unsigned broadcastRadius;
	unsigned transmitOptions;
	QByteArray data;
public:
	TXRequest();
	virtual quint8 getFrameType() const { return pTXRequest; }
	quint8 getFrameID();
	QByteArray getDestAddr64();
	QByteArray getDestAddr16();
	unsigned getBroadcastRadius();
	unsigned getTransmitOptions();
	QByteArray getData();
	QByteArray getFrameData();
	void setFrameID(quint8);
	void setBroadcastRadius(int rad);
	void setTransmitOptions(unsigned to);
	void setDestAddr64(QByteArray da64);
	void setDestAddr16(QByteArray da16);
	void setData(QByteArray d);
	void setFrameData(QByteArray);
};

#endif // TXREQUEST_H
