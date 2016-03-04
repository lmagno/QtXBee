#ifndef RXINDICATOR_H
#define RXINDICATOR_H

#include <QByteArray>

#include "typedef.h"
#include "XBeeFrame.h"

class RXIndicator : public XBeeFrame
{
	QByteArray sourceAddress;
	byte       receiveOptions;
	QByteArray receivedData;
protected:
	void setSourceAddress(QByteArray);
	void setReceiveOptions(byte);
	void setReceivedData(QByteArray);
public:
	RXIndicator();
	virtual byte getFrameType() const { return pRXIndicator; }
	QByteArray   getSourceAddress();
	byte         getReceiveOptions();
	QByteArray   getReceivedData();

	virtual QByteArray getFrameData();
	virtual void 	   setFrameData(QByteArray);
};

#endif // RXINDICATOR_H
