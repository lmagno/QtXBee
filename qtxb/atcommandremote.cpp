#include "atcommandremote.h"
#include "atcommand.h"

ATCommandRemote::ATCommandRemote() {
	setApiID(0x17);
	setFrameID(0);
	setCommandOptions(0x02);
	setDestinationAddress((unsigned char [])0x000000000000FFFF); // Broadcast by default
}

QByteArray ATCommandRemote::getDestinationAdress() {
	return destAddress;
}

unsigned char ATCommandRemote::getCommandOptions() {
	return commandOptions;
}

void ATCommandRemote::setDestinationAddress(QByteArray address) {
	if (address.length() >= 8) destAddress = address.left(8);
}

void ATCommandRemote::setCommandOptions(unsigned char options) {
	commandOptions = options;
}

QByteArray ATCommandRemote::getFrameData() {
	QByteArray frameData;
	frameData = getApiID();
	frameData += getFrameID();
	frameData += getDestinationAdress();
	frameData += (unsigned char[])0xFFFE;
	frameData += getCommandOptions();
	frameData += getATCommand();
	frameData += getParameter();
	return frameData;
}

void ATCommandRemote::setFrameData(QByteArray data) {
	if (data.size() < 15) return;
	setApiID(data[0]);
	setFrameID(data[1]);
	setDestinationAddress(data.mid(2,8));
	setCommandOptions(data[12]);
	setATCommand(data.mid(13,2));
	if (data.size() > 15) setParameter(data.mid(15));
}
