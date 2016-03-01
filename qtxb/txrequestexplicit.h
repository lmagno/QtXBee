#ifndef TXREQUESTEXPLICIT_H
#define TXREQUESTEXPLICIT_H

#include "txrequest.h"
#include <QByteArray>

class TXRequestExplicit : public TXRequest
{

public:
	TXRequestExplicit();
	QByteArray sourceEndpoint;
	QByteArray destinationEndpoint;
	QByteArray clusterID;
	QByteArray profileID;
};

#endif // TXREQUESTEXPLICIT_H
