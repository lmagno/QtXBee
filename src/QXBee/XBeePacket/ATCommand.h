#ifndef ATCOMMAND_H
#define ATCOMMAND_H

#include <QByteArray>
#include <QString>

#include "XBeePacket.h"

class ATCommand : public XBeePacket
{
	uint8_t			   frameID;
	QByteArray		   atCommand;
	QByteArray		   atParameter;

public:
	ATCommand();

	virtual uint8_t	   getFrameType() const { return FrameType::ATCommand; }
	uint8_t			   getFrameID();
	QByteArray		   getATCommand();
	QByteArray		   getATParameter();
	virtual QByteArray getFrameData();

	void			   setFrameID(uint8_t id);
	void			   setATCommand(QString command);
	void			   setATParameter(QByteArray parameter);
	virtual void	   setFrameData(QByteArray data);
	virtual			   ~ATCommand();
};

#endif // ATCOMMAND_H
