#include "operand.h"

Operand::Operand(QObject *parent)
    : QObject{parent}, m_dizaine(0), m_unite(0)
{
    generate_number();
}

int Operand::get_complete_value()
{
    return (QString::number(m_dizaine) + QString::number(m_unite)).toInt();
}

void Operand::generate_number()
{
    m_dizaine = QRandomGenerator::global()->bounded(9);
    m_unite = QRandomGenerator::global()->bounded(9);
}

int Operand::get_dizaine() const
{
    return m_dizaine;
}

int Operand::get_unite() const
{
    return m_unite;
}
