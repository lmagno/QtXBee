#ifndef TESTATCOMMANDRESPONSE_H
#define TESTATCOMMANDRESPONSE_H

#include "AutoTest.h"
#include "QXBee.h"

class TestATCommandResponse : public QObject
{
    Q_OBJECT

private slots:
    void frameDataWithoutParameter();
    void frameDataWithParameter();
};

DECLARE_TEST(TestATCommandResponse)

#endif // TESTATCOMMANDRESPONSE_H
