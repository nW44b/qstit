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
#include <QKeyEvent>
#include <QEvent>
#include <QFlags>
#include <QPointer>

#include "QSTit_fadShow.h"

class diaSettW;
class diaGridW;
class diaGridC;
class butBubbC;
class butToolC;

class winMain : public QWidget
{
    Q_OBJECT

    public:

    QString gVers;
    bool    gHelp;
    bool    gLogo;
    bool    gScre;
    int     gLang;
    bool    gWork;
    bool    gManu;
    bool    gAuto;
    bool    gPlay;
    bool    gSrtx;
    int     gPuls;
    int     gAcce;
    int     gJump;
    int     gJumpBase;                                      // gpb 120408
    bool    gInit;
    int     gRmax;
    int     gRows;
    bool    gShow;
    bool    gShowButt;                                      // gpb 120406


    QString gConf;
    QFile   oConf;

    QFile   oHelp;
    int     gHelpWidt;
    int     gHelpHeig;
    int     gHelpLefx;
    int     gHelpTopy;

    int     gDeskWidt;
    int     gDeskHeig;
    int     gDeskStat;

    int     gWindWidt;
    int     gWindHeig;
    QString gWindBack;

    int     gMenuWidt;
    int     gMenuHeig;
    int     gMenuLefx;
    int     gMenuTopy;

    bool    gExitShow;

    QString gFileErro;

    QString gWindStyl;
    QString gMenuStyl;
    QString gHelpStyl;
    QString gSettStyl;
    QString gRowsStyl;
    QString gMaskStyl;
    QString gTitlStyl;
    QString gTitlDisa;
    QString gTitlStyI;
    QString gTitlDisI;
    QString gExplStyl;
    QString gExplDisa;
    QString gGboxStyl;
    QString gGboxStyx;
    QString gGboxStyz;
    QString gGridStyl;
    QString gGriCStyl;
    QString gClokStyl;
    QString gTimeStyl;
    QString gPulsStyl;
    QString gIconStyl;
    QString gGriIStyl;
    QString gTitlSpin;

    int     gRowsWidt;
    int     gRowsHeig;
    int     gRowsLefx;
    int     gRowsTopy;
    int     gRowsSpac;
    int     gRowsNumb;
    int     gRowsMaxi;
    QFont   gRowsFont;
    QString gRowsBack;
    QString gRowsColo;
    bool    gGridHourBold;
    int     gRowsCharMaxi;
    int     gRowsWmax;
    bool    gGridColoDark;

    int     gSettWidt;
    int     gSettHeig;
    int     gSettLefx;
    int     gSettTopy;
    bool    gSettShow;

    int     gGridWidtBase;
    int     gGridWidt;
    int     gGridHeig;
    int     gGridLefx;
    int     gGridTopy;
    bool    gGridShow;
    int     gGridModi;
    bool    gGridEdit;
    bool    gGridSave;
    bool    gGridEditSave;
    QFont   gGridFont;
    QString gGridFontFami;
    int     gGridFontSize;
    int     gGridRowsHeig;
    int     gGridInfo;

    int     gMessLefx;
    int     gMessTopy;

    int     gInfoWidt;
    int     gInfoHeig;
    int     gInfoLefx;
    int     gInfoTopy;

    int     gProjWidt;
    int     gProjHeig;
    int     gProjLefx;
    int     gProjTopy;

    int     gOutlThik;
    QColor  gOutlColo;
    QColor  gGridEmpt;
    QColor  gInfoBack;
    QColor  gInfoColo;
    QColor  gErroBack;
    QColor  gErroColo;

    bool    gSecoText;
    bool    gSecoItal;

    int     gFileWidt;
    int     gFileHeig;
    int     gFileLefx;
    int     gFileTopy;
    QFile   oFile;
    bool    gFileEnco;
    bool    gFileInfo;
    QString gFile;
    int     gFileMaxiGrid[9];
    int     gFileMaxiLeng[9];
    int     gFileMaxiChar[9];
    int     gFileMaxiRows[9];
    int     gFileMaxiLine[9];
    int     gFileMaxiColo[9];
    int     gFileMaxiColu[5];
    QString gSrtxStar;
    QString gSrtxStop;

