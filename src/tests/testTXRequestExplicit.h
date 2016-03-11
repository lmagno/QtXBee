#ifndef TESTTXREQUESTEXPLICIT_H
#define TESTTXREQUESTEXPLICIT_H

#include "AutoTest.h"
#include "QXBee.h"

class TestTXRequestExplicit : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
	void frameDataWithPayload();
};

DECLARE_TEST(TestTXRequestExplicit)

#endif // TESTTXREQUESTEXPLICIT_H
