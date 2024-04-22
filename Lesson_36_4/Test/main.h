#ifndef MAIN_H
#define MAIN_H

#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QTimer>

class Printer : public QObject
{
    Q_OBJECT
public:
    Printer(QWidget *parent = nullptr);

public slots:
    void printFinished();
};

#endif // MAIN_H
