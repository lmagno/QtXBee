#ifndef MODEMSTATUS_H
#define MODEMSTATUS_H

#include "digimeshpacket.h"
#include <QByteArray>

class ModemStatus : public DigiMeshPacket
{
	unsigned char status;
	void setStatus(unsigned char);
	void setFrameData(QByteArray);
public:
	ModemStatus();
	unsigned char getStatus();
	QByteArray getFrameData();
};

#endif // MODEMSTATUS_H
