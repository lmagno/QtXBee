#include "atcommandresponse.h"
#include "atcommand.h"
#include <QDebug>

ATCommandResponse::ATCommandResponse(QObject *parent) :
    DigiMeshPacket(parent)
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

void ATCommandResponse::setFrameID(unsigned char id) {
	frameID = id;
}
void ATCommandResponse::setATCommand(QString command) {
	atCommand = command;
}
void ATCommandResponse::setCommandStatus(unsigned char status) {
	commandStatus = status;
}
void ATCommandResponse::setCommandData(QByteArray data) {
	commandData = data;
}

void ATCommandResponse::update() {
	if (!frameData.isEmpty()) {
		setApiID(frameData[0]);
		setFrameID(frameData[1]);
		setATCommand(frameData.mid(2, 2));
		setCommandStatus(frameData[4]);
		setCommandData(frameData.mid(5));
	}
}
