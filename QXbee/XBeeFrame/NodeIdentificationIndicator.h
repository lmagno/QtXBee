#ifndef NODEIDENTIFICATIONINDICATOR_H
#define NODEIDENTIFICATIONINDICATOR_H

#include <QByteArray>
#include <QString>

#include "XBeeFrame.h"

class NodeIdentificationIndicator : public XBeeFrame
{
	QByteArray sourceAddress;
	quint8 receiveOptions;
	QByteArray remoteAddress;
	QString niString;
	quint8 deviceType;
	quint8 sourceEvent;
	QByteArray profileID;
	QByteArray manufaccturerID;
	QByteArray ddValue;
	quint8 rssiValue;
protected:
	void setSourceAddress(QByteArray);
	void setReceiveOptions(quint8);
	void setRemoteAddress(QByteArray);
	void setNIString(QString);
	void setDeviceType(quint8);
	void setSourceEvent(quint8);
	void setProfileID(QByteArray);
	void setManufacturerID(QByteArray);
	void setDDValue(QByteArray);
	void setRSSI(quint8);
public:
	virtual quint8 getFrameType() const { return pNodeIdentificationIndicator; }
	NodeIdentificationIndicator();
	QByteArray getSourceAddress();
	quint8 getReceiveOptions();
	QByteArray getRemoteAddress();
	QString getNIString();
	quint8 getDeviceType();
	quint8 getSourceEvent();
	QByteArray getProfileID();
	QByteArray getManufacturerID();
	QByteArray getDDValue();
	quint8 getRSSI();
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // NODEIDENTIFICATIONINDICATOR_H
