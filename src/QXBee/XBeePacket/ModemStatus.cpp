#include "ModemStatus.h"

ModemStatus::ModemStatus() {
}

uint8_t ModemStatus::getStatus(){
	return statusValue;
}

QByteArray ModemStatus::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getStatus();
	return frameData;
}

void ModemStatus::setStatus(uint8_t status) {
	statusValue = status;
}

void ModemStatus::setFrameData(QByteArray data) {
	if ((data.size() < 2) && (data.at(0) != getFrameType())) return;
	setStatus(data[1]);
}

ModemStatus::~ModemStatus() {
}
