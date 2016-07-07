/**
 * @class ModemStatus
 * @ingroup XBeePacket
 *
 * Represents an AT Command packet
 *
 * Test...
 */

#ifndef MODEMSTATUS_H
#define MODEMSTATUS_H

#include <QByteArray>

#include "XBeePacket.h"

class ModemStatus : public XBeePacket
{
	uint8_t		 statusValue;

protected:
	void		 setStatus(uint8_t status);

public:
	ModemStatus();

	virtual uint8_t getFrameType() const { return FrameType::ModemStatus; }
	uint8_t		 getStatus();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray data);
	virtual		 ~ModemStatus();
};

#endif // MODEMSTATUS_H
