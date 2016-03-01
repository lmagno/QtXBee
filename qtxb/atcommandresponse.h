#ifndef ATCOMMANDRESPONSE_H
#define ATCOMMANDRESPONSE_H

#include "atcommand.h"
#include <QByteArray>

class ATCommandResponse : public DigiMeshPacket
{
	unsigned char frameID;
	QByteArray atCommand;
	unsigned char commandStatus;
	QByteArray commandData;
	void setFrameID(unsigned char);
	void setATCommand(QString);
	void setCommandStatus(unsigned char);
	void setCommandData(QByteArray);
	void update();
public:
	ATCommandResponse();
	unsigned char getFrameID();
	QString getATCommand();
	unsigned char getCommandStatus();
	QByteArray getCommandData();
};

#endif // ATCOMMANDRESPONSE_H
