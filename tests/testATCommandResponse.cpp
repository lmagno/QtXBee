#include "testATCommandResponse.h"

void TestATCommandResponse::frameDataWithoutParameter() {
	QByteArray frame = QByteArray::fromHex("88014E4403");
	ATCommandResponse at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestATCommandResponse::frameDataWithParameter() {
	QByteArray frame = QByteArray::fromHex("88014E4404426C6168426C6168426C61680A");
	ATCommandResponse at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
