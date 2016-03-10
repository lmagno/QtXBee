#ifndef TESTTXREQUEST_H
#define TESTTXREQUEST_H

#include "AutoTest.h"
#include "QXBee.h"

class TestTXRequest : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
	void frameDataWithPayload();
};

DECLARE_TEST(TestTXRequest)

#endif // TESTTXREQUEST_H
