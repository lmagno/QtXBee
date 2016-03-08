#ifndef TESTATCOMMAND_H
#define TESTATCOMMAND_H

#include "AutoTest.h"
#include "QXbee.h"

class TestATCommand : public QObject
{
    Q_OBJECT

private slots:
    void frame1();
};

DECLARE_TEST(TestATCommand)

#endif
