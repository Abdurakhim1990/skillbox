#include "circlewidget.h"

CircleWidget::CircleWidget(QWidget *parent) : QWidget(parent)
{
    setParent(parent);
    //setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mCircleGreen = QPixmap("../Task_1/png/green.png");
    mCircleYellow = QPixmap("../Task_1/png/yellow.png");
    mCircleRed = QPixmap("../Task_1/png/red.png");
    mCurrentCircle = mCircleGreen;
    setGeometry(mCurrentCircle.rect());
    setFixedSize(200, 200);

    QPainter painter(this);
}

QPixmap CircleWidget::getCurrentCircle()
{
    return mCurrentCircle;
}

void CircleWidget::setGreen()
{
    mCurrentCircle = mCircleGreen;
    update();
}

void CircleWidget::setYellow()
{
    mCurrentCircle = mCircleYellow;
    update();
}

void CircleWidget::setRed()
{
    mCurrentCircle = mCircleRed;
    update();
}

QSize CircleWidget::minimumSizeHint() const
{
    return QSize(100, 100);
}

void CircleWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(event->rect(), this->mCurrentCircle);
}
