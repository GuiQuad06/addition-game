#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("S'amuser avec les addiions");

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
    m_v_operand = new QVector<Operand>(2);
    m_operand = new QVector<int>(2);

    ui->label_dizaine_a->setText(QString::number(m_v_operand->at(0).get_dizaine()));
    ui->label_unite_a->setText(QString::number(m_v_operand->at(0).get_unite()));
    ui->label_dizaine_b->setText(QString::number(m_v_operand->at(1).get_dizaine()));
    ui->label_unite_b->setText(QString::number(m_v_operand->at(1).get_unite()));
}
