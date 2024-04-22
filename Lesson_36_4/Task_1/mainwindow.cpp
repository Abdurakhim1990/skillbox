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

void MainWindow::paintEvent(QPaintEvent *)
{
//    QPainter painter;
//    painter.begin(this);
//    QPen pen;
//    pen.setColor(Qt::red);
//    pen.setStyle(Qt::SolidLine);
//    pen.setWidth(5);

//    QBrush brush;
//    brush.setColor(Qt::blue);
//    brush.setStyle(Qt::SolidPattern);

//    painter.setPen(pen);
//    painter.setBrush(brush);
//    //painter.drawLine(50, 50, 400, 500);
//    //painter.drawRect(50, 50, 400, 500);
//    painter.drawEllipse(50, 50, 500, 500);

//    painter.end();
}

