#include "TransmitStatus.h"

TransmitStatus::TransmitStatus()
{
}

uint8_t TransmitStatus::getFrameID(){
	return frameID;
}

QByteArray TransmitStatus::getDestinationAddress16() {
	return destinationAddress16;
}

uint8_t TransmitStatus::getTransmitRetryCount(){
	return transmitRetryCount;
}

uint8_t TransmitStatus::getDeliveryStatus(){
	return deliveryStatus;
}

uint8_t TransmitStatus::getDiscoveryStatus(){
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

void TransmitStatus::setFrameID(uint8_t id){
	frameID = id;
}

void TransmitStatus::setDestinationAddress16(QByteArray address) {
	destinationAddress16 = address;
}

void TransmitStatus::setTransmitRetryCount(uint8_t count){
	transmitRetryCount = count;
}

void TransmitStatus::setDeliveryStatus(uint8_t status){
	deliveryStatus = status;
}

void TransmitStatus::setDiscoveryStatus(uint8_t status){
	discoveryStatus = status;
}

void TransmitStatus::setFrameData(QByteArray data){
	if ((data.size() < 7) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setDestinationAddress16(data.mid(2,2));
	setTransmitRetryCount(data[4]);
	setDeliveryStatus(data[5]);
	setDiscoveryStatus(data[6]);
}

TransmitStatus::~TransmitStatus() {
}
