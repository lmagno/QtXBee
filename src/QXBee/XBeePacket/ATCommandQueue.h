/**
 * @class ATCommandQueue
 * @ingroup XBeePacket
 *
 * Represents an AT Command packet
 *
 * Test...
 */

#ifndef ATCOMMANDQUEUE_H
#define ATCOMMANDQUEUE_H

#include "ATCommand.h"

class ATCommandQueue : public ATCommand
{
public:
	virtual uint8_t	   getFrameType() const { return FrameType::ATCommandQueue; }
};

#endif // ATCOMMANDQUEUE_H
