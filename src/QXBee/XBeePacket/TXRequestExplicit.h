#ifndef TXREQUESTEXPLICIT_H
#define TXREQUESTEXPLICIT_H

#include <QByteArray>

#include "TXRequest.h"

class TXRequestExplicit : public TXRequest
{
	uint8_t		 sourceEndpoint;
	uint8_t		 destinationEndpoint;
	QByteArray	 clusterID;
	QByteArray	 profileID;

public:
	TXRequestExplicit();

	virtual uint8_t getFrameType() const { return FrameType::TXRequestExplicit; }
	uint8_t		 getSourceEndpoint();
	uint8_t		 getDestinationEndpoint();
	QByteArray	 getClusterID();
	QByteArray	 getProfileID();
	QByteArray	 getFrameData();

	void		 setSourceEndpoint(uint8_t endpoint);
	void		 setDestinationEndpoint(uint8_t endpoint);
	void		 setCLusterID(QByteArray id);
	void		 setProfileID(QByteArray id);
	void		 setFrameData(QByteArray data);
};

#endif // TXREQUESTEXPLICIT_H
