#include "testRXIndicatorExplicit.h"

void TestRXIndicatorExplicit::frameData()
{
	QByteArray frame = QByteArray::fromHex("91FFFFFFFFFFFFFFFFFFFE00000000000001");
	RXIndicatorExplicit at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestRXIndicatorExplicit::frameDataWithPayload()
{
	QByteArray frame = QByteArray::fromHex("91FFFFFFFFFFFFFFFFFFFE000000000000016461736466615344");
	RXIndicatorExplicit at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
