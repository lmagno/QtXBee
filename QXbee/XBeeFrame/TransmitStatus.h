#ifndef TRANSMITSTATUS_H
#define TRANSMITSTATUS_H

#include <QByteArray>

#include "typedef.h"
#include "XBeeFrame.h"

class TransmitStatus : public XBeeFrame
{
	byte frameID;
	byte transmitRetryCount;
	byte deliveryStatus;
	byte discoveryStatus;
public:
	TransmitStatus();
	virtual byte getFrameType() const { return pTransmitStatus; }
	byte 		 getFrameID();
	byte 		 getTransmitRetryCount();
	byte 		 getDeliveryStatus();
	byte 		 getDiscoveryStatus();
	QByteArray 	 getFrameData();

	void 		 setFrameID(byte fi);
	void 		 setTransmitRetryCount(byte trc);
	void 		 setDeliveryStatus(byte ds);
	void 		 setDiscoveryStatus(byte ds);
	void 		 setFrameData(QByteArray);
};

#endif // TRANSMITSTATUS_H
