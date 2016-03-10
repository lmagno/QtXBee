#include "testATCommandQueue.h"

void TestATCommandQueue::frameData()
{
	QByteArray frame = QByteArray::fromHex("09014E44");
	ATCommandQueue at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestATCommandQueue::frameDataWithParameter()
{
	QByteArray frame = QByteArray::fromHex("09014E446C616C616C616C616C61");
	ATCommandQueue at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
