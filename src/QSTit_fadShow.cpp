/*
    This file is part of Qstit
   ══════════════════════════════════════════════════════════════
    Qstit is developed by Nova Cinema, Brussels - http://www.nova-cinema.org
    Feedback, comments and questions are welcome: subtitles@nova-cinema.org
   ══════════════════════════════════════════════════════════════
    Conception: Georges Piedboeuf-Boen & Laurent Tenzer
    Programming: Georges Piedboeuf-Boen - georges.pi.bo@gmail.com
   ══════════════════════════════════════════════════════════════
    Icons credit: Nova & Axialis Team - http://www.axialis.com/free/icons
   ══════════════════════════════════════════════════════════════
    Qstit is a free software: you can redistribute it and/or modify it under the terms
    of the GNU General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version.
    If you do, we'd like to hear about it.

    Qstit is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
    PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Qstit.
    If not, see http://www.gnu.org/licenses
   ══════════════════════════════════════════════════════════════
*/

#include <QtGui>
#include "QSTit_fadShow.h"

FaderWidget::FaderWidget(QWidget *parent) : QWidget(parent)
{
    if (parent) startColor=parent->palette().window().color();
    else startColor=Qt::white;

    currentAlpha=0;
    duration=2000;

    timer = new QTimer(this);
    timer->setInterval(50);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    setAttribute(Qt::WA_DeleteOnClose);
    resize(parent->size());
}
void FaderWidget::start() {currentAlpha=0;timer->start();show();}

void FaderWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor semiTransparentColor=startColor;
    semiTransparentColor.setAlpha(currentAlpha);
    painter.fillRect(rect(),semiTransparentColor);

    currentAlpha += 255 * timer->interval() / duration;
    if (currentAlpha>=255) {timer->stop();hide();close();}
}