    QFile   oFlog;

    QPixmap gIconAcce;
    QPixmap gIconCanc;
    QPixmap gIconClea;
    QPixmap gIconColo;
    QPixmap gIconCurH;
    QPixmap gIconCurV;
    QPixmap gIconDece;
    QPixmap gIconDial;
    QPixmap gIconDown;
    QPixmap gIconEdit;
    QPixmap gIconEditDisa;
    QPixmap gIconEditEnab;
    QPixmap gIconExit;
    QPixmap gIconFile;
    QPixmap gIconFindDisa;
    QPixmap gIconFindEnab;
    QPixmap gIconFlag;
    QPixmap gIconFont;
    QPixmap gIconGotoDisa;
    QPixmap gIconGotoEnab;
    QPixmap gIconGray;
    QPixmap gIconInfoDisa;
    QPixmap gIconInfoEnab;
    QPixmap gIconInfoGoto;
    QPixmap gIconJump;
    QPixmap gIconJumpBack;
    QPixmap gImagLogo;
    QPixmap gIconOkok;
    QPixmap gIconPaus;
    QPixmap gIconPlay;
    QPixmap gIconRollOpen;
    QPixmap gIconRollClos;
    QPixmap gIconSaveDisa;
    QPixmap gIconSaveEnab;
    QPixmap gIconSett;
    QPixmap gIconStop;
    QPixmap gIconUndoDisa;
    QPixmap gIconUndoEnab;
    QPixmap gIconUpup;

    int     gEditTextRows[99];
    int     gEditTextColu[99];
    int     gEditTextLine[99];
    QString gEditTextOldx[99];
    QString gEditTextNewx[99];

    public:

    QWidget *winWind;

    public:

    winMain();
    QString fL(QString);
    void    fT();

    bool    fFlogOpen();

    void    fHelpDial();
    QString fHelpFileRead();

    void    fConfRead();
    void    fConfConf(QString, QString);
    void    fConfWrit();

    void    fWindCrea();
    void    fWindScre(QString);
    void    fWindLogoHide();
    void    fWindLogoFade();
    void    fWindClear();
    void    fWindPosiMess(QMessageBox*);
    void    fWindPosiDial(QDialog*);
    void    fWindPosiProg(QProgressDialog&);

    void    fMenuCrea();
    void    fMenuAdapt(int);

    bool    fFileConf();
    void    fFileRead();
    QString fFileLineForm(QByteArray);
    void    fFileTextMaxi(int, int, int, int, int, int);
    void    fFileWrit(QString);
    void    fFileLogx();
    void    fFileCodec(QByteArray);
    void    fFileCodeTest(QByteArray, bool);
    void    fFileReadSrtx();
    int     fFileSrtxVeriNumb(int, QString, int);
    bool    fFileSrtxVeriHour(int, QString, int);
    bool    fFileSrtxVeriText(int, QString, int);
    bool    fFileSrtxVeriBlan(int, QString, int);
    void    fFileWritSrtx(QString);
    void    fFileInfoClos();
    void    fFileInfoGeom();

    void    fRowsCrea();
    void    fRowsInit();
    void    fRowsHeigCalc();
    void    fRowsClear();
    void    fRowsFram();
    void    fRowsPixxCalc();
    void    fRowsTextOutl(QTextEdit*, QTextCharFormat);
    void    fRowsShow(int);

    void    fSettCrea();
    void    fSettGeom();

    void    fGridCrea();
    void    fGridZero();
    void    fGridInit();
    void    fGridInitCols();
    void    fGridInitRows();
    void    fGridShow(bool);
    void    fGridGeom();
    void    fGridRows(int);
    void    fGridMarkRows(int);
    void    fGridModi();
    void    fGridSaveIcon();
    void    fGridEditEnab();
    void    fGridEditDisa();
    void    fGridEditMemo(int, int, QString);
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

