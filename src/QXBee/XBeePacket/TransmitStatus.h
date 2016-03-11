#ifndef TRANSMITSTATUS_H
#define TRANSMITSTATUS_H

#include <QByteArray>

#include "XBeePacket.h"

class TransmitStatus : public XBeePacket
{
	byte		 frameID;
	QByteArray	 destinationAddress16;
	byte		 transmitRetryCount;
	byte		 deliveryStatus;
	byte		 discoveryStatus;

protected:
	void		 setFrameID(byte);
	void		 setDestinationAddress16(QByteArray);
	void		 setTransmitRetryCount(byte);
	void		 setDeliveryStatus(byte);
	void		 setDiscoveryStatus(byte);

public:
	TransmitStatus();

	virtual byte getFrameType() const { return pTransmitStatus; }
	byte		 getFrameID();
	QByteArray	 getDestinationAddress16();
	byte		 getTransmitRetryCount();
	byte		 getDeliveryStatus();
	byte		 getDiscoveryStatus();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray);
	virtual		 ~TransmitStatus();
};

#endif // TRANSMITSTATUS_H
