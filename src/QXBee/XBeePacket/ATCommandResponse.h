#ifndef ATCOMMANDRESPONSE_H
#define ATCOMMANDRESPONSE_H

#include <QByteArray>
#include <QString>

#include "XBeePacket.h"

class ATCommandResponse : public XBeePacket
{
	uint8_t			   frameID;
	QByteArray		   atCommand;
	uint8_t			   commandStatus;
	QByteArray		   commandData;

protected:
	void			   setFrameID(uint8_t);
	void			   setATCommand(QString);
	void			   setCommandStatus(uint8_t);
	void			   setCommandData(QByteArray);

public:
	ATCommandResponse();

	virtual uint8_t	   getFrameType() const { return pATCommandResponse; }
	uint8_t			   getFrameID();
	QString			   getATCommand();
	uint8_t			   getCommandStatus();
	QByteArray		   getCommandData();
	virtual QByteArray getFrameData();

	virtual void	   setFrameData(QByteArray);
	virtual			   ~ATCommandResponse();
};

#endif // ATCOMMANDRESPONSE_H
