#ifndef TRANSMITSTATUS_H
#define TRANSMITSTATUS_H

#include <QByteArray>

#include "XBeeFrame.h"

class TransmitStatus : public XBeeFrame
{
	unsigned char deliveryStatus;
	unsigned char transmitRetryCount;
	unsigned char discoveryStatus;
public:
	TransmitStatus();
	virtual unsigned char getFrameType() const { return pTransmitStatus; }
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
