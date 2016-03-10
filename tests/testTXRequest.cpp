#include "testTXRequest.h"

void TestTXRequest::frameData()
{
	QByteArray frame = QByteArray::fromHex("10010000000000000000FFFE0000");
	TXRequest at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestTXRequest::frameDataWithPayload()
{
	QByteArray frame = QByteArray::fromHex("10010000000000000000FFFE000077656671656666");
	TXRequest at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
