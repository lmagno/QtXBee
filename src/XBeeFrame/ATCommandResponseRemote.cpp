#include "ATCommandResponseRemote.h"

ATCommandResponseRemote::ATCommandResponseRemote()
{
}

QByteArray ATCommandResponseRemote::getSourceAddress64() {
	return sourceAddress64;
}

QByteArray ATCommandResponseRemote::getSourceAddress16() {
	return sourceAddress16;
}

QByteArray ATCommandResponseRemote::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getSourceAddress64();
	frameData += getSourceAddress16();
	frameData += getATCommand();
	frameData += getCommandStatus();
	frameData += getCommandData();
	return frameData;
}

void ATCommandResponseRemote::setSourceAddress64(QByteArray address) {
	sourceAddress64 = address;
}

void ATCommandResponseRemote::setSourceAddress16(QByteArray address) {
	sourceAddress16 = address;
}

void ATCommandResponseRemote::setFrameData(QByteArray data) {
	if ((data.size() < 15) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setSourceAddress64(data.mid(2,8));
	setSourceAddress16(data.mid(10,2));
	setATCommand(data.mid(12,2));
	setCommandStatus(data[14]);
	if (data.size() > 15) setCommandData(data.mid(15));
}
