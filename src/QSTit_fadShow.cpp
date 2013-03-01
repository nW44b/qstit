#include <QtGui>
#include "QSTit_fadShow.h"

FaderWidget::FaderWidget(QWidget *parent)
    : QWidget(parent)
{
    if (parent)
        startColor = parent->palette().window().color();
    else
        startColor = Qt::white;

    currentAlpha = 0;
    duration = 2000;

    timer = new QTimer(this);
    timer->setInterval(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    setAttribute(Qt::WA_DeleteOnClose);
    resize(parent->size());
}

void FaderWidget::start()
{
    currentAlpha = 0;
    timer->start();
    show();
}

void FaderWidget::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    QColor semiTransparentColor = startColor;
    semiTransparentColor.setAlpha(currentAlpha);
    painter.fillRect(rect(), semiTransparentColor);

    currentAlpha += 255 * timer->interval() / duration;
    if (currentAlpha >= 255)
    {
        timer->stop();
        hide();
        close();
    }
}
