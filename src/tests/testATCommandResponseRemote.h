#ifndef TESTATCOMMANDRESPONSEREMOTE_H
#define TESTATCOMMANDRESPONSEREMOTE_H

#include "AutoTest.h"
#include "QXBee.h"

class TestATCommandResponseRemote : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
	void frameDataWithPayload();
};

DECLARE_TEST(TestATCommandResponseRemote)

#endif // TESTATCOMMANDRESPONSEREMOTE_H
