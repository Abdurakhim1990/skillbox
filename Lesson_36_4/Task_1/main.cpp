#include "mainwindow.h"
#include <QApplication>

#include <QPaintEvent>
#include <QWidget>
#include <QPainter>
#include <QSlider>
#include <QPixmap>
#include <QVBoxLayout>
#include <QGridLayout>
#include "circlewidget.h"
#include <iostream>
#include <QObject>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QWidget w;
    QSlider slider(&w);
    CircleWidget circle(&w);

    w.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    slider.setOrientation(Qt::Horizontal);
    slider.setMinimum(0);
    slider.setMaximum(100);
    slider.resize(250, 20);
    slider.move(50, 300);
    slider.setValue(10);

    w.setFixedSize(220, 250);

    QObject::connect(&slider, &QSlider::valueChanged, [&slider, &circle](int newValue){
        if(newValue <= 33) circle.setGreen();
        else if(newValue <= 66) circle.setYellow();
        else circle.setRed();
    });

    QGridLayout *layout = new QGridLayout(&w);
    layout->addWidget(&circle);
    layout->addWidget(&slider);

    circle.show();
    slider.show();
    w.show();
    return a.exec();
}
