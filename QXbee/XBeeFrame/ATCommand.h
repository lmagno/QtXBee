#ifndef ATCOMMAND_H
#define ATCOMMAND_H

#include <QByteArray>
#include <QString>

#include "XBeeFrame.h"

class ATCommand : public XBeeFrame
{
	quint8 frameID;
    QByteArray atCommand;
	QByteArray atParameter;
public:
	ATCommand();
	virtual quint8 getFrameType() const { return pATCommand; }
	quint8 getFrameID();
    QByteArray getATCommand();
	QByteArray getATParameter();
	virtual QByteArray getFrameData();
	void setFrameID(quint8);
	void setATCommand(QString);
	void setATParameter(QByteArray array);
	virtual void setFrameData(QByteArray);
};

#endif // ATCOMMAND_H
