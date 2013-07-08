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

#ifndef H_WINSKIN
#define H_WINSKIN

#include <QApplication>
#include <QtGui>
#include <QFrame>

int fCalcPosX(int);
int fCalcPosY(int,QFrame*);
QString fStylFram();
QString fStylTitl();
QString fStylButt();

class rowSkin : public QFrame
{
    Q_OBJECT
    public:
        rowSkin(QWidget *,int,int);
        int     iX,iY,iW,iH;
    private:
        QWidget *parWin;
        int     iCx,iCy;
        int     iPr,iPb,iPm;
    signals:
        void sMoved();
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};
class menuSkin : public QFrame
{
    Q_OBJECT
    public:
        menuSkin(QWidget *,int,int,int,int);
        int     iX,iY,iW,iH;
        bool    bLink;
    private:
        QWidget *parWin;
        int     iCx,iCy;
        int     iPr,iPb,iPm;
    signals:
        void sMoved();
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};
class diaSkin : public QFrame
{
    Q_OBJECT
    public:
        diaSkin(QWidget*,QFrame*,QString,int,int,int,int);
        QLabel  *labTitl;
        void fRePosi();
    private:
        QWidget *parWin;
        QFrame  *parMen;
        int     iCx,iCy;
        int     iPr,iPb,iPm;
    private slots:
        void fGridClos();
    signals:
        void sClosed();
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};
class grpSkin : public QFrame
{
    Q_OBJECT
    public:
        grpSkin(QWidget*,int,int,int,int);
};
class diaExitSkin : public QDialog
{
    Q_OBJECT
    public:
        diaExitSkin(QWidget*,QFrame*,QString,int,int,int,int);
        QLabel  *labTitl;
        void fRePosi();
    private:
        QWidget *parWin;
        QFrame  *parMen;
        int     iCx,iCy;
        int     iPr,iPb,iPm;
    private slots:
        void fGridClos();
    signals:
        void sClosed();
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};
class diaConfSkin : public QDialog
{
    Q_OBJECT
    public:
        diaConfSkin(QWidget*,QFrame*,QString,int,int,int,int);
        QLabel  *labTitl;
        void fRePosi();
    private:
        QWidget *parWin;
        QFrame  *parMen;
        int     iCx,iCy;
        int     iPr,iPb,iPm;
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};
class messSkin : public QDialog
{
    Q_OBJECT
    public:
        bool fMess(QWidget*,QFrame*,QString,QString,QString);
        bool bOk;
    private:
        QWidget*        parWin;
        QFrame*         parMen;
        QLabel*         labMess;
        QPushButton*    bY;
        QPushButton*    bN;
    private slots:
        void fButY();
        void fButN();
};
class diaColoSkin : public QFrame
{
    Q_OBJECT
    public:
        diaColoSkin(QWidget*,QFrame*,QString,QString);
    private:
        QWidget *parWin;
        QFrame  *parMen;
        QColorDialog *diaColo;
        int     iCx,iCy;
        int     iPr,iPb,iPm;
    private slots:
        void fGridClos();
        void fColorGet(QColor);
    signals:
        void sClosed();
        void sColorGet(QColor);
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};
class diaFontSkin : public QFrame
{
    Q_OBJECT
    public:
        diaFontSkin(QWidget*,QFrame*,QString,QFont);
    private:
        QWidget *parWin;
        QFrame  *parMen;
        QFontDialog *diaFont;
        int     iCx,iCy;
        int     iPr,iPb,iPm;
    private slots:
        void fGridClos();
        void fFontGet(QFont);
    signals:
        void sClosed();
        void sFontGet(QFont);
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};
class diaFileSkin : public QFrame
{
    Q_OBJECT
    public:
        diaFileSkin(QWidget*,QFrame*,QString,QString,QString,QString);
    private:
        QWidget *parWin;
        QFrame  *parMen;
        QFileDialog *diaFile;
        int     iCx,iCy;
        int     iPr,iPb,iPm;
    private slots:
        void fGridClos();
        void fFileGet(QString);
    signals:
        void sClosed();
        void sFileGet(QString);
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};
class diaInfoSkin : public QFrame
{
    Q_OBJECT
    public:
        diaInfoSkin(QWidget*,QFrame*,QString,int,int,int,int);
        QLabel*     labTitl;
        QFrame*     fraSizB;
        void fRePosi();
    private:
        QWidget*    parWin;
        QFrame*     parMen;
        int         iX,iY,iW,iH;
        int         iCx,iCy;
        int         iPr,iPb,iPm;
        QFrame*     fraSizT;
        bool        bSizT,bSizB;
        QString     sStylBord;
        void        fGridSizeVert(bool,int);
        void        fGridSizeBord();
    private slots:
        void fGridClos();
    signals:
        void sClosed();
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};
class diaHelpSkin : public QFrame
{
    Q_OBJECT
    public:
        diaHelpSkin(QWidget*,QFrame*,QString,int,int,int,int);
        QLabel*     labTitl;
        QFrame*     fraSizB;
        void fRePosi();
    private:
        QWidget*    parWin;
        QFrame*     parMen;
        int         iX,iY,iW,iH;
        int         iCx,iCy;
        int         iPr,iPb,iPm;
        QFrame*     fraSizT;
        bool        bSizT,bSizB;
        QString     sStylBord;
        void        fGridSizeVert(bool,int);
        void        fGridSizeBord();
    private slots:
        void fGridClos();
    signals:
        void sClosed();
    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void keyPressEvent(QKeyEvent*);
};

#endif
