#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QVector>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

typedef struct {
    int dizaine;
    int unite;
} operand_t;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void action_quitter();
    void generate_exo();

private:
    Ui::MainWindow *ui;

    QVector<operand_t> *m_v_operand;
    QVector<int> * m_operand;

};
#endif // MAINWINDOW_H
