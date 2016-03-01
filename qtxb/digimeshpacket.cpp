#include "digimeshpacket.h"

DigiMeshPacket::DigiMeshPacket(QObject *parent) : QObject(parent) {
	setApiID(0);
}

void DigiMeshPacket::setApiID(unsigned char id) {
	apiID = id;
}

void DigiMeshPacket::setFrameData(QByteArray data) {
	frameData = data;
	this->update();
}

unsigned char DigiMeshPacket::getApiID() {
	return apiID;
}

QByteArray DigiMeshPacket::getFrameData() {
	this->update();
	return frameData;
}
