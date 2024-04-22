#include "imagebutton.h"

ImageButton::ImageButton() = default;

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("Стоп");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mBottonUpPixmap = QPixmap("../Test_3/red_button_up.png");
    mBottonDownPixmap = QPixmap("../Test_3/red_button_down.png");
    mCurrentBottonPixmap = mBottonUpPixmap;
    setGeometry(mCurrentBottonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentBottonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}

void ImageButton::setUp()
{
    mCurrentBottonPixmap = mBottonUpPixmap;
    update();
}

void ImageButton::setDown()
{
    mCurrentBottonPixmap = mBottonDownPixmap;
    update();
    QTimer::singleShot(200, this, &ImageButton::setUp);
}
