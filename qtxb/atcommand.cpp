#include "atcommand.h"
#include "digimeshpacket.h"

ATCommand::ATCommand(QObject *parent) :
    DigiMeshPacket(parent)
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
void ATCommand::update(){
	frameData.clear();
	frameData.append(getApiID());
	frameData.append(getFrameID());
	frameData.append(getATCommand());
	frameData.append(getParameter());
}

