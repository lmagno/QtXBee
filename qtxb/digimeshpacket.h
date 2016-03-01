#ifndef DIGIMESHPACKET_H
#define DIGIMESHPACKET_H
#include <QByteArray>
#include <QObject>


class DigiMeshPacket
{
	unsigned char apiID;
public:
	DigiMeshPacket();
	void setApiID(unsigned char);
	virtual void setFrameData(QByteArray) = 0;
	unsigned char getApiID();
	virtual QByteArray getFrameData() = 0;
};

#endif // DIGIMESHPACKET_H
