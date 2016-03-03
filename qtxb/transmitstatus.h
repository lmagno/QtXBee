#ifndef TRANSMITSTATUS_H
#define TRANSMITSTATUS_H
#include "xbeepacket.h"
#include <QByteArray>

class TransmitStatus : public XBeePacket
{
	unsigned char deliveryStatus;
	unsigned char transmitRetryCount;
	unsigned char discoveryStatus;
public:
	TransmitStatus();
	virtual unsigned char getApiID() const { return QTXB::pTransmitStatus; }
	unsigned char getDeliveryStatus();
	unsigned char getTransmitRetryCount();
	unsigned char getDiscoveryStatus();
	QByteArray getFrameData();
	void setDeliveryStatus(unsigned ds);
	void setTransmitRetryCount(unsigned trc);
	void setDiscoveryStatus(unsigned ds);
	void setFrameData(QByteArray);
};

#endif // TRANSMITSTATUS_H
