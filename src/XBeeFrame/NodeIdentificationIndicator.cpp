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

byte NodeIdentificationIndicator::getRSSI() {
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

void NodeIdentificationIndicator::setRSSI(byte rssi) {
	rssiValue = rssi;
}

void NodeIdentificationIndicator::setFrameData(QByteArray data) {
	int idx = 0;
	if ((data.size() < 32) && (data.at(0) != getFrameType())) return;
	setSourceAddress64(data.mid(1,8));
	setSourceAddress16(data.mid(9,2));
	setReceiveOptions(data[11]);
	setRemoteAddress16(data.mid(12,2));
	setRemoteAddress64(data.mid(14,8));
	idx = data.indexOf((char)0x00, 22);
	setNIString(data.mid(22,idx-22));
	idx++;
	setParentAddress16(data.mid(idx, 2));
	setDeviceType(data[idx+2]);
	setSourceEvent(data[idx+3]);
	setProfileID(data.mid(idx+4,2));
	setManufacturerID(data.mid(idx+6,2));
	if (data.size() > idx+8) {
		if (data.size() == idx+9) {
			setDeviceTypeID(data.mid(idx+8,4));
			setRSSI(data[idx+12]);
		}
		else if (data.size() == idx+7)
			setDeviceTypeID(data.mid(idx+8,4));
		else
			setRSSI(data[idx+8]);
	}
}
