#ifndef ATCOMMANDREMOTE_H
#define ATCOMMANDREMOTE_H

#include <QByteArray>

#include "typedef.h"
#include "ATCommand.h"

class ATCommandRemote : public ATCommand
{
	QByteArray destinationAddress;
	byte commandOptions;
public:
	ATCommandRemote();
	virtual byte getFrameType() const { return pATCommandRemote; }
	QByteArray getDestinationAdress();
	byte getCommandOptions();
	QByteArray getFrameData();
	void setDestinationAddress(QByteArray);
	void setCommandOptions(byte);
	void setFrameData(QByteArray);
};

#endif // ATCOMMANDREMOTE_H
