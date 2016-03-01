#include "txrequest.h"
#include "digimeshpacket.h"

TXRequest::TXRequest()
{
    unsigned zero = 0x00;
    unsigned oxff = 0xFF;
    unsigned oxfe = 0xFE;
    destAddr16 += oxff;
    destAddr16 += oxfe;
    destAddr64 += zero;
    destAddr64 += zero;
    destAddr64 += zero;
    destAddr64 += zero;
    destAddr64 += zero;
    destAddr64 += zero;
    destAddr64 += oxff;
    destAddr64 += oxff;

    broadcastRadius = 1;
    transmitOptions = 0x00;
    setFrameType(0x10);
    setFrameId(0x01);
}
void TXRequest::setBroadcastRadius(int rad){
    broadcastRadius = rad;
}
void TXRequest::setTransmitOptions(unsigned to){
    transmitOptions = to;
}
void TXRequest::setDestAddr64(QByteArray da64){
    destAddr64.clear();
    destAddr64 += da64;
}
void TXRequest::setDestAddr16(QByteArray da16){
    destAddr16.clear();
    destAddr16 += da16;
}
void TXRequest::setData(QByteArray d){
    data.clear();
    data += d;
}
QByteArray TXRequest::getDestAddr64(){
    return destAddr64;
}
QByteArray TXRequest::getDestAddr16(){
    return destAddr16;
}
unsigned TXRequest::getBroadcastRadius(){
    return broadcastRadius;
}
unsigned TXRequest::getTransmitOptions(){
    return transmitOptions;
}
QByteArray TXRequest::getData(){
    return data;
}
void TXRequest::assemblePacket(){
    packet.clear();
    packet += getFrameType();
    packet += getFrameId();
    packet += getDestAddr64();
    packet += getDestAddr16();
    packet += getBroadcastRadius();
    packet += getTransmitOptions();
    packet += getData();
    setLength(packet.size());
    createChecksum(packet);
    packet += getChecksum();
    packet.insert(0, getStartDelimiter());
    packet.insert(1, getLength());

}

