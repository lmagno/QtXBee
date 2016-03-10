#ifndef TESTNODEIDENTIFICATIONINDICATOR_H
#define TESTNODEIDENTIFICATIONINDICATOR_H

#include "AutoTest.h"
#include "QXBee.h"

class TestNodeIdentificationIndicator : public QObject
{
    Q_OBJECT

private slots:
	void frameData();
	void frameDataWithDeviceTypeID();
	void frameDataWithRSSI();
	void frameDataWithDeviceTypeIDandRSSI();
};

DECLARE_TEST(TestNodeIdentificationIndicator)

#endif // TESTNODEIDENTIFICATIONINDICATOR_H
