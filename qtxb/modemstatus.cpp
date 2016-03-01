#include "modemstatus.h"
#include "digimeshpacket.h"
#include <QDebug>

ModemStatus::ModemStatus(QObject *parent) : DigiMeshPacket(parent) {
}

unsigned char ModemStatus::getStatus(){
    return status;
}

void ModemStatus::setStatus(unsigned char st) {
	status = st;
}

void ModemStatus::update() {
	if (frameData.size() > 1) {
		setApiID(frameData[0]);
		setStatus(frameData[1]);
	}
}
