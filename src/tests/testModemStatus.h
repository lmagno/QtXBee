#ifndef TESTMODEMSTATUS_H
#define TESTMODEMSTATUS_H

#include "AutoTest.h"
#include "QXBee.h"

class TestModemStatus : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
};

DECLARE_TEST(TestModemStatus)

#endif // TESTMODEMSTATUS_H
