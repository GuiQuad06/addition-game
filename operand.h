#ifndef OPERAND_H
#define OPERAND_H

#include <QObject>
#include <QRandomGenerator>

class Operand : public QObject
{
    Q_OBJECT
public:
    explicit Operand(QObject *parent = nullptr);

    int get_complete_value();
    void generate_number();
    int get_dizaine() const;
    int get_unite() const;

signals:

private:
    int m_dizaine;
    int m_unite;
};

#endif // OPERAND_H
