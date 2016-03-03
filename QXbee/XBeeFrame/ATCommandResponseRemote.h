#ifndef ATCOMMANDRESPONSEREMOTE_H
#define ATCOMMANDRESPONSEREMOTE_H

#include <QObject>
#include <QByteArray>

#include "ATCommandResponse.h"

class ATCommandResponseRemote : public ATCommandResponse
{
	QByteArray remoteAddress;
protected:
	void setRemoteAddress(QByteArray);
public:
	ATCommandResponseRemote();
	virtual quint8 getFrameType() const { return pATCommandResponseRemote; }
	QByteArray getRemoteAddress();
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // ATCOMMANDRESPONSEREMOTE_H
