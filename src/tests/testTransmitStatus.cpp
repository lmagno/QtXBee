#include "testTransmitStatus.h"

void TestTransmitStatus::frameData()
{
	QByteArray frame = QByteArray::fromHex("8B010000000000");
	TransmitStatus at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
