#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <iostream>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

class ImageButton : public QPushButton
{
    Q_OBJECT
public:
    ImageButton();
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentBottonPixmap;
    QPixmap mBottonDownPixmap;
    QPixmap mBottonUpPixmap;
    bool isDown = false;

};

#endif // IMAGEBUTTON_H
