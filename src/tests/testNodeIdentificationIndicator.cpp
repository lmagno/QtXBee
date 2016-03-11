#include "testNodeIdentificationIndicator.h"

void TestNodeIdentificationIndicator::frameData()
{
	QByteArray frame = QByteArray::fromHex("95FFFFFFFFFFFFFFFFFFFE01FFFEFFFFFFFFFFFFFFFF2000FFFE000100000000");
	NodeIdentificationIndicator at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestNodeIdentificationIndicator::frameDataWithDeviceTypeID()
{
	QByteArray frame = QByteArray::fromHex("95FFFFFFFFFFFFFFFFFFFE01FFFEFFFFFFFFFFFFFFFF2000FFFE000100000000AAAAAAAA");
	NodeIdentificationIndicator at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestNodeIdentificationIndicator::frameDataWithRSSI()
{
	QByteArray frame = QByteArray::fromHex("95FFFFFFFFFFFFFFFFFFFE01FFFEFFFFFFFFFFFFFFFF2000FFFE000100000000EE");
	NodeIdentificationIndicator at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestNodeIdentificationIndicator::frameDataWithDeviceTypeIDandRSSI()
{
	QByteArray frame = QByteArray::fromHex("95FFFFFFFFFFFFFFFFFFFE01FFFEFFFFFFFFFFFFFFFF2000FFFE000100000000AAAAAAAAEE");
	NodeIdentificationIndicator at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
