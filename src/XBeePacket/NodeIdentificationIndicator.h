#ifndef NODEIDENTIFICATIONINDICATOR_H
#define NODEIDENTIFICATIONINDICATOR_H

#include <QByteArray>
#include <QString>

#include "XBeePacket.h"

class NodeIdentificationIndicator : public XBeePacket
{
	QByteArray	 sourceAddress64;
	QByteArray	 sourceAddress16;
	byte		 receiveOptions;
	QByteArray	 remoteAddress64;
	QByteArray	 remoteAddress16;
	QString		 niString;
	QByteArray	 parentAddress16;
	byte		 deviceType;
	byte		 sourceEvent;
	QByteArray	 profileID;
	QByteArray	 manufaccturerID;
	QByteArray	 deviceTypeID;
	QByteArray	 rssiValue;

protected:
	void		 setSourceAddress64(QByteArray);
	void		 setSourceAddress16(QByteArray);
	void		 setReceiveOptions(byte);
	void		 setRemoteAddress64(QByteArray);
	void		 setRemoteAddress16(QByteArray);
	void		 setNIString(QString);
	void		 setParentAddress16(QByteArray);
	void		 setDeviceType(byte);
	void		 setSourceEvent(byte);
	void		 setProfileID(QByteArray);
	void		 setManufacturerID(QByteArray);
	void		 setDeviceTypeID(QByteArray);
	void		 setRSSI(QByteArray);

public:
	NodeIdentificationIndicator();

	virtual byte getFrameType() const { return pNodeIdentificationIndicator; }
	QByteArray	 getSourceAddress64();
	QByteArray	 getSourceAddress16();
	byte		 getReceiveOptions();
	QByteArray	 getRemoteAddress64();
	QByteArray	 getRemoteAddress16();
	QString		 getNIString();
	QByteArray	 getParentAddress16();
	byte		 getDeviceType();
	byte		 getSourceEvent();
	QByteArray	 getProfileID();
	QByteArray	 getManufacturerID();
	QByteArray	 getDeviceTypeID();
	QByteArray	 getRSSI();
	QByteArray	 getFrameData();

	void		 setFrameData(QByteArray);
};

#endif // NODEIDENTIFICATIONINDICATOR_H
