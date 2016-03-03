#include "txrequestexplicit.h"
#include "../QXbee.h"

TXRequestExplicit::TXRequestExplicit()
{
}

unsigned char TXRequestExplicit::getApiID() const {
	return QXbee::pTXRequestExplicit;
}
