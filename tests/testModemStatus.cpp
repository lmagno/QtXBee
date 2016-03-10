#include "testModemStatus.h"

void TestModemStatus::frameData()
{
	QByteArray frame = QByteArray::fromHex("8A06");
	ModemStatus at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
