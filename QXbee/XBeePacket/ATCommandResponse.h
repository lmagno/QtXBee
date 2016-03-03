#ifndef ATCOMMANDRESPONSE_H
#define ATCOMMANDRESPONSE_H

#include <QByteArray>

#include "XBeePacket.h"

class ATCommandResponse : public XBeePacket
{
	unsigned char frameID;
	QByteArray atCommand;
	unsigned char commandStatus;
	QByteArray commandData;
protected:
	void setFrameID(unsigned char);
	void setATCommand(QString);
	void setCommandStatus(unsigned char);
	void setCommandData(QByteArray);
public:
	ATCommandResponse();
	virtual unsigned char getApiID() const { return pATCommandResponse; }
	unsigned char getFrameID();
	QString getATCommand();
	unsigned char getCommandStatus();
	QByteArray getCommandData();
	virtual QByteArray getFrameData();
	virtual void setFrameData(QByteArray);
};

#endif // ATCOMMANDRESPONSE_H
