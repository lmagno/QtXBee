#include "atcommand.h"
#include "atcommandqueueparam.h"

ATCommandQueueParam::ATCommandQueueParam(QObject *parent) :
    ATCommand(parent)
{
	setApiID(0x09);
	setFrameID(0);
}
