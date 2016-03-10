#include "NodeIdentificationIndicator.h"

NodeIdentificationIndicator::NodeIdentificationIndicator() {
}

QByteArray NodeIdentificationIndicator::getSourceAddress64() {
	return sourceAddress64;
}

QByteArray NodeIdentificationIndicator::getSourceAddress16() {
	return sourceAddress16;
}

byte NodeIdentificationIndicator::getReceiveOptions() {
	return receiveOptions;
}

QByteArray NodeIdentificationIndicator::getRemoteAddress64() {
	return remoteAddress64;
}

QByteArray NodeIdentificationIndicator::getRemoteAddress16() {
	return remoteAddress16;
}

QString NodeIdentificationIndicator::getNIString() {
	return niString;
}

QByteArray NodeIdentificationIndicator::getParentAddress16() {
	return parentAddress16;
}

byte NodeIdentificationIndicator::getDeviceType() {
	return deviceType;
}

byte NodeIdentificationIndicator::getSourceEvent() {
	return sourceEvent;
}

QByteArray NodeIdentificationIndicator::getProfileID() {
	return profileID;
}

QByteArray NodeIdentificationIndicator::getManufacturerID() {
	return manufaccturerID;
}

QByteArray NodeIdentificationIndicator::getDeviceTypeID() {
	return deviceTypeID;
}

QByteArray NodeIdentificationIndicator::getRSSI() {
	return rssiValue;
}

QByteArray NodeIdentificationIndicator::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getSourceAddress64();
	frameData += getSourceAddress16();
	frameData += getReceiveOptions();
	frameData += getRemoteAddress16();
	frameData += getRemoteAddress64();
	frameData += getNIString();
	frameData += (char)0x00;
	frameData += getParentAddress16();
	frameData += getDeviceType();
	frameData += getSourceEvent();
	frameData += getProfileID();
	frameData += getManufacturerID();
	frameData += getDeviceTypeID();
	frameData += getRSSI();
	return frameData;
}

void NodeIdentificationIndicator::setSourceAddress64(QByteArray address) {
	sourceAddress64 = address;
}

void NodeIdentificationIndicator::setSourceAddress16(QByteArray address) {
	sourceAddress16 = address;
}

void NodeIdentificationIndicator::setReceiveOptions(byte options) {
	receiveOptions = options;
}

void NodeIdentificationIndicator::setRemoteAddress64(QByteArray address) {
	remoteAddress64 = address;
}

void NodeIdentificationIndicator::setRemoteAddress16(QByteArray address) {
	remoteAddress16 = address;
}

void NodeIdentificationIndicator::setNIString(QString ni) {
	niString = ni;
}

void NodeIdentificationIndicator::setParentAddress16(QByteArray address) {
	parentAddress16 = address;
}

void NodeIdentificationIndicator::setDeviceType(byte type) {
	deviceType = type;
}

void NodeIdentificationIndicator::setSourceEvent(byte event) {
	sourceEvent = event;
}

void NodeIdentificationIndicator::setProfileID(QByteArray id) {
	profileID = id;
}

void NodeIdentificationIndicator::setManufacturerID(QByteArray id) {
	manufaccturerID = id;
}

void NodeIdentificationIndicator::setDeviceTypeID(QByteArray id) {
	deviceTypeID = id;
}

void NodeIdentificationIndicator::setRSSI(QByteArray rssi) {
	rssiValue = rssi;
}

void NodeIdentificationIndicator::setFrameData(QByteArray data) {
	int idx = 0, dataSize = data.size();
	if ((dataSize < 32) && (data.at(0) != getFrameType())) return;
	setSourceAddress64(data.mid(1,8));
	setSourceAddress16(data.mid(9,2));
	setReceiveOptions(data[11]);
	setRemoteAddress16(data.mid(12,2));
	setRemoteAddress64(data.mid(14,8));
	idx = data.indexOf((char)0x00, 22);
	setNIString(data.mid(22,idx-22));
	setParentAddress16(data.mid(idx+1, 2));
	setDeviceType(data[idx+3]);
	setSourceEvent(data[idx+4]);
	setProfileID(data.mid(idx+5,2));
	setManufacturerID(data.mid(idx+7,2));
	if (dataSize > idx+9) {
		if (dataSize == idx+14) {
			setDeviceTypeID(data.mid(idx+9,4));
			setRSSI(QByteArray(1,data[idx+13]));
		}
		else if (dataSize == idx+13)
			setDeviceTypeID(data.mid(idx+9,4));
		else
			setRSSI(QByteArray(1, data[idx+9]));
	}
}
