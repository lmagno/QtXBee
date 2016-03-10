#ifndef TESTATCOMMANDQUEUE_H
#define TESTATCOMMANDQUEUE_H

#include "AutoTest.h"
#include "QXBee.h"

class TestATCommandQueue : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
	void frameDataWithParameter();
};

DECLARE_TEST(TestATCommandQueue)

#endif // TESTATCOMMANDQUEUE_H