    void    fHelpDialClos(int);
    void    fWorkLang();
    void    fClearAll();
    void    fClearAllDial();

    void    fWindTogg();
    void    fWindLogo();
    void    fWindBott();
    void    fWindExitDial();
    void    fWindExitFini(int);
    void    fWindExit();
    void    fWindExitCanc();
    void    fWindBack();

    void    fMenuClear();
    void    fMenuClok();

    void    fFileDial();
    void    fFileEnco();
    void    fFileDialRepo(QString);
    void    fFileInfo();
    void    fFileInfoGoto(int, int);
    void    fFileInfoFini(int);

    void    fRowsWidt(int);
    void    fRowsHeig(int);
    void    fRowsLocV(int);
    void    fRowsLocH(int);
    void    fRowsPosi(int);
    void    fRowsSpac(int);
    void    fRowsNumb();
    void    fRowsNumbBloc();
    void    fRowsSeco(int);
    void    fRowsItal(int);
    void    fRowsTextAlig();
    void    fRowsColoDial();
    void    fRowsBackDial();
    void    fRowsOutlDial();
    void    fRowsOutlThik();
    void    fRowsTextForm();
    void    fGridHourBold();
    void    fRowsFontDial();
    void    fRowsFontChan();
    void    fRowsShowSlot();
    void    fGridColoDark();
    void    fJumpBase(int);

    void    fSettShow();
    void    fSettClos();
    void    fSettFini(int);

    void    fGridClic(int, int);
    void    fGridEdit(int, int);
    void    fGridChan(int, int, int, int);
    void    fGridSave();
    void    fGridUndo();
    void    fGridEditButt();
    void    fGridEditSave();
    void    fGridEditCanc();
    void    fGridFontSize();
    void    fGridFontFami();
    void    fGridFontGrid();
    void    fGridItemSetx(QString, int, int);
    void    fGridGoto();
    void    fGridFind();
    void    fGridLight(int);                            // gpb 120316

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

    private:

    QTimer *tmrClok;
    QTimer *tmrAuto;
    QTime   timAuto;
    QTime   timStar;
    QTime   timStop;

    QDialog     *diaLogo;
    QLabel      *labLogo;
    QFrame      *fraLogo;

    QDialog     *diaHelp;
    QTextEdit   *texHelp;
    QVBoxLayout *layHelp;
    QFrame      *fraHelp;

    QTextEdit   *texRow1;
    QTextEdit   *texRow2;
    QTextEdit   *texRow3;
    QTextEdit   *texRow4;
    QVBoxLayout *layRows;
    QFrame      *fraRows;
    QFrame      *fraMask;

    QRadioButton *radRow1;
    QRadioButton *radRow2;
    QRadioButton *radRow3;
    QRadioButton *radRow4;

    QCheckBox   *chkSecoText;
    QCheckBox   *chkSecoItal;
    QSpinBox    *spiJumpBase;

    diaGridW    *diaGrid;
    QGridLayout *layGrid;
    diaGridC    *griText;
    butBubbC    *bubButt;

    butToolC    *butGridCade;
    butToolC    *butGridInfo;
    butToolC    *butGridSave;
    butToolC    *butGridUndo;
    butToolC    *butGridGoto;
    butToolC    *butGridFind;
    butToolC    *butGridEdit;
    butToolC    *butRoll;

    QDialog     *diaEdit;

    QPushButton *butTextColo;
    QPushButton *butTextBack;
    QPushButton *butFont;
    QPushButton *butFile;
    QPushButton *butSett;
    QPushButton *butExit;
    QPushButton *butClea;
    QFrame      *fraMenu;
    QLabel      *labClok;
    QLabel      *labTime;
    QLabel      *labPuls;
    QLabel      *labJump;

