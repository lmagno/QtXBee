#include "rxindicatorexplicit.h"
#include "../QXbee.h"

#include <QDebug>

RXIndicatorExplicit::RXIndicatorExplicit() {
}

unsigned char RXIndicatorExplicit::getApiID() const {
	return QXbee::pRXIndicatorExplicit;
}

void RXIndicatorExplicit::setFrameData(QByteArray data) {
	qDebug() << data.toHex();
}

QByteArray RXIndicatorExplicit::getFrameData() {
	QByteArray frameData;
	return frameData;
}
