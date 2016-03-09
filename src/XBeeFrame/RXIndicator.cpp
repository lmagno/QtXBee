#include "RXIndicator.h"

RXIndicator::RXIndicator()
{
}

QByteArray RXIndicator::getSourceAddress64(){
	return sourceAddress64;
}

QByteArray RXIndicator::getSourceAddress16(){
	return sourceAddress16;
}

byte RXIndicator::getReceiveOptions(){
	return receiveOptions;
}

QByteArray RXIndicator::getReceivedData(){
	return receivedData;
}

QByteArray RXIndicator::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getSourceAddress64();
	frameData += getSourceAddress16();
	frameData += getReceiveOptions();
	frameData += getReceivedData();
	return frameData;
}

void RXIndicator::setSourceAddress64(QByteArray address){
	sourceAddress64 = address;
}

void RXIndicator::setSourceAddress16(QByteArray address){
	sourceAddress16 = address;
}

void RXIndicator::setReceiveOptions(byte options){
	receiveOptions = options;
}

void RXIndicator::setReceivedData(QByteArray data){
	receivedData = data;
}

void RXIndicator::setFrameData(QByteArray data){
	if (data.size() < 12 && data.at(0) != getFrameType()) return;
	setSourceAddress64(data.mid(1, 8));
	setSourceAddress16(data.mid(9,2));
	setReceiveOptions(data[11]);
	if (data.size() > 12) setReceivedData(data.mid(12));
}
