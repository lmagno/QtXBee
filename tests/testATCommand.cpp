#include "testATCommand.h"

void TestATCommand::frameDataWithoutParameter()
{
	QByteArray frame = QByteArray::fromHex("08014E44");
	ATCommand at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestATCommand::frameDataWithParameter()
{
	QByteArray frame = QByteArray::fromHex("08014E444023245246406632");
	ATCommand at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
