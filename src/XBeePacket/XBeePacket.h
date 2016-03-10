#ifndef XBEEPACKET_H
#define XBEEPACKET_H

#include <QByteArray>

#include "typedef.h"

class XBeePacket
{
public:
	// Frame types (API ID)
	static const byte  pATCommand = 0x08;
	static const byte  pATCommandQueue = 0x09;
	static const byte  pTXRequest = 0x10;
	static const byte  pTXRequestExplicit = 0x11;
	static const byte  pATCommandRemote = 0x17;
	static const byte  pATCommandResponse = 0x88;
	static const byte  pModemStatus = 0x8A;
	static const byte  pTransmitStatus = 0x8B;
	static const byte  pRXIndicator = 0x90;
	static const byte  pRXIndicatorExplicit = 0x91;
	static const byte  pNodeIdentificationIndicator = 0x95;
	static const byte  pATCommandResponseRemote = 0x97;

	virtual byte	   getFrameType() const = 0;
	virtual QByteArray getFrameData() = 0;
	virtual void	   setFrameData(QByteArray) = 0;
	virtual			   ~XBeePacket() {} // Magic
};

#endif // XBEEPACKET_H
