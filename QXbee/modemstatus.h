#ifndef MODEMSTATUS_H
#define MODEMSTATUS_H

#include "xbeepacket.h"
#include <QByteArray>

class ModemStatus : public XBeePacket
{
	unsigned char status;
protected:
	void setStatus(unsigned char);
public:
	ModemStatus();
	virtual unsigned char getApiID() const;
	unsigned char getStatus();
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // MODEMSTATUS_H
