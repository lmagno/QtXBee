#include "TransmitStatus.h"

TransmitStatus::TransmitStatus()
{
}

byte TransmitStatus::getFrameID(){
	return frameID;
}

QByteArray TransmitStatus::getDestinationAddress16() {
	return destinationAddress16;
}

byte TransmitStatus::getTransmitRetryCount(){
	return transmitRetryCount;
}

byte TransmitStatus::getDeliveryStatus(){
	return deliveryStatus;
}

byte TransmitStatus::getDiscoveryStatus(){
	return discoveryStatus;
}

QByteArray TransmitStatus::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getDestinationAddress16();
	frameData += getTransmitRetryCount();
	frameData += getDeliveryStatus();
	frameData += getDiscoveryStatus();
	return frameData;
}

void TransmitStatus::setFrameID(byte id){
	frameID = id;
}

void TransmitStatus::setDestinationAddress16(QByteArray address) {
	destinationAddress16 = address;
}

void TransmitStatus::setTransmitRetryCount(byte count){
	transmitRetryCount = count;
}

void TransmitStatus::setDeliveryStatus(byte status){
	deliveryStatus = status;
}

void TransmitStatus::setDiscoveryStatus(byte status){
	discoveryStatus = status;
}

void TransmitStatus::setFrameData(QByteArray data){
	if (data.size() != 7 && data.at(0) != getFrameType()) return;
	setFrameID(data[1]);
	setDestinationAddress16(data.mid(2,2));
	setTransmitRetryCount(data[4]);
	setDeliveryStatus(data[8]);
	setDiscoveryStatus(data[9]);
}
