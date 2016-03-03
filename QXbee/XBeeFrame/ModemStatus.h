#ifndef MODEMSTATUS_H
#define MODEMSTATUS_H

#include <QByteArray>

#include "XBeeFrame.h"

class ModemStatus : public XBeeFrame
{
	unsigned char status;
protected:
	void setStatus(unsigned char);
public:
	ModemStatus();
	virtual unsigned char getFrameType() const { return pModemStatus; }
	unsigned char getStatus();
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // MODEMSTATUS_H
