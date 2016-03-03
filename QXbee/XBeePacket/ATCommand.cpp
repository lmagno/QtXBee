#include "ATCommand.h"

ATCommand::ATCommand()
{
	setFrameID(0);
}

unsigned char ATCommand::getFrameID() {
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
	frameData.append(getApiID());
	frameData += getFrameID();
	frameData += getATCommand();
	frameData += getATParameter();
	return frameData;
}

void ATCommand::setATCommand(QString command){
	atCommand.append(command);
}

void ATCommand::setATParameter(QByteArray parameter){
	atParameter = parameter;
}

void ATCommand::setFrameID(unsigned char id) {
	frameID = id;
}

void ATCommand::setFrameData(QByteArray data) {
	if ((data.size() < 4) && (data.at(0) != getApiID())) return;
	setFrameID(data[1]);
	setATCommand(data.mid(2,2));
	if (data.size() > 4) setATParameter(data.mid(4));
}

