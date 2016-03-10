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
	frameData += getDestinationAddress64();
	frameData += getDestinationAddress16();
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
	if ((data.size() < 20) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setDestinationAddress64(data.mid(2,8));
	setDestinationAddress16(data.mid(10,2));
	setSourceEndpoint(data[12]);
	setDestinationEndpoint(data[13]);
	setCLusterID(data.mid(14,2));
	setProfileID(data.mid(16,2));
	setBroadcastRadius(data[18]);
	setTransmitOptions(data[19]);
	if (data.size() > 20) setTransmitingData(data.mid(20));
}
