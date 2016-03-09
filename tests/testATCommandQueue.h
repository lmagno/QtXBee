#ifndef TESTATCOMMANDQUEUE_H
#define TESTATCOMMANDQUEUE_H

#include "AutoTest.h"
#include "QXBee.h"

class TestATCommandQueue : public QObject
{
    Q_OBJECT

private slots:
    void frameDataWithoutParameter();
};

DECLARE_TEST(TestATCommand)

#endif
