#ifndef ATCOMMAND_H
#define ATCOMMAND_H

#include <QByteArray>
#include <QString>

#include "XBeePacket.h"

class ATCommand : public XBeePacket
{
	byte			   frameID;
	QByteArray		   atCommand;
	QByteArray		   atParameter;

public:
	ATCommand();

	virtual byte	   getFrameType() const { return pATCommand; }
	byte			   getFrameID();
	QByteArray		   getATCommand();
	QByteArray		   getATParameter();
	virtual QByteArray getFrameData();

	void			   setFrameID(byte);
	void			   setATCommand(QString);
	void			   setATParameter(QByteArray array);
	virtual void	   setFrameData(QByteArray);
	virtual			   ~ATCommand();
};

#endif // ATCOMMAND_H
