/**
 * @class ATCommand
 * @ingroup XBeePacket
 *
 * Represents an AT Command packet
 *
 * Test...
 */

#ifndef ATCOMMAND_H
#define ATCOMMAND_H

#include <QByteArray>
#include <QString>

#include "XBeePacket.h"

class ATCommand : public XBeePacket
{
	uint8_t			   frameID;
	QByteArray		   atCommand;
	QByteArray		   atParameter;

public:
	ATCommand();

	virtual uint8_t	   getFrameType() const { return FrameType::ATCommand; }    ///< @brief Returns the API frame type value
	uint8_t			   getFrameID(); 											///< @brief Returns the frame ID, used for correlation between a request and a response packet
	QByteArray		   getATCommand(); 											///< @brief Returns two ASCII characters that identify the AT command.
	QByteArray		   getATParameter();										///< @brief Returns the AT parameter
	virtual QByteArray getFrameData();											///< @brief Returns the data portion of the frame

	void			   setFrameID(uint8_t id);  								///< @brief Sets the frame ID, used for correlation between a request and a response packet
	void			   setATCommand(QString command);							///< @brief Returns two ASCII characters that identify the AT command.
	void			   setATParameter(QByteArray parameter); 					///< @brief Sets the AT parameter.
	virtual void	   setFrameData(QByteArray data); 							///< @brief Sets the data portion of the frame.
	virtual			   ~ATCommand();
};

#endif // ATCOMMAND_H
