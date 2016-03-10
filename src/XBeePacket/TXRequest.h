#ifndef TXREQUEST_H
#define TXREQUEST_H

#include <QByteArray>

#include "typedef.h"
#include "XBeeFrame.h"

class TXRequest : public XBeeFrame
{
	byte			   frameID;
	QByteArray		   destinationAddress64;
	QByteArray		   destinationAddress16;
	byte			   broadcastRadius;
	byte			   transmitOptions;
	QByteArray		   rfData;

public:
	TXRequest();

	virtual byte	   getFrameType() const { return pTXRequest; }
	byte			   getFrameID();
	QByteArray		   getDestinationAddress64();
	QByteArray		   getDestinationAddress16();
	byte			   getBroadcastRadius();
	byte			   getTransmitOptions();
	QByteArray		   getTransmitingData();
	virtual QByteArray getFrameData();

	void			   setFrameID(byte);
	void			   setDestinationAddress64(QByteArray);
	void			   setDestinationAddress16(QByteArray);
	void			   setBroadcastRadius(byte);
	void			   setTransmitOptions(byte);
	void			   setTransmitingData(QByteArray);
	virtual void	   setFrameData(QByteArray);
};

#endif // TXREQUEST_H
