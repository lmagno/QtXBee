#ifndef ATCOMMANDREMOTE_H
#define ATCOMMANDREMOTE_H

#include <QByteArray>

#include "ATCommand.h"

class ATCommandRemote : public ATCommand
{
	QByteArray		 destinationAddress64;
	QByteArray		 destinationAddress16;
	uint8_t			 commandOptions;

public:
	ATCommandRemote();

	virtual uint8_t	 getFrameType() const { return FrameType::ATCommandRemote; }
	QByteArray		 getDestinationAdress64();
	QByteArray		 getDestinationAdress16();
	uint8_t			 getCommandOptions();
	QByteArray		 getFrameData();

	void			 setDestinationAddress64(QByteArray);
	void			 setDestinationAddress16(QByteArray);
	void			 setCommandOptions(uint8_t);
	void			 setFrameData(QByteArray);
};

#endif // ATCOMMANDREMOTE_H
