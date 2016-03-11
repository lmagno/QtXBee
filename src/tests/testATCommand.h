#ifndef TESTATCOMMAND_H
#define TESTATCOMMAND_H

#include "AutoTest.h"
#include "QXBee.h"

class TestATCommand : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
	void frameDataWithParameter();
};

DECLARE_TEST(TestATCommand)

#endif // TESTATCOMMAND_H
