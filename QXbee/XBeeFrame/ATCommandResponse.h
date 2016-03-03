#ifndef ATCOMMANDRESPONSE_H
#define ATCOMMANDRESPONSE_H

#include <QByteArray>

#include "XBeeFrame.h"

class ATCommandResponse : public XBeeFrame
{
	quint8 frameID;
	QByteArray atCommand;
	quint8 commandStatus;
	QByteArray commandData;
protected:
	void setFrameID(quint8);
	void setATCommand(QString);
	void setCommandStatus(quint8);
	void setCommandData(QByteArray);
public:
	ATCommandResponse();
	virtual quint8 getFrameType() const { return pATCommandResponse; }
	quint8 getFrameID();
	QString getATCommand();
	quint8 getCommandStatus();
	QByteArray getCommandData();
	virtual QByteArray getFrameData();
	virtual void setFrameData(QByteArray);
};

#endif // ATCOMMANDRESPONSE_H
