#ifndef NODEIDENTIFICATIONINDICATOR_H
#define NODEIDENTIFICATIONINDICATOR_H

#include <QByteArray>
#include <QString>

#include "XBeeFrame.h"

class NodeIdentificationIndicator : public XBeeFrame
{
	QByteArray sourceAddress;
	unsigned char receiveOptions;
	QByteArray remoteAddress;
	QString niString;
	unsigned char deviceType;
	unsigned char sourceEvent;
	QByteArray profileID;
	QByteArray manufaccturerID;
	QByteArray ddValue;
	unsigned char rssiValue;
protected:
	void setSourceAddress(QByteArray);
	void setReceiveOptions(unsigned char);
	void setRemoteAddress(QByteArray);
	void setNIString(QString);
	void setDeviceType(unsigned char);
	void setSourceEvent(unsigned char);
	void setProfileID(QByteArray);
	void setManufacturerID(QByteArray);
	void setDDValue(QByteArray);
	void setRSSI(unsigned char);
public:
	virtual unsigned char getFrameType() const { return pNodeIdentificationIndicator; }
	NodeIdentificationIndicator();
	QByteArray getSourceAddress();
	unsigned char getReceiveOptions();
	QByteArray getRemoteAddress();
	QString getNIString();
	unsigned char getDeviceType();
	unsigned char getSourceEvent();
	QByteArray getProfileID();
	QByteArray getManufacturerID();
	QByteArray getDDValue();
	unsigned char getRSSI();
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // NODEIDENTIFICATIONINDICATOR_H
