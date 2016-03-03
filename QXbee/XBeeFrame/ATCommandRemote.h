#ifndef ATCOMMANDREMOTE_H
#define ATCOMMANDREMOTE_H

#include <QByteArray>

#include "ATCommand.h"

class ATCommandRemote : public ATCommand
{
	QByteArray destinationAddress;
	quint8 commandOptions;
public:
	ATCommandRemote();
	virtual quint8 getFrameType() const { return pATCommandRemote; }
	QByteArray getDestinationAdress();
	quint8 getCommandOptions();
	QByteArray getFrameData();
	void setDestinationAddress(QByteArray);
	void setCommandOptions(quint8);
	void setFrameData(QByteArray);
};

#endif // ATCOMMANDREMOTE_H
