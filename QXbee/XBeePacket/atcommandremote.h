#ifndef ATCOMMANDREMOTE_H
#define ATCOMMANDREMOTE_H

#include "atcommand.h"
#include <QByteArray>

class ATCommandRemote : public ATCommand
{
	QByteArray destinationAddress;
	unsigned char commandOptions;
public:
	ATCommandRemote();
	virtual unsigned char getApiID() const;
	QByteArray getDestinationAdress();
	unsigned char getCommandOptions();
	QByteArray getFrameData();
	void setDestinationAddress(QByteArray);
	void setCommandOptions(unsigned char);
	void setFrameData(QByteArray);
};

#endif // ATCOMMANDREMOTE_H