    QPushButton  *butChar;
    QRadioButton *radNone;
    QRadioButton *radThin;
    QRadioButton *radBold;

    diaSettW    *diaSett;
    QTabWidget  *tabSett;
    QLabel      *labTaskShow;
    QLabel      *texRowsNumb;
    QLabel      *labTextFont;
    QLabel      *labFileEnco;
    QLabel      *labWorkLang;
    QLabel      *labJumpBase;
    QCheckBox   *chkWindCros;
    QCheckBox   *chkWindLogo;
    QLabel      *texRowsLocV;
    QLabel      *texRowsLoVm;
    QLabel      *texRowsLoVM;
    QLabel      *texRowsLocH;
    QLabel      *texRowsLoHm;
    QLabel      *texRowsLoHM;
    QLabel      *texRowsHeig;
    QLabel      *texRowsHeim;
    QLabel      *texRowsHeiM;
    QLabel      *texRowsWidt;
    QLabel      *texRowsWidm;
    QLabel      *texRowsWidM;
    QLabel      *labCharOutl;
    QLabel      *labCharThic;
    QLabel      *labTextAliH;
    QLabel      *labTextAliV;

    QRadioButton *radWindBacB;
    QRadioButton *radWindBacG;

    QRadioButton *radTaskShow;
    QRadioButton *radTaskHide;
    QLabel       *labWindMenu;
    QRadioButton *radWindMenT;
    QRadioButton *radWindMenB;
    QLabel       *labWindBack;
    QLabel       *texRowsBack;
    QSlider      *sliRowsSpac;
    QSlider      *sliRowsHeig;
    QSlider      *sliRowsWidt;
    QSlider      *sliRowsLocV;
    QSlider      *sliRowsLocH;
    QSlider      *sliRows;
    QSlider      *sliLigh;

    QRadioButton *radLeft;
    QRadioButton *radCenH;
    QRadioButton *radRigh;
    QRadioButton *radTopy;
    QRadioButton *radCenV;
    QRadioButton *radBott;
    QRadioButton *radAnsi;
    QRadioButton *radUtf8;
    QRadioButton *radEngl;
    QRadioButton *radFren;
    QRadioButton *radDutc;

    QLabel       *labCharMaxi;
    QSpinBox     *spiCharMaxi;

    QLabel       *texRowsSpac;

    QLabel       *labGridFfam;
    QRadioButton *radFam1;
    QRadioButton *radFam2;
    QRadioButton *radFam3;

    QLabel       *labGridFsiz;
    QRadioButton *radSiz1;
    QRadioButton *radSiz2;
    QRadioButton *radSiz3;

    QLabel       *labGridHour;
    QRadioButton *radGridHour;

    QLabel       *labGridColo;
    QRadioButton *radGridColo;

    QPushButton  *butEditSave;
    QPushButton  *butEditCanc;

    QDialog      *diaInfo;
    QTableWidget *griInfo;

    QTableWidgetItem *widInfoName;
    QTableWidgetItem *widInfoPath;
    QTableWidgetItem *widInfoModi;
    QTableWidgetItem *widInfoEnco;
    QTableWidgetItem *widInfoCols;
    QTableWidgetItem *widInfoRows;
    QTableWidgetItem *widInfoLine;
    QTableWidgetItem *widInfoProb;

    butToolC    *butProjUpup;
    butToolC    *butProjDown;
    butToolC    *butProjPlay;
    butToolC    *butProjAcce;
    butToolC    *butProjDece;
    butToolC    *butProjBack;
    butToolC    *butProjJump;

    QDialog      *diaExit;
    QRadioButton *radExitSavN;
    QRadioButton *radExitSavP;
    QRadioButton *radExitSavF;
    QPushButton  *butExitSave;
    QPushButton  *butExitCanc;

    private:

    QPointer<FaderWidget> faderWidget;

    protected:

    virtual void keyPressEvent(QKeyEvent *qe);
};

#endif
