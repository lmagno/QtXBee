#include "TXRequestExplicit.h"

TXRequestExplicit::TXRequestExplicit()
{
}

byte TXRequestExplicit::getSourceEndpoint() {
	return sourceEndpoint;
}

byte TXRequestExplicit::getDestinationEndpoint() {
	return destinationEndpoint;
}

QByteArray TXRequestExplicit::getClusterID() {
	return clusterID;
}

QByteArray TXRequestExplicit::getProfileID() {
	return profileID;
}

QByteArray TXRequestExplicit::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getDestinationAddress();
	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;
	frameData += getSourceEndpoint();
	frameData += getDestinationEndpoint();
	frameData += getClusterID();
	frameData += getProfileID();
	frameData += getBroadcastRadius();
	frameData += getTransmitOptions();
	frameData += getTransmitingData();
	return frameData;
}

void TXRequestExplicit::setSourceEndpoint(byte endpoint) {
	sourceEndpoint = endpoint;
}

void TXRequestExplicit::setDestinationEndpoint(byte endpoint) {
	destinationEndpoint = endpoint;
}

void TXRequestExplicit::setCLusterID(QByteArray id) {
	clusterID = id;
}

void TXRequestExplicit::setProfileID(QByteArray id) {
	profileID = id;
}

void TXRequestExplicit::setFrameData(QByteArray data) {
	if ((data.size() < 15) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setDestinationAddress(data.mid(2,8));
	setBroadcastRadius(data[12]);
	setTransmitOptions(data[13]);
	setTransmitingData(data.mid(14));
}
