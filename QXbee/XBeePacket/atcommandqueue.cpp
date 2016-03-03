#include "atcommandqueue.h"
#include "../QXbee.h"

unsigned char ATCommandQueue::getApiID() const {
	return QXbee::pATCommandQueue;
}
