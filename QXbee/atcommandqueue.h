#ifndef ATCOMMANDQUEUE_H
#define ATCOMMANDQUEUE_H

#include "atcommand.h"

class ATCommandQueue : public ATCommand
{
public:
	virtual unsigned char getApiID() const;
};

#endif // ATCOMMANDQUEUE_H
