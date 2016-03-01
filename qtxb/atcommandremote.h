#ifndef ATCOMMANDREMOTE_H
#define ATCOMMANDREMOTE_H

#include "atcommand.h"
#include <QByteArray>

class ATCommandRemote : public ATCommand
{
	unsigned char commandOptions;
	QByteArray destAddress;
public:
	ATCommandRemote();
	QByteArray getDestinationAdress();
	unsigned char getCommandOptions();
	QByteArray getFrameData();
	void setDestinationAddress(QByteArray);
	void setCommandOptions(unsigned char);
	void setFrameData(QByteArray);
};

#endif // ATCOMMANDREMOTE_H
