#ifndef TESTTRANSMITSTATUS_H
#define TESTTRANSMITSTATUS_H

#include "AutoTest.h"
#include "QXBee.h"

class TestTransmitStatus : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
};

DECLARE_TEST(TestTransmitStatus)

#endif // TESTTRANSMITSTATUS_H
