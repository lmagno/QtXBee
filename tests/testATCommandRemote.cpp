#include "testATCommandRemote.h"

void TestATCommandRemote::frameData()
{
    // Without parameter
    QByteArray frame = QByteArray::fromHex("1701000000000000FFFFFFFE024E44");
    ATCommandRemote at;
    at.setFrameData(frame);
    QCOMPARE(at.getFrameData(), frame);

    // With parameter
    frame = QByteArray::fromHex("1701000000000000FFFFFFFE024E4431323334");
    at.setFrameData(frame);
    QCOMPARE(at.getFrameData(), frame);
}
