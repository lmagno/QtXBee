#ifndef XBEEFRAME_H
#define XBEEFRAME_H

#include <QByteArray>

class XBeeFrame
{
public:
	// Frame types (API ID)
	static const quint8 pATCommand = 0x08;
	static const quint8 pATCommandQueue = 0x09;
	static const quint8 pTXRequest = 0x10;
	static const quint8 pTXRequestExplicit = 0x11;
	static const quint8 pATCommandRemote = 0x17;
	static const quint8 pATCommandResponse = 0x88;
	static const quint8 pModemStatus = 0x8A;
	static const quint8 pTransmitStatus = 0x8B;
	static const quint8 pRXIndicator = 0x90;
	static const quint8 pRXIndicatorExplicit = 0x91;
	static const quint8 pNodeIdentificationIndicator = 0x95;
	static const quint8 pATCommandResponseRemote = 0x97;

	virtual quint8 getFrameType() const = 0;
	virtual QByteArray getFrameData() = 0;
	virtual void setFrameData(QByteArray) = 0;
};

#endif // XBEEFRAME_H
