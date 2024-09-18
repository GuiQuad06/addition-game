#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QVector>

#include "operand.h"

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
    void generate_exo();
    void test_result();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<QVector<Operand>> m_v_operand;
    std::unique_ptr<QVector<uint>> m_operand;

};
#endif // MAINWINDOW_H
