/**
 * @class TransmitStatus
 * @ingroup XBeePacket
 *
 * Represents an AT Command packet
 *
 * Test...
 */

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
	void		 setFrameID(uint8_t id);
	void		 setDestinationAddress16(QByteArray address);
	void		 setTransmitRetryCount(uint8_t count);
	void		 setDeliveryStatus(uint8_t status);
	void		 setDiscoveryStatus(uint8_t status);

public:
	TransmitStatus();

	virtual uint8_t getFrameType() const { return FrameType::TransmitStatus; }
	uint8_t		 getFrameID();
	QByteArray	 getDestinationAddress16();
	uint8_t		 getTransmitRetryCount();
	uint8_t		 getDeliveryStatus();
	uint8_t		 getDiscoveryStatus();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray data);
	virtual		 ~TransmitStatus();
};

#endif // TRANSMITSTATUS_H
