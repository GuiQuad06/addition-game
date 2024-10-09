#ifndef OPERAND_H
#define OPERAND_H

#include <QObject>
#include <QRandomGenerator>

class Operand : public QObject
{
    Q_OBJECT
public:
    explicit Operand(QObject *parent = nullptr);
    Operand(const Operand &other) = default; // Copy constructor
    Operand &operator=(const Operand &other) = default; // Copy assignment operator

    uint get_complete_value() const;
    void generate_number();
    uint get_dizaine() const;
    uint get_unite() const;

signals:

private:
    uint m_value;
    QChar m_dizaine;
    QChar m_unite;
};

#endif // OPERAND_H
