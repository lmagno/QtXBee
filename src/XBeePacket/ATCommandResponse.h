#ifndef ATCOMMANDRESPONSE_H
#define ATCOMMANDRESPONSE_H

#include <QByteArray>
#include <QString>

#include "XBeePacket.h"

class ATCommandResponse : public XBeePacket
{
	byte			   frameID;
	QByteArray		   atCommand;
	byte			   commandStatus;
	QByteArray		   commandData;

protected:
	void			   setFrameID(byte);
	void			   setATCommand(QString);
	void			   setCommandStatus(byte);
	void			   setCommandData(QByteArray);

public:
	ATCommandResponse();

	virtual byte	   getFrameType() const { return pATCommandResponse; }
	byte			   getFrameID();
	QString			   getATCommand();
	byte			   getCommandStatus();
	QByteArray		   getCommandData();
	virtual QByteArray getFrameData();

	virtual void	   setFrameData(QByteArray);
};

#endif // ATCOMMANDRESPONSE_H
