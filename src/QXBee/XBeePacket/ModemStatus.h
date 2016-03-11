#ifndef MODEMSTATUS_H
#define MODEMSTATUS_H

#include <QByteArray>

#include "XBeePacket.h"

class ModemStatus : public XBeePacket
{
	uint8_t		 status;

protected:
	void		 setStatus(uint8_t);

public:
	ModemStatus();

	virtual uint8_t getFrameType() const { return pModemStatus; }
	uint8_t		 getStatus();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray);
	virtual		 ~ModemStatus();
};

#endif // MODEMSTATUS_H
