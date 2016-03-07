#include <QDebug>

#include "RXIndicatorExplicit.h"

RXIndicatorExplicit::RXIndicatorExplicit() {
}

void RXIndicatorExplicit::setSourceEndpoint(byte endpoint) {
	sourceEndpoint = endpoint;
}

void RXIndicatorExplicit::setDestinationEndpoint(byte endpoint) {
	destinationEndpoint = endpoint;
}

void RXIndicatorExplicit::setClusterID(QByteArray id) {
	clusterID = id;
}

void RXIndicatorExplicit::setProfileID(QByteArray id) {
	profileID = id;
}

void RXIndicatorExplicit::setFrameData(QByteArray data) {
	if ((data.size() < 18) && (data.at(0) != getFrameType())) return;
	setSourceAddress(data.mid(1,8));
	setSourceEndpoint(data[11]);
	setDestinationEndpoint(data[12]);
	setClusterID(data.mid(13,2));
	setProfileID(data.mid(15,2));
	setReceiveOptions(data[17]);
	if (data.size() > 18) setReceivedData(data.mid(18));
}

byte RXIndicatorExplicit::getSourceEndpoint() {
	return sourceEndpoint;
}

byte RXIndicatorExplicit::getDestinationEndpoint() {
	return destinationEndpoint;
}

QByteArray RXIndicatorExplicit::getClusterID() {
	return clusterID;
}

QByteArray RXIndicatorExplicit::getProfileID() {
	return profileID;
}

QByteArray RXIndicatorExplicit::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getSourceAddress();
	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;
	frameData += getSourceEndpoint();
	frameData += getDestinationEndpoint();
	frameData += getClusterID();
	frameData += getProfileID();
	frameData += getReceiveOptions();
	frameData += getReceivedData();
	return frameData;
}
