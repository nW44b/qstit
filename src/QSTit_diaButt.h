/*
    This file is part of Qstit - http://subtitles.nova-cinema.org
    Feedback, comments and questions are welcome: subtitles@nova-cinema.org
   ════════════════════════════════════════════════════════════════════════════════════
    Qstit is developed by Nova Cinema, Brussels - http://www.nova-cinema.org
    Conception: Laurent Tenzer
    Programming: Georges Piedboeuf-Boen - georges.pi.bo@gmail.com
    Icons credit: Nova & Axialis Team - http://www.axialis.com/free/icons
   ════════════════════════════════════════════════════════════════════════════════════
    Qstit is a free software: you can redistribute it and/or modify it under the terms
    of the GNU General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version.
    If you do, we'd like to hear about it.

    Qstit is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
    PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Qstit.
    If not, see http://www.gnu.org/licenses
   ════════════════════════════════════════════════════════════════════════════════════
*/

#ifndef H_TOOLBUTT
#define H_TOOLBUTT

#include <QApplication>
#include <QToolButton>
#include <QToolTip>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QKeyEvent>
#include <QEvent>

class butDspi : public QDoubleSpinBox
{
    Q_OBJECT

    public:
        butDspi(QWidget*,int,int,double,double,double,double,int);
    private:
        QWidget *parWin;
    protected:
        virtual void keyPressEvent(QKeyEvent*);
};
class butSpin : public QSpinBox
{
    Q_OBJECT

    public:
        butSpin(QWidget*,int,int,int,int,int,int);
    private:
        QWidget *parWin;
    protected:
        virtual void keyPressEvent(QKeyEvent*);
};
class butToolC : public QToolButton
{
    Q_OBJECT

    public:
        butToolC(QWidget*,QPixmap,QString,bool);
    protected:
        virtual void keyPressEvent(QKeyEvent*);
        bool event(QEvent*);
};
class butToolX : public QToolButton
{
    Q_OBJECT

    public:
        butToolX(QWidget*);
    protected:
        virtual void keyPressEvent(QKeyEvent*);
        bool event(QEvent*);
};

#endif
