#include "testRXIndicator.h"

void TestRXIndicator::frameData()
{
	QByteArray frame = QByteArray::fromHex("90FFFFFFFFFFFFFFFFFFFE01");
	RXIndicator at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestRXIndicator::frameDataWithPayload()
{
	QByteArray frame = QByteArray::fromHex("90FFFFFFFFFFFFFFFFFFFE01424C41564C410A");
	RXIndicator at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
