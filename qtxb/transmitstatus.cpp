#include "transmitstatus.h"
#include "digimeshpacket.h"
#include <QDebug>

TransmitStatus::TransmitStatus()
{
}
void TransmitStatus::readPacket(QByteArray rx){
	packet.clear();
	packet += rx;
	setStartDelimiter(rx[0]);
	setLength(rx[2]);
	if(rx.size() == rx[2]+4){
		setFrameType(rx[3]);
		setFrameId(rx[4]);
		reserved += rx[5];
		reserved += rx[6];
		setTransmitRetryCount(rx[7]);
		setDeliveryStatus(rx[8]);
		setDiscoveryStatus(rx[9]);
		setChecksum(rx[10]);
	}else{

		qDebug()<< "Invalid Packet Received!";
		qDebug()<< packet.toHex();
		packet.clear();
	}
}
void TransmitStatus:: setDeliveryStatus(unsigned ds){
	deliveryStatus = ds;
}
void TransmitStatus:: setTransmitRetryCount(unsigned trc){
	transmitRetryCount = trc;
}
void TransmitStatus:: setDiscoveryStatus(unsigned ds){
	discoveryStatus = ds;
}
unsigned TransmitStatus:: getDeliveryStatus(){
	return deliveryStatus;
}
unsigned TransmitStatus:: getTransmitRetryCount(){
	return transmitRetryCount;
}
unsigned TransmitStatus:: getDiscoveryStatus(){
	return discoveryStatus;
}
QByteArray TransmitStatus:: getReserved(){
	return reserved;
}

void TransmitStatus::assemblePacket() {

}
