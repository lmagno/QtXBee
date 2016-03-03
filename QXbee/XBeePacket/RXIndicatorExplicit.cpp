#include "RXIndicatorExplicit.h"

#include <QDebug>

RXIndicatorExplicit::RXIndicatorExplicit() {
}

void RXIndicatorExplicit::setFrameData(QByteArray data) {
	qDebug() << data.toHex();
}

QByteArray RXIndicatorExplicit::getFrameData() {
	QByteArray frameData;
	return frameData;
}
