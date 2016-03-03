#ifndef ATCOMMAND_H
#define ATCOMMAND_H

#include <QByteArray>
#include <QString>

#include "XBeePacket.h"

class ATCommand : public XBeePacket
{
	unsigned char frameID;
    QByteArray atCommand;
	QByteArray atParameter;
public:
	ATCommand();
	virtual unsigned char getApiID() const { return pATCommand; }
	unsigned char getFrameID();
    QByteArray getATCommand();
	QByteArray getATParameter();
	virtual QByteArray getFrameData();
	void setFrameID(unsigned char);
	void setATCommand(QString);
	void setATParameter(QByteArray array);
	virtual void setFrameData(QByteArray);
};

#endif // ATCOMMAND_H
