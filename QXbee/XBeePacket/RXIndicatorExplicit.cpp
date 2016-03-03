#include <QDebug>

#include "RXIndicatorExplicit.h"

RXIndicatorExplicit::RXIndicatorExplicit() {
}

void RXIndicatorExplicit::setFrameData(QByteArray data) {
	qDebug() << data.toHex();
}

QByteArray RXIndicatorExplicit::getFrameData() {
	QByteArray frameData;
	return frameData;
}
