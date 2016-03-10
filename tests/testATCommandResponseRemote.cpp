#include "testATCommandResponseRemote.h"

void TestATCommandResponseRemote::frameData() {
	QByteArray frame = QByteArray::fromHex("97010000000000000000FFFE4E4400");
	ATCommandResponseRemote at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}

void TestATCommandResponseRemote::frameDataWithPayload() {
	QByteArray frame = QByteArray::fromHex("9701001200AA00C40002FFFE4E4400424C41424C41424C41");
	ATCommandResponseRemote at;

	at.setFrameData(frame);
	QCOMPARE(at.getFrameData(), frame);
}
