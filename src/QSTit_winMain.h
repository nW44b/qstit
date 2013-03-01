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

#ifndef H_WINMAIN
#define H_WINMAIN

#include <QtGui>
#include <QApplication>
#include <QFile>
#include <QString>
#include <QTableWidget>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QModelIndex>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QKeyEvent>
#include <QEvent>
#include <QColorDialog>

#include "QSTit_fadShow.h"

class diaGridC;
class butBubbC;
class butToolC;
class butToolX;
class menuSkin;
class rowSkin;
class diaSkin;
class diaGridSkin;
class grpSkin;
class barSkin;
class mesSkin;
class diaColoSkin;
class diaFontSkin;
class diaFileSkin;

class winMain : public QWidget
{
    Q_OBJECT

    public:
        winMain();
    private:
        QString     gSystFontFami;
        bool        gExitDial;
        bool        gFileDial;
        bool        gFontDial;
        bool        gColoDial;
        bool        gBackDial;
        bool        gOutlDial;
        bool        gGridDial;
        QWidget     *winWind;
        QString     gVers;
        QFile       oFlog;
        QString     gConf;
        QFile       oConf;
        int         gLang;
        QFile       oLang;
        QStringList gLangCode;
        QStringList gLangText;
        bool        gHelpDial;
        QFile       oHelp;
        bool        gWork;
        bool        gManu;
        bool        gAuto;
        bool        gPlay;
        bool        gSrtx;
        int         gPuls;
        int         gAcce;
        int         gJump;
        int         gJumpBase;
        bool        gInit;
        int         gRmax;
        int         gRows;
        bool        gShow;
        bool        gShowButt;
        QString     gColo;
        int         gShed;

        int         gWindWidt;
        int         gWindHeig;

        int         gMenuWidt;
        int         gMenuHeig;
        int         gMenuLefx;
        int         gMenuTopy;

        QString     gFileErro;

        QString     gExplDisa;
        QString     gGriCStyl;
        QString     gClokStyl;
        QString     gTimeStyl;
        QString     gPulsStyl;
        QString     gExplStyl;
        QString     gSpinStyl;

        int         gRowsHone;
        int         gRowsWbas;
        int         gRowsSpac;
        int         gRowsNumb;
        int         gRowsMaxi;
        QFont       gRowsFont;
        QString     gRowsBack;
        QString     gRowsColo;
        int         gRowsHcen;
        int         gRowsVcen;
        int         gRowsHcenPrev;
        int         gRowsVcenPrev;

        bool        gSettShow;
        int         gSettWidt;
        int         gSettHeig;
        int         gSettLefx;
        int         gSettTopy;

        QString     gGridBack;
        QString     gGridColo;
        int         gGridWidtBase;
        int         gGridWidt;
        int         gGridHeig;
        bool        gGridShow;
        int         gGridModi;
        bool        gGridEdit;
        bool        gGridSave;
        bool        gGridEditSave;
        QFont       gGridFont;
        int         gGridRowsHeig;
        int         gGridInfo;
        QString     gGridGotoText;
        bool        gGridColoDark;

        int         gOutlThik;
        QColor      gOutlColo;
        QColor      gErroBack;
        QColor      gErroColo;

        bool        gSecoText;
        bool        gSecoItal;

        QFile       oFile;
        bool        gFileEnco;
        bool        gFileInfo;
        QString     gFile;
        int         gFileMaxiGrid[9];
        int         gFileMaxiLeng[9];
        int         gFileMaxiChar[9];
        int         gFileMaxiRows[9];
        int         gFileMaxiLine[9];
        int         gFileMaxiColo[9];
        int         gFileMaxiColu[4];
        QString     gSrtxStop;

        int         gEditTextRows[99];
        int         gEditTextColu[99];
        int         gEditTextLine[99];
        QString     gEditTextOldx[99];
        QString     gEditTextNewx[99];
    public:
        QString fL(QString);
        bool    fFlogOpen();
        QString fHelpFileRead();
        void    fLangFileRead();
        void    fConfRead();
        void    fConfConf(QString,QString);
        void    fConfWrit();
        QString fConfWritLine(QString,QString);

        void    fWindCrea();
        void    fWindStyle();
        void    fWindLogoHide();
        void    fWindLogoFade();
        void    fWindClear();

