#ifndef TXREQUESTEXPLICIT_H
#define TXREQUESTEXPLICIT_H

#include "TXRequest.h"
#include <QByteArray>

class TXRequestExplicit : public TXRequest
{
	QByteArray sourceEndpoint;
	QByteArray destinationEndpoint;
	QByteArray clusterID;
	QByteArray profileID;
public:
	TXRequestExplicit();
	virtual unsigned char getApiID() const;
};

#endif // TXREQUESTEXPLICIT_H
