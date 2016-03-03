#include <QDebug>

#include "ATCommand.h"

ATCommand::ATCommand()
{
	setFrameID(0);
}

byte ATCommand::getFrameID() {
	return frameID;
}

QByteArray ATCommand::getATCommand(){
    return atCommand;
}

QByteArray ATCommand::getATParameter(){
	return atParameter;
}

QByteArray ATCommand::getFrameData() {
	QByteArray frameData;
	frameData.append(getFrameType());
	frameData += getFrameID();
	frameData += getATCommand();
	frameData += getATParameter();
	return frameData;
}

void ATCommand::setATCommand(QString command){
	if (command.size() >= 2) atCommand.append(command.left(2));
}

void ATCommand::setATParameter(QByteArray parameter){
	atParameter = parameter;
}

void ATCommand::setFrameID(byte id) {
	frameID = id;
}

void ATCommand::setFrameData(QByteArray data) {
	if ((data.size() < 4) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setATCommand(data.mid(2,2));
	if (data.size() > 4) setATParameter(data.mid(4));
}

