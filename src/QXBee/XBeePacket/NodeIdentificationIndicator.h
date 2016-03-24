#ifndef NODEIDENTIFICATIONINDICATOR_H
#define NODEIDENTIFICATIONINDICATOR_H

#include <QByteArray>
#include <QString>

#include "XBeePacket.h"

class NodeIdentificationIndicator : public XBeePacket
{
	QByteArray	 sourceAddress64;
	QByteArray	 sourceAddress16;
	uint8_t		 receiveOptions;
	QByteArray	 remoteAddress64;
	QByteArray	 remoteAddress16;
	QString		 niString;
	QByteArray	 parentAddress16;
	uint8_t		 deviceType;
	uint8_t		 sourceEvent;
	QByteArray	 profileID;
	QByteArray	 manufaccturerID;
	QByteArray	 deviceTypeID;
	QByteArray	 rssiValue;

protected:
	void		 setSourceAddress64(QByteArray);
	void		 setSourceAddress16(QByteArray);
	void		 setReceiveOptions(uint8_t);
	void		 setRemoteAddress64(QByteArray);
	void		 setRemoteAddress16(QByteArray);
	void		 setNIString(QString);
	void		 setParentAddress16(QByteArray);
	void		 setDeviceType(uint8_t);
	void		 setSourceEvent(uint8_t);
	void		 setProfileID(QByteArray);
	void		 setManufacturerID(QByteArray);
	void		 setDeviceTypeID(QByteArray);
	void		 setRSSI(QByteArray);

public:
	NodeIdentificationIndicator();

	virtual uint8_t getFrameType() const { return FrameType::NodeIdentificationIndicator; }
	QByteArray	 getSourceAddress64();
	QByteArray	 getSourceAddress16();
	uint8_t		 getReceiveOptions();
	QByteArray	 getRemoteAddress64();
	QByteArray	 getRemoteAddress16();
	QString		 getNIString();
	QByteArray	 getParentAddress16();
	uint8_t		 getDeviceType();
	uint8_t		 getSourceEvent();
	QByteArray	 getProfileID();
	QByteArray	 getManufacturerID();
	QByteArray	 getDeviceTypeID();
	QByteArray	 getRSSI();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray);
	virtual		 ~NodeIdentificationIndicator();
};

#endif // NODEIDENTIFICATIONINDICATOR_H
