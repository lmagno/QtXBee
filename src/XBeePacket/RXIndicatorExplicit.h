#ifndef RXINDICATOREXPLICIT_H
#define RXINDICATOREXPLICIT_H

#include <QByteArray>

#include "RXIndicator.h"

class RXIndicatorExplicit : public RXIndicator
{
	byte		 sourceEndpoint;
	byte		 destinationEndpoint;
	QByteArray	 clusterID;
	QByteArray	 profileID;

protected:
	void		 setSourceEndpoint(byte);
	void		 setDestinationEndpoint(byte);
	void		 setClusterID(QByteArray);
	void		 setProfileID(QByteArray);

public:
	RXIndicatorExplicit();

	virtual byte getFrameType() const { return pRXIndicatorExplicit; }
	byte		 getSourceEndpoint();
	byte		 getDestinationEndpoint();
	QByteArray	 getClusterID();
	QByteArray	 getProfileID();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray);
};

#endif // RXINDICATOREXPLICIT_H
