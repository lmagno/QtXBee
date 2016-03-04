#include "ATCommandResponseRemote.h"

ATCommandResponseRemote::ATCommandResponseRemote()
{
}

void ATCommandResponseRemote::setRemoteAddress(QByteArray address) {
	remoteAddress = address;
}

void ATCommandResponseRemote::setFrameData(QByteArray data) {
	if (data.size() < 15 && data.at(0) != getFrameType()) return;
	setFrameID(data[1]);
	setRemoteAddress(data.mid(2,8));
	setATCommand(data.mid(12,2));
	setCommandStatus(data[14]);
	if (data.size() > 15) setCommandData(data.mid(15));
}

QByteArray ATCommandResponseRemote::getRemoteAddress() {
	return remoteAddress;
}

QByteArray ATCommandResponseRemote::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getRemoteAddress();

	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;

	frameData += getATCommand();
	frameData += getCommandStatus();
	frameData += getCommandData();
	return frameData;
}
