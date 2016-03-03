#ifndef NODEIDENTIFICATIONINDICATOR_H
#define NODEIDENTIFICATIONINDICATOR_H

#include <QByteArray>
#include <QString>

#include "../typedef.h"
#include "XBeeFrame.h"

class NodeIdentificationIndicator : public XBeeFrame
{
	QByteArray sourceAddress;
	byte receiveOptions;
	QByteArray remoteAddress;
	QString niString;
	byte deviceType;
	byte sourceEvent;
	QByteArray profileID;
	QByteArray manufaccturerID;
	QByteArray ddValue;
	byte rssiValue;
protected:
	void setSourceAddress(QByteArray);
	void setReceiveOptions(byte);
	void setRemoteAddress(QByteArray);
	void setNIString(QString);
	void setDeviceType(byte);
	void setSourceEvent(byte);
	void setProfileID(QByteArray);
	void setManufacturerID(QByteArray);
	void setDDValue(QByteArray);
	void setRSSI(byte);
public:
	virtual byte getFrameType() const { return pNodeIdentificationIndicator; }
	NodeIdentificationIndicator();
	QByteArray getSourceAddress();
	byte getReceiveOptions();
	QByteArray getRemoteAddress();
	QString getNIString();
	byte getDeviceType();
	byte getSourceEvent();
	QByteArray getProfileID();
	QByteArray getManufacturerID();
	QByteArray getDDValue();
	byte getRSSI();
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // NODEIDENTIFICATIONINDICATOR_H
