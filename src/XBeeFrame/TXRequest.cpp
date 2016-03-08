#include "TXRequest.h"

TXRequest::TXRequest()
{
	static const byte broadcast[] = {0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF};
	setFrameID(0x01);
	setDestinationAddress(QByteArray((char *)broadcast, 8)); // Broadcast by default
	setBroadcastRadius(1);
	setTransmitOptions(0x00);
}

byte TXRequest::getFrameID() {
	return frameID;
}

QByteArray TXRequest::getDestinationAddress(){
	return destinationAddress;
}

byte TXRequest::getBroadcastRadius(){
	return broadcastRadius;
}

byte TXRequest::getTransmitOptions(){
	return transmitOptions;
}

QByteArray TXRequest::getTransmitingData(){
	return rfData;
}

QByteArray TXRequest::getFrameData(){
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getDestinationAddress();
	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;
	frameData += getBroadcastRadius();
	frameData += getTransmitOptions();
	frameData += getTransmitingData();
	return frameData;
}

void TXRequest::setFrameID(byte id) {
	frameID = id;
}

void TXRequest::setBroadcastRadius(byte radius){
	broadcastRadius = radius;
}

void TXRequest::setTransmitOptions(byte options){
	transmitOptions = options;
}

void TXRequest::setDestinationAddress(QByteArray address){
	destinationAddress = address;
}

void TXRequest::setTransmitingData(QByteArray data){
	rfData = data;
}

void TXRequest::setFrameData(QByteArray data) {
	if ((data.size() < 15) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setDestinationAddress(data.mid(2,8));
	setBroadcastRadius(data[12]);
	setTransmitOptions(data[13]);
	setTransmitingData(data.mid(14));
}
