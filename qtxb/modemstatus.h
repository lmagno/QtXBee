#ifndef MODEMSTATUS_H
#define MODEMSTATUS_H

#include "digimeshpacket.h"
#include <QByteArray>

class ModemStatus : public DigiMeshPacket
{
	unsigned char status;
	void setStatus(unsigned char);
public:
    explicit ModemStatus(QObject *parent);
	unsigned char getStatus();
};

#endif // MODEMSTATUS_H
