#include "testATCommand.h"

void TestATCommand::frame1()
{
    QByteArray frame = QByteArray::fromHex("08014E44");
    ATCommand at;

    at.setFrameData(frame);
    QCOMPARE(at.getFrameData(), frame);
}
