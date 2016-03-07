#ifndef ATCOMMANDRESPONSEREMOTE_H
#define ATCOMMANDRESPONSEREMOTE_H

#include <QByteArray>

#include "typedef.h"
#include "ATCommandResponse.h"

class ATCommandResponseRemote : public ATCommandResponse
{
	QByteArray	 remoteAddress;

protected:
	void		 setSourceAddress(QByteArray);

public:
	ATCommandResponseRemote();

	virtual byte getFrameType() const { return pATCommandResponseRemote; }
	QByteArray	 getSourceAddress();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray);
};

#endif // ATCOMMANDRESPONSEREMOTE_H
