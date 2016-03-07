#include "TXRequest.h"

TXRequest::TXRequest()
{
	// Ma HAHAiiiii vai ou não vaiiiii
    unsigned zero = 0x00;
    unsigned oxff = 0xFF;
	destinationAddress += zero;
	destinationAddress += zero;
	destinationAddress += zero;
	destinationAddress += zero;
	destinationAddress += zero;
	destinationAddress += zero;
	destinationAddress += oxff;
	destinationAddress += oxff;

    broadcastRadius = 1;
    transmitOptions = 0x00;
	setFrameID(0x01);
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

QByteArray TXRequest::getRFData(){
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
	frameData += getRFData();
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

void TXRequest::setRFData(QByteArray data){
	rfData = data;
}

void TXRequest::setFrameData(QByteArray data) {
	if ((data.size() < 15) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setDestinationAddress(data.mid(2,8));
	setBroadcastRadius(data[12]);
	setTransmitOptions(data[13]);
	setRFData(data.mid(14));
}
