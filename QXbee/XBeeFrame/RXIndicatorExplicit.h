#ifndef RXINDICATOREXPLICIT_H
#define RXINDICATOREXPLICIT_H

#include <QByteArray>

#include "typedef.h"
#include "XBeeFrame.h"

class RXIndicatorExplicit : public XBeeFrame
{
public:
	RXIndicatorExplicit();
	virtual byte getFrameType() const { return pRXIndicatorExplicit; }
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // RXINDICATOREXPLICIT_H
