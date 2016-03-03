#ifndef ATCOMMANDQUEUE_H
#define ATCOMMANDQUEUE_H

#include "ATCommand.h"

class ATCommandQueue : public ATCommand
{
public:
	virtual quint8 getFrameType() const { return pATCommandQueue; }
};

#endif // ATCOMMANDQUEUE_H
