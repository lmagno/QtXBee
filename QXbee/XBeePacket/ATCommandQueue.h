#ifndef ATCOMMANDQUEUE_H
#define ATCOMMANDQUEUE_H

#include "ATCommand.h"

class ATCommandQueue : public ATCommand
{
public:
	virtual unsigned char getFrameType() const { return pATCommandQueue; }
};

#endif // ATCOMMANDQUEUE_H
