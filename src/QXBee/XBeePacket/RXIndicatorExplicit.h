#ifndef RXINDICATOREXPLICIT_H
#define RXINDICATOREXPLICIT_H

#include <QByteArray>

#include "RXIndicator.h"

class RXIndicatorExplicit : public RXIndicator
{
	uint8_t		 sourceEndpoint;
	uint8_t		 destinationEndpoint;
	QByteArray	 clusterID;
	QByteArray	 profileID;

protected:
	void		 setSourceEndpoint(uint8_t endpoint);
	void		 setDestinationEndpoint(uint8_t endpoint);
	void		 setClusterID(QByteArray id);
	void		 setProfileID(QByteArray id);

public:
	RXIndicatorExplicit();

	virtual uint8_t getFrameType() const { return FrameType::RXIndicatorExplicit; }
	uint8_t		 getSourceEndpoint();
	uint8_t		 getDestinationEndpoint();
	QByteArray	 getClusterID();
	QByteArray	 getProfileID();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray data);
};

#endif // RXINDICATOREXPLICIT_H
