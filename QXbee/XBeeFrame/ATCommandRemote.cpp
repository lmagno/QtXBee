#include "ATCommandRemote.h"

ATCommandRemote::ATCommandRemote() {
	static const quint8 broadcast[] = {0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF};
	setFrameID(0);
	setCommandOptions(0x02);
	setDestinationAddress(QByteArray((char *)broadcast, 8)); // Broadcast by default
}

QByteArray ATCommandRemote::getDestinationAdress() {
	return destinationAddress;
}

quint8 ATCommandRemote::getCommandOptions() {
	return commandOptions;
}

void ATCommandRemote::setDestinationAddress(QByteArray address) {
	if (address.length() >= 8) destinationAddress = address.left(8);
}

void ATCommandRemote::setCommandOptions(quint8 options) {
	commandOptions = options;
}

QByteArray ATCommandRemote::getFrameData() {
	QByteArray frameData;
	static const quint8 reserved[] = {0xFF,0xFE};
	frameData.append(getFrameType());
	frameData += getFrameID();
	frameData += getDestinationAdress();
	frameData.append((char *)reserved, 2);
	frameData += getCommandOptions();
	frameData += getATCommand();
	frameData += getATParameter();
	return frameData;
}

void ATCommandRemote::setFrameData(QByteArray data) {
	if (data.size() < 15 && data.at(0) != getFrameType()) return;
	setFrameID(data[1]);
	setDestinationAddress(data.mid(2,8));
	setCommandOptions(data[12]);
	setATCommand(data.mid(13,2));
	if (data.size() > 15) setATParameter(data.mid(15));
}