        void    fMenuCrea();
        void    fMenuAdapt(int);

        void    fFileRead();
        void    fFileReadSrtx();
        bool    fFileConf();
        int     fFileSize(QString);
        void    fFileEncoding(QString);
        QString fFileLineForm(QString);
        bool    fFileTextMaxi(int,int,int,int,int,int);
        void    fFileWrit(QString);
        void    fFileLogx();
        int     fFileSrtxVeriNumb(int,QString,int);
        bool    fFileSrtxVeriHour(int,QString,int);
        bool    fFileSrtxVeriText(int,QString,int);
        bool    fFileSrtxVeriBlan(int,QString,int);
        void    fFileWritSrtx(QString);

        void    fRowsAdapt();
        void    fRowsChck();
        void    fRowsCrea();
        void    fRowsBase(int,int);
        void    fRowsInit();
        void    fRowsClear();
        void    fRowsFram();
        void    fRowsFramCent();
        void    fRowsFramHeig();
        void    fRowsFramInit();
        void    fRowsFramPosi();
        void    fRowsHeigCalc();
        void    fRowsWidtCalc();
        void    fRowsShow(int);
        void    fRowsLocDFast();
        void    fRowsLocUFast();
        void    fRowsLocLFast();
        void    fRowsLocRFast();
        void    fRowsNumbAdap();

        void    fSettCrea();

        void    fGridCrea();
        void    fGridZero();
        void    fGridInit();
        void    fGridInitCols();
        void    fGridInitRows();
        void    fGridShow(bool);
        void    fGridRows(int);
        void    fGridMarkRows(int);
        void    fGridModi();
        void    fGridSaveIcon();
        void    fGridEditEnab();
        void    fGridEditDisa();
        void    fGridEditMemo(int,int,QString);
        void    fGridFocus();
        QString fGridTextClean(QString);
        void    fGridTitle();

        void    fManuInit();
        void    fAutoInit();
        void    fAutoPaus();
        void    fAutoStarInit();
        void    fAutoGridShow();
        void    fAutoJumpBack();
        void    fAutoAcceShow();
    public slots:
        void    fHelpDial();
        void    fHelpDialClos();
        void    fLAll();
        void    fClearAll(bool);
        void    fClearGrid();

        void    fWindLogo();
        void    fWindTask();
        void    fWindExitDial();
        void    fWindExitClos();
        void    fWindExit();
        void    fWindExitCanc();
        void    fWindBack();

        void    fMenuClear();
        void    fMenuClok();

        void    fFileDial();
        void    fFileDialRepo(QString);
        void    fFileDialCanc();
        void    fFileInfoDial();
        void    fFileInfoGoto(int,int);
        void    fFileInfoClos();

        void    fRowsStat();
        void    fRowsColoGet(QColor);
        void    fRowsBackGet(QColor);
        void    fRowsOutlGet(QColor);
        void    fRowsFontGet(QFont);
        void    fRowsLocU();
        void    fRowsLocL();
        void    fRowsLocC();
        void    fRowsLocR();
        void    fRowsLocD();

        void    fRowsDimH(int);
        void    fRowsDimV(int);
        void    fRowsSpac(int);
        void    fRowsRota(int);
        void    fRowsNumb();
        void    fRowsSeco(int);
        void    fRowsItal(int);
        void    fRowsTextAlig();
        void    fRowsColo();
        void    fRowsCol1();
        void    fRowsCol2();
        void    fRowsCol3();
        void    fRowsCol4();
        void    fRowsColoDial();
        void    fColoDialClos();
        void    fRowsBack();
        void    fRowsBac1();
        void    fRowsBac2();
        void    fRowsBac3();
        void    fRowsBac4();
        void    fRowsBackDial();
        void    fBackDialClos();
        void    fRowsOutlDial();
        void    fOutlDialClos();
        void    fRowsOutlSlid(int);
        void    fRowsTextForm();
        void    fRowsTextDraw(int);
        void    fRowsFont();
        void    fRowsFon1();
        void    fRowsFon2();
        void    fRowsFon3();
        void    fRowsFon4();
        void    fRowsFontDial();
        void    fFontDialClos();
        void    fRowsFontChan();
        void    fRowsShowSlot();

        void    fShedNumb();
        void    fShedHeig(int);
        void    fShedSpac(int);
        void    fShedRota(int);

