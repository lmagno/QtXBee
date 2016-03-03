#ifndef TRANSMITSTATUS_H
#define TRANSMITSTATUS_H

#include <QByteArray>

#include "typedef.h"
#include "XBeeFrame.h"

class TransmitStatus : public XBeeFrame
{
	byte deliveryStatus;
	byte transmitRetryCount;
	byte discoveryStatus;
public:
	TransmitStatus();
	virtual byte getFrameType() const { return pTransmitStatus; }
	byte getDeliveryStatus();
	byte getTransmitRetryCount();
	byte getDiscoveryStatus();
	QByteArray getFrameData();
	void setDeliveryStatus(unsigned ds);
	void setTransmitRetryCount(unsigned trc);
	void setDiscoveryStatus(unsigned ds);
	void setFrameData(QByteArray);
};

#endif // TRANSMITSTATUS_H
