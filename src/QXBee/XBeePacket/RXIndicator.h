/**
 * @class RXIndicator
 * @ingroup XBeePacket
 *
 * Represents an AT Command packet
 *
 * Test...
 */

#ifndef RXINDICATOR_H
#define RXINDICATOR_H

#include <QByteArray>

#include "XBeePacket.h"

class RXIndicator : public XBeePacket
{
	QByteArray		   sourceAddress64;
	QByteArray		   sourceAddress16;
	uint8_t			   receiveOptions;
	QByteArray		   receivedData;

protected:
	void			   setSourceAddress64(QByteArray address);
	void			   setSourceAddress16(QByteArray address);
	void			   setReceiveOptions(uint8_t options);
	void			   setReceivedData(QByteArray data);

public:
	RXIndicator();

	virtual uint8_t	   getFrameType() const { return FrameType::RXIndicator; }
	QByteArray		   getSourceAddress64();
	QByteArray		   getSourceAddress16();
	uint8_t			   getReceiveOptions();
	QByteArray		   getReceivedData();
	virtual QByteArray getFrameData();

	virtual void	   setFrameData(QByteArray data);
	virtual			   ~RXIndicator();
};

#endif // RXINDICATOR_H
