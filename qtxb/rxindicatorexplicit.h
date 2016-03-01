#ifndef RXINDICATOREXPLICIT_H
#define RXINDICATOREXPLICIT_H
#include "digimeshpacket.h"
#include <QByteArray>


class RXIndicatorExplicit : public DigiMeshPacket
{
public:
	RXIndicatorExplicit();
    void readPacket(QByteArray rx);
	void assemblePacket();
};

#endif // RXINDICATOREXPLICIT_H
