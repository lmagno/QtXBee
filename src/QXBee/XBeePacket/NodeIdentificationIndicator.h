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
	void		 setSourceAddress64(QByteArray address);
	void		 setSourceAddress16(QByteArray address);
	void		 setReceiveOptions(uint8_t options);
	void		 setRemoteAddress64(QByteArray address);
	void		 setRemoteAddress16(QByteArray address);
	void		 setNIString(QString name);
	void		 setParentAddress16(QByteArray address);
	void		 setDeviceType(uint8_t type);
	void		 setSourceEvent(uint8_t event);
	void		 setProfileID(QByteArray id);
	void		 setManufacturerID(QByteArray id);
	void		 setDeviceTypeID(QByteArray id);
	void		 setRSSI(QByteArray rssi);

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

	void		 setFrameData(QByteArray data);
	virtual		 ~NodeIdentificationIndicator();
};

#endif // NODEIDENTIFICATIONINDICATOR_H
