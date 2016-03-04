#include "RXIndicator.h"

RXIndicator::RXIndicator()
{
}

QByteArray RXIndicator::getSourceAddress(){
	return sourceAddress;
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
	frameData += getSourceAddress();

	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;

	frameData += getReceiveOptions();
	frameData += getReceivedData();

	return frameData;
}

void RXIndicator::setSourceAddress(QByteArray sa){
	sourceAddress.clear();
	sourceAddress += sa;
}

void RXIndicator::setReceiveOptions(byte ro){
	receiveOptions = ro;
}

void RXIndicator::setReceivedData(QByteArray rd){
	receivedData.clear();
	receivedData += rd;
}

void RXIndicator::setFrameData(QByteArray data){
	if (data.size() < 12 && data.at(0) != getFrameType()) return;

	setSourceAddress(data.mid(1, 8));
	setReceiveOptions(data[11]);
	if (data.size() > 12) setReceivedData(data.mid(12));
}
