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
	void			   setSourceAddress64(QByteArray);
	void			   setSourceAddress16(QByteArray);
	void			   setReceiveOptions(uint8_t);
	void			   setReceivedData(QByteArray);

public:
	RXIndicator();

	virtual uint8_t	   getFrameType() const { return FrameType::RXIndicator; }
	QByteArray		   getSourceAddress64();
	QByteArray		   getSourceAddress16();
	uint8_t			   getReceiveOptions();
	QByteArray		   getReceivedData();
	virtual QByteArray getFrameData();

	virtual void	   setFrameData(QByteArray);
	virtual			   ~RXIndicator();
};

#endif // RXINDICATOR_H
