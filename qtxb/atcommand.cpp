#include "atcommand.h"
#include "digimeshpacket.h"

ATCommand::ATCommand()
{
	setApiID(0x08);
	setFrameID(0);
}
void ATCommand::setATCommand(QString command){
	atCommand = command;
}
void ATCommand::setParameter(QByteArray array){
	parameter = array;
}
QByteArray ATCommand::getATCommand(){
    return atCommand;
}
QByteArray ATCommand::getParameter(){
    return parameter;
}
QByteArray ATCommand::getFrameData() {
	QByteArray frameData;
	frameData = getApiID();
	frameData += getFrameID();
	frameData += getATCommand();
	frameData += getParameter();
	return frameData;
}

void ATCommand::setFrameData(QByteArray data) {
	if (data.size() < 4) return;
	setApiID(data[0]);
	setFrameID(data[1]);
	setATCommand(data.mid(2,2));
	if (data.size() > 4) setParameter(data.mid(4));
}

