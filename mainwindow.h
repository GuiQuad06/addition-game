#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QRandomGenerator>

#include "operand.h"
#include "operation.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void action_quitter();
    void action_add();
    void action_sub();
    void generate_exo();
    void test_result();

private:
    Ui::MainWindow *ui;

    std::vector<std::unique_ptr<Operand>> m_v_operand;

    std::unique_ptr<Operation> m_ope = nullptr; // Pointer to Operation (base class)

    int m_expected_result;
    int m_result;
};
#endif // MAINWINDOW_H
