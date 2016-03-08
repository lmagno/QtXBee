#include "ATCommandResponseRemote.h"

ATCommandResponseRemote::ATCommandResponseRemote()
{
}

QByteArray ATCommandResponseRemote::getSourceAddress() {
	return remoteAddress;
}

QByteArray ATCommandResponseRemote::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getSourceAddress();

	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;

	frameData += getATCommand();
	frameData += getCommandStatus();
	frameData += getCommandData();
	return frameData;
}

void ATCommandResponseRemote::setSourceAddress(QByteArray address) {
	remoteAddress = address;
}

void ATCommandResponseRemote::setFrameData(QByteArray data) {
	if (data.size() < 15 && data.at(0) != getFrameType()) return;
	setFrameID(data[1]);
	setSourceAddress(data.mid(2,8));
	setATCommand(data.mid(12,2));
	setCommandStatus(data[14]);
	if (data.size() > 15) setCommandData(data.mid(15));
}
