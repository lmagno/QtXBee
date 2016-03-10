#include "testTXRequestExplicit.h"

void TestTXRequestExplicit::frameData()
{
	QByteArray frame = QByteArray::fromHex("11010000000000000000FFFEE8E80011C1050000");
	TXRequestExplicit at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestTXRequestExplicit::frameDataWithPayload()
{
	QByteArray frame = QByteArray::fromHex("11010000000000000000FFFEE8E80011C1050000776463657165");
	TXRequestExplicit at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