        void    fSettBase();
        void    fSettShow();
        void    fSettClos();

        void    fGridLink();
        void    fGridClic(int,int);
        void    fGridEdit(int,int);
        void    fGridChan(int,int,int,int);
        void    fGridSave();
        void    fGridUndo();
        void    fGridEditButt();
        void    fGridEditSave();
        void    fGridEditCanc();
        void    fGridFontSize();
        void    fGridFontGrid();
        void    fGridItemSetx(QString,int,int);
        void    fGridGoto();
        void    fGridFind();
        void    fGridColoTogg();
        void    fGridColo();
        void    fGridFontDial();
        void    fGridFontClos();
        void    fGridFontGet(QFont);
        void    fButtPrev();
        void    fButtNext();

        void    fAutoStar();
        void    fAutoClok();
        void    fAutoTimeInit();
        QTime   fAutoTimeConv(QString);
        void    fAutoAcce();
        void    fAutoDece();
        void    fAutoJump();
        void    fAutoBack();
        void    fJumpBase(int);
    private:
        QLabel      *labLogo;
        diaSkin     *diaHelp;
        QTextEdit   *texHelp;
        diaColoSkin *diaColo;
        diaFontSkin *diaFont;
        diaFileSkin *diaFile;

        QTimer      *tmrClok;
        QTimer      *tmrAuto;
        QTime       timAuto;
        QTime       timStar;
        QTime       timStop;

        struct objRows
        {
            QString text;
            bool    show;
            QFont   font;
            QColor  colF;
            QColor  colB;
            int     x;
            int     y;
            int     widt;
            int     heig;
            int     spac;
            int     rota;
            int     savH;
            int     savS;
        } objRow0,objRow1,objRow2,objRow3,objRow4;
        rowSkin     *fraRows;
        QLabel      *texRow1;
        QLabel      *texRow2;
        QLabel      *texRow3;
        QLabel      *texRow4;
        QToolButton *butRowsCent;

        grpSkin     *grpTextAliH;
        grpSkin     *grpTextAliV;

        diaGridSkin *diaGrid;
        diaGridC    *griText;
        butBubbC    *bubButt;

        butToolC    *butGridCade;
        butToolC    *butGridInfo;
        butToolC    *butGridSave;
        butToolC    *butGridUndo;
        butToolC    *butGridGoto;
        butToolC    *butGridFind;
        butToolC    *butGridEdit;
        butToolC    *butGridClea;
        butToolC    *butGridLink;
        butToolC    *butRoll;

        QDialog     *diaEdit;

        butToolC    *butExit;
        butToolC    *butHelp;
        butToolC    *butFile;
        butToolC    *butSett;

        menuSkin    *fraMenu;
        QLabel      *labClok;
        QLabel      *labTime;
        QLabel      *texPuls,*labPuls;
        QLabel      *texJump,*labJump;

        diaSkin         *diaSett;
        QTabWidget      *tabSett;

        QWidget         *tabRows;
        QLabel          *texRowsNumb;
        QRadioButton    *radRow1;
        QRadioButton    *radRow2;
        QRadioButton    *radRow3;
        QRadioButton    *radRow4;
        QLabel          *texRowsLoca;
        butToolX        *butLocaUpup;
        butToolX        *butLocaCent;
        butToolX        *butLocaLeft;
        butToolX        *butLocaRigh;
        butToolX        *butLocaDown;
        QLabel          *texRowsDime;
        QLabel          *labRowsDimH;
        QSpinBox        *spiRowsDimH;
        QLabel          *labRowsDimV;
        QSpinBox        *spiRowsDimV;

        butToolX        *butDimeUpup;
        butToolX        *butDimeLeft;
        butToolX        *butDimeRigh;
        butToolX        *butDimeDown;
        QLabel          *texRowsSpac;
        QSpinBox        *spiRowsSpac;
        QLabel          *texRowsRota;
        QSpinBox        *spiRowsRota;
        QLabel          *texRowsBack;
        QPushButton     *butTextBack;
        QLabel          *labWindBack;
        QRadioButton    *radWindBacB;
        QRadioButton    *radWindBacG;
        QLabel          *labSettLin1;
        QLabel          *labTextFont;
        QPushButton     *butTextColo;
        QPushButton     *butFont;
        QLabel          *labRowsOutl;
        QSpinBox        *spiRowsOutl;
        QPushButton     *butRowsOutl;
        QLabel          *texRowsHeim;
        QLabel          *texRowsHeiM;
        QLabel          *texRowsWidm;
        QLabel          *texRowsWidM;
        QLabel          *labTextAliH;
        QLabel          *labTextAliV;

