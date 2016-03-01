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
    explicit ATCommand(QObject *parent);
	void setFrameID(unsigned char);
	void setATCommand(QString);
	void setParameter(QByteArray array);
	unsigned char getFrameID();
    QByteArray getATCommand();
    QByteArray getParameter();
    void assemblePacket();
};

#endif // ATCOMMANDPACKET_H
