#ifndef ATCOMMANDQUEUEPARAM_H
#define ATCOMMANDQUEUEPARAM_H
#include "atcommand.h"

class ATCommandQueueParam : public ATCommand
{
public:
    explicit ATCommandQueueParam(QObject *parent);
};

#endif // ATCOMMANDQUEUEPARAM_H
