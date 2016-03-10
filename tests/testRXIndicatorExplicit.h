#ifndef TESTRXINDICATOREXPLICIT_H
#define TESTRXINDICATOREXPLICIT_H

#include "AutoTest.h"
#include "QXBee.h"

class TestRXIndicatorExplicit : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
	void frameDataWithPayload();
};

DECLARE_TEST(TestRXIndicatorExplicit)

#endif // TESTRXINDICATOREXPLICIT_H
