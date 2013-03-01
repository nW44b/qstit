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

#ifndef H_WINGRID
#define H_WINGRID

#include <QtGui>
#include <QTableWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <QDialog>

class menuSkin;
class butToolG;

class diaGridSkin : public QFrame
{
    Q_OBJECT

    public:
        diaGridSkin(QWidget*,menuSkin*,QString,int,int);
        QLabel      *labTitl;
        int         iX,iY,iW,iH;
        bool        bLink;
        int         nColo;
        int         iWid3,iWid4,iWid5,iWid6;
        double      dPou3,dPou4,dPou5,dPou6;

        void        fRePosi();
        void        fWorkLang(QStringList,QStringList);
        void        fGridSizeInit(int);
        void        fGridSizeHori(int);
        void        fGridLink();
    private:
        QWidget     *parWin;
        menuSkin    *parMen;
        int         iCx;
        int         iCy;
        int         iPr;
        int         iPb;
        int         iPm;
        QString     sPf;
        QLabel      *labSizV;
        QLabel      *labSizH;
        bool        bSizV;
        bool        bSizH;
        QStringList gLangCode;
        QStringList gLangText;

        void        fMenuMove();
        QString     fL(QString);
        void        fGridSizeVert(int);
    signals:
        void sMoved();
    protected:
        void        moveEvent(QMoveEvent*);
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
};

class diaGridC : public QTableWidget
{
    Q_OBJECT

    public:
        diaGridC(diaGridSkin*,QWidget*,QFrame*);
        void        fWorkLang(QStringList,QStringList);
    private:
        diaGridSkin *parEnt;
        QWidget     *parWin;
        QFrame      *parMen;
        QStringList gLangCode;
        QStringList gLangText;
        bool        gGridGoto;
        bool        gGridFind;
        QString     gFindText;
        int         gFindFrom;
        QDialog     *diaGoto;
        QDialog     *diaFind;
        QLineEdit   *ediGoto;
        QLineEdit   *ediFind;

        void        fGridGoto();
        void        fGridFind();
        void        fGridFindLoop(QString, int);
        void        fGridMarkRows();
        QString     fL(QString);
    private slots:
        void        fGridGotoCanc();
        void        fGridGotoLine();
        void        fGridFindCanc();
        void        fGridFindWord();
    protected:
        virtual void keyPressEvent(QKeyEvent*);
};

#endif
/*
    ════════════════════════════════════════════════════════════════════════════════
    Code analysis/programming:  Georges Piedboeuf-Boen  georges.pi.bo@gmail.com
    Functional analysis:        Laurent Tenzer          lt@nova-cinema.org
    Project origin:             Cinéma Nova             http://www.nova-cinema.org
    Made in Brussels            Belgium                 http://www.brussels.be
    ════════════════════════════════════════════════════════════════════════════════
*/
