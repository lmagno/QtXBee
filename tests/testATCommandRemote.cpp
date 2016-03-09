#include "testATCommandRemote.h"

void TestATCommandRemote::frameDataWithoutParameter()
{
    QByteArray frame = QByteArray::fromHex("1701000000000000FFFFFFFE024E44");
    ATCommandRemote at;

    at.setFrameData(frame);
    QCOMPARE(at.getFrameData(), frame);
}

void TestATCommandRemote::frameDataWithParameter()
{
    QByteArray frame = QByteArray::fromHex("1701000000000000FFFFFFFE024E4431323334");
    ATCommandRemote at;

    at.setFrameData(frame);
    QCOMPARE(at.getFrameData(), frame);
}
