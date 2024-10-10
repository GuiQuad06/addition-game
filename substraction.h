#ifndef SUBSTRACTION_H
#define SUBSTRACTION_H

#include "operation.h"

class Substraction : public Operation
{
public:
    explicit Substraction(QObject *parent = nullptr);

    int process(int a, int b) override { return a - b; }
};

#endif // SUBSTRACTION_H
