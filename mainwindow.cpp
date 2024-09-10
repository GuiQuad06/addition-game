#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("S'amuser avec les addiions");

    m_v_operand = new QVector<operand_t>(2);
    m_operand = new QVector<int>(2);

    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(action_quitter()));
    connect(ui->pushButton_generateExo, SIGNAL(clicked()), this, SLOT(generate_exo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::action_quitter()
{
    QCoreApplication::quit();
}

void MainWindow::generate_exo()
{
    QVector<operand_t>::iterator it;

    for (it = m_v_operand->begin(); it != m_v_operand->end(); ++it) {
        it->dizaine = QRandomGenerator::global()->bounded(9);
        it->unite = QRandomGenerator::global()->bounded(9);
    }

    ui->label_dizaine_a->setText(QString::number(m_v_operand->at(0).dizaine));
    ui->label_unite_a->setText(QString::number(m_v_operand->at(0).unite));
    ui->label_dizaine_b->setText(QString::number(m_v_operand->at(1).dizaine));
    ui->label_unite_b->setText(QString::number(m_v_operand->at(1).unite));
}
