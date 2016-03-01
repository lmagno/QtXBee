#ifndef DIGIMESHPACKET_H
#define DIGIMESHPACKET_H
#include <QByteArray>
#include <QObject>


class DigiMeshPacket : public QObject
{
    Q_OBJECT
	unsigned char apiID;
	QByteArray frameData;
	virtual void update() = 0;
public:
    explicit DigiMeshPacket(QObject *parent = 0);
	void setApiID(unsigned char);
	void setFrameData(QByteArray);
	unsigned char getApiID();
	QByteArray getFrameData();
};

#endif // DIGIMESHPACKET_H
