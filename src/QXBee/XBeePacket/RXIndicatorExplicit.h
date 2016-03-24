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
	void		 setSourceEndpoint(uint8_t);
	void		 setDestinationEndpoint(uint8_t);
	void		 setClusterID(QByteArray);
	void		 setProfileID(QByteArray);

public:
	RXIndicatorExplicit();

	virtual uint8_t getFrameType() const { return FrameType::RXIndicatorExplicit; }
	uint8_t		 getSourceEndpoint();
	uint8_t		 getDestinationEndpoint();
	QByteArray	 getClusterID();
	QByteArray	 getProfileID();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray);
};

#endif // RXINDICATOREXPLICIT_H
