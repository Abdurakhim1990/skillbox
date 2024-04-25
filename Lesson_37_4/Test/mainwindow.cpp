#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::cout << "Constructor" << std::endl;
}

MainWindow::~MainWindow()
{
    std::cout << "Destructor" << std::endl;
    delete ui;
}

void MainWindow::add0()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "0");
}

void MainWindow::add1()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "1");
}

void MainWindow::add2()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "2");
}

void MainWindow::add3()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3");
}

void MainWindow::add4()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "4");
}

void MainWindow::add5()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "5");
}

void MainWindow::add6()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "6");
}

void MainWindow::add7()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "7");
}

void MainWindow::add8()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "8");
}

void MainWindow::add9()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "9");
}

void MainWindow::makeCall()
{
    ui->lineEdit->setText("CALL!!!");
}

