#ifndef ATCOMMANDREMOTE_H
#define ATCOMMANDREMOTE_H

#include "ATCommand.h"
#include <QByteArray>

class ATCommandRemote : public ATCommand
{
	QByteArray destinationAddress;
	unsigned char commandOptions;
public:
	ATCommandRemote();
	virtual unsigned char getApiID() const { return pATCommandRemote; }
	QByteArray getDestinationAdress();
	unsigned char getCommandOptions();
	QByteArray getFrameData();
	void setDestinationAddress(QByteArray);
	void setCommandOptions(unsigned char);
	void setFrameData(QByteArray);
};

#endif // ATCOMMANDREMOTE_H
