/*
    ═══════════════════════════════════════════════════════════════════════════
    This file is part of QSTit.
    Feedback, comments and questions are welcome:
    subtitles@nova-cinema.org

    QSTit is a free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version. If you do, we'd like to hear about it.

    QSTit is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QSTit. If not, see <http://www.gnu.org/licenses/>
    ═══════════════════════════════════════════════════════════════════════════
*/

#include "QSTit_diaButt.h"

butToolC::butToolC(QWidget *pPare,QPixmap pIcon,QString pText,bool pAuto) : QToolButton(pPare)
{
    int iSize;
    int iWidt;

    if (pText.left(1)=="L") iSize=35;
    if (pText.left(1)=="M") iSize=28;
    if (pText.left(1)=="S") iSize=17;
    iWidt=iSize;
    if (pText.left(1)=="R") {iSize=35; iWidt=65;}

    this->setIcon(pIcon);
    this->setText(pText.mid(1));
    this->setStyleSheet("border:none;");
    this->setContentsMargins(0,0,0,0);
    this->resize(iWidt,iSize);
    this->setIconSize(QSize(iWidt-3,iSize-3));
    this->setAutoRepeat(pAuto);
    if (pAuto)
    {
        this->setAutoRepeatInterval(50);
        this->setAutoRepeatDelay(200);
    }
}
bool butToolC::event(QEvent *e)
{
    if (e->type()==QEvent::ToolTip)
    {
        QHelpEvent *helpEvent=static_cast<QHelpEvent *>(e);
        QToolTip::showText(helpEvent->globalPos(),this->text());
        return true;
    }
    return QWidget::event(e);
}
void butToolC::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_Escape:    break;
        case Qt::Key_Return:    break;
        case Qt::Key_Enter:     break;
        case Qt::Key_Space:
            if (e->modifiers()==Qt::NoModifier)
            {
                QApplication::sendEvent(this,new QKeyEvent(QEvent::KeyPress,Qt::Key_Down,Qt::NoModifier,"",false,1));
                break;
            }
            if (e->modifiers()==Qt::ShiftModifier)
            {
                QApplication::sendEvent(this,new QKeyEvent(QEvent::KeyPress,Qt::Key_Up,Qt::NoModifier,"",false,1));
                break;
            }
        default: QToolButton::keyPressEvent(e);
    }
}

//-------------------------------------------------------------------------------------------------

butToolX::butToolX(QWidget *wParent) : QToolButton(wParent)
{
    this->resize(17,17);
    this->setStyleSheet("border:none;");
    this->setContentsMargins(0,0,0,0);
    this->setIconSize(QSize(16,16));
    this->setAutoRepeat(true);
    this->setAutoRepeatInterval(50);
    this->setAutoRepeatDelay(200);
}
bool butToolX::event(QEvent *e)
{
    if (e->type()==QEvent::ToolTip)
    {
        QHelpEvent *helpEvent=static_cast<QHelpEvent *>(e);
        QToolTip::showText(helpEvent->globalPos(),this->text());
        return true;
    }
    return QWidget::event(e);
}
void butToolX::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_Escape:    break;
        case Qt::Key_Return:    break;
        case Qt::Key_Enter:     break;
        case Qt::Key_Space:
            if (e->modifiers()==Qt::NoModifier)
            {
                QApplication::sendEvent(this,new QKeyEvent(QEvent::KeyPress,Qt::Key_Down,Qt::NoModifier,"",false,1));
                break;
            }
            if (e->modifiers()==Qt::ShiftModifier)
            {
                QApplication::sendEvent(this,new QKeyEvent(QEvent::KeyPress,Qt::Key_Up,Qt::NoModifier,"",false,1));
                break;
            }
        default: QToolButton::keyPressEvent(e);
    }
}

//-------------------------------------------------------------------------------------------------

butToolG::butToolG(QWidget *pPare,QPixmap pIcon,int pSize,QString pText,bool pAuto) : QToolButton(pPare)
{
    this->setIcon(pIcon);
    this->setText(pText);
    this->setStyleSheet("border:none;");
    this->setContentsMargins(0,0,0,0);
    this->resize(pSize,pSize);
    this->setIconSize(QSize(pSize,pSize));
    this->setAutoRepeat(pAuto);
    if (pAuto)
    {
        this->setAutoRepeatInterval(50);
        this->setAutoRepeatDelay(200);
    }
}
bool butToolG::event(QEvent *e)
{
    if (e->type()==QEvent::ToolTip)
    {
        QHelpEvent *helpEvent=static_cast<QHelpEvent *>(e);
        QToolTip::showText(helpEvent->globalPos(),this->text());
        return true;
    }
    return QWidget::event(e);
}
void butToolG::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_Escape:    break;
        case Qt::Key_Return:    break;
        case Qt::Key_Enter:     break;
        case Qt::Key_Space:
            if (e->modifiers()==Qt::NoModifier)
            {
                QApplication::sendEvent(this,new QKeyEvent(QEvent::KeyPress,Qt::Key_Down,Qt::NoModifier,"",false,1));
                break;
            }
            if (e->modifiers()==Qt::ShiftModifier)
            {
                QApplication::sendEvent(this,new QKeyEvent(QEvent::KeyPress,Qt::Key_Up,Qt::NoModifier,"",false,1));
                break;
            }
        default: QToolButton::keyPressEvent(e);
    }
}
