#include "operand.h"

Operand::Operand(QObject *parent) : QObject{ parent }, m_value(0), m_dizaine(0), m_unite(0)
{
    generate_number();
}

uint Operand::get_complete_value() const
{
    return m_value;
}

void Operand::generate_number()
{
    m_value = QRandomGenerator::global()->bounded(49);

    QString tmp = QString::number(m_value);
    uint len = tmp.size();

    if (len < 1 || len > 2) {
        return;
    } else if (len < 2) {
        m_unite = QString::number(m_value).at(len - 1);
        m_dizaine = '0';
    } else {
        m_unite = QString::number(m_value).at(len - 1);
        m_dizaine = QString::number(m_value).at(len - 2);
    }
}

uint Operand::get_dizaine() const
{
    return m_dizaine.digitValue();
}

uint Operand::get_unite() const
{
    return m_unite.digitValue();
}
