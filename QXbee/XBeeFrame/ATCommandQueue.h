#ifndef ATCOMMANDQUEUE_H
#define ATCOMMANDQUEUE_H

#include "../typedef.h"
#include "ATCommand.h"

class ATCommandQueue : public ATCommand
{
public:
	virtual byte getFrameType() const { return pATCommandQueue; }
};

#endif // ATCOMMANDQUEUE_H
