#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <algorithm>

#define NB_OF_OPERANDS 2

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("S'amuser avec les additions");

    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(action_quitter()));
    connect(ui->pushButton_generateExo, SIGNAL(clicked()), this, SLOT(generate_exo()));
    connect(ui->pushButton_submit, SIGNAL(clicked()), this, SLOT(test_result()));
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
    m_v_operand.clear();

    for (uint i = 0; i < NB_OF_OPERANDS; i++)
        m_v_operand.push_back(std::make_unique<Operand>(this));

    // Sort using a custom comparator (to avoid negative number with substractions)
    std::sort(m_v_operand.begin(), m_v_operand.end(),
              [](const std::unique_ptr<Operand> &a, const std::unique_ptr<Operand> &b) {
                  return a->get_complete_value() > b->get_complete_value();
              });

    // Update UI with the generated Operand objects
    ui->label_dizaine_a->setText(QString::number(m_v_operand.at(0)->get_dizaine()));
    ui->label_unite_a->setText(QString::number(m_v_operand.at(0)->get_unite()));
    ui->label_dizaine_b->setText(QString::number(m_v_operand.at(1)->get_dizaine()));
    ui->label_unite_b->setText(QString::number(m_v_operand.at(1)->get_unite()));
}

void MainWindow::test_result()
{
    QMessageBox msg;

    int expected_result =
            m_v_operand.at(0)->get_complete_value() + m_v_operand.at(1)->get_complete_value();

    int result = (ui->lineEdit_dizaine_res->text() + ui->lineEdit_unite_res->text()).toUInt();

    if (result != expected_result) {
        msg.setIcon(QMessageBox::Critical);
        msg.setText("Oups... C'est pas gave Recommence :)");
        msg.exec();
    } else {
        msg.setIcon(QMessageBox::Information);
        msg.setText("Bravo mon Enfant :)");
        msg.exec();
    }

    ui->lineEdit_dizaine_res->clear();
    ui->lineEdit_unite_res->clear();
}
