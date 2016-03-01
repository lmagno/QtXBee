#include "digimeshpacket.h"

DigiMeshPacket::DigiMeshPacket() {
	setApiID(0);
}

void DigiMeshPacket::setApiID(unsigned char id) {
	apiID = id;
}

void DigiMeshPacket::setFrameData(QByteArray data) {
	frameData = data;
}

unsigned char DigiMeshPacket::getApiID() {
	return apiID;
}

QByteArray DigiMeshPacket::getFrameData() {
	return frameData;
}
