#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H

#include <QApplication>
#include <QPaintEvent>
#include <QWidget>
#include <QPainter>
#include <QSlider>
#include <QSize>

class CircleWidget : public QWidget
{
    Q_OBJECT
public:

    CircleWidget(QWidget *parent = 0);

    QPixmap getCurrentCircle();

public slots:
    void setGreen();
    void setYellow();
    void setRed();
    QSize minimumSizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap mCurrentCircle;
    QPixmap mCircleRed;
    QPixmap mCircleYellow;
    QPixmap mCircleGreen;
};


#endif // CIRCLEWIDGET_H
