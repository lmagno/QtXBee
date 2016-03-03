#ifndef TRANSMITSTATUS_H
#define TRANSMITSTATUS_H

#include <QByteArray>

#include "XBeeFrame.h"

class TransmitStatus : public XBeeFrame
{
	quint8 deliveryStatus;
	quint8 transmitRetryCount;
	quint8 discoveryStatus;
public:
	TransmitStatus();
	virtual quint8 getFrameType() const { return pTransmitStatus; }
	quint8 getDeliveryStatus();
	quint8 getTransmitRetryCount();
	quint8 getDiscoveryStatus();
	QByteArray getFrameData();
	void setDeliveryStatus(unsigned ds);
	void setTransmitRetryCount(unsigned trc);
	void setDiscoveryStatus(unsigned ds);
	void setFrameData(QByteArray);
};

#endif // TRANSMITSTATUS_H
