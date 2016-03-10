#ifndef RXINDICATOR_H
#define RXINDICATOR_H

#include <QByteArray>

#include "typedef.h"
#include "XBeeFrame.h"

class RXIndicator : public XBeeFrame
{
	QByteArray		   sourceAddress64;
	QByteArray		   sourceAddress16;
	byte			   receiveOptions;
	QByteArray		   receivedData;

protected:
	void			   setSourceAddress64(QByteArray);
	void			   setSourceAddress16(QByteArray);
	void			   setReceiveOptions(byte);
	void			   setReceivedData(QByteArray);

public:
	RXIndicator();

	virtual byte	   getFrameType() const { return pRXIndicator; }
	QByteArray		   getSourceAddress64();
	QByteArray		   getSourceAddress16();
	byte			   getReceiveOptions();
	QByteArray		   getReceivedData();
	virtual QByteArray getFrameData();

	virtual void	   setFrameData(QByteArray);
};

#endif // RXINDICATOR_H
