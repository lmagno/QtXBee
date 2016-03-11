#ifndef TESTATCOMMANDREMOTE_H
#define TESTATCOMMANDREMOTE_H

#include "AutoTest.h"
#include "QXBee.h"

class TestATCommandRemote : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
    void frameDataWithParameter();
};

DECLARE_TEST(TestATCommandRemote)

#endif // TESTATCOMMANDREMOTE_H
