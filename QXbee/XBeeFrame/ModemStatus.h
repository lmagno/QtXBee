#ifndef MODEMSTATUS_H
#define MODEMSTATUS_H

#include <QByteArray>

#include "typedef.h"
#include "XBeeFrame.h"

class ModemStatus : public XBeeFrame
{
	byte status;
protected:
	void setStatus(byte);
public:
	ModemStatus();
	virtual byte getFrameType() const { return pModemStatus; }
	byte getStatus();
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // MODEMSTATUS_H
