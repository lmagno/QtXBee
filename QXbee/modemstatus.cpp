#include "modemstatus.h"
#include "xbeepacket.h"
#include <QDebug>

ModemStatus::ModemStatus() {
}

unsigned char ModemStatus::getStatus(){
	return status;
}

QByteArray ModemStatus::getFrameData() {
	QByteArray frameData;
	frameData.append(getApiID());
	frameData += getStatus();
	return frameData;
}

void ModemStatus::setStatus(unsigned char st) {
	status = st;
}

void ModemStatus::setFrameData(QByteArray data) {
	if ((data.size() < 2) && (data.at(0) != (char)0x8A)) return;
	setStatus(data[1]);
}
