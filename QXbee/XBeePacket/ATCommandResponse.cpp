#include <QString>

#include "ATCommandResponse.h"

ATCommandResponse::ATCommandResponse()
{
}

unsigned char ATCommandResponse::getFrameID() {
	return frameID;
}

QString ATCommandResponse::getATCommand() {
	return atCommand;
}

unsigned char ATCommandResponse::getCommandStatus() {
	return commandStatus;
}

QByteArray ATCommandResponse::getCommandData() {
	return commandData;
}

QByteArray ATCommandResponse::getFrameData() {
	QByteArray frameData;
	frameData.append(getFrameType());
	frameData += getFrameID();
	frameData += getATCommand();
	frameData += getCommandStatus();
	frameData += getCommandData();
	return frameData;
}

void ATCommandResponse::setFrameID(unsigned char id) {
	frameID = id;
}
void ATCommandResponse::setATCommand(QString command) {
	atCommand = command.toLocal8Bit();
}
void ATCommandResponse::setCommandStatus(unsigned char status) {
	commandStatus = status;
}
void ATCommandResponse::setCommandData(QByteArray data) {
	commandData = data;
}

void ATCommandResponse::setFrameData(QByteArray data) {
	if (data.size() < 8 && data.at(0) != getFrameType()) return;
	setFrameID(data[1]);
	setATCommand(data.mid(2,2));
	setCommandStatus(data[4]);
	if (data.size() > 8) setCommandData(data.mid(5));
}