        QRadioButton    *radLeft;
        QRadioButton    *radCenH;
        QRadioButton    *radRigh;
        QRadioButton    *radTopy;
        QRadioButton    *radCenV;
        QRadioButton    *radBott;

        QWidget         *tabGene;
        QLabel          *labWorkLang;
        QRadioButton    *radLangEngl;
        QRadioButton    *radLangOthe;
        QLabel          *labTaskShow;
        QRadioButton    *radTaskShow;
        QRadioButton    *radTaskHide;
        QLabel          *labGridFont;
        QPushButton     *butGridFont;
        QLabel          *labGridColo;
        QRadioButton    *radGridColo;
        QLabel          *labSettLin2;
        QCheckBox       *chkSecoText;
        QCheckBox       *chkSecoItal;
        QLabel          *labJumpBase;
        QSpinBox        *spiJumpBase;
        QPushButton     *butSettBase;

        QWidget         *tabShed;
        QLabel          *labRowsLoca;
        QLabel          *labRowsSize;
        QLabel          *labRowsCent;
        QLabel          *labMenuSize;
        QLabel          *labMenuLoca;
        QLabel          *labScreSize;
        QLabel          *labGridCol3;
        QLabel          *labGridCol4;
        QLabel          *labGridCol5;
        QLabel          *labGridCol6;

        QLabel          *labShedDesc;
        QLabel          *labShedShow;
        QLabel          *labShedFont;
        QLabel          *labShedFore;
        QLabel          *labShedBack;
        QLabel          *labShedPosX;
        QLabel          *labShedPosY;
        QLabel          *labShedWidt;
        QLabel          *labShedHeig;
        QLabel          *labShedSpac;
        QLabel          *labShedRota;

        QLabel          *labShedRow1;
        QLabel          *labShedTit1;
        QRadioButton    *radShedSho1;
        QPushButton     *butShedFon1;
        QPushButton     *butShedFor1;
        QPushButton     *butShedBac1;
        QSpinBox        *spiShedHei1;
        QSpinBox        *spiShedSpa1;
        QSpinBox        *spiShedRot1;

        QLabel          *labShedRow2;
        QLabel          *labShedTit2;
        QRadioButton    *radShedSho2;
        QPushButton     *butShedFon2;
        QPushButton     *butShedFor2;
        QPushButton     *butShedBac2;
        QSpinBox        *spiShedHei2;
        QSpinBox        *spiShedSpa2;
        QSpinBox        *spiShedRot2;

        QLabel          *labShedRow3;
        QLabel          *labShedTit3;
        QRadioButton    *radShedSho3;
        QPushButton     *butShedFon3;
        QPushButton     *butShedFor3;
        QPushButton     *butShedBac3;
        QSpinBox        *spiShedHei3;
        QSpinBox        *spiShedSpa3;
        QSpinBox        *spiShedRot3;

        QLabel          *labShedRow4;
        QLabel          *labShedTit4;
        QRadioButton    *radShedSho4;
        QPushButton     *butShedFon4;
        QPushButton     *butShedFor4;
        QPushButton     *butShedBac4;
        QSpinBox        *spiShedHei4;
        QSpinBox        *spiShedRot4;

        QPushButton     *butEditSave;
        QPushButton     *butEditCanc;

        diaSkin         *diaInfo;
        QTableWidget    *griInfo;

        butToolC        *butProjUpup;
        butToolC        *butProjDown;
        butToolC        *butProjPlay;
        butToolC        *butProjAcce;
        butToolC        *butProjDece;
        butToolC        *butProjBack;
        butToolC        *butProjJump;

        diaSkin         *diaExit;
        diaSkin         *diaMess;
        QRadioButton    *radExitSavN;
        QRadioButton    *radExitSavP;
        QRadioButton    *radExitSavF;
        butToolC        *butExitSave;
    private:
        QPointer<FaderWidget> faderWidget;
    protected:
        virtual void keyPressEvent(QKeyEvent *qe);
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
