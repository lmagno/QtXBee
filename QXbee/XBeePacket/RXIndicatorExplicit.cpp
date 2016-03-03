#include "RXIndicatorExplicit.h"

#include <QDebug>

RXIndicatorExplicit::RXIndicatorExplicit() {
}

unsigned char RXIndicatorExplicit::getApiID() const {
	return pRXIndicatorExplicit;
}

void RXIndicatorExplicit::setFrameData(QByteArray data) {
	qDebug() << data.toHex();
}

QByteArray RXIndicatorExplicit::getFrameData() {
	QByteArray frameData;
	return frameData;
}
