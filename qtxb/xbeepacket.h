#ifndef DIGIMESHPACKET_H
#define DIGIMESHPACKET_H

#include <QByteArray>

class XBeePacket
{
public:
	virtual unsigned char getApiID() const = 0;
	virtual QByteArray getFrameData() = 0;
	virtual void setFrameData(QByteArray) = 0;
};

#endif // DIGIMESHPACKET_H
