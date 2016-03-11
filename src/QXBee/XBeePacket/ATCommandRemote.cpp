#include "ATCommandRemote.h"

ATCommandRemote::ATCommandRemote() {
	static const uint8_t broadcast[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF };
	static const uint8_t unknown[] = { 0xFF, 0xFE };
	setFrameID(0x01);
	setCommandOptions(0x02);
	setDestinationAddress64(QByteArray((char *)broadcast, 8)); // Broadcast by default
	setDestinationAddress16(QByteArray((char *)unknown, 2));
}

QByteArray ATCommandRemote::getDestinationAdress64() {
	return destinationAddress64;
}

QByteArray ATCommandRemote::getDestinationAdress16() {
	return destinationAddress16;
}

uint8_t ATCommandRemote::getCommandOptions() {
	return commandOptions;
}

QByteArray ATCommandRemote::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getDestinationAdress64();
	frameData += getDestinationAdress16();
	frameData += getCommandOptions();
	frameData += getATCommand();
	frameData += getATParameter();
	return frameData;
}

void ATCommandRemote::setDestinationAddress64(QByteArray address) {
	if (address.length() >= 8) destinationAddress64 = address.left(8);
}

void ATCommandRemote::setDestinationAddress16(QByteArray address) {
	if (address.length() >= 2) destinationAddress16 = address.left(2);
}

void ATCommandRemote::setCommandOptions(uint8_t options) {
	commandOptions = options;
}

void ATCommandRemote::setFrameData(QByteArray data) {
	if ((data.size() < 15) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setDestinationAddress64(data.mid(2, 8));
	setDestinationAddress16(data.mid(10, 2));
	setCommandOptions(data[12]);
	setATCommand(data.mid(13,2));
	if (data.size() > 15) setATParameter(data.mid(15));
}
