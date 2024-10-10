#ifndef ADDITION_H
#define ADDITION_H

#include "operation.h"

class Addition : public Operation
{
public:
    explicit Addition(QObject *parent = nullptr);

    int process(int a, int b) override { return a + b; }
};

#endif // ADDITION_H
