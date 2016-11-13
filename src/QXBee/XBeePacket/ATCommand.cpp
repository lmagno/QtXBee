#include "ATCommand.h"

ATCommand::ATCommand()
{
	setFrameID(0x01);
}

uint8_t ATCommand::getFrameID() {
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
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getATCommand();
	frameData += getATParameter();
	return frameData;
}

void ATCommand::setATCommand(QString command){
	atCommand = command.toLocal8Bit();
}

void ATCommand::setATParameter(QByteArray parameter){
	atParameter = parameter;
}

void ATCommand::setFrameID(uint8_t id) {
	frameID = id;
}

void ATCommand::setFrameData(QByteArray data) {
	if ((data.size() < 4) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setATCommand(data.mid(2,2));
	if (data.size() > 4) setATParameter(data.mid(4));
}

ATCommand::~ATCommand() {
}

