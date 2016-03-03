#ifndef ATCOMMAND_H
#define ATCOMMAND_H

#include "qtxb.h"
#include "xbeepacket.h"
#include <QByteArray>
#include <QString>

class ATCommand : public XBeePacket
{
	unsigned char frameID;
    QByteArray atCommand;
	QByteArray atParameter;
public:
	ATCommand();
	virtual unsigned char getApiID() const { return QTXB::pATCommand; }
	unsigned char getFrameID();
    QByteArray getATCommand();
	QByteArray getATParameter();
	virtual QByteArray getFrameData();
	void setFrameID(unsigned char);
	void setATCommand(QString);
	void setATParameter(QByteArray array);
	virtual void setFrameData(QByteArray);
};

#endif // ATCOMMANDPACKET_H
