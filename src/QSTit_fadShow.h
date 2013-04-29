/*
    This file is part of Qstit
   ═════════════════════════════════════════════════════════════════
    Qstit is developed by Nova Cinema, Brussels - http://www.nova-cinema.org
    Feedback, comments and questions are welcome: subtitles@nova-cinema.org
   ═════════════════════════════════════════════════════════════════
    Programming: Georges Piedboeuf-Boen - georges.pi.bo@gmail.com
   ═════════════════════════════════════════════════════════════════
    Icons credit: Nova & Axialis Team - http://www.axialis.com/free/icons
   ═════════════════════════════════════════════════════════════════
    Qstit is a free software: you can redistribute it and/or modify it under the terms
    of the GNU General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version.
    If you do, we'd like to hear about it.

    Qstit is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
    without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Qstit.
    If not, see http://www.gnu.org/licenses
   ═════════════════════════════════════════════════════════════════
*/

#ifndef FADERWIDGET_H
#define FADERWIDGET_H

#include <QWidget>


class QTimer;

class FaderWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor fadeColor READ fadeColor WRITE setFadeColor)
    Q_PROPERTY(int fadeDuration READ fadeDuration WRITE setFadeDuration)
public:

    FaderWidget(QWidget *parent);

    QColor fadeColor() const { return startColor; }
    void setFadeColor(const QColor &newColor) { startColor = newColor; }

    int fadeDuration() const { return duration; }
    void setFadeDuration(int milliseconds) { duration = milliseconds; }

    void start();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QTimer *timer;
    QColor startColor;
    int currentAlpha;
    int duration;
};

#endif
