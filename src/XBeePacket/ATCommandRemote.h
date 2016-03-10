#ifndef ATCOMMANDREMOTE_H
#define ATCOMMANDREMOTE_H

#include <QByteArray>

#include "ATCommand.h"

class ATCommandRemote : public ATCommand
{
	QByteArray		 destinationAddress64;
	QByteArray		 destinationAddress16;
	byte			 commandOptions;

public:
	ATCommandRemote();

	virtual byte	 getFrameType() const { return pATCommandRemote; }
	QByteArray		 getDestinationAdress64();
	QByteArray		 getDestinationAdress16();
	byte			 getCommandOptions();
	QByteArray		 getFrameData();

	void			 setDestinationAddress64(QByteArray);
	void			 setDestinationAddress16(QByteArray);
	void			 setCommandOptions(byte);
	void			 setFrameData(QByteArray);
};

#endif // ATCOMMANDREMOTE_H
