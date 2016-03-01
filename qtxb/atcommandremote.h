#ifndef ATCOMMANDREMOTE_H
#define ATCOMMANDREMOTE_H

#include "atcommand.h"
#include <QByteArray>

class ATCommandRemote : public ATCommand
{
	unsigned char commandOptions;
	QByteArray destAddress;
public:
    explicit ATCommandRemote(QObject *parent);
	QByteArray getDestinationAdress();
	unsigned char getCommandOptions();
	void setDestinationAddress(QByteArray);
	void setCommandOptions(unsigned char);
};

#endif // ATCOMMANDREMOTE_H
