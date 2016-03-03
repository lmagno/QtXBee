#ifndef RXINDICATOREXPLICIT_H
#define RXINDICATOREXPLICIT_H

#include <QByteArray>

#include "XBeePacket.h"

class RXIndicatorExplicit : public XBeePacket
{
public:
	RXIndicatorExplicit();
	virtual unsigned char getFrameType() const { return pRXIndicatorExplicit; }
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // RXINDICATOREXPLICIT_H
