#include "ModemStatus.h"

ModemStatus::ModemStatus() {
}

quint8 ModemStatus::getStatus(){
	return status;
}

QByteArray ModemStatus::getFrameData() {
	QByteArray frameData;
	frameData.append(getFrameType());
	frameData += getStatus();
	return frameData;
}

void ModemStatus::setStatus(quint8 st) {
	status = st;
}

void ModemStatus::setFrameData(QByteArray data) {
	if ((data.size() < 2) && (data.at(0) != getFrameType())) return;
	setStatus(data[1]);
}
