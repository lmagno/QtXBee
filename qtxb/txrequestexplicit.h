#ifndef TXREQUESTEXPLICIT_H
#define TXREQUESTEXPLICIT_H

#include "txrequest.h"
#include <QByteArray>

class TXRequestExplicit : public TXRequest
{
	QByteArray sourceEndpoint;
	QByteArray destinationEndpoint;
	QByteArray clusterID;
	QByteArray profileID;
public:
	TXRequestExplicit();
	virtual unsigned char getApiID() const { return QTXB::pTXRequestExplicit; }
};

#endif // TXREQUESTEXPLICIT_H
