#include "atcommandremote.h"
#include "atcommand.h"

ATCommandRemote::ATCommandRemote(QObject *parent) : ATCommand(parent) {
	setApiID(0x17);
	setFrameID(0);
	setCommandOptions(0x02);
	setDestinationAddress(0x000000000000FFFF); // Broadcast by default
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

void ATCommandRemote::update() {
	frameData.clear();
	frameData.append(getApiID());
	frameData.append(getFrameID());
	frameData.append(getDestinationAdress());
	frameData.append(0xFFFE);
	frameData.append(getCommandOptions());
	frameData.append(getATCommand());
	frameData.append(getParameter());
}
