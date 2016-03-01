#ifndef ATCOMMAND_H
#define ATCOMMAND_H

#include "digimeshpacket.h"
#include <QByteArray>
#include <QString>

class ATCommand : public DigiMeshPacket
{
	unsigned char frameID;
    QByteArray atCommand;
    QByteArray parameter;
public:
	ATCommand();
	void setFrameID(unsigned char);
	void setATCommand(QString);
	void setParameter(QByteArray array);
	void setFrameData(QByteArray);
	unsigned char getFrameID();
    QByteArray getATCommand();
    QByteArray getParameter();
	QByteArray getFrameData();
};

#endif // ATCOMMANDPACKET_H
