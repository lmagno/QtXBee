#include "NodeIdentificationIndicator.h"

NodeIdentificationIndicator::NodeIdentificationIndicator() {
}

QByteArray NodeIdentificationIndicator::getSourceAddress() {
	return sourceAddress;
}

byte NodeIdentificationIndicator::getReceiveOptions() {
	return receiveOptions;
}

QByteArray NodeIdentificationIndicator::getRemoteAddress() {
	return remoteAddress;
}

QString NodeIdentificationIndicator::getNIString() {
	return niString;
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

QByteArray NodeIdentificationIndicator::getDDValue() {
	return ddValue;
}

byte NodeIdentificationIndicator::getRSSI() {
	return rssiValue;
}

QByteArray NodeIdentificationIndicator::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getSourceAddress();
	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;
	frameData += getReceiveOptions();
	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;
	frameData += getRemoteAddress();
	frameData += getNIString();
	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;
	frameData += getDeviceType();
	frameData += getSourceEvent();
	frameData += getProfileID();
	frameData += getManufacturerID();
	frameData += getDDValue();
	frameData += getRSSI();
	return frameData;
}

void NodeIdentificationIndicator::setSourceAddress(QByteArray address) {
	sourceAddress = address;
}

void NodeIdentificationIndicator::setReceiveOptions(byte options) {
	receiveOptions = options;
}

void NodeIdentificationIndicator::setRemoteAddress(QByteArray address) {
	remoteAddress = address;
}

void NodeIdentificationIndicator::setNIString(QString ni) {
	niString = ni;
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

void NodeIdentificationIndicator::setDDValue(QByteArray dd) {
	ddValue = dd;
}

void NodeIdentificationIndicator::setRSSI(byte rssi) {
	rssiValue = rssi;
}

void NodeIdentificationIndicator::setFrameData(QByteArray data) {
	int idx = 0;
	if (data.size() < 32 && data.at(0) != getFrameType()) return;
	setSourceAddress(data.mid(1,8));
	setReceiveOptions(data[11]);
	setRemoteAddress(data.mid(14,8));
	idx = data.indexOf((char)0x00, 22);
	setNIString(data.mid(22,idx-22));
	idx += 3;
	setDeviceType(data[idx]);
	setSourceEvent(data[idx+1]);
	setProfileID(data.mid(idx+2,2));
	setManufacturerID(data.mid(idx+4,2));
	if (data.size() > idx+6) {
		if (data.size() == idx+7) {
			setDDValue(data.mid(idx+6,4));
			setRSSI(data[idx+10]);
		}
		else if (data.size() == idx+5)
			setDDValue(data.mid(idx+6,4));
		else
			setRSSI(data[idx+6]);
	}
}
