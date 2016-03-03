#ifndef XBEEPACKET_H
#define XBEEPACKET_H

#include <QByteArray>

class XBeePacket
{
public:
	// Packet types (API ID)
	static const unsigned char pATCommand = 0x08;
	static const unsigned char pATCommandQueue = 0x09;
	static const unsigned char pTXRequest = 0x10;
	static const unsigned char pTXRequestExplicit = 0x11;
	static const unsigned char pATCommandRemote = 0x17;
	static const unsigned char pATCommandResponse = 0x88;
	static const unsigned char pModemStatus = 0x8A;
	static const unsigned char pTransmitStatus = 0x8B;
	static const unsigned char pRXIndicator = 0x90;
	static const unsigned char pRXIndicatorExplicit = 0x91;
	static const unsigned char pNodeIdentificationIndicator = 0x95;
	static const unsigned char pATCommandResponseRemote = 0x97;

	virtual unsigned char getFrameType() const = 0;
	virtual QByteArray getFrameData() = 0;
	virtual void setFrameData(QByteArray) = 0;
};

#endif // XBEEPACKET_H
