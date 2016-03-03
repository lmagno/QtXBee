#include "atcommandremote.h"
#include "../QXbee.h"

ATCommandRemote::ATCommandRemote() {
	//unsigned char broadcast[] = {0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF};
	setFrameID(0);
	setCommandOptions(0x02);
	setDestinationAddress(QByteArray((char *)((const unsigned char[]){0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF}), 8)); // Broadcast by default
}

unsigned char ATCommandRemote::getApiID() const {
	return QXbee::pATCommandRemote;
}

QByteArray ATCommandRemote::getDestinationAdress() {
	return destinationAddress;
}

unsigned char ATCommandRemote::getCommandOptions() {
	return commandOptions;
}

void ATCommandRemote::setDestinationAddress(QByteArray address) {
	if (address.length() >= 8) destinationAddress = address.left(8);
}

void ATCommandRemote::setCommandOptions(unsigned char options) {
	commandOptions = options;
}

QByteArray ATCommandRemote::getFrameData() {
	QByteArray frameData;
	frameData.append(getApiID());
	frameData += getFrameID();
	frameData += getDestinationAdress();
	frameData.append((char *)((unsigned char[]){0xFF,0xFE}), 2);
	frameData += getCommandOptions();
	frameData += getATCommand();
	frameData += getATParameter();
	return frameData;
}

void ATCommandRemote::setFrameData(QByteArray data) {
	if (data.size() < 15 && data.at(0) != getApiID()) return;
	setFrameID(data[1]);
	setDestinationAddress(data.mid(2,8));
	setCommandOptions(data[12]);
	setATCommand(data.mid(13,2));
	if (data.size() > 15) setATParameter(data.mid(15));
}
