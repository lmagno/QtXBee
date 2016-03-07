#ifndef TXREQUESTEXPLICIT_H
#define TXREQUESTEXPLICIT_H

#include <QByteArray>

#include "typedef.h"
#include "TXRequest.h"

class TXRequestExplicit : public TXRequest
{
	byte		 sourceEndpoint;
	byte		 destinationEndpoint;
	QByteArray	 clusterID;
	QByteArray	 profileID;

public:
	TXRequestExplicit();

	virtual byte getFrameType() const { return pTXRequestExplicit; }
	byte		 getSourceEndpoint();
	byte		 getDestinationEndpoint();
	QByteArray	 getClusterID();
	QByteArray	 getProfileID();
	QByteArray	 getFrameData();

	void		 setSourceEndpoint(byte);
	void		 setDestinationEndpoint(byte);
	void		 setCLusterID(QByteArray);
	void		 setProfileID(QByteArray);
	void		 setFrameData(QByteArray);
};

#endif // TXREQUESTEXPLICIT_H
