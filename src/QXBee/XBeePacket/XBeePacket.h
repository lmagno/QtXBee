#ifndef XBEEPACKET_H
#define XBEEPACKET_H

#include <QByteArray>

class XBeePacket
{
public:
	// Frame types (API ID)
	static const uint8_t  pATCommand = 0x08;
	static const uint8_t  pATCommandQueue = 0x09;
	static const uint8_t  pTXRequest = 0x10;
	static const uint8_t  pTXRequestExplicit = 0x11;
	static const uint8_t  pATCommandRemote = 0x17;
	static const uint8_t  pATCommandResponse = 0x88;
	static const uint8_t  pModemStatus = 0x8A;
	static const uint8_t  pTransmitStatus = 0x8B;
	static const uint8_t  pRXIndicator = 0x90;
	static const uint8_t  pRXIndicatorExplicit = 0x91;
	static const uint8_t  pNodeIdentificationIndicator = 0x95;
	static const uint8_t  pATCommandResponseRemote = 0x97;

	virtual uint8_t	   getFrameType() const = 0;
	virtual QByteArray getFrameData() = 0;
	virtual void	   setFrameData(QByteArray) = 0;
	virtual			   ~XBeePacket() {} // Magic
};

#endif // XBEEPACKET_H
