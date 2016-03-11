#include "TXRequest.h"

TXRequest::TXRequest()
{
	static const uint8_t broadcast[] = {0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF};
	static const uint8_t unknown[] = { 0xFF, 0xFE };
	setFrameID(0x01);
	setDestinationAddress64(QByteArray((char *)broadcast, 8)); // Broadcast by default
	setDestinationAddress16(QByteArray((char *)unknown, 2));
	setBroadcastRadius(1);
	setTransmitOptions(0x00);
}

uint8_t TXRequest::getFrameID() {
	return frameID;
}

QByteArray TXRequest::getDestinationAddress64(){
	return destinationAddress64;
}

QByteArray TXRequest::getDestinationAddress16(){
	return destinationAddress16;
}

uint8_t TXRequest::getBroadcastRadius(){
	return broadcastRadius;
}

uint8_t TXRequest::getTransmitOptions(){
	return transmitOptions;
}

QByteArray TXRequest::getTransmitingData(){
	return rfData;
}

QByteArray TXRequest::getFrameData(){
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getDestinationAddress64();
	frameData += getDestinationAddress16();
	frameData += getBroadcastRadius();
	frameData += getTransmitOptions();
	frameData += getTransmitingData();
	return frameData;
}

void TXRequest::setFrameID(uint8_t id) {
	frameID = id;
}

void TXRequest::setBroadcastRadius(uint8_t radius){
	broadcastRadius = radius;
}

void TXRequest::setTransmitOptions(uint8_t options){
	transmitOptions = options;
}

void TXRequest::setDestinationAddress64(QByteArray address){
	destinationAddress64 = address;
}

void TXRequest::setDestinationAddress16(QByteArray address){
	destinationAddress16 = address;
}

void TXRequest::setTransmitingData(QByteArray data){
	rfData = data;
}

void TXRequest::setFrameData(QByteArray data) {
	if ((data.size() < 14) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setDestinationAddress64(data.mid(2,8));
	setDestinationAddress16(data.mid(10,2));
	setBroadcastRadius(data[12]);
	setTransmitOptions(data[13]);
	if (data.size() > 14) setTransmitingData(data.mid(14));
}

TXRequest::~TXRequest() {
}
