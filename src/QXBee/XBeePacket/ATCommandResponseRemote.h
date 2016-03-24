#ifndef ATCOMMANDRESPONSEREMOTE_H
#define ATCOMMANDRESPONSEREMOTE_H

#include <QByteArray>

#include "ATCommandResponse.h"

class ATCommandResponseRemote : public ATCommandResponse
{
	QByteArray	 sourceAddress64;
	QByteArray	 sourceAddress16;

protected:
	void		 setSourceAddress64(QByteArray);
	void		 setSourceAddress16(QByteArray);

public:
	ATCommandResponseRemote();

	virtual uint8_t getFrameType() const { return FrameType::ATCommandResponseRemote; }
	QByteArray	 getSourceAddress64();
	QByteArray	 getSourceAddress16();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray);
};

#endif // ATCOMMANDRESPONSEREMOTE_H
