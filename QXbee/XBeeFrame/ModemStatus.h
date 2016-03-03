#ifndef MODEMSTATUS_H
#define MODEMSTATUS_H

#include <QByteArray>

#include "XBeeFrame.h"

class ModemStatus : public XBeeFrame
{
	quint8 status;
protected:
	void setStatus(quint8);
public:
	ModemStatus();
	virtual quint8 getFrameType() const { return pModemStatus; }
	quint8 getStatus();
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // MODEMSTATUS_H
