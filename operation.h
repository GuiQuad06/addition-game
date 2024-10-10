#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>

class Operation : public QObject
{
    Q_OBJECT
public:
    explicit Operation(QObject *parent = nullptr);

    virtual int process(int a, int b) = 0;

signals:
};

#endif // OPERATION_H
