#include "NodeIdentificationIndicator.h"

NodeIdentificationIndicator::NodeIdentificationIndicator() {
}

QByteArray NodeIdentificationIndicator::getSourceAddress() {
	return sourceAddress;
}

quint8 NodeIdentificationIndicator::getReceiveOptions() {
	return receiveOptions;
}

QByteArray NodeIdentificationIndicator::getRemoteAddress() {
	return remoteAddress;
}

QString NodeIdentificationIndicator::getNIString() {
	return niString;
}

quint8 NodeIdentificationIndicator::getDeviceType() {
	return deviceType;
}

quint8 NodeIdentificationIndicator::getSourceEvent() {
	return sourceEvent;
}

QByteArray NodeIdentificationIndicator::getProfileID() {
	return profileID;
}

QByteArray NodeIdentificationIndicator::getManufacturerID() {
	return manufaccturerID;
}

QByteArray NodeIdentificationIndicator::getDDValue() {
	return ddValue;
}

quint8 NodeIdentificationIndicator::getRSSI() {
	return rssiValue;
}

QByteArray NodeIdentificationIndicator::getFrameData() {
	QByteArray frameData;
	return frameData;
}

void NodeIdentificationIndicator::setSourceAddress(QByteArray address) {
	sourceAddress = address;
}

void NodeIdentificationIndicator::setReceiveOptions(quint8 options) {
	receiveOptions = options;
}

void NodeIdentificationIndicator::setRemoteAddress(QByteArray address) {
	remoteAddress = address;
}

void NodeIdentificationIndicator::setNIString(QString ni) {
	niString = ni;
}

void NodeIdentificationIndicator::setDeviceType(quint8 type) {
	deviceType = type;
}

void NodeIdentificationIndicator::setSourceEvent(quint8 event) {
	sourceEvent = event;
}

void NodeIdentificationIndicator::setProfileID(QByteArray id) {
	profileID = id;
}

void NodeIdentificationIndicator::setManufacturerID(QByteArray id) {
	manufaccturerID = id;
}

void NodeIdentificationIndicator::setDDValue(QByteArray dd) {
	ddValue = dd;
}

void NodeIdentificationIndicator::setRSSI(quint8 rssi) {
	rssiValue = rssi;
}

void NodeIdentificationIndicator::setFrameData(QByteArray) {
	/*
	int index = 0;
	if (!frameData.isEmpty()) {
		setApiID(frameData[0]);
		setSourceAddress(frameData.mid(1,8));
		setReceiveOptions(frameData[11]);
		setRemoteAddress(frameData.mid(14,8));
		index = frameData.indexOf((char)0x00, 22);
		setNIString(frameData.mid(22,index-21));
		index++;
	}
	*/
}
