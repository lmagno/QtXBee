#ifndef TXREQUEST_H
#define TXREQUEST_H

#include <QByteArray>

#include "XBeePacket.h"

class TXRequest : public XBeePacket
{
	uint8_t			   frameID;
	QByteArray		   destinationAddress64;
	QByteArray		   destinationAddress16;
	uint8_t			   broadcastRadius;
	uint8_t			   transmitOptions;
	QByteArray		   rfData;

public:
	TXRequest();

	virtual uint8_t	   getFrameType() const { return pTXRequest; }
	uint8_t			   getFrameID();
	QByteArray		   getDestinationAddress64();
	QByteArray		   getDestinationAddress16();
	uint8_t			   getBroadcastRadius();
	uint8_t			   getTransmitOptions();
	QByteArray		   getTransmitingData();
	virtual QByteArray getFrameData();

	void			   setFrameID(uint8_t);
	void			   setDestinationAddress64(QByteArray);
	void			   setDestinationAddress16(QByteArray);
	void			   setBroadcastRadius(uint8_t);
	void			   setTransmitOptions(uint8_t);
	void			   setTransmitingData(QByteArray);
	virtual void	   setFrameData(QByteArray);
	virtual			   ~TXRequest();
};

#endif // TXREQUEST_H
