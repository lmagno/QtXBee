#ifndef TXREQUESTEXPLICIT_H
#define TXREQUESTEXPLICIT_H

#include <QByteArray>

#include "../typedef.h"
#include "TXRequest.h"

class TXRequestExplicit : public TXRequest
{
	QByteArray sourceEndpoint;
	QByteArray destinationEndpoint;
	QByteArray clusterID;
	QByteArray profileID;
public:
	TXRequestExplicit();
	virtual byte getFrameType() const { return pTXRequestExplicit; }
};

#endif // TXREQUESTEXPLICIT_H
