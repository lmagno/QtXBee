#include "ModemStatus.h"

ModemStatus::ModemStatus() {
}

uint8_t ModemStatus::getStatus(){
	return status;
}

QByteArray ModemStatus::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getStatus();
	return frameData;
}

void ModemStatus::setStatus(uint8_t st) {
	status = st;
}

void ModemStatus::setFrameData(QByteArray data) {
	if ((data.size() < 2) && (data.at(0) != getFrameType())) return;
	setStatus(data[1]);
}

ModemStatus::~ModemStatus() {
}
