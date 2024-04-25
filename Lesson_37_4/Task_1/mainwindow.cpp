#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addition()
{
    int res = ui->num_1->text().toInt() + ui->num_2->text().toInt();
    ui->result->setText(QString::number(res));

}

void MainWindow::subtraction()
{
    int res = ui->num_1->text().toInt() - ui->num_2->text().toInt();
    ui->result->setText(QString::number(res));
}

void MainWindow::multiplication()
{
    int res = ui->num_1->text().toInt() * ui->num_2->text().toInt();
    ui->result->setText(QString::number(res));
}

void MainWindow::division()
{
    if(ui->num_2->text().toInt()){
        int res = ui->num_1->text().toInt() / ui->num_2->text().toInt();
        ui->result->setText(QString::number(res));
    } else {
        ui->result->setText("ERROR");
    }

}

