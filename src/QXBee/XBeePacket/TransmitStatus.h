#ifndef TRANSMITSTATUS_H
#define TRANSMITSTATUS_H

#include <QByteArray>

#include "XBeePacket.h"

class TransmitStatus : public XBeePacket
{
	uint8_t		 frameID;
	QByteArray	 destinationAddress16;
	uint8_t		 transmitRetryCount;
	uint8_t		 deliveryStatus;
	uint8_t		 discoveryStatus;

protected:
	void		 setFrameID(uint8_t);
	void		 setDestinationAddress16(QByteArray);
	void		 setTransmitRetryCount(uint8_t);
	void		 setDeliveryStatus(uint8_t);
	void		 setDiscoveryStatus(uint8_t);

public:
	TransmitStatus();

	virtual uint8_t getFrameType() const { return FrameType::TransmitStatus; }
	uint8_t		 getFrameID();
	QByteArray	 getDestinationAddress16();
	uint8_t		 getTransmitRetryCount();
	uint8_t		 getDeliveryStatus();
	uint8_t		 getDiscoveryStatus();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray);
	virtual		 ~TransmitStatus();
};

#endif // TRANSMITSTATUS_H
