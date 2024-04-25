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

void MainWindow::bt_0()
{
    selectChannel(0);
}

void MainWindow::bt_1()
{
    selectChannel(1);
}

void MainWindow::bt_2()
{
    selectChannel(2);
}

void MainWindow::bt_3()
{
    selectChannel(3);
}

void MainWindow::bt_4()
{
    selectChannel(4);
}

void MainWindow::bt_5()
{
    selectChannel(5);
}

void MainWindow::bt_6()
{
    selectChannel(6);
}

void MainWindow::bt_7()
{
    selectChannel(7);
}

void MainWindow::bt_8()
{
    selectChannel(8);
}

void MainWindow::bt_9()
{
    selectChannel(9);
}

void MainWindow::btChUp()
{
    ++channel %= 100;
    displayChannel();
}

void MainWindow::btChDw()
{
    --channel;
    if(channel < 0)
        channel = 99;
    displayChannel();
}

void MainWindow::btVolUp()
{
    volume += 10;
    if(volume > 100)
        volume = 100;
    ui->sliderVolume->setValue(volume);
}

void MainWindow::btVolDw()
{
    volume -= 10;
    if(volume < 0)
        volume = 0;
    ui->sliderVolume->setValue(volume);
}

void MainWindow::displayChannel()
{
    ui->textChannel->setText("Channel "+ QString::number(channel));
    delay = true;
}

void MainWindow::displayDelayChannel()
{
    ui->textChannel->setText("Channel -"+ QString::number(channel));
}

void MainWindow::selectChannel(int ch)
{
    if(delay){
        channel = ch;
        displayDelayChannel();
        QTimer::singleShot(1500, this, &MainWindow::displayChannel);
        delay = false;
    } else {
        channel *= 10;
        channel += ch;
        displayChannel();
        delay = true;
    }
}

