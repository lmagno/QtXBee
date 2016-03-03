#include "rxindicator.h"
#include "xbeepacket.h"
#include "QXbee.h"
#include <QDebug>

RXIndicator::RXIndicator()
{
}

unsigned char RXIndicator::getApiID() const {
	return QXbee::pRXIndicator;
}

QByteArray RXIndicator::getSrcAddr64(){
	return srcAddr64;
}

QByteArray RXIndicator::getSrcAddr16(){
	return srcAddr16;
}

unsigned RXIndicator::getReceiveOptions(){
	return receiveOptions;
}

QByteArray RXIndicator::getData(){
	return data;
}

QByteArray RXIndicator::getFrameData() {
	QByteArray frameData;
	return frameData;
}

void RXIndicator::setReceiveOptions(unsigned ro){
	receiveOptions = ro;
}

void RXIndicator::setSrcAddr64(QByteArray sa64){
	srcAddr64.clear();
	srcAddr64 += sa64;
}
void RXIndicator::setSrcAddr16(QByteArray sa16){
	srcAddr16.clear();
	srcAddr16 += sa16;
}
void RXIndicator::setData(QByteArray d){
	data.clear();
	data += d;
}

void RXIndicator::setFrameData(QByteArray data){
	setReceiveOptions(data[0]);
/*
	packet.clear();
	packet += rx;
	setStartDelimiter(rx[0]);
	setLength(rx[2]);
	if(rx.size() == rx[2]+4 && rx.size() > 15){
		setFrameType(rx[3]);
		srcAddr64 += rx[4];
		srcAddr64 += rx[5];
		srcAddr64 += rx[6];
		srcAddr64 += rx[7];
		srcAddr64 += rx[8];
		srcAddr64 += rx[9];
		srcAddr64 += rx[10];
		srcAddr64 += rx[11];
		srcAddr16 += rx[12];
		srcAddr16 += rx[13];
		setReceiveOptions(rx[14]);
		int count = 15;
		while(count < rx.size()-1){
			data += rx[count];
			count++;
		}
		setChecksum(rx[count]);
	}else{

		qDebug()<< "Invalid Packet Received!";
		qDebug()<< packet.toHex();
		packet.clear();
	}
	*/
}
