#ifndef RXINDICATOREXPLICIT_H
#define RXINDICATOREXPLICIT_H

#include <QByteArray>

#include "XBeeFrame.h"

class RXIndicatorExplicit : public XBeeFrame
{
public:
	RXIndicatorExplicit();
	virtual quint8 getFrameType() const { return pRXIndicatorExplicit; }
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // RXINDICATOREXPLICIT_H
