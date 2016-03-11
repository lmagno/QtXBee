#ifndef TESTRXINDICATOR_H
#define TESTRXINDICATOR_H

#include "AutoTest.h"
#include "QXBee.h"

class TestRXIndicator : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
	void frameDataWithPayload();
};

DECLARE_TEST(TestRXIndicator)

#endif // TESTRXINDICATOR_H
