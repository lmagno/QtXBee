#include "TransmitStatus.h"

TransmitStatus::TransmitStatus()
{
}

byte TransmitStatus::getFrameID(){
	return frameID;
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

	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;

	frameData += getTransmitRetryCount();
	frameData += getDeliveryStatus();
	frameData += getDiscoveryStatus();

	return frameData;
}

void TransmitStatus::setFrameID(byte fi){
	frameID = fi;
}

void TransmitStatus::setTransmitRetryCount(byte trc){
	transmitRetryCount = trc;
}

void TransmitStatus::setDeliveryStatus(byte ds){
	deliveryStatus = ds;
}

void TransmitStatus::setDiscoveryStatus(byte ds){
	discoveryStatus = ds;
}

void TransmitStatus::setFrameData(QByteArray data){
	if (data.size() != 7 && data.at(0) != getFrameType()) return;

	setFrameID(data[1]);
	setTransmitRetryCount(data[4]);
	setDeliveryStatus(data[8]);
	setDiscoveryStatus(data[9]);
}
