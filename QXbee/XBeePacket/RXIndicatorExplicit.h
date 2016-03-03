#ifndef RXINDICATOREXPLICIT_H
#define RXINDICATOREXPLICIT_H

#include "XBeePacket.h"
#include <QByteArray>


class RXIndicatorExplicit : public XBeePacket
{
public:
	RXIndicatorExplicit();
	virtual unsigned char getApiID() const { return pRXIndicatorExplicit; }
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // RXINDICATOREXPLICIT_H
