#include <QtGui>
#include <stdlib.h>
#include "stdio.h"
#include "QSTit_winMain.h"
#include "QSTit_diaGrid.h"
#include "QSTit_diaExpl.h"

winMain::winMain()
{
    gVers = "1.23";

    // works --------------------------------------------------------------------------------------

    QDesktopWidget *wScre = QApplication::desktop();
    QRect rAvai = wScre->availableGeometry();

    gHelp = false;      // on screen or not

    gLogo = true;       // on screen or not
    gScre = true;       // true: normal (menu down), false: inverted (menu up)
    gLang = 0;          // 0: En, 1: Fr, 2: Nl

    gWork = false;
    gManu = false;
    gAuto = false;
    gSrtx = false;      // true: srt, false: txt

    gPuls = 100;        // basic timeout interval in mls (100/1000 = 0.1 sec)
    gAcce = 0;          // accelerator in mls
    gJump = 0;          // jump step
    gJumpBase = 200;    // jump base

    gFileEnco = true;
    gFileInfo = false;  // on screen or not

    // icons --------------------------------------------------------------------------------------

    gIconAcce = QPixmap(":/Imag/QSTit_acce.png");
    gIconCanc = QPixmap(":/Imag/QSTit_canc.png");
    gIconClea = QPixmap(":/Imag/QSTit_clea.png");
    gIconColo = QPixmap(":/Imag/QSTit_colo.png");
    gIconCurH = QPixmap(":/Imag/QSTit_curH.png");
    gIconCurV = QPixmap(":/Imag/QSTit_curV.png");
    gIconDece = QPixmap(":/Imag/QSTit_dece.png");
    gIconDial = QPixmap(":/Imag/QSTit_gray.png");
    gIconDown = QPixmap(":/Imag/QSTit_down.png");
    gIconEdit = QPixmap(":/Imag/QSTit_edit.png");
    gIconEditDisa = QPixmap(":/Imag/QSTit_edit_disa.png");
    gIconEditEnab = QPixmap(":/Imag/QSTit_edit_enab.png");
    gIconExit = QPixmap(":/Imag/QSTit_exit.png");
    gIconFile = QPixmap(":/Imag/QSTit_file.png");
    gIconFindDisa = QPixmap(":/Imag/QSTit_find_disa.png");
    gIconFindEnab = QPixmap(":/Imag/QSTit_find_enab.png");
    gIconFlag = QPixmap(":/Imag/QSTit_flag.png");
    gIconFont = QPixmap(":/Imag/QSTit_font.png");
    gIconGotoDisa = QPixmap(":/Imag/QSTit_goto_disa.png");
    gIconGotoEnab = QPixmap(":/Imag/QSTit_goto_enab.png");
    gIconGray = QPixmap(":/Imag/QSTit_gray.png");
    gIconInfoDisa = QPixmap(":/Imag/QSTit_info_disa.png");
    gIconInfoEnab = QPixmap(":/Imag/QSTit_info_enab.png");
    gIconInfoGoto = QPixmap(":/Imag/QSTit_info_goto.png");
    gIconJump = QPixmap(":/Imag/QSTit_jump.png");
    gIconJumpBack = QPixmap(":/Imag/QSTit_jump_back.png");
    gImagLogo = QPixmap(":/Imag/QSTit_logo.gif");
    gIconOkok = QPixmap(":/Imag/QSTit_okok.png");
    gIconPaus = QPixmap(":/Imag/QSTit_paus.png");
    gIconPlay = QPixmap(":/Imag/QSTit_play.png");
    gIconRollOpen = QPixmap(":/Imag/QSTit_roll_open.png");
    gIconRollClos = QPixmap(":/Imag/QSTit_roll_clos.png");
    gIconSaveDisa = QPixmap(":/Imag/QSTit_save_disa.png");
    gIconSaveEnab = QPixmap(":/Imag/QSTit_save_enab.png");
    gIconSett = QPixmap(":/Imag/QSTit_sett.png");
    gIconUndoDisa = QPixmap(":/Imag/QSTit_undo_disa.png");
    gIconUndoEnab = QPixmap(":/Imag/QSTit_undo_enab.png");
    gIconUpup = QPixmap(":/Imag/QSTit_upup.png");

    // desktop ------------------------------------------------------------------------------------

    gDeskWidt = wScre->width();
    gDeskHeig = wScre->height();
    gDeskStat = gDeskHeig - rAvai.height();

    gWindWidt = gDeskWidt;
    gWindHeig = gDeskHeig;

    gRowsNumb = 0;
    gRowsMaxi = 0;

    // colors -------------------------------------------------------------------------------------

    gRowsBack = "#000000";
    gRowsColo = "#ffffff";
    gOutlColo = QColor("#eeeeee");
    gGridEmpt = QColor("#aaaaaa");
    gInfoBack = "#202020";
    gInfoColo = "#ffffff";
    gErroBack = "#ff0000";
    gErroColo = "#ffffff";

    // fonts --------------------------------------------------------------------------------------

    gRowsFont = QFont("Arial", 22, QFont::Normal, false);
    gRowsFont.setStyleStrategy(QFont::PreferAntialias);
    gGridFontFami = "lucida console";
    gGridFontSize = 9;
    gGridFont = QFont(gGridFontFami, gGridFontSize, QFont::Normal, false);

    // styles -------------------------------------------------------------------------------------

    gWindStyl = "background-color:#000000;color:#ffffff;font:arial 11px normal;";
    gMenuStyl = "background-color:#151515;color:#ffffff;";
    gSettStyl = "background-color:#151515;color:#ffffff;";
    gGridStyl = "background-color:#151515;color:#ffffff;";
    gGriCStyl = "background-color:#ffffff;color:#000000;selection-background-color:#ffff33;selection-color:#000000;";   // gpb 120315
    gGriIStyl = "background-color:#ffffff;color:#000000;";
    gHelpStyl = "background-color:#000000;color:#ffffff;";
    gRowsStyl = "background-color:#000000;color:#ffffff;";
    gMaskStyl = "background-color:#000000;";
    gTitlStyl = "color:#ffffff;min-width:99px;";
    gTitlDisa = "color:#555555;min-width:99px;";
    gTitlStyI = "color:#ffffff;min-width:200px;";
    gTitlDisI = "color:#555555;min-width:200px;";
    gExplStyl = "color:#ffffff;min-width:50px;min-height:15px;max-height:15px;";
    gExplDisa = "color:#555555;min-width:50px;min-height:15px;max-height:15px;";
    gGboxStyl = "background-color:#202020;border:none;width:50px;";
    gGboxStyx = "background-color:#202020;border:none;width:70px;";
    gGboxStyz = "border:none;width:250px;";
    gClokStyl = "min-height:20px;min-width:40px;background-color:#000000;color:#ffffff;border:1px solid #000000;border-radius:3px;";
    gTimeStyl = "min-height:20px;min-width:40px;background-color:#000000;color:#ffffff;border:1px solid #000000;border-radius:3px;";
    gPulsStyl = "min-height:20px;min-width:20px;background-color:#000000;color:#ffffff;border:1px solid #000000;border-radius:3px;";
    gIconStyl = "min-height:20px;max-height:20px;min-width:20px;max-width:20px;background-color:#151515;color:#ffffff;border:none;";
    gTitlSpin = "color:#ffffff;max-width:40px;max-height:20px;";

    // others -------------------------------------------------------------------------------------

    gSecoText = false;
    gSecoItal = false;

    gGridEdit = true;
    gGridSave = false;

    gGridHourBold = false;
    gGridColoDark = false;

    gOutlThik = 0;

    gFileWidt = 570;
    gFileHeig = 320;
    gFileLefx = 0;  // calculated
    gFileTopy = 0;  // calculated

    // window -------------------------------------------------------------------------------------

    this->setGeometry(0, 0, gWindWidt, gWindHeig);
    this->setWindowFlags(Qt::FramelessWindowHint);

    gExitShow = false;
    gSettShow = false;
    gGridShow = false;

    // create all entities ------------------------------------------------------------------------

    fWindCrea();
    fMenuCrea();
    fRowsCrea();
    fSettCrea();
    fGridCrea();
    fWindLogo();

    // read config --------------------------------------------------------------------------------

    gConf = "./QSTit.cfg";
    fConfRead();

    // init rows ----------------------------------------------------------------------------------

    fRowsInit();                                        // gpb 120220
    fRowsShow(true);

    // focus --------------------------------------------------------------------------------------

    fraMenu->setFocus(Qt::OtherFocusReason);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// main window functions
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void winMain::fWindTogg()
{
    int iD = 0;
    int iP = gRowsTopy;

    if (gScre)  iD = gMenuTopy - gRowsHeig - abs(gRowsTopy);
    else        iD = abs(gRowsTopy) - gMenuTopy - gMenuHeig;

    gScre = radWindMenB->isChecked() ? true : false;

    fWindScre("a");
    fWindPosiDial(diaSett);

    if (gScre)  iP = sliRowsLocV->minimum() + iD;
    else        iP = sliRowsLocV->maximum() - iD;

    sliRowsLocV->setValue(iP);
}

void winMain::fWindCrea()
{
    gWindBack = "#000000";

    winWind = new QWidget(this);
    winWind->setGeometry(0, 0, gWindWidt, gWindHeig);
    winWind->setStyleSheet(gWindStyl);
    winWind->setContentsMargins(0, 0, 0, 0);
    winWind->setCursor(QCursor(gIconCurV, -1, -1));
}

void winMain::fWindBott()
{
    int pHeig = radTaskShow->isChecked() ? gDeskStat : 0;

    gWindHeig = gDeskHeig - pHeig;
    setFixedSize(gWindWidt, gWindHeig);

    if (gScre)
    {
        gMenuTopy = gWindHeig - gMenuHeig;
        fraMenu->move(gMenuLefx, gMenuTopy);
        gSettTopy = gMenuTopy - gSettHeig - 10;
        diaSett->move(gSettLefx, gSettTopy);
        gGridTopy = gMenuTopy - gGridHeig - 10;

        fGridGeom();
        fSettGeom();
    }
}

void winMain::fWindExit()
{
    fFileLogx();
    fConfWrit();
    QApplication::quit();
}

void winMain::fWindExitCanc()
{
    diaExit->close();
    gExitShow=false;
}

void winMain::fWindExitFini(int)
{
    gExitShow=false;
}

void winMain::fWindExitDial()
{
    if (gExitShow)
    {
        fWindExitCanc();
        return;
    }
    gExitShow=true;

    fGridModi();

    int iExitWidt = 300;
    int iExitHeig = 115;
    int iExitLefx = 0;  // calculated at the end
    int iExitTopy = 0;  // calculated at the end

    QString sStyl = "background-color:#151515;color:#ffffff; ";
    QString sStyD = "background-color:#151515;color:#555555; ";

    diaExit = new QDialog(this);
    diaExit->setWindowTitle(fL("Quit"));
    diaExit->setStyleSheet(sStyl);
    diaExit->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    diaExit->setCursor(Qt::ArrowCursor);
    diaExit->setMinimumWidth(iExitWidt);
    diaExit->setMaximumWidth(iExitWidt);
    diaExit->setMinimumHeight(iExitHeig);
    diaExit->setMaximumHeight(iExitHeig);
    diaExit->setGeometry(iExitLefx, iExitTopy, iExitWidt, iExitHeig);
    diaExit->move(iExitLefx, iExitTopy);                // necessary!
    connect(diaExit, SIGNAL(finished(int)), this, SLOT(fWindExitFini(int)));

    radExitSavN = new QRadioButton(fL("Don't save settings"), diaExit);
    radExitSavN->setStyleSheet(sStyl);

    radExitSavP = new QRadioButton(fL("Save as general settings"), diaExit);
    radExitSavP->setStyleSheet(sStyl);

    radExitSavF = new QRadioButton(fL("Save as settings for this file"), diaExit);
    if (gFile.size() > 4)
    {
        radExitSavF->setStyleSheet(sStyl);
    }
    else
    {
        radExitSavF->setStyleSheet(sStyD);
        radExitSavF->setEnabled(false);
    }

    radExitSavN->setChecked(true);

    QVBoxLayout *boxExitSave = new QVBoxLayout;
    boxExitSave->setContentsMargins(2, 2, 2, 2);
    boxExitSave->setSpacing(1);
    boxExitSave->addWidget(radExitSavN);
    boxExitSave->addWidget(radExitSavP);
    boxExitSave->addWidget(radExitSavF);

    QGroupBox *grpExitSave = new QGroupBox("", diaExit);
    grpExitSave->setStyleSheet(gGboxStyz);
    grpExitSave->setLayout(boxExitSave);
    grpExitSave->move(10, 10);

    QPushButton *butExitSave = new QPushButton(gIconExit, fL("Quit"), diaExit);
    butExitSave->move(10, 80);
    connect(butExitSave, SIGNAL(clicked()), this, SLOT(fWindExit()));

    QPushButton *butExitCanc = new QPushButton(gIconCanc, fL("Cancel"), diaExit);
    butExitCanc->move(90, 80);
    connect(butExitCanc, SIGNAL(clicked()), this, SLOT(fWindExitCanc()));

    fWindPosiDial(diaExit);
	diaExit->exec();
}

void winMain::fWindLogo()
{
    int iWidt = gImagLogo.width();
    int iHeig = gImagLogo.height();
    int iLefx = (gWindWidt - iWidt) / 2;
    int iTopy = (gWindHeig - iHeig) / 2;

    labLogo = new QLabel(winWind);
    labLogo->setPixmap(gImagLogo);
    labLogo->setGeometry(iLefx, iTopy, iWidt, iHeig);
}

void winMain::fWindLogoHide()
{
    gLogo = false;
    labLogo->setHidden(true);
}

void winMain::fWindLogoFade()
{
    if (faderWidget) faderWidget->close();
    faderWidget = new FaderWidget(labLogo);
    faderWidget->start();
}

void winMain::fWindScre(QString sW)
{
    if (sW == "m" || sW == "a")
    {
        gMenuTopy = gScre ? gWindHeig - gMenuHeig : 0;
        fraMenu->setGeometry(gMenuLefx, gMenuTopy, gMenuWidt, gMenuHeig);
        gMessTopy = gScre ? gMenuTopy - 150 : gMenuHeig + 10;
    }
    if (sW == "s" || sW == "a")
    {
        gSettTopy = gScre ? (gWindHeig - gMenuHeig - gSettHeig - 10) : (gMenuTopy + gMenuHeig + 30);
        diaSett->setGeometry(gSettLefx, gSettTopy, gSettWidt, gSettHeig);
    }
    if (sW == "g" || sW == "a")
    {
        gGridTopy = gScre ? (gWindHeig - gMenuHeig - gGridHeig - 10) : (gMenuTopy + gMenuHeig + 30);
        fGridGeom();
    }
    if (sW == "f" || sW == "a")
    {
        gFileTopy = gScre ? (gWindHeig - gMenuHeig - gFileHeig - 40) : (gMenuTopy + gMenuHeig);
    }
    if (sW == "r" || sW == "a")
    {
        int iSlidMaxi = -1 * (gScre ? 1 : gMenuTopy + gMenuHeig + 1);                                       // top
        int iSlidMini = -1 * (gScre ? gWindHeig - gMenuHeig - gRowsHeig - 5: gWindHeig - gRowsHeig - 5);    // bottom

        int iP = gRowsTopy;                     // must be placed here, before setRange() that re-init the value

        sliRows->setRange(iSlidMini, iSlidMaxi);
        sliRowsLocV->setRange(iSlidMini, iSlidMaxi);
        sliRowsLocV->setValue(iP);
    }
    if (sW == "i" || sW == "a")
    {
        gInfoTopy = gScre ? (gGridTopy - gInfoHeig - 55) : (gMenuTopy + gMenuHeig + 20);
    }
}

void winMain::fWindBack()
{
    if (radWindBacB->isChecked()) gWindBack = "#000000";
    if (radWindBacG->isChecked()) gWindBack = "#575757";

    gWindStyl = "background-color:"+ gWindBack +";color:#ffffff;";
    winWind->setStyleSheet(gWindStyl);

    gMaskStyl = "background-color:"+ gWindBack +";";
}

void winMain::fWindClear()
{
    radWindBacB->setChecked(true);
    fWindBack();
}

void winMain::fWindPosiMess(QMessageBox *messBox)
{
    int iScreBott = this->frameGeometry().bottom();
    int iScreMidd = this->frameGeometry().width() / 2;
    int iMenuBott = fraMenu->frameGeometry().bottom();
    int iMenuTopy = fraMenu->frameGeometry().top();
    messBox->show();    // needed to get the correct box's dimensions
    int iMessHeig = messBox->frameGeometry().height();
    int iMessMidd = messBox->frameGeometry().width() / 2;

    if (iMenuBott + iMessHeig < iScreBott) messBox->move(iScreMidd - iMessMidd, iMenuBott + 6);
    else messBox->move(iScreMidd - iMessMidd, iMenuTopy - iMessHeig - 6);
}

void winMain::fWindPosiDial(QDialog *dialBox)
{
    int iScreBott = this->frameGeometry().bottom();
    int iScreMidd = this->frameGeometry().width() / 2;
    int iMenuBott = fraMenu->frameGeometry().bottom();
    int iMenuTopy = fraMenu->frameGeometry().top();
    dialBox->show();    // needed to get the correct box's dimensions
    int iMessHeig = dialBox->frameGeometry().height();
    int iMessMidd = dialBox->frameGeometry().width() / 2;

    if (iMenuBott + iMessHeig < iScreBott) dialBox->move(iScreMidd - iMessMidd, iMenuBott + 1);
    else dialBox->move(iScreMidd - iMessMidd, iMenuTopy - iMessHeig - 1);
}

void winMain::fWindPosiProg(QProgressDialog &dialBox)
{
    int iScreBott = this->frameGeometry().bottom();
    int iScreMidd = this->frameGeometry().width() / 2;
    int iMenuBott = fraMenu->frameGeometry().bottom();
    int iMenuTopy = fraMenu->frameGeometry().top();
    dialBox.show();    // needed to get the correct box's dimensions
    int iMessHeig = dialBox.frameGeometry().height();
    int iMessMidd = dialBox.frameGeometry().width() / 2;

    if (iMenuBott + iMessHeig < iScreBott) dialBox.move(iScreMidd - iMessMidd, iMenuBott + 1);
    else dialBox.move(iScreMidd - iMessMidd, iMenuTopy - iMessHeig - 1);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// menu functions
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void winMain::fMenuCrea()
{
    gMenuWidt = 386;
    gMenuHeig = 40;

    gMenuLefx = (gWindWidt - gMenuWidt) / 2;
    gMenuTopy = gWindHeig - gMenuHeig;

    gMessLefx = (gWindWidt - 240) / 2;
    gMessTopy = gMenuTopy - 120;

    fraMenu = new QFrame(winWind);
    fraMenu->setStyleSheet(gMenuStyl);
    fraMenu->setFrameShape(QFrame::NoFrame);
    fraMenu->setGeometry(gMenuLefx, gMenuTopy, gMenuWidt, gMenuHeig);
    fraMenu->setCursor(Qt::ArrowCursor);
    fraMenu->setFocusPolicy(Qt::NoFocus);   // very important for keyboard events

    // right aligned

    butExit = new QPushButton(gIconExit,fL("Quit"),fraMenu);
    connect(butExit, SIGNAL(clicked()), this, SLOT(fWindExitDial()));
    butExit->setFocusPolicy(Qt::NoFocus);   // very important for keyboard events
    butExit->move(gMenuWidt - 80, 7);
    butFile = new QPushButton(gIconFile,fL("Open"),fraMenu);
    connect(butFile, SIGNAL(clicked()), this, SLOT(fFileDial()));
    butFile->setFocusPolicy(Qt::NoFocus);   // very important for keyboard events
    butFile->move(gMenuWidt - 160, 7);
    butSett = new QPushButton(gIconSett,fL("Settings"),fraMenu);
    connect(butSett, SIGNAL(clicked()), this, SLOT(fSettShow()));
    butSett->setFocusPolicy(Qt::NoFocus);   // very important for keyboard events
    butSett->move(gMenuWidt - 240, 7);
    butClea = new QPushButton(gIconClea,fL("Reset"),fraMenu);
    connect(butClea, SIGNAL(clicked()), this, SLOT(fClearAllDial()));
    butClea->setFocusPolicy(Qt::NoFocus);   // very important for keyboard events
    butClea->move(gMenuWidt - 320, 7);

    labClok = new QLabel("00:00:00", fraMenu);
    labClok->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labClok->setStyleSheet(gClokStyl);
    labClok->setGeometry(gMenuWidt - 380, 8, 50, 20);
    tmrClok = new QTimer(this);
    connect(tmrClok, SIGNAL(timeout()), this, SLOT(fMenuClok()));
    tmrClok->start(1000);

    // left aligned

    butRoll = new butToolC(fraMenu);
    butRoll->gLang = gLang;
    butRoll->parText = "Hide/Show screen [N]";
    butRoll->resize(35, 35);
    butRoll->setContentsMargins(0, 0, 0, 0);
    butRoll->setIconSize(QSize(32, 32));
    butRoll->setIcon(gIconRollOpen);
    butRoll->move(10, 3);
    connect(butRoll, SIGNAL(clicked()), this, SLOT(fRowsShowSlot()));
    butRoll->hide();

    labTime = new QLabel("00:00:00", fraMenu);
    labTime->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labTime->setStyleSheet(gTimeStyl);
    labTime->setGeometry(70, 8, 70, 20);
    labTime->hide();

    // in between aligned

    butProjUpup = new butToolC(fraMenu);
    butProjUpup->gLang = gLang;
    butProjUpup->parText = "Previous subtitle [Up]";
    butProjUpup->resize(35, 35);
    butProjUpup->setContentsMargins(0, 0, 0, 0);
    butProjUpup->setIconSize(QSize(32, 32));
    butProjUpup->setIcon(gIconUpup);
    butProjUpup->move(200, 3);
    connect(butProjUpup, SIGNAL(clicked()), this, SLOT(fButtPrev()));
    butProjUpup->hide();

    butProjDown = new butToolC(fraMenu);
    butProjDown->gLang = gLang;
    butProjDown->parText = "Next subtitle [Down]";
    butProjDown->resize(35, 35);
    butProjDown->setContentsMargins(0, 0, 0, 0);
    butProjDown->setIconSize(QSize(32, 32));
    butProjDown->setIcon(gIconDown);
    butProjDown->move(250, 3);
    connect(butProjDown, SIGNAL(clicked()), this, SLOT(fButtNext()));
    butProjDown->hide();

    butProjPlay = new butToolC(fraMenu);
    butProjPlay->gLang = gLang;
    butProjPlay->parText = "Start/Pause timer [Space]";
    butProjPlay->resize(65, 35);
    butProjPlay->setContentsMargins(0, 0, 0, 0);
    butProjPlay->setIconSize(QSize(64, 32));
    butProjPlay->setIcon(gIconPlay);
    butProjPlay->move(300, 3);
    connect(butProjPlay, SIGNAL(clicked()), this, SLOT(fAutoStar()));
    butProjPlay->hide();

    butProjDece = new butToolC(fraMenu);
    butProjDece->gLang = gLang;
    butProjDece->parText = "Decelerate [-] or [M]";
    butProjDece->resize(35, 35);
    butProjDece->setContentsMargins(0, 0, 0, 0);
    butProjDece->setIconSize(QSize(24, 24));
    butProjDece->setIcon(gIconDece);
    butProjDece->move(380, 3);
    connect(butProjDece, SIGNAL(clicked()), this, SLOT(fAutoDece()));
    butProjDece->hide();

    labPuls = new QLabel("", fraMenu);
    labPuls->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labPuls->setStyleSheet(gPulsStyl);
    labPuls->setGeometry(416, 9, 24, 20);
    labPuls->hide();

    butProjAcce = new butToolC(fraMenu);
    butProjAcce->gLang = gLang;
    butProjAcce->parText = "Accelerate [+] or [P]";
    butProjAcce->resize(35, 35);
    butProjAcce->setContentsMargins(0, 0, 0, 0);
    butProjAcce->setIconSize(QSize(24, 24));
    butProjAcce->setIcon(gIconAcce);
    butProjAcce->move(441, 3);
    connect(butProjAcce, SIGNAL(clicked()), this, SLOT(fAutoAcce()));
    butProjAcce->hide();

    butProjBack = new butToolC(fraMenu);
    butProjBack->gLang = gLang;
    butProjBack->parText = "Jump backwards [Left]";
    butProjBack->resize(35, 35);
    butProjBack->setContentsMargins(0, 0, 0, 0);
    butProjBack->setIconSize(QSize(24, 24));
    butProjBack->setIcon(gIconJumpBack);
    butProjBack->move(491, 3);
    connect(butProjBack, SIGNAL(clicked()), this, SLOT(fAutoBack()));
    butProjBack->hide();

    labJump = new QLabel("", fraMenu);
    labJump->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labJump->setStyleSheet(gPulsStyl);
    labJump->setGeometry(528, 9, 20, 20);
    labJump->hide();

    butProjJump = new butToolC(fraMenu);
    butProjJump->gLang = gLang;
    butProjJump->parText = "Jump forward [Right]";
    butProjJump->resize(35, 35);
    butProjJump->setContentsMargins(0, 0, 0, 0);
    butProjJump->setIconSize(QSize(24, 24));
    butProjJump->setIcon(gIconJump);
    butProjJump->move(552, 3);
    connect(butProjJump, SIGNAL(clicked()), this, SLOT(fAutoJump()));
    butProjJump->hide();
}

void winMain::fMenuAdapt(int m)   // 0=init, 1=manu, 2=auto
{
    int iP;

    if (m==0)
    {
        gMenuWidt = 386;
        gMenuHeig = 40;
        gMenuLefx = (gWindWidt - gMenuWidt) / 2;
        gMenuTopy = gWindHeig - gMenuHeig;

        // right aligned

        iP = gMenuWidt;
        iP -= 80; butExit->move(iP, 7);
        iP -= 80; butFile->move(iP, 7);
        iP -= 80; butSett->move(iP, 7);
        iP -= 80; butClea->move(iP, 7);
        iP -= 60; labClok->setGeometry(iP, 8, 50, 20);

        // left aligned

        butRoll->hide();
        labTime->hide();
        butProjUpup->hide();
        butProjDown->hide();
        butProjPlay->hide();
        butProjDece->hide();
        labPuls->hide();
        butProjAcce->hide();
        butProjBack->hide();
        labJump->hide();
        butProjJump->hide();
    }
    else if (m==1)
    {
        gMenuWidt = 510;
        gMenuLefx = (gWindWidt - gMenuWidt) / 2;

        // right aligned

        iP = gMenuWidt;
        iP -= 80; butExit->move(iP, 7);
        iP -= 80; butFile->move(iP, 7);
        iP -= 80; butSett->move(iP, 7);
        iP -= 80; butClea->move(iP, 7);
        iP -= 60; labClok->setGeometry(iP, 8, 50, 20);

        // left aligned

        iP = 0;
        iP += 7; butRoll->move(iP, 3);
        butRoll->show();
        labTime->hide();
        iP += 40; butProjUpup->move(iP, 3);
        butProjUpup->show();
        iP += 40; butProjDown->move(iP, 3);
        butProjDown->show();
        butProjPlay->hide();
        butProjDece->hide();
        labPuls->hide();
        butProjAcce->hide();
        butProjBack->hide();
        labJump->hide();
        butProjJump->hide();
    }
    else if (m==2)
    {
        gMenuWidt = 870;
        gMenuLefx = (gWindWidt - gMenuWidt) / 2;

        // right aligned

        iP = gMenuWidt;
        iP -= 80; butExit->move(iP, 7);
        iP -= 80; butFile->move(iP, 7);
        iP -= 80; butSett->move(iP, 7);
        iP -= 80; butClea->move(iP, 7);
        iP -= 60; labClok->setGeometry(iP, 8, 50, 20);

        // left aligned

        iP = 0;
        iP += 7; butRoll->move(iP, 3);
        butRoll->show();
        iP += 40; butProjUpup->move(iP, 3);
        butProjUpup->show();
        iP += 40; butProjDown->move(iP, 3);
        butProjDown->show();
        iP += 45; labTime->setGeometry(iP, 8, 50, 20);
        labTime->show();
        iP += 60; butProjPlay->move(iP, 3);
        butProjPlay->show();
        iP += 80; butProjDece->move(iP, 3);
        butProjDece->show();
        iP += 35; labPuls->setGeometry(iP, 9, 24, 20);
        labPuls->show();
        iP += 24; butProjAcce->move(iP, 3);
        butProjAcce->show();
        iP += 50; butProjBack->move(iP, 3);
        butProjBack->show();
        iP += 35; labJump->setGeometry(iP, 9, 24, 20);
        labJump->show();
        iP += 24; butProjJump->move(iP, 3);
        butProjJump->show();
    }

    gMessLefx = (gWindWidt - 240) / 2;
    gMessTopy = gMenuTopy - 120;
    fraMenu->setGeometry(gMenuLefx, gMenuTopy, gMenuWidt, gMenuHeig);
}

void winMain::fMenuClok()
{
    labClok->setText(QTime::currentTime().toString("hh:mm:ss"));

    static int iP = 0;
    iP++;
    if (iP == 1) fWindLogoFade();
    if (iP == 3) fWindLogoHide();
}

void winMain::fMenuClear()
{
    labTime->hide();
    butRoll->hide();
    butProjUpup->hide();
    butProjDown->hide();
    butProjPlay->hide();
    butProjDece->hide();
    labPuls->hide();
    butProjAcce->hide();
    butProjBack->hide();
    labJump->hide();                                    // gpb 110930
    butProjJump->hide();
    fMenuAdapt(0);                                      // gpb 111123
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// rows functions
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void winMain::fRowsCrea()
{
    gRowsWmax = gWindWidt - 2;
    gRowsWidt = gRowsWmax / 2;                          // gpb 120305
    gRowsHeig = 45 * gRowsNumb;
    gRowsLefx = 1 + ((gWindWidt-gRowsWidt-2) / 2);      // gpb 120305
    gRowsTopy = 1;
    gRowsSpac = 1;

    gRowsCharMaxi = 99;

    texRow1 = new QTextEdit("");
    texRow1->setReadOnly(true);
    texRow1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    texRow1->setFrameShape(QFrame::NoFrame);
    texRow1->setContentsMargins(0, 0, 0, 0);
    texRow1->setWordWrapMode(QTextOption::NoWrap);
    texRow1->horizontalScrollBar()->setFixedHeight(0);
    texRow1->setFont(gRowsFont);
    texRow1->setStyleSheet(gRowsStyl);
    texRow1->document()->setDocumentMargin(0);
    texRow1->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    texRow2 = new QTextEdit("");
    texRow2->setReadOnly(true);
    texRow2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    texRow2->setFrameShape(QFrame::NoFrame);
    texRow2->setContentsMargins(0, 0, 0, 0);
    texRow2->setWordWrapMode(QTextOption::NoWrap);
    texRow2->setFont(gRowsFont);
    texRow2->setStyleSheet(gRowsStyl);
    texRow2->document()->setDocumentMargin(0);
    texRow2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    texRow3 = new QTextEdit("");
    texRow3->setReadOnly(true);
    texRow3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    texRow3->setFrameShape(QFrame::NoFrame);
    texRow3->setContentsMargins(0, 0, 0, 0);
    texRow3->setWordWrapMode(QTextOption::NoWrap);
    texRow3->setFont(gRowsFont);
    texRow3->setStyleSheet(gRowsStyl);
    texRow3->document()->setDocumentMargin(0);
    texRow3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    texRow4 = new QTextEdit("");
    texRow4->setReadOnly(true);
    texRow4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    texRow4->setFrameShape(QFrame::NoFrame);
    texRow4->setContentsMargins(0, 0, 0, 0);
    texRow4->setFont(gRowsFont);
    texRow4->setStyleSheet(gRowsStyl);
    texRow4->setWordWrapMode(QTextOption::NoWrap);
    texRow4->document()->setDocumentMargin(0);
    texRow4->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    layRows = new QVBoxLayout;
    layRows->setSpacing(gRowsSpac);
    layRows->setContentsMargins(0, 0, 0, 0);
    layRows->addWidget(texRow1);
    layRows->addWidget(texRow2);
    layRows->addWidget(texRow3);
    layRows->addWidget(texRow4);

    fraRows = new QFrame(winWind);
    fraRows->setFrameShape(QFrame::NoFrame);
    fraRows->setGeometry(gRowsLefx, gRowsTopy, gRowsWidt, gRowsHeig);
    fraRows->setContentsMargins(0, 0, 0, 0);
    fraRows->setLayout(layRows);

    fraMask = new QFrame(this);
    fraMask->setCursor(QCursor(gIconCurH, -1, -1));
    fraMask->setFrameShape(QFrame::NoFrame);
    fraMask->setWindowOpacity(0);
    fraMask->setGeometry(gRowsLefx, gRowsTopy, gRowsWidt, gRowsHeig);
}

void winMain::fRowsInit()                               // gpb 120220
{
    if (!gSettShow && !gGridShow)
    {
        texRow1->setHtml("");
        texRow2->setHtml("");
        texRow3->setHtml("");
        texRow4->setHtml("");

        fRowsNumb();
        fRowsTextForm();
        fRowsTextAlig();
        fRowsShow(true);
    }
    if (gSettShow && !gGridShow)
    {
        QString s1 = fL("Line") + " 1 - " + fL("Line") + " 1";
        QString s2 = fL("Line") + " 2 - " + fL("Line") + " 2";
        QString s3 = fL("Line") + " 3 - " + fL("Line") + " 3";
        QString s4 = fL("Line") + " 4 - " + fL("Line") + " 4";

        if (gSecoText) s2 = fL("Line") + " 2 / " + fL("Line") + " 1";
        if (gSecoItal) s2 = "<i>" + s2 + "</i>";

        texRow1->setHtml(s1);
        texRow2->setHtml(s2);
        texRow3->setHtml(s3);
        texRow4->setHtml(s4);

        radRow4->setChecked(true);
        fRowsNumb();
        fRowsTextForm();
        fRowsTextAlig();
        fRowsShow(true);
    }
}

void winMain::fRowsFram()
{
    int iH = gRowsHeig + (gRowsNumb * gRowsSpac);
    fraRows->setGeometry(gRowsLefx, abs(gRowsTopy), gRowsWidt, iH);
    fraMask->setGeometry(gRowsLefx, abs(gRowsTopy), gRowsWidt, iH);
    sliRows->setRange(-1 * (gWindHeig - iH - 1), -1);
    sliRowsLocV->setRange(-1 * (gWindHeig - iH - 1), -1);
}

void winMain::fRowsWidt(int pWidt)
{
    gRowsWidt = pWidt;
    sliRowsLocH->setRange(-1 * (gWindWidt-gRowsWidt-2), 0);
    fRowsFram();
}

void winMain::fRowsHeig(int pHeig)
{
    gRowsHeig = gRowsNumb * pHeig;
    fRowsTextForm();
    fRowsFram();
}

void winMain::fRowsHeigCalc()
{
    int iHeig = gRowsFont.pointSize()+8;
    int iRowsHeig = gRowsNumb * iHeig;
    if (iRowsHeig != gRowsHeig)
    {
        gRowsHeig = iRowsHeig;
        sliRowsHeig->setMinimum(iHeig);
        sliRowsHeig->setMaximum(3*iHeig);
        fWindScre("r");
    }
    fRowsFram();
}

void winMain::fRowsLocV(int pY)
{
    gRowsTopy = pY;
    fRowsFram();
    if (sliRows->value() != pY) sliRows->setValue(pY);
}

void winMain::fRowsLocH(int pX)
{
    gRowsLefx = 1 + abs(pX);
    fRowsFram();
}

void winMain::fRowsPosi(int pY)
{
    sliRowsLocV->setValue(pY);
}

void winMain::fRowsSpac(int pS)
{
    gRowsSpac = pS;
    layRows->setSpacing(gRowsSpac);
    fRowsFram();
}

void winMain::fRowsTextForm()
{
    gRowsStyl = "";
    gRowsStyl += QString("background-color:%1;").arg(gRowsBack);
    gRowsStyl += QString("color:%1;").arg(gRowsColo);
    gRowsStyl += QString("font-family:'%1';").arg(gRowsFont.family());
    gRowsStyl += QString("font-size:%1px;").arg(gRowsFont.pointSize());
    if (gRowsFont.bold()) gRowsStyl += "font-weight:bold;";
    if (gRowsFont.italic()) gRowsStyl += "font-style:italic;";


    if (gRowsFont.underline()) gRowsStyl += "text-decoration:underline;";
    gRowsStyl += "margin-top:0px;margin-left:0px;";
    gRowsStyl += "padding-left:0px;padding-right:0px;";

    int iRowH = sliRowsHeig->value();
    int iFonH = gRowsFont.pointSize();
    if (radTopy->isChecked()) gRowsStyl += "padding-top:0px;";
    if (radCenV->isChecked()) gRowsStyl += QString("padding-top:%1px;").arg((iRowH-iFonH-4)/2);
    if (radBott->isChecked()) gRowsStyl += QString("padding-top:%1px;").arg(iRowH-iFonH-4);

    texRow1->setStyleSheet(gRowsStyl);
    texRow2->setStyleSheet(gRowsStyl);
    texRow3->setStyleSheet(gRowsStyl);
    texRow4->setStyleSheet(gRowsStyl);

    QTextCharFormat cf;
    QPen pen;
    if (gOutlThik == 0)
    {
        pen.setStyle(Qt::NoPen);
    }
    else
    {
        pen.setStyle(Qt::SolidLine);
        pen.setColor(gOutlColo);
        pen.setWidth(gOutlThik);
    }
    cf.setTextOutline(pen);

    fRowsTextOutl(texRow1, cf);
    if (gRowsNumb > 1) fRowsTextOutl(texRow2, cf);
    if (gRowsNumb > 2) fRowsTextOutl(texRow3, cf);
    if (gRowsNumb > 3) fRowsTextOutl(texRow4, cf);
}

void winMain::fRowsTextOutl(QTextEdit *e, QTextCharFormat f)
{
    QTextDocument *d = e->document();
    QTextCursor c(d);
    c.movePosition(QTextCursor::StartOfLine);
    c.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    c.mergeCharFormat(f);
}

void winMain::fRowsOutlDial()
{
    QColor cColo = QColorDialog::getColor(gOutlColo, this, fL("Outline colour"));
    if (gOutlColo != cColo)
    {
        gOutlColo = cColo;
        if (radNone->isChecked()) radThin->setChecked(true);
        fRowsOutlThik();
    }
}

void winMain::fRowsOutlThik()
{
    if (radNone->isChecked()) gOutlThik = 0;
    if (radThin->isChecked()) gOutlThik = 1;
    if (radBold->isChecked()) gOutlThik = 2;
    fRowsTextForm();
}

void winMain::fRowsSeco(int iChck)
{
    gSecoText = false;
    if (iChck) gSecoText = true;

    if (gWork) fGridRows(griText->currentRow());
    else fRowsInit();
}

void winMain::fRowsItal(int iChck)
{
    gSecoItal = false;
    if (iChck) gSecoItal = true;

    if (gWork) fGridRows(griText->currentRow());
    else fRowsInit();
}

void winMain::fRowsColoDial()
{
    QColor cColo = QColorDialog::getColor(QColor(gRowsColo), this, fL("Text colour"));
    if (gRowsColo != cColo.name())
    {
        gRowsColo = cColo.name();
        fRowsTextForm();
    }
}

void winMain::fRowsBackDial()
{
    QColor cColo = QColorDialog::getColor(QColor(gRowsBack), this, fL("Background colour"));
    if (gRowsBack != cColo.name())
    {
        gRowsBack = cColo.name();
        fRowsTextForm();
    }
}

void winMain::fRowsClear()
{
    texRow1->setHtml("");
    texRow2->setHtml("");
    texRow3->setHtml("");
    texRow4->setHtml("");
    fRowsTextForm();
}

void winMain::fRowsTextAlig()
{
    if (radLeft->isChecked()) texRow1->setAlignment(Qt::AlignLeft);
    if (radCenH->isChecked()) texRow1->setAlignment(Qt::AlignHCenter);
    if (radRigh->isChecked()) texRow1->setAlignment(Qt::AlignRight);
    texRow2->setAlignment(texRow1->alignment());
    texRow3->setAlignment(texRow1->alignment());
    texRow4->setAlignment(texRow1->alignment());
    fRowsTextForm();
}

void winMain::fRowsNumb()
{
    if (radRow1->isChecked())
    {
        gRowsNumb = 1;
        texRow2->setHidden(true);
        texRow3->setHidden(true);
        texRow4->setHidden(true);
    }
    if (radRow2->isChecked())
    {
        gRowsNumb = 2;
        texRow2->setHidden(false);
        texRow3->setHidden(true);
        texRow4->setHidden(true);
    }
    if (radRow3->isChecked())
    {
        gRowsNumb = 3;
        texRow2->setHidden(false);
        texRow3->setHidden(false);
        texRow4->setHidden(true);
    }
    if (radRow4->isChecked())
    {
        gRowsNumb = 4;
        texRow2->setHidden(false);
        texRow3->setHidden(false);
        texRow4->setHidden(false);
    }
    fRowsHeig(sliRowsHeig->value());
    if (gGridShow) fGridInit();
}

void winMain::fRowsNumbBloc()
{
    radRow1->setDisabled(true);
    radRow2->setDisabled(true);
    radRow3->setDisabled(true);
    radRow4->setDisabled(true);

    texRowsNumb->setStyleSheet(gTitlDisa);
    radRow1->setStyleSheet(gExplDisa);
    radRow2->setStyleSheet(gExplDisa);
    radRow3->setStyleSheet(gExplDisa);
    radRow4->setStyleSheet(gExplDisa);
}

void winMain::fRowsFontDial()
{
    fFileInfoClos();

    bool bModi = false;
    QFont fFont = QFontDialog::getFont(&bModi, gRowsFont, this, fL("Font"));
    if (bModi)
    {
        gRowsFont = fFont;
        fRowsFontChan();
    }
}

void winMain::fRowsFontChan()
{
    fRowsHeigCalc();
    fRowsTextForm();
    if (gWork) fRowsPixxCalc();
}

void winMain::fRowsPixxCalc()
{
    QFontMetrics mRows = QFontMetrics(gRowsFont);
    int iM;
    QString sT;

    for (iM = 0; iM < 9; iM++)
    {
        sT = griText->item(gFileMaxiRows[iM], gFileMaxiColo[iM])->text();
        gFileMaxiLeng[iM] = mRows.width(sT);
    }
}

void winMain::fRowsShowSlot()
{
    fRowsShow(-1);
}

void winMain::fRowsShow(int pShow)
{
    static int sShow = 1;

    if (pShow!=-1) sShow = pShow;
    else sShow = sShow == 0 ? 1 : 0;

    if (sShow==1)
    {
        fraMask->setStyleSheet("");
        fraMask->setWindowOpacity(0);
        butRoll->setIcon(gIconRollOpen);
    }
    else
    {
        fraMask->setStyleSheet(gMaskStyl);
        fraMask->setWindowOpacity(1);
        butRoll->setIcon(gIconRollClos);
    }
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// grid functions
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void winMain::fGridCrea()
{
    gGridModi = 0;
    gGridInfo = 0;

    gGridRowsHeig = 18;

    gGridWidtBase = gWindWidt - 20;
    gGridWidt = gGridWidtBase;
    gGridLefx = 10;
    gGridHeig = 132;
    gGridTopy = gWindHeig - gMenuHeig - gGridHeig - 8;

    diaGrid = new diaGridW(this, fraMenu);
    diaGrid->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    diaGrid->setCursor(Qt::ArrowCursor);
    diaGrid->setMinimumHeight(gGridHeig);
    diaGrid->setMaximumHeight((gWindHeig - gGridHeig) / 2);
    diaGrid->setContentsMargins(0, 0, 0, 0);
    diaGrid->setStyleSheet(gGridStyl);

    // slider is defined before the grid because slider is a parameter of the grid

    QFrame *fraGridButt = new QFrame;
    fraGridButt->setMinimumWidth(108);
    fraGridButt->setContentsMargins(10, 0, 0, 0);

    sliRows = new QSlider(Qt::Vertical, fraGridButt);
    sliRows->move(78, 11);
    sliRows->setStyleSheet(gMenuStyl);
    sliRows->setTickPosition(QSlider::NoTicks);
    sliRows->setRange(-1 * (gWindHeig - gRowsHeig - 1), -1);
    sliRows->setValue(gWindHeig - gRowsHeig);
    sliRows->setFixedWidth(20);
    sliRows->setFixedHeight(85);
    connect(sliRows, SIGNAL(valueChanged(int)), this, SLOT(fRowsPosi(int)));

    // grid

    fGridGeom();

    griText = new diaGridC(diaGrid, sliRows, this);
    griText->setGeometry(0, 0, gGridWidt - 10, gGridHeig - 10);
    griText->setSelectionBehavior(QAbstractItemView::SelectRows);
    griText->setSelectionMode(QAbstractItemView::SingleSelection);
    griText->setStyleSheet(gGriCStyl);
    connect(griText, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(fGridChan(int, int, int, int)));
    connect(griText, SIGNAL(cellClicked(int, int)), this, SLOT(fGridClic(int, int)));

    // other buttons

    butGridEdit = new butToolC(fraGridButt);
    butGridEdit->gLang = gLang;
    butGridEdit->parText = "Edit text/timecode [Ctrl+E]";
    butGridEdit->resize(28, 28);
    butGridEdit->setContentsMargins(0, 0, 0, 0);
    butGridEdit->setIconSize(QSize(28, 28));
    butGridEdit->setIcon(gIconEditEnab);
    butGridEdit->move(10, 10);
    connect(butGridEdit, SIGNAL(clicked()), this, SLOT(fGridEditButt()));

    butGridInfo = new butToolC(fraGridButt);
    butGridInfo->gLang = gLang;
    butGridInfo->parText = "File info [Ctrl+I]";
    butGridInfo->resize(28, 28);
    butGridInfo->setContentsMargins(0, 0, 0, 0);
    butGridInfo->setIconSize(QSize(28, 28));
    butGridInfo->setIcon(gIconInfoEnab);
    butGridInfo->move(40, 10);
    connect(butGridInfo, SIGNAL(clicked()), this, SLOT(fFileInfo()));

    butGridSave = new butToolC(fraGridButt);
    butGridSave->gLang = gLang;
    butGridSave->parText = "Save modified file as...";
    butGridSave->resize(28, 28);
    butGridSave->setContentsMargins(0, 0, 0, 0);
    butGridSave->setIconSize(QSize(28, 28));
    butGridSave->setIcon(gIconSaveDisa);
    butGridSave->move(10, 40);
    connect(butGridSave, SIGNAL(clicked()), this, SLOT(fGridSave()));

    butGridUndo = new butToolC(fraGridButt);
    butGridUndo->gLang = gLang;
    butGridUndo->parText = "Undo changes (in reverse chronology) [Ctrl+Z]";
    butGridUndo->resize(28, 28);
    butGridUndo->setContentsMargins(0, 0, 0, 0);
    butGridUndo->setIconSize(QSize(28, 28));
    butGridUndo->setIcon(gIconUndoDisa);
    butGridUndo->move(40, 40);
    connect(butGridUndo, SIGNAL(clicked()), this, SLOT(fGridUndo()));

    butGridGoto = new butToolC(fraGridButt);
    butGridGoto->gLang = gLang;
    butGridGoto->parText = "Go to... [Ctrl+G]";
    butGridGoto->resize(28, 28);
    butGridGoto->setContentsMargins(0, 0, 0, 0);
    butGridGoto->setIconSize(QSize(28, 28));
    butGridGoto->setIcon(gIconGotoEnab);
    butGridGoto->move(10, 70);
    connect(butGridGoto, SIGNAL(clicked()), this, SLOT(fGridGoto()));

    butGridFind = new butToolC(fraGridButt);
    butGridFind->gLang = gLang;
    butGridFind->parText = "Find... [Ctrl+F]";
    butGridFind->resize(28, 28);
    butGridFind->setContentsMargins(0, 0, 0, 0);
    butGridFind->setIconSize(QSize(28, 28));
    butGridFind->setIcon(gIconFindEnab);
    butGridFind->move(40, 70);
    connect(butGridFind, SIGNAL(clicked()), this, SLOT(fGridFind()));

    sliLigh = new QSlider(Qt::Horizontal, fraGridButt); // gpb 120316
    sliLigh->move(10, 120);
    sliLigh->setStyleSheet(gMenuStyl);
    sliLigh->setTickPosition(QSlider::NoTicks);
    sliLigh->setRange(0, 1);
    sliLigh->setValue(0);
    sliLigh->setFixedWidth(30);
    sliLigh->setFixedHeight(10);
    connect(sliLigh, SIGNAL(valueChanged(int)), this, SLOT(fGridLight(int)));
    sliLigh->setValue(1);

    layGrid = new QGridLayout;
    layGrid->setContentsMargins(0, 0, 0, 0);
    layGrid->setHorizontalSpacing(0);
    layGrid->addWidget(griText, 0, 0);
    layGrid->addWidget(fraGridButt, 0, 1);
    diaGrid->setLayout(layGrid);
}

void winMain::fGridLight(int pC)                        // gpb 120316
{
    QString sColo = "#000000";
    QString sBack = "#ffffff";
    QString sSele = "#ffff33";
    QString sRest = "selection-color:#000000;selection-background-color:";
    if      (pC==0) {sBack = "#eeeeee";}
    else {sBack = "#222222";sColo = "#ffffff";sSele = "#00ff00";}
    gGriCStyl = "background-color:" + sBack + ";color:" + sColo + ";" + sRest + sSele + ";";
    griText->setStyleSheet(gGriCStyl);

    QString sStyl = "QFrame#fraMenu {border:1px solid #ffffff;background-color:#151515;color:#ffffff;} ";
    sStyl = sStyl + "QPushButton {min-height:20px;max-height:20px;min-width:70px;max-width:90px;background-color:#202020;color:#ffffff;border:1px solid #555555;border-radius:3px;text-align:left;padding-left:2px;} ";
    sStyl = sStyl + "QPushButton:hover {border-color:#4a90d9;} ";
    sStyl = sStyl + "QTabWidget {font:arial normal 8px;background-color:#151515;color:#ffffff;border:none;} ";
    sStyl = sStyl + "QTabWidget::pane {font:arial normal 8px;background-color:#151515;color:#ffffff;border:none;} ";
    sStyl = sStyl + "QTabWidget::tab-bar {font:arial normal 8px;background-color:#151515;color:#ffffff;} ";
    sStyl = sStyl + "QTabWidget::tab {border:1px solid #ffffff;border-bottom-color:#151515;margin:5px;width:70px;height:20px;} ";
    sStyl = sStyl + "QTabBar::tab:selected {background-color:#151515;color:#4a90d9;width:70px;height:20px;margin-bottom:1px;margin-right:6px;border:1px solid #555555;border-radius:3px;} ";
    sStyl = sStyl + "QTabBar::tab:!selected {background-color:#151515;color:#ffffff;width:70px;height:20px;margin-bottom:1px;margin-right:6px;border:1px solid #555555;border-radius:3px;} ";
    sStyl = sStyl + "QTabBar::tab:hover {border-color:#4a90d9;} ";
    sStyl = sStyl + "QHeaderView::section {background-color:" + sBack + ";color:" + sColo + ";font:lucida normal 9px;border:1px solid " + sBack + ";border-right:1px solid #cccccc;border-bottom:1px solid #cccccc;}";

    sStyl = sStyl + "QTableCornerButton::section {background:" +sBack + "; color:" + sBack + ";border:1px solid " + sBack + ";border-right:1px solid #cccccc;border-bottom:1px solid #cccccc;} ";
    sStyl = sStyl + "QToolTip {background-color:#ffffff;color:#000000;border-style:outset;border-width:1px;border-color:#4a90d9;font:lucida bold 9px;padding:0px;} ";
    sStyl = sStyl + "QScrollBar:vertical {width:10px;background:#aaaaaa;margin:10px 0 10px 0;} ";
    sStyl = sStyl + "QScrollBar::handle:vertical {background:#777777;min-height:30px;border-radius:4px;} ";
    sStyl = sStyl + "QScrollBar::handle:hover {background:#4a90d9;} ";
    sStyl = sStyl + "QScrollBar::add-line:vertical {background-image: url(:/Imag/QSTit_scro_down.png); height:12px; subcontrol-position:bottom;subcontrol-origin:margin;} ";
    sStyl = sStyl + "QScrollBar::sub-line:vertical {background-image: url(:/Imag/QSTit_scro_upup.png);height:12px;subcontrol-position:top;subcontrol-origin:margin;} ";
    sStyl = sStyl + "QScrollBar::add-page:vertical {background:none;} ";
    sStyl = sStyl + "QScrollBar::sub-page:vertical {background:none;} ";
    sStyl = sStyl + "QScrollBar:horizontal {height:10px;background:#aaaaaa;margin:0 10px 0 10px;} ";
    sStyl = sStyl + "QScrollBar::handle:horizontal {background:#777777;min-width:30px;border-radius:4px;} ";
    sStyl = sStyl + "QScrollBar::handle:hover {background:#4a90d9;} ";
    sStyl = sStyl + "QScrollBar::add-line:horizontal {background-image: url(:/Imag/QSTit_scro_righ.png); width:12px; subcontrol-position:right;subcontrol-origin:margin;} ";
    sStyl = sStyl + "QScrollBar::sub-line:horizontal {background-image: url(:/Imag/QSTit_scro_left.png);width:12px;subcontrol-position:left;subcontrol-origin:margin;} ";
    sStyl = sStyl + "QScrollBar::add-page:horizontal {background:none;} ";
    sStyl = sStyl + "QScrollBar::sub-page:horizontal {background:none;} ";
    qApp->setStyleSheet(sStyl);

    if (pC==0)
    {
        gGridColoDark=false;
        radGridColo->setChecked(gGridColoDark);
    }
    else if (pC==1)
    {
        gGridColoDark=true;
        radGridColo->setChecked(gGridColoDark);
    }
}

void winMain::fGridItemSetx(QString sText, int iR, int iC)
{
    QTableWidgetItem *wi = new QTableWidgetItem(sText, 0);
    if (gGridHourBold && (iC==1 || iC==2))
    {
        wi->setFont(QFont(gGridFontFami, gGridFontSize, QFont::Bold, false));
    }
    else
    {
        wi->setFont(gGridFont);
    }
    wi->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    griText->setItem(iR, iC, wi);
}

void winMain::fGridEditEnab()
{
    gGridEdit = true;
    butGridEdit->setIcon(gIconEditEnab);
    butGridFind->setIcon(gIconFindEnab);
    butGridGoto->setIcon(gIconGotoEnab);
    butGridInfo->setIcon(gIconInfoEnab);
}

void winMain::fGridEditDisa()
{
    gGridEdit = false;
    butGridEdit->setIcon(gIconEditDisa);
    butGridFind->setIcon(gIconFindDisa);
    butGridGoto->setIcon(gIconGotoDisa);
    butGridInfo->setIcon(gIconInfoDisa);
}

void winMain::fGridSaveIcon()
{
    if (gGridModi > 0)
    {
        butGridSave->setIcon(gIconSaveEnab);
        butGridUndo->setIcon(gIconUndoEnab);
    }
    else
    {
        butGridSave->setIcon(gIconSaveDisa);
        butGridUndo->setIcon(gIconUndoDisa);
    }
}

void winMain::fGridZero()
{
    griText->setRowCount(1);
    griText->setColumnCount(7);
}

void winMain::fGridTitle()                              // gpb 120407
{
    QFileInfo fInfo = QFileInfo(gFile);
    QString sTitl = fInfo.fileName() + "  ·  ";
    sTitl += fL("") + QString("%1").arg(gRowsMaxi-1) + fL(" subtitles ( widest: ") + QString("%1").arg(gFileMaxiRows[0]);
    if (gSrtx) sTitl +=   " · " + fL("last at ") + gSrtxStop.left(8) +" )";
	else sTitl +=   " )";
    diaGrid->setWindowTitle(sTitl);
}

void winMain::fGridInit()
{
    for (int iR = 0; iR < 99; iR++)
    {
        gEditTextRows[iR] = 0;
        gEditTextColu[iR] = 0;
        gEditTextLine[iR] = 0;
        gEditTextOldx[iR] = "";
        gEditTextNewx[iR] = "";
    }
    griText->horizontalHeader()->setFixedHeight(3);
    griText->verticalHeader()->setFixedWidth(35);
    fGridInitCols();
    fGridInitRows();
}

void winMain::fGridInitCols()
{
    int c;
    int cn = gRowsNumb;
    int ct = 180;
    int cwMaxi = 950 / gRowsNumb;
    int cw;

    for (c = 0; c < 7; c++)
    {
        griText->setColumnWidth(c, 0);



    }

    griText->setColumnWidth(0, 22);
    ct += 22;

    if (gSrtx)
    {
        QFontMetrics mGrid = QFontMetrics(gGridFont);
        cw = mGrid.width("99:99:99,999") + 10;
        if (gGridHourBold) cw += 10;

        griText->setColumnWidth(1, cw);
        ct += cw;
        griText->setColumnWidth(2, cw);
        ct += cw;
    }

    cw = gFileMaxiGrid[0] + 20;
    if (cw > cwMaxi) cw = cwMaxi;

    for (c = 0; c < cn; c++)
    {
        griText->setColumnWidth(3+c, cw);
        ct += cw;
    }

    gGridWidtBase = ct;

    fGridGeom();
}

void winMain::fGridInitRows()
{
    if (griText->rowCount() == 0) return;
    for (int iR = 0; iR < griText->rowCount(); iR++)
    {
        griText->setRowHeight(iR, gGridRowsHeig);
        griText->setVerticalHeaderItem(iR, new QTableWidgetItem(QString("%1").arg(iR)));
    }
}

void winMain::fGridShow(bool bShow)
{
    gGridShow = false;
    diaGrid->hide();
    fGridGeom();
    if (bShow)
    {
        gGridShow = true;
        diaGrid->show();
    }
}

void winMain::fGridGeom()
{
    gGridWidt = gGridWidtBase;
    gGridLefx = (gWindWidt - gGridWidt) / 2;
    diaGrid->setGeometry(gGridLefx, gGridTopy, gGridWidt, gGridHeig);
}

QString winMain::fGridTextClean(QString sText)          // 120310
{
    QString sT = sText.trimmed();
    sT.remove("<b>");
    sT.remove("</b>");
    sT.remove("<i>");
    sT.remove("</i>");
    sT.remove("<u>");
    sT.remove("</u>");
    return sT;
}

void winMain::fGridRows(int r)
{
    QString st1 = griText->item(r, 3)->text();
    QString st2 = "";

    if (gRowsNumb > 1)
    {
        st2 = griText->item(r, 4)->text();
        if (gSecoText and st2.isEmpty())
        {
            st2 = st1;
            st1 = "";
        }
        if (gSecoItal)
        {
            st2 = "<i>" + st2 + "</i>";
        }
    }

    texRow1->setHtml(st1);
    if (gRowsNumb > 1) texRow2->setHtml(st2);
    if (gRowsNumb > 2) texRow3->setHtml(griText->item(r, 5)->text());
    if (gRowsNumb > 3) texRow4->setHtml(griText->item(r, 6)->text());

    fRowsTextForm();
    fRowsTextAlig();
}

void winMain::fGridChan(int iR, int iC, int pr, int pc)
{
    griText->setCurrentCell(iR, iC);
    fGridRows(iR);
}

void winMain::fGridClic(int iR, int iC)
{
    if (iC == 0)
    {
        fGridMarkRows(iR);
        return;
    }

    if (gAuto && !gInit)
    {
        griText->setCurrentCell(iR, iC);
        fAutoStarInit();
    }
    if (gAuto && gInit)
    {
        if (gPlay) tmrAuto->stop();
        griText->setCurrentCell(iR, iC);
        fAutoStarInit();
        if (gPlay) tmrAuto->start();
    }
}

void winMain::fGridEditButt()
{
    fGridEdit(griText->currentRow(), griText->currentColumn());
}

void winMain::fGridEdit(int iR, int iC)
{
    if (!gGridEdit || iC == 0 || iR == 0 || iR == gRowsMaxi) return;

    int iLineWidt = griText->columnWidth(iC) + 20;
    int gEditLefx = diaGrid->frameGeometry().x() + 20;
    int gEditTopy = diaGrid->frameGeometry().y() - 10;
    int gEditWidt = iLineWidt + 90;
    int gEditHeig = 70;

    diaEdit = new QDialog(this);
    diaEdit->setWindowTitle(fL("Edit"));
    diaEdit->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    diaEdit->setStyleSheet(gGridStyl);
    diaEdit->setCursor(Qt::ArrowCursor);
    diaEdit->setMinimumWidth(gEditWidt);
    diaEdit->setMaximumWidth(gEditWidt);
    diaEdit->setMinimumHeight(gEditHeig);
    diaEdit->setMaximumHeight(gEditHeig);
    diaEdit->setGeometry(gEditLefx, gEditTopy, gEditWidt, gEditHeig);
    diaEdit->move(gEditLefx, gEditTopy);                // necessary!

    QTableWidgetItem *wi = griText->item(iR, iC);

    QLineEdit *ediLine = new QLineEdit();
    ediLine->setStyleSheet("border:1px solid #202020;background-color:#ffffff;color:#000000;");
    ediLine->setFont(gGridFont);
    ediLine->setEchoMode(QLineEdit::Normal);
    ediLine->setText(QString(wi->text()));
    ediLine->setGeometry(5, 5, iLineWidt, gGridRowsHeig);
    ediLine->setFocus();
    connect(ediLine, SIGNAL(returnPressed()), this, SLOT(fGridEditSave()));

    butEditSave = new QPushButton(gIconOkok, fL("Confirm"));
    connect(butEditSave, SIGNAL(clicked()), this, SLOT(fGridEditSave()));

    butEditCanc = new QPushButton(gIconCanc, fL("Cancel"));
    connect(butEditCanc, SIGNAL(clicked()), this, SLOT(fGridEditCanc()));

    QGridLayout *boxEditButt = new QGridLayout;
    boxEditButt->addWidget(ediLine, 0, 0);
    boxEditButt->addWidget(butEditSave, 0, 1);
    boxEditButt->addWidget(butEditCanc, 1, 1);

    QFrame *fraEditButt = new QFrame;
    fraEditButt->setLayout(boxEditButt);

    QGridLayout *layEdit = new QGridLayout;
    layEdit->setContentsMargins(0, 0, 0, 0);
    layEdit->setHorizontalSpacing(0);
    layEdit->addWidget(fraEditButt, 0, 1);
    diaEdit->setLayout(layEdit);

    gGridEditSave = false;
    QString sTextOrig = wi->text();

    diaEdit->exec();

    if (gGridEditSave && ediLine->isModified())
    {
        gGridSave = true;
        gGridModi++;
        wi->setText(ediLine->text());
        QTableWidgetItem *wic = griText->item(iR, 0);
        wic->setIcon(gIconEdit);
        wic->setText("E");
        fGridSaveIcon();
        fGridRows(iR);
        fGridEditMemo(iR, iC, sTextOrig);
    }

    fGridFocus();
}

void winMain::fGridEditMemo(int iR, int iC, QString sTextOrig)
{
    QTableWidgetItem *wi = griText->item(iR, iC);
    gEditTextRows[gGridModi] = iR;
    gEditTextColu[gGridModi] = iC;
    gEditTextLine[gGridModi] = (iR + 1) / 2;
    gEditTextOldx[gGridModi] = sTextOrig;
    gEditTextNewx[gGridModi] = wi->text();
}

void winMain::fGridEditCanc()
{
    gGridEditSave = false;
    diaEdit->done(0);
}

void winMain::fGridEditSave()
{
    gGridEditSave = true;
    diaEdit->done(0);
}

void winMain::fGridModi()
{
    if (gGridSave)
    {
        QMessageBox *qm = new QMessageBox(QMessageBox::Question, fL("Edit"), fL("The file has been edited.\nSave changes?"), QMessageBox::Yes|QMessageBox::No, this);
        qm->move(diaGrid->frameGeometry().x() + 20, diaGrid->frameGeometry().y() - 10);
        int iRep = qm->exec();
        if (iRep == QMessageBox::Yes) fGridSave();
        else return;
    }
}

void winMain::fGridMarkRows(int iR)
{
    if (iR == 0 || iR == gRowsMaxi) return;

    QTableWidgetItem *wi = griText->item(iR, 0);

    if (wi->text() == "E") return;

    QIcon ic = wi->icon();

    if (!ic.isNull())
    {
        QTableWidgetItem *wi = new QTableWidgetItem("", 0);
        wi->setFlags(Qt::NoItemFlags|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        griText->setItem(iR, 0, wi);
        gGridInfo--;
    }
    else
    {
        QTableWidgetItem *wi = griText->item(iR, 0);
        wi->setIcon(gIconFlag);
        wi->setText("I");
        gGridInfo++;
    }
}

void winMain::fGridUndo()
{
    if (!gGridEdit) return;
    if (gGridModi == 0) return;

    int iR = gEditTextRows[gGridModi];
    int iC = gEditTextColu[gGridModi];

    // undo the text
    griText->item(iR, iC)->setText(gEditTextOldx[gGridModi]);

    // suppress 'edit' icon
    QTableWidgetItem *ic = new QTableWidgetItem("", 0);
    ic->setFlags(Qt::NoItemFlags|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    griText->setItem(iR, 0, ic);

    gGridModi--;
    if (gGridModi == 0) gGridSave = false;
    fGridSaveIcon();
}

void winMain::fGridSave()
{
    if (!gGridSave) return;
    if (gAuto && gPlay) return;

    QString sFile = gFile;

    sFile = QFileDialog::getSaveFileName(this, "Save", sFile, "Supported (*.srt *.txt)");
    if (sFile.isEmpty())
    {
        griText->setFocus();
        return;
    }

    if (gSrtx) fFileWritSrtx(sFile);
    else fFileWrit(sFile);

    fGridSaveIcon();
    griText->setFocus();
}

void winMain::fGridFontFami()
{
    if (radFam1->isChecked()) {gGridFontFami = "trebuchet ms";}
    if (radFam2->isChecked()) {gGridFontFami = "arial";}
    if (radFam3->isChecked()) {gGridFontFami = "lucida console";}
    gGridFont.setFamily(gGridFontFami);
    if (gWork) fGridFontGrid();
}

void winMain::fGridFontSize()
{
    if (radSiz1->isChecked()) {gGridFontSize = 9;   gGridRowsHeig = 18;}
    if (radSiz2->isChecked()) {gGridFontSize = 10;  gGridRowsHeig = 19;}
    if (radSiz3->isChecked()) {gGridFontSize = 11;  gGridRowsHeig = 20;}
    gGridFont.setPointSize(gGridFontSize);
    if (gWork) fGridFontGrid();
}

void winMain::fGridFontGrid()
{
    int iR;
    int iC;
    int iRmax = gRowsMaxi;
    int iCmax = 3+gRowsNumb;
    QTableWidgetItem *wi;
    QFontMetrics mGrid = QFontMetrics(gGridFont);
    QFontMetrics mRows = QFontMetrics(gRowsFont);

    fFileTextMaxi(-1, 0, 0, 0, 0, 0);
    for (iR=1; iR<iRmax; iR++)
    {
        for (iC=1; iC<iCmax; iC++)
        {
            wi = griText->item(iR, iC);
            if (iC==1 || iC==2)
            {
                if (gGridHourBold) wi->setFont(QFont(gGridFontFami, gGridFontSize, QFont::Bold, false));
                else wi->setFont(gGridFont);
            }
            else
            {
                wi->setFont(gGridFont);
                fFileTextMaxi(mGrid.width(wi->text()), mRows.width(wi->text()), wi->text().length(), iR, iR, iC);
            }
        }
    }
    fGridInitCols();
    fGridInitRows();
}

void winMain::fGridGoto()
{
    if (gAuto && gPlay) return;
    QApplication::sendEvent(griText, new QKeyEvent(QEvent::KeyPress, Qt::Key_G, Qt::ControlModifier, "", false, 1));
}

void winMain::fGridFind()
{
    if (gAuto && gPlay) return;
    QApplication::sendEvent(griText, new QKeyEvent(QEvent::KeyPress, Qt::Key_F, Qt::ControlModifier, "", false, 1));
}

void winMain::fGridFocus()
{
        diaGrid->activateWindow();
        griText->setFocus(Qt::OtherFocusReason);
}

void winMain::fGridHourBold()
{
    gGridHourBold = false;
    if (radGridHour->isChecked()) gGridHourBold = true;
    if (gWork && gAuto) fGridFontGrid();
}

void winMain::fGridColoDark()
{
    if (radGridColo->isChecked())
    {
        gGridColoDark = true;
        sliLigh->setValue(13);
    }
    else
    {
        gGridColoDark = false;
        sliLigh->setValue(0);
    }
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// settings functions
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void winMain::fSettCrea()
{
    gSettShow = false;
    gSettHeig = 230;
    gSettWidt = 700;
    gSettLefx = (gMenuLefx + gMenuWidt) - gSettWidt - 20;
    gSettTopy = gWindHeig - gMenuHeig - gSettHeig - 10;

    diaSett = new diaSettW(this);
    diaSett->setHidden(true);
    diaSett->setWindowTitle(fL("Settings"));
    diaSett->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    diaSett->setCursor(Qt::ArrowCursor);
    diaSett->setMinimumWidth(gSettWidt);
    diaSett->setMaximumWidth(gSettWidt);
    diaSett->setMinimumHeight(gSettHeig);
    diaSett->setMaximumHeight(gSettHeig);
    diaSett->setContentsMargins(0, 0, 0, 0);
    diaSett->setStyleSheet(gSettStyl);
    diaSett->setGeometry(gSettLefx, gSettTopy, gSettWidt, gSettHeig);
    connect(diaSett, SIGNAL(finished(int)), this, SLOT(fSettFini(int)));

    tabSett = new QTabWidget(diaSett);
    tabSett->setTabPosition(QTabWidget::North);
    tabSett->setGeometry(gSettLefx, gSettTopy, gSettWidt, gSettHeig);
    tabSett->setGeometry(2, 3, gSettWidt - 3, gSettHeig - 3);
    tabSett->setCursor(Qt::ArrowCursor);
    tabSett->setStyleSheet(gSettStyl);

    // page 1 - texts - rows ----------------------------------------------------------------------

    QWidget *tabRows = new QWidget;
    tabRows->setStyleSheet(gSettStyl);

    texRowsNumb = new QLabel(fL("Lines"), tabRows);
    texRowsNumb->setStyleSheet(gTitlStyl);
    texRowsNumb->move(10, 10);

    radRow1 = new QRadioButton("1");
    radRow1->setStyleSheet(gExplStyl);
    connect(radRow1, SIGNAL(clicked()), this, SLOT(fRowsNumb()));

    radRow2 = new QRadioButton("2");
    radRow2->setStyleSheet(gExplStyl);
    connect(radRow2, SIGNAL(clicked()), this, SLOT(fRowsNumb()));

    radRow3 = new QRadioButton("3");
    radRow3->setStyleSheet(gExplStyl);
    connect(radRow3, SIGNAL(clicked()), this, SLOT(fRowsNumb()));

    radRow4 = new QRadioButton("4");
    radRow4->setStyleSheet(gExplStyl);
    connect(radRow4, SIGNAL(clicked()), this, SLOT(fRowsNumb()));

    if (gRowsNumb==1) radRow1->setChecked(true);
    if (gRowsNumb==2) radRow2->setChecked(true);
    if (gRowsNumb==3) radRow3->setChecked(true);
    if (gRowsNumb==4) radRow4->setChecked(true);

    QVBoxLayout *boxRowsNumb = new QVBoxLayout;
    boxRowsNumb->setContentsMargins(2, 2, 2, 2);
    boxRowsNumb->setSpacing(1);
    boxRowsNumb->addWidget(radRow1);
    boxRowsNumb->addWidget(radRow2);
    boxRowsNumb->addWidget(radRow3);
    boxRowsNumb->addWidget(radRow4);

    QGroupBox *grpRowsNumb = new QGroupBox("", tabRows);
    grpRowsNumb->setStyleSheet(gGboxStyl);
    grpRowsNumb->setLayout(boxRowsNumb);
    grpRowsNumb->move(10, 35);

    texRowsLocV = new QLabel(fL("V. position"), tabRows);
    texRowsLocV->setStyleSheet(gTitlStyl);
    texRowsLocV->move(100, 10);
    texRowsLoVm = new QLabel(fL("Top"), tabRows);
    texRowsLoVm->setStyleSheet(gExplStyl);
    texRowsLoVm->move(130, 31);
    texRowsLoVM = new QLabel(fL("Bottom"), tabRows);
    texRowsLoVM->setStyleSheet(gExplStyl);
    texRowsLoVM->move(130, 87);

    sliRowsLocV = new QSlider(Qt::Vertical,tabRows);
    sliRowsLocV->setTickPosition(QSlider::NoTicks);
    sliRowsLocV->setRange(-1 * (gWindHeig - gRowsHeig - 1), -1);
    sliRowsLocV->setValue(gRowsTopy);
    sliRowsLocV->setGeometry(100, 35, 20, 65);
    connect(sliRowsLocV, SIGNAL(valueChanged(int)), this, SLOT(fRowsLocV(int)));

    texRowsLocH = new QLabel(fL("H. position"), tabRows);
    texRowsLocH->setStyleSheet(gTitlStyl);
    texRowsLocH->move(200, 10);
    texRowsLoHm = new QLabel(fL("Left"), tabRows);
    texRowsLoHm->setStyleSheet(gExplStyl);
    texRowsLoHm->move(230, 31);
    texRowsLoHM = new QLabel(fL("Right"), tabRows);
    texRowsLoHM->setStyleSheet(gExplStyl);
    texRowsLoHM->move(230, 87);

    sliRowsLocH = new QSlider(Qt::Vertical,tabRows);
    sliRowsLocH->setTickPosition(QSlider::NoTicks);
    sliRowsLocH->setMinimum(-1 * (gWindWidt-gRowsWidt-2));
    sliRowsLocH->setMaximum(-1);
    sliRowsLocH->setValue(-1 * (gWindWidt-gRowsWidt-2) / 2);    // gpb 120305
    sliRowsLocH->setGeometry(200, 35, 20, 65);
    connect(sliRowsLocH, SIGNAL(valueChanged(int)), this, SLOT(fRowsLocH(int)));

    texRowsHeig = new QLabel(fL("Height"), tabRows);
    texRowsHeig->setStyleSheet(gTitlStyl);
    texRowsHeig->move(300, 10);
    texRowsHeim = new QLabel("Max.", tabRows);
    texRowsHeim->setStyleSheet(gExplStyl);
    texRowsHeim->move(330, 31);
    texRowsHeiM = new QLabel("Min.", tabRows);
    texRowsHeiM->setStyleSheet(gExplStyl);
    texRowsHeiM->move(330, 87);

    sliRowsHeig = new QSlider(Qt::Vertical, tabRows);
    sliRowsHeig->setTickPosition(QSlider::NoTicks);
    sliRowsHeig->setMinimum(gRowsFont.pointSize()+8);
    sliRowsHeig->setMaximum(3*sliRowsHeig->minimum());
    sliRowsHeig->setValue(sliRowsHeig->minimum());
    sliRowsHeig->setGeometry(300, 35, 20, 65);
    connect(sliRowsHeig, SIGNAL(valueChanged(int)), this, SLOT(fRowsHeig(int)));

    texRowsWidt = new QLabel(fL("Width"), tabRows);
    texRowsWidt->setStyleSheet(gTitlStyl);
    texRowsWidt->move(400, 10);
    texRowsWidm = new QLabel(fL("Max."), tabRows);
    texRowsWidm->setStyleSheet(gExplStyl);
    texRowsWidm->move(430, 31);
    texRowsWidM = new QLabel(fL("Min."), tabRows);
    texRowsWidM->setStyleSheet(gExplStyl);
    texRowsWidM->move(430, 87);


    sliRowsWidt = new QSlider(Qt::Vertical, tabRows);


    sliRowsWidt->setTickPosition(QSlider::NoTicks);
    sliRowsWidt->setRange(300, gRowsWmax);
    sliRowsWidt->setValue(gRowsWidt);
    sliRowsWidt->setGeometry(400, 35, 20, 65);
    connect(sliRowsWidt, SIGNAL(valueChanged(int)), this, SLOT(fRowsWidt(int)));

    texRowsSpac = new QLabel(fL("Spacing"), tabRows);
    texRowsSpac->setStyleSheet(gTitlStyl);
    texRowsSpac->move(500, 10);
    QLabel *texRowsSpam = new QLabel("Max.", tabRows);
    texRowsSpam->setStyleSheet(gExplStyl);
    texRowsSpam->move(530, 31);
    QLabel *texRowsSpaM = new QLabel("Min.", tabRows);
    texRowsSpaM->setStyleSheet(gExplStyl);
    texRowsSpaM->move(530, 87);

    sliRowsSpac = new QSlider(Qt::Vertical,tabRows);
    sliRowsSpac->setTickPosition(QSlider::NoTicks);
    sliRowsSpac->setRange(1, 50);
    sliRowsSpac->setValue(1);
    sliRowsSpac->setGeometry(500, 35, 20, 65);
    connect(sliRowsSpac, SIGNAL(valueChanged(int)), this, SLOT(fRowsSpac(int)));

    texRowsBack = new QLabel(fL("Background"), tabRows);
    texRowsBack->setStyleSheet(gTitlStyl);
    texRowsBack->move(600, 10);

    butTextBack = new QPushButton(gIconColo, fL("Colour"), tabRows);
    butTextBack->move(599,35);
    connect(butTextBack, SIGNAL(clicked()), this, SLOT(fRowsBackDial()));

    // page 1 - texts - texts ---------------------------------------------------------------------

    labTextFont = new QLabel(fL("Text"), tabRows);
    labTextFont->setStyleSheet(gTitlStyl);
    labTextFont->move(10, 120);

    butTextColo = new QPushButton(gIconColo, fL("Colour"), tabRows);
    butTextColo->move(9, 144);
    connect(butTextColo, SIGNAL(clicked()), this, SLOT(fRowsColoDial()));

    butFont = new QPushButton(gIconFont, fL("&Font"), tabRows);
    butFont->move(9, 176);
    connect(butFont, SIGNAL(clicked()), this, SLOT(fRowsFontDial()));

    labCharThic = new QLabel(fL("Outline"), tabRows);
    labCharThic->setStyleSheet(gTitlStyl);
    labCharThic->move(100, 120);

    radNone = new QRadioButton(fL("None"));
    radNone->setStyleSheet(gExplStyl);
    connect(radNone, SIGNAL(clicked()), this, SLOT(fRowsOutlThik()));

    radThin = new QRadioButton(fL("1px"));
    radThin->setStyleSheet(gExplStyl);
    connect(radThin, SIGNAL(clicked()), this, SLOT(fRowsOutlThik()));

    radBold = new QRadioButton(fL("2px"));
    radBold->setStyleSheet(gExplStyl);
    connect(radBold, SIGNAL(clicked()), this, SLOT(fRowsOutlThik()));

    radNone->setChecked(true);

    QVBoxLayout *boxCharThic = new QVBoxLayout;
    boxCharThic->setContentsMargins(2, 2, 2, 2);
    boxCharThic->setSpacing(1);
    boxCharThic->addWidget(radNone);
    boxCharThic->addWidget(radThin);
    boxCharThic->addWidget(radBold);

    QGroupBox *qrpCharThic = new QGroupBox("", tabRows);
    qrpCharThic->setStyleSheet(gGboxStyl);
    qrpCharThic->setLayout(boxCharThic);
    qrpCharThic->move(100, 145);

    labCharOutl = new QLabel(fL("Outline"), tabRows);
    labCharOutl->setStyleSheet(gTitlStyl);
    labCharOutl->move(200, 120);

    butChar = new QPushButton(gIconColo, fL("Colour"), tabRows);
    butChar->move(199, 144);
    connect(butChar, SIGNAL(clicked()), this, SLOT(fRowsOutlDial()));

    labTextAliH = new QLabel(fL("H. align"), tabRows);
    labTextAliH->setStyleSheet(gTitlStyl);
    labTextAliH->move(300, 120);

    radLeft = new QRadioButton(fL("Left"));
    radLeft->setStyleSheet(gExplStyl);
    connect(radLeft, SIGNAL(clicked()), this, SLOT(fRowsTextAlig()));

    radCenH = new QRadioButton(fL("Center"));
    radCenH->setStyleSheet(gExplStyl);
    connect(radCenH, SIGNAL(clicked()), this, SLOT(fRowsTextAlig()));

    radRigh = new QRadioButton(fL("Right"));
    radRigh->setStyleSheet(gExplStyl);
    connect(radRigh, SIGNAL(clicked()), this, SLOT(fRowsTextAlig()));

    radCenH->setChecked(true);

    QVBoxLayout *boxTextAliH = new QVBoxLayout;
    boxTextAliH->setContentsMargins(2, 2, 2, 2);
    boxTextAliH->setSpacing(1);
    boxTextAliH->addWidget(radLeft);
    boxTextAliH->addWidget(radCenH);
    boxTextAliH->addWidget(radRigh);

    QGroupBox *grpTextAliH = new QGroupBox("", tabRows);
    grpTextAliH->setStyleSheet(gGboxStyl);
    grpTextAliH->setLayout(boxTextAliH);
    grpTextAliH->move(300, 145);

    labTextAliV = new QLabel(fL("V. align"), tabRows);
    labTextAliV->setStyleSheet(gTitlStyl);
    labTextAliV->move(400, 120);

    radTopy = new QRadioButton(fL("Top"));
    radTopy->setStyleSheet(gExplStyl);
    connect(radTopy, SIGNAL(clicked()), this, SLOT(fRowsTextAlig()));

    radCenV = new QRadioButton(fL("Center"));
    radCenV->setStyleSheet(gExplStyl);
    connect(radCenV, SIGNAL(clicked()), this, SLOT(fRowsTextAlig()));

    radBott = new QRadioButton(fL("Bottom"));
    radBott->setStyleSheet(gExplStyl);
    connect(radBott, SIGNAL(clicked()), this, SLOT(fRowsTextAlig()));

    radTopy->setChecked(true);

    QVBoxLayout *boxTextAliV = new QVBoxLayout;
    boxTextAliV->setContentsMargins(2, 2, 2, 2);
    boxTextAliV->setSpacing(1);
    boxTextAliV->addWidget(radTopy);
    boxTextAliV->addWidget(radCenV);
    boxTextAliV->addWidget(radBott);

    QGroupBox *grpTextAliV = new QGroupBox("", tabRows);
    grpTextAliV->setStyleSheet(gGboxStyl);
    grpTextAliV->setLayout(boxTextAliV);
    grpTextAliV->move(400, 145);

    labWindBack = new QLabel(fL("Test screen"), tabRows);
    labWindBack->setStyleSheet(gTitlStyl);
    labWindBack->move(600, 120);

    radWindBacB = new QRadioButton(fL("Off"));
    radWindBacB->setStyleSheet(gExplStyl);
    connect(radWindBacB, SIGNAL(clicked()), this, SLOT(fWindBack()));

    radWindBacG = new QRadioButton(fL("On"));
    radWindBacG->setStyleSheet(gExplStyl);
    connect(radWindBacG, SIGNAL(clicked()), this, SLOT(fWindBack()));

    radWindBacB->setChecked(true);

    QVBoxLayout *boxWindBack = new QVBoxLayout;
    boxWindBack->setContentsMargins(2, 2, 2, 2);
    boxWindBack->setSpacing(1);
    boxWindBack->addWidget(radWindBacB);
    boxWindBack->addWidget(radWindBacG);

    QGroupBox *grpWindBack = new QGroupBox("", tabRows);
    grpWindBack->setStyleSheet(gGboxStyl);
    grpWindBack->setLayout(boxWindBack);
    grpWindBack->move(600, 145);

    // page 2 - grid ------------------------------------------------------------------------------

    QWidget *tabGrid = new QWidget;
    tabGrid->setStyleSheet(gSettStyl);

    labGridFfam = new QLabel(fL("Grid font"), tabGrid);
    labGridFfam->setStyleSheet(gTitlStyl);
    labGridFfam->move(10, 10);

    radFam1 = new QRadioButton("Trebuchet");
    radFam1->setStyleSheet(gExplStyl);
    connect(radFam1, SIGNAL(clicked()), this, SLOT(fGridFontFami()));

    radFam2 = new QRadioButton("Arial");
    radFam2->setStyleSheet(gExplStyl);
    connect(radFam2, SIGNAL(clicked()), this, SLOT(fGridFontFami()));

    radFam3 = new QRadioButton("Lucida");
    radFam3->setStyleSheet(gExplStyl);
    connect(radFam3, SIGNAL(clicked()), this, SLOT(fGridFontFami()));

    radFam3->setChecked(true);

    QVBoxLayout *boxGridFfam = new QVBoxLayout;
    boxGridFfam->setContentsMargins(2, 2, 2, 2);
    boxGridFfam->setSpacing(1);
    boxGridFfam->addWidget(radFam1);
    boxGridFfam->addWidget(radFam2);
    boxGridFfam->addWidget(radFam3);

    QGroupBox *grpGridFfam = new QGroupBox("", tabGrid);
    grpGridFfam->setStyleSheet(gGboxStyx);
    grpGridFfam->setLayout(boxGridFfam);
    grpGridFfam->move(10, 35);

    labGridFsiz = new QLabel(fL("Grid font size"), tabGrid);
    labGridFsiz->setStyleSheet(gTitlStyl);
    labGridFsiz->move(115, 10);

    radSiz1 = new QRadioButton("9");
    radSiz1->setStyleSheet(gExplStyl);
    connect(radSiz1, SIGNAL(clicked()), this, SLOT(fGridFontSize()));

    radSiz2 = new QRadioButton("10");
    radSiz2->setStyleSheet(gExplStyl);
    connect(radSiz2, SIGNAL(clicked()), this, SLOT(fGridFontSize()));

    radSiz3 = new QRadioButton("11");
    radSiz3->setStyleSheet(gExplStyl);
    connect(radSiz3, SIGNAL(clicked()), this, SLOT(fGridFontSize()));

    radSiz1->setChecked(true);

    QVBoxLayout *boxGridFsiz = new QVBoxLayout;
    boxGridFsiz->setContentsMargins(2, 2, 2, 2);
    boxGridFsiz->setSpacing(1);
    boxGridFsiz->addWidget(radSiz1);
    boxGridFsiz->addWidget(radSiz2);
    boxGridFsiz->addWidget(radSiz3);

    QGroupBox *grpGridFsiz = new QGroupBox("", tabGrid);
    grpGridFsiz->setStyleSheet(gGboxStyl);
    grpGridFsiz->setLayout(boxGridFsiz);
    grpGridFsiz->move(115, 35);

    labGridHour = new QLabel(fL("Hours format"), tabGrid);
    labGridHour->setStyleSheet(gTitlStyl);
    labGridHour->move(215, 10);

    radGridHour = new QRadioButton(fL("bold"));
    radGridHour->setStyleSheet(gExplStyl);
    connect(radGridHour, SIGNAL(clicked()), this, SLOT(fGridHourBold()));
    radGridHour->setChecked(gGridHourBold);

    QVBoxLayout *boxGridHour = new QVBoxLayout;
    boxGridHour->setContentsMargins(2, 2, 2, 2);
    boxGridHour->setSpacing(1);
    boxGridHour->addWidget(radGridHour);

    QGroupBox *grpGridHour = new QGroupBox("", tabGrid);
    grpGridHour->setStyleSheet(gGboxStyl);
    grpGridHour->setLayout(boxGridHour);
    grpGridHour->move(215, 35);

    labGridColo = new QLabel(fL("Dark theme"), tabGrid);
    labGridColo->setStyleSheet(gTitlStyl);
    labGridColo->move(315, 10);

    radGridColo = new QRadioButton(fL("On/Off"));
    radGridColo->setStyleSheet(gExplStyl);
    connect(radGridColo, SIGNAL(clicked()), this, SLOT(fGridColoDark()));
    radGridColo->setChecked(gGridColoDark);

    QVBoxLayout *boxGridColo = new QVBoxLayout;
    boxGridColo->setContentsMargins(2, 2, 2, 2);
    boxGridColo->setSpacing(1);
    boxGridColo->addWidget(radGridColo);

    QGroupBox *grpGridColo = new QGroupBox("", tabGrid);
    grpGridColo->setStyleSheet(gGboxStyl);
    grpGridColo->setLayout(boxGridColo);
    grpGridColo->move(315, 35);


    // page 3 - general ---------------------------------------------------------------------------

    QWidget *tabGene = new QWidget;
    tabGene->setStyleSheet(gSettStyl);

    labTaskShow = new QLabel(fL("Show Taskbar"),tabGene);
    labTaskShow->setStyleSheet(gTitlStyl);
    labTaskShow->move(10, 10);

    radTaskShow = new QRadioButton(fL("Yes"));
    radTaskShow->setStyleSheet(gExplStyl);
    connect(radTaskShow, SIGNAL(clicked()), this, SLOT(fWindBott()));

    radTaskHide = new QRadioButton(fL("No"));
    radTaskHide->setStyleSheet(gExplStyl);
    connect(radTaskHide, SIGNAL(clicked()), this, SLOT(fWindBott()));

    radTaskHide->setChecked(true);

    QVBoxLayout *boxTaskShow = new QVBoxLayout;
    boxTaskShow->setContentsMargins(2, 2, 2, 2);
    boxTaskShow->setSpacing(1);
    boxTaskShow->addWidget(radTaskShow);
    boxTaskShow->addWidget(radTaskHide);

    QGroupBox *grpTaskShow = new QGroupBox("", tabGene);
    grpTaskShow->setStyleSheet(gGboxStyl);
    grpTaskShow->setLayout(boxTaskShow);
    grpTaskShow->move(10, 35);

    labWindMenu = new QLabel(fL("Menu location"),tabGene);
    labWindMenu->setStyleSheet(gTitlStyl);
    labWindMenu->move(110, 10);

    radWindMenT = new QRadioButton(fL("Top"));
    radWindMenT->setStyleSheet(gExplStyl);
    connect(radWindMenT, SIGNAL(clicked()), this, SLOT(fWindTogg()));

    radWindMenB = new QRadioButton(fL("Bottom"));
    radWindMenB->setStyleSheet(gExplStyl);
    connect(radWindMenB, SIGNAL(clicked()), this, SLOT(fWindTogg()));

    radWindMenB->setChecked(true);

    QVBoxLayout *boxWindMenu = new QVBoxLayout;
    boxWindMenu->setContentsMargins(2, 2, 2, 2);
    boxWindMenu->setSpacing(1);
    boxWindMenu->addWidget(radWindMenT);
    boxWindMenu->addWidget(radWindMenB);

    QGroupBox *grpWindMenu = new QGroupBox("", tabGene);
    grpWindMenu->setStyleSheet(gGboxStyl);
    grpWindMenu->setLayout(boxWindMenu);
    grpWindMenu->move(110, 35);

    labFileEnco = new QLabel(fL("File encoding"), tabGene);
    labFileEnco->setStyleSheet(gTitlStyl);
    labFileEnco->move(210, 10);

    radAnsi = new QRadioButton("ANSI");
    radAnsi->setStyleSheet(gExplStyl);
    connect(radAnsi, SIGNAL(clicked()), this, SLOT(fFileEnco()));

    radUtf8 = new QRadioButton("UTF-8");
    radUtf8->setStyleSheet(gExplStyl);
    connect(radUtf8, SIGNAL(clicked()), this, SLOT(fFileEnco()));

    radAnsi->setChecked(true);

    QVBoxLayout *boxFileEnco = new QVBoxLayout;
    boxFileEnco->setContentsMargins(2, 2, 2, 2);
    boxFileEnco->setSpacing(1);
    boxFileEnco->addWidget(radAnsi);
    boxFileEnco->addWidget(radUtf8);

    QGroupBox *grpFileEnco = new QGroupBox("", tabGene);
    grpFileEnco->setStyleSheet(gGboxStyl);
    grpFileEnco->setLayout(boxFileEnco);
    grpFileEnco->move(210, 35);

    labWorkLang = new QLabel(fL("Interface language"), tabGene);
    labWorkLang->setStyleSheet(gTitlStyl);
    labWorkLang->move(310, 10);

    radEngl = new QRadioButton("English");
    radEngl->setStyleSheet(gExplStyl);
    connect(radEngl, SIGNAL(clicked()), this, SLOT(fWorkLang()));

    radFren = new QRadioButton("Français");
    radFren->setStyleSheet(gExplStyl);
    connect(radFren, SIGNAL(clicked()), this, SLOT(fWorkLang()));

    radDutc = new QRadioButton("Nederlands");
    radDutc->setStyleSheet(gExplStyl);
    connect(radDutc, SIGNAL(clicked()), this, SLOT(fWorkLang()));

    if (gLang == 0) radEngl->setChecked(true);
    if (gLang == 1) radFren->setChecked(true);
    if (gLang == 2) radDutc->setChecked(true);

    QVBoxLayout *boxWorkLang = new QVBoxLayout;
    boxWorkLang->setContentsMargins(2, 2, 2, 2);
    boxWorkLang->setSpacing(1);
    boxWorkLang->addWidget(radEngl);
    boxWorkLang->addWidget(radFren);
    boxWorkLang->addWidget(radDutc);

    QGroupBox *grpWorkLang = new QGroupBox("", tabGene);
    grpWorkLang->setStyleSheet(gGboxStyx);
    grpWorkLang->setLayout(boxWorkLang);
    grpWorkLang->move(310, 35);

    // page 3 - general - others ------------------------------------------------------------------

    chkSecoText = new QCheckBox(fL("Display one-line subtitles on bottom line"), tabGene);
    chkSecoText->setStyleSheet(gTitlStyI);
    chkSecoText->move(10, 120);
    connect(chkSecoText, SIGNAL(stateChanged(int)), this, SLOT(fRowsSeco(int)));

    chkSecoItal = new QCheckBox(fL("Force italic for bottom lines"), tabGene);
    chkSecoItal->setStyleSheet(gTitlStyI);
    chkSecoItal->move(10, 140);
    connect(chkSecoItal, SIGNAL(stateChanged(int)), this, SLOT(fRowsItal(int)));

    labJumpBase = new QLabel(fL("Jump steps (1/10 sec.)"), tabGene);
    labJumpBase->setStyleSheet(gTitlStyl);
    labJumpBase->move(350, 120);

    spiJumpBase = new QSpinBox(tabGene);
    spiJumpBase->setStyleSheet(gTitlSpin);
    spiJumpBase->setRange(1,10);
    spiJumpBase->setValue(2);
    spiJumpBase->move(310, 120);
    connect(spiJumpBase, SIGNAL(valueChanged(int)), this, SLOT(fJumpBase(int)));

    // add pages ----------------------------------------------------------------------------------

    tabSett->addTab(tabRows, fL("Subtitles"));
    tabSett->addTab(tabGrid, fL("Grid"));
    tabSett->addTab(tabGene, fL("General"));
}

void winMain::fSettShow()
{
    fWindLogoHide();
    fFileInfoClos();
    if (diaSett->isHidden())
    {
        gSettShow = true;
        fWindPosiDial(diaSett);
    }
    else
    {
        gSettShow = false;
        diaSett->setHidden(true);
        if (gGridShow) fGridFocus();
    }
    fRowsInit();
}

void winMain::fSettFini(int)
{
    gSettShow = false;
    if (gGridShow) fGridFocus();
}

void winMain::fSettClos()
{
    gSettShow = false;
    diaSett->setHidden(true);
}

void winMain::fSettGeom()
{
    gSettLefx = (gMenuLefx + gMenuWidt) - gSettWidt - 20;
    fWindScre("s");
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// file functions
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

bool winMain::fFileConf()
{
    QString sConf = gFile.mid(0, gFile.size() - 4) + QString(".cfg");

    oConf.setFileName(sConf);
    if (!oConf.exists()) return false;

    QMessageBox *qm = new QMessageBox(QMessageBox::Question, fL("Settings"), fL("Settings found for this file.\nDo you want to use them ?"), QMessageBox::Yes|QMessageBox::No, this);
    fWindPosiMess(qm);
    int iRep = qm->exec();

    if (iRep == QMessageBox::No) return false;

    gConf = sConf;
    return true;
}

void winMain::fFileDialRepo(QString sRepo)
{
    gFile = sRepo;
}

void winMain::fFileDial()
{
    fWindLogoHide();
    fRowsClear();

    if (gGridSave)
    {
        fGridModi();
    }
    else if (gGridShow)
    {
        QMessageBox *qm = new QMessageBox(QMessageBox::Question, fL("Open"), fL("Close currently loaded file ?"), QMessageBox::Yes|QMessageBox::No, this);
        fWindPosiMess(qm);
        int iRep = qm->exec();
        if (iRep == QMessageBox::No) return;
    }

    fClearAll();                                        // gpb 120220
    fMenuClear();                                       // gpb 110930

    gFileLefx = (gMenuLefx + gMenuWidt) - gFileWidt - 10;

    fWindScre("f"); // calculate gFileTopy

    QFileDialog *fd = new QFileDialog(this, fL("Open"), "", "Supported (*.srt *.txt)");
    fd->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    connect(fd, SIGNAL(fileSelected(QString)), SLOT(fFileDialRepo(QString)));
    fd->setGeometry(gFileLefx, gFileTopy, gFileWidt, gFileHeig);
    fd->show(); // needed to get the correct frame dimensions
    fWindPosiDial(fd);
    fd->exec();

    if (gFile.isEmpty())
    {
        if (!gGridShow) diaGrid->hide();
    }
    else
    {
        gWork = false;

        if (fFileConf()) fConfRead();

        if (QFileInfo(gFile).suffix().toLower() == "srt") gSrtx = true;
        else gSrtx = false;

        if (gSrtx) fFileReadSrtx();
        else fFileRead();

        gGridSave = false;
        butGridSave->setIcon(gIconSaveDisa);
    }
}

void winMain::fFileEnco()
{
    if (radAnsi->isChecked()) gFileEnco = true;
    if (radUtf8->isChecked()) gFileEnco = false;
    if (gWork)
    {
        if (gSrtx) fFileReadSrtx();
        else fFileRead();
    }
}

void winMain::fFileRead()
{
    QString sLine;
    QByteArray aLine;
    int iGrid = -1;
    int iLine = 0;
    int iRows = 0;
    int iColo = 0;
    int iC, iT;
    QStringList lText;

    oFile.setFileName(gFile);

    if (!oFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, fL("Open"), QString(fL("Cannot read file %1:\n%2")).arg(gFile).arg(oFile.errorString()));
        return;
    }

    fFileCodeTest("i", true);
    while (!oFile.atEnd())
    {
        aLine = oFile.readLine();
        fFileCodeTest(aLine, false);
        iLine++;
    }
    oFile.close();
    fFileCodeTest("", true);

    QProgressDialog barFile(fL("Loading..."), QString(), 0, iLine, this);
    barFile.setWindowTitle(fL(".txt file"));
    barFile.setMinimumDuration(200);
    barFile.setValue(0);
    fWindPosiProg(barFile);

    gWork = true;
    gManu = true;

    gGridModi = 0;
    gGridSave = false;
    fGridSaveIcon();
    gGridInfo = 0;
    fGridShow(false);
    fGridZero();

    gFileErro = "";

    iLine = 0;
    fFileTextMaxi(-1, 0, 0, 0, 0, 0);

    QFontMetrics mGrid = QFontMetrics(gGridFont);
    QFontMetrics mRows = QFontMetrics(gRowsFont);

    // one blank-line before the beginning

    griText->insertRow(++iGrid);
    for (iC = 0; iC < 5; iC++) {fGridItemSetx("", 0, iC);}

    // all the lines

    oFile.open(QIODevice::ReadOnly);
    while (!oFile.atEnd())
    {
        barFile.setValue(iRows);

        iRows++;
        iLine++;
        sLine = fFileLineForm(oFile.readLine());
        lText = sLine.split(QString("\\"));

        griText->insertRow(++iGrid);
        fGridItemSetx("", iGrid, 0);
        fGridItemSetx("", iGrid, 1);
        fGridItemSetx("", iGrid, 2);

        for (iT = 0; iT < 3; iT++)
        {
            iC = iT + 3;
            if (lText.size() > iT)
            {
                sLine = lText[iT].trimmed();
                fGridItemSetx(sLine, iGrid, iC);
                sLine = fGridTextClean(lText[iT]);      // gpb 120310
                fFileTextMaxi(mGrid.width(sLine), mRows.width(sLine), sLine.length(), iGrid, iLine, iC);
            }
            else
            {
                fGridItemSetx("", iGrid, iC);
            }
        }

        if (lText.size()>iColo) iColo = lText.size();
    }
    oFile.close();

    // one blank-line after the end

    griText->insertRow(++iGrid);
    for (iC = 0; iC < 5; iC++) {fGridItemSetx("", iGrid, iC);}

    // remove the very last line

    griText->setRowCount(griText->rowCount()-1);

    gRowsMaxi = griText->rowCount()-1;
    gRowsNumb = iColo;
    if (iColo == 1) radRow1->setChecked(true);
    if (iColo == 2) radRow2->setChecked(true);
    if (iColo == 3) radRow3->setChecked(true);
    if (iColo == 4) radRow4->setChecked(true);
    fRowsNumb();
    fRowsNumbBloc();

    fGridInit();
    fGridTitle();
    fGridShow(true);

    fManuInit();

    diaGrid->setFocus(Qt::OtherFocusReason);
    griText->setFocus(Qt::OtherFocusReason);
    griText->setCurrentCell(0, 1);
}

void winMain::fFileCodec(QByteArray aText)
{
    if (aText.indexOf("Ã") > 0) gFileEnco = false;
    else gFileEnco = true;

    if (gFileEnco) radAnsi->setChecked(true);
    else radUtf8->setChecked(true);
}

void winMain::fFileCodeTest(QByteArray aLine, bool bTest)
{
    static QByteArray aText = "";

    if (!bTest)
    {
        aText += aLine;
    }
    else if (aLine == "i")
    {
        aText = "";
    }
    else
    {
        if (aText.indexOf("Ã") > 0) gFileEnco = false;
        else gFileEnco = true;
        if (gFileEnco) radAnsi->setChecked(true);
        else radUtf8->setChecked(true);
    }
}

QString winMain::fFileLineForm(QByteArray sLine)
{
    QTextEdit sEdit;
    QString sForm;
    QTextCodec *codec;

    sLine = sLine.left(sLine.size()-1);
    sLine = sLine.trimmed();
    sLine.replace("  ", " ");
    sLine.replace(" .", ".");
    sLine.replace(" :", ":");
    sLine.replace(" ;", ";");
    sLine.replace(" ,", ",");
    sLine.replace(" !", "!");
    sLine.replace(" ?", "?");
    sLine.replace("( ", "(");
    sLine.replace(" )", ")");
    sLine.replace("[ ", "[");
    sLine.replace(" ]", "]");
    sLine.replace("{ ", "{");
    sLine.replace(" }", "}");

    if (gFileEnco)  {codec = QTextCodec::codecForName("ISO 8859-1");}
    else            {codec = QTextCodec::codecForName("UTF-8");}

    sForm = codec->toUnicode(sLine);
    return sForm;
}

void winMain::fFileTextMaxi(int iGrid, int iLeng, int iChar, int iRows, int iLine, int iC)
{
    if (iGrid < 0)
    {
        for (iC = 1; iC < 5; iC++)
        {
            gFileMaxiColu[iC] = 0;
        }
        for (int iM = 0; iM < 9; iM++)
        {
            gFileMaxiGrid[iM] = 0;
            gFileMaxiLeng[iM] = 0;
            gFileMaxiChar[iM] = 0;
            gFileMaxiRows[iM] = 0;
            gFileMaxiColo[iM] = 0;
            gFileMaxiLine[iM] = 0;
        }
    }
    else
    {
        if (iLeng>gRowsWmax) gFileErro += QString("|%1 - Line is too wide").arg(iLine);

        if (iLeng > gFileMaxiColu[iC]) gFileMaxiColu[iC] = iLeng;
        for (int iM = 0; iM <= 8; iM++)
        {
            if (iLeng == gFileMaxiLeng[iM]) break;
            if (iLeng > gFileMaxiLeng[iM])
            {
                for (int iN = 8; iN >= iM; iN--)
                {
                    gFileMaxiGrid[iN] = gFileMaxiGrid[iN - 1];
                    gFileMaxiLeng[iN] = gFileMaxiLeng[iN - 1];
                    gFileMaxiChar[iN] = gFileMaxiChar[iN - 1];
                    gFileMaxiRows[iN] = gFileMaxiRows[iN - 1];
                    gFileMaxiColo[iN] = gFileMaxiColo[iN - 1];

                    gFileMaxiLine[iN] = gFileMaxiLine[iN - 1];
                }
                gFileMaxiGrid[iM] = iGrid;
                gFileMaxiLeng[iM] = iLeng;
                gFileMaxiChar[iM] = iChar;
                gFileMaxiRows[iM] = iRows;
                gFileMaxiColo[iM] = iC;
                gFileMaxiLine[iM] = iLine;
                break;
            }
        }
    }
}

void winMain::fFileWrit(QString sFile)
{
    int r;

    oFile.setFileName(sFile);
    if (!oFile.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    gGridSave = false;

    QTableWidgetItem *it1;
    QTableWidgetItem *it2;
    QString sLine;
    QString st1;
    QString st2;

    for (r = 1; r < gRowsMaxi; r++)
    {
        sLine = "";
        it1 = griText->item(r, 3);
        it2 = griText->item(r, 4);
        st1 = it1->text();
        st2 = it2->text();
        if (gSecoText and st1.isEmpty())
        {
            st1 = st2;
            st2 = "";
        }
        sLine = st1;
        if (gRowsNumb>1)
        {
            if (!st2.isEmpty()) sLine = sLine + "\\" + st2;
        }
        if (gRowsNumb>2)
        {
            QTableWidgetItem *it3 = griText->item(r, 5);
            QString st3 = it3->text();
            if (!st3.isEmpty()) sLine = sLine + "\\" + st3;
        }
        if (gRowsNumb>3)
        {
            QTableWidgetItem *it4 = griText->item(r, 6);
            QString st4 = it4->text();
            if (!st4.isEmpty()) sLine = sLine + "\\" + st4;
        }
        sLine = sLine + "\n";
        oFile.write(sLine.toAscii());
    }
    oFile.close();
}

void winMain::fFileWritSrtx(QString sFile)
{
    oFile.setFileName(sFile);
    if (!oFile.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    gGridSave = false;

    QString sLine;
    QString sNumb;
    QString sStar;
    QString sStop;
    QString sTex1;
    QString sTex2;
    int iR;

    for (iR = 1; iR < gRowsMaxi; iR++)
    {
        sNumb = griText->verticalHeaderItem(iR)->text();
        sStar = griText->item(iR, 1)->text();
        sStop = griText->item(iR, 2)->text();
        sTex1 = griText->item(iR, 3)->text();
        sTex2 = griText->item(iR, 4)->text();

        if (gSecoText and sTex1.isEmpty())
        {
            sTex1 = sTex2;
            sTex2 = "";
        }

        sLine = sNumb + "\n";
        sLine += (sStar + " --> " + sStop + "\n");
        if (!sTex1.isEmpty()) sLine += (sTex1 + "\n");
        if (!sTex2.isEmpty()) sLine += (sTex2 + "\n");
        sLine += "\n";
        oFile.write(sLine.toAscii());
    }
    oFile.close();
}

void winMain::fFileLogx()
{
    //if (gGridModi == 0 && gGridInfo == 0 && gFileErro.isEmpty()) return;

    int iR;
    int iRmaxi = griText->rowCount();
    int iC;
    int r;
    QString sLine;

    if (!gFileErro.isEmpty())
    {
        QStringList lProb = gFileErro.split(QString("|"));

        for (int iP = 1; iP < lProb.count(); iP++)
        {
            sLine = QString("[Error] Row " + lProb[iP]);
            sLine += "\n";

            if (!fFlogOpen()) return;
            oFlog.write(sLine.toAscii());
        }
    }

    for (iR = 0; iR < iRmaxi; iR++)
    {
        if (griText->item(iR, 0)->text() == "I")
        {
            sLine = QString("[Flagged] Row %1 : ").arg(griText->verticalHeaderItem(iR)->text().toInt());
            sLine += QString("[" + griText->item(iR, 3)->text() + "...]");
            sLine += "\n";

            if (!fFlogOpen()) return;
            oFlog.write(sLine.toAscii());
        }
        if (griText->item(iR, 0)->text() == "E")
        {
            for (r = 1; r <= gGridModi; r++)
            {
                if (iR == gEditTextRows[r])
                {
                    iC = gEditTextColu[r];
                    if (!gSrtx) iC -= 2;

                    sLine = QString("[Edited] Row %1 Col %2 : ").arg(gEditTextLine[r]).arg(iC);
                    sLine += QString("[" + gEditTextOldx[r] + "]");
                    sLine += QString(" -> [" + gEditTextNewx[r] + "]");
                    sLine += "\n";

                    if (!fFlogOpen()) return;
                    oFlog.write(sLine.toAscii());
                }
            }
        }
    }
    if (oFlog.isOpen()) oFlog.close();
}

bool winMain::fFlogOpen()
{
    if (oFlog.isOpen()) return true;

    int iSize = gFile.size();
    QString sFlog = gFile.mid(0, iSize - 4) + QString(".log");
    oFlog.setFileName(sFlog);
    return oFlog.open(QIODevice::WriteOnly | QIODevice::Text);
}

void winMain::fFileReadSrtx()
{
    QString sLine;
    QByteArray aLine;
    int iGrid = 0;
    int iLine = 0;
    int iRows = 0;
    int iColo = 1;
    QStringList lText;
    int iStru = 1;
    QString sNumb = "";
    QString sStar = "";
    QString sStop = "";
    QString sTex1 = "";
    QString sTex2 = "";
    bool bOk = true;

    oFile.setFileName(gFile);

    if (!oFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, fL("Open"), QString(fL("Cannot read file %1:\n%2")).arg(gFile).arg(oFile.errorString()));
        return;
    }

    fFileCodeTest("i", true);
    while (!oFile.atEnd())
    {
        aLine = oFile.readLine();
        fFileCodeTest(aLine, false);
        iLine++;
    }
    oFile.close();
    fFileCodeTest("", true);

    QProgressDialog barFile(fL("Loading..."), QString(), 0, iLine, this);
    barFile.setWindowTitle(fL(".srt file"));
    barFile.setMinimumDuration(200);
    barFile.setValue(0);
    fWindPosiProg(barFile);

    gWork = true;
    gManu = false;

    gGridModi = 0;
    gGridSave = false;
    fGridSaveIcon();

    gGridInfo = 0;
    gFileErro = "";

    gSrtxStar = "";
    gSrtxStop = "";

    fGridShow(false);
    fGridZero();
    iGrid = -1;
    iRows = 0;
    iLine = 0;
    fFileTextMaxi(-1, 0, 0, 0, 0, 0);
    QFontMetrics mGrid = QFontMetrics(gGridFont);
    QFontMetrics mRows = QFontMetrics(gRowsFont);

    try
    {
        oFile.open(QIODevice::ReadOnly);
    }
    catch (...)
    {
        gFileErro += QString("|x - An error occurred while opening the file.");
        return;
    }

    // one blank-line before the beginning

    griText->insertRow(++iGrid);
    fGridItemSetx("", iGrid, 0);
    fGridItemSetx("00:00:00,000", iGrid, 1);
    fGridItemSetx("00:00:00,000", iGrid, 2);
    fGridItemSetx("", iGrid, 3);
    fGridItemSetx("", iGrid, 4);

    // all the lines

    while (!oFile.atEnd())
    {
        iRows++;
        barFile.setValue(iRows);

        if (iStru == 1 && !sNumb.isEmpty())
        {
            griText->insertRow(++iGrid);
            fGridItemSetx("", iGrid, 0);
            fGridItemSetx(sStar, iGrid, 1);
            fGridItemSetx(sStop, iGrid, 2);
            fGridItemSetx(sTex1, iGrid, 3);
            fGridItemSetx(sTex2, iGrid, 4);

            sTex1 = fGridTextClean(sTex1);              // gpb 120310
            sTex2 = fGridTextClean(sTex2);              // gpb 120310
            fFileTextMaxi(mGrid.width(sTex1), mRows.width(sTex1), sTex1.length(), iGrid, iLine, 3);
            fFileTextMaxi(mGrid.width(sTex2), mRows.width(sTex2), sTex2.length(), iGrid, iLine, 4);

            if (gSrtxStar.isEmpty()) gSrtxStar = sStar;

            sNumb = "";
            sStar = "";
            sStop = "";
            sTex1 = "";
            sTex2 = "";
        }

        try
        {
            aLine = oFile.readLine();
            sLine = fFileLineForm(aLine);
        }
        catch (...)
        {
            gFileErro += QString("|%1 - An error occurred.").arg(iRows);
            oFile.close();
            return;
        }

        if (iStru == 1)
        {
            iLine = fFileSrtxVeriNumb(iRows, sLine, iLine);
            if (iLine < 0) {bOk = false; break;}
            sNumb = sLine;
            iStru++;
        }
        else if (iStru == 2)
        {
            if (!fFileSrtxVeriHour(iRows, sLine, iLine)) {bOk = false; break;}
            lText = sLine.split(QString(" --> "));
            sStar = lText[0];
            sStop = lText[1];

            iStru++;
        }
        else if (iStru == 3)
        {
            if (sLine.length() < 1) iStru = 1;          // line 1 could be optional
            else
            {
                fFileSrtxVeriText(iRows, sLine, iLine);
                iStru++;
            }
            sTex1 = sLine.trimmed();                    // gpb 120310
        }
        else if (iStru == 4)
        {
            if (sLine.length() < 1) iStru = 1;          // line 2 is optional
            else
            {
                fFileSrtxVeriText(iRows, sLine, iLine);
                iColo = 2;
                iStru++;
            }
            sTex2 = sLine.trimmed();                    // gpb 120310
        }
        else if (iStru == 5)
        {
            if (!fFileSrtxVeriBlan(iRows, sLine, iLine)) {bOk = false; break;}
            iStru = 1;
        }
    }
    oFile.close();

    if (!bOk)
    {
        barFile.close();
        QMessageBox::critical(this, fL("Loading..."), fL("Problem encountered, see File info."));
    }

    // store the last lines read

    if (!sNumb.isEmpty())
    {
        griText->insertRow(++iGrid);
        fGridItemSetx("", iGrid, 0);
        fGridItemSetx(sStar, iGrid, 1);
        fGridItemSetx(sStop, iGrid, 2);
        fGridItemSetx(sTex1, iGrid, 3);
        fGridItemSetx(sTex2, iGrid, 4);

        fFileTextMaxi(mGrid.width(sTex1), mRows.width(sTex1), sTex1.length(), iGrid, iLine, 3);
        fFileTextMaxi(mGrid.width(sTex2), mRows.width(sTex2), sTex2.length(), iGrid, iLine, 4);

        gSrtxStop = sStop;
    }

    // one blank-line after the end

    griText->insertRow(++iGrid);
    fGridItemSetx("", iGrid, 0);
    fGridItemSetx("00:00:00,000", iGrid, 1);
    fGridItemSetx("00:00:00,000", iGrid, 2);
    fGridItemSetx("", iGrid, 3);
    fGridItemSetx("", iGrid, 4);

    // remove the very last line

    griText->setRowCount(griText->rowCount()-1);

    gRowsMaxi = griText->rowCount()-1;
    gRowsNumb = iColo;
    if (iColo == 1) radRow1->setChecked(true);
    if (iColo == 2) radRow2->setChecked(true);
    if (iColo == 3) radRow3->setChecked(true);
    if (iColo == 4) radRow4->setChecked(true);

    fRowsNumb();

    fGridInit();
    fGridTitle();
    fGridShow(true);

    fAutoInit();

    diaGrid->setFocus(Qt::OtherFocusReason);
    griText->setFocus(Qt::OtherFocusReason);
    griText->setCurrentCell(0, 1);
}

int winMain::fFileSrtxVeriNumb(int iRows, QString sText, int iLine)
{
    bool bOk;

    if (sText.length() < 1)
    {
        gFileErro += QString("|%1 (file line %2) - Number: unexpected empty line").arg(iLine).arg(iRows);
        gFileErro += QString("|%1 (file line %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return -1;
    }
    if (!sText.at(0).isDigit())
    {
        gFileErro += QString("|%1 (file line %2) - Number: expected: %1").arg(iLine).arg(iRows);
        gFileErro += QString("|%1 (file line %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return -1;
    }
    int iTemp = sText.toInt(&bOk, 10);
    if (iLine == 0) iLine = iTemp;
    else iLine++;
    if (iLine != iTemp)
    {
        gFileErro += QString("|%1 (file line %2) - Number: read: %3, expected: %1").arg(iLine).arg(iRows).arg(iTemp);
        iLine = iTemp;
    }
    return iLine;
}

bool winMain::fFileSrtxVeriHour(int iRows, QString sText, int iLine)
{
    static int iPrev = 0;
    bool bOk;

    if (iLine == 1) iPrev = 0;

    if (sText.length() < 1)
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: unexpected empty line").arg(iLine).arg(iRows);
        gFileErro += QString("|%1 (file line %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return false;
    }
    if (sText.length() != 29)
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: bad length (less or more than 29 char.)").arg(iLine).arg(iRows);
        gFileErro += QString("|%1 (file line %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return false;
    }
    if (!sText.at(0).isDigit() || !sText.at(1).isDigit() || !sText.at(17).isDigit() || !sText.at(18).isDigit())
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: bad hours format").arg(iLine).arg(iRows);
        return true;
    }
    if (sText.at(2) != ':' || sText.at(19) != ':')
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: bad time separator, ':' expected").arg(iLine).arg(iRows);
        return true;
    }
    if (!sText.at(3).isDigit() || !sText.at(4).isDigit() || !sText.at(20).isDigit() || !sText.at(21).isDigit())
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: bad minutes format").arg(iLine).arg(iRows);
        return true;
    }
    if (sText.at(5) != ':' || sText.at(22) != ':')
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: bad time separator, ':' expected").arg(iLine).arg(iRows);
        return true;
    }
    if (!sText.at(6).isDigit() || !sText.at(7).isDigit() || !sText.at(23).isDigit() || !sText.at(24).isDigit())
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: bad seconds format").arg(iLine).arg(iRows);
        return true;
    }
    if (sText.at(8) != ',' || sText.at(25) != ',')
    {
        gFileErro += QString("|%1 - Timecode: bad time separator, ',' expected").arg(iLine).arg(iRows);
        return true;
    }
    if (!sText.at(9).isDigit() || !sText.at(10).isDigit() || !sText.at(11).isDigit() || !sText.at(26).isDigit() || !sText.at(27).isDigit() || !sText.at(28).isDigit())
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: bad milliseconds format").arg(iLine).arg(iRows);
        return true;
    }
    if (sText.mid(12, 5) != " --> ")
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: bad In/Out separator, ' --> ' expected").arg(iLine).arg(iRows);
        return true;
    }
    QString sStar = sText.mid(0, 2) + sText.mid(3, 2) + sText.mid(6, 2) + sText.mid(9, 3);
    int iStar = sStar.toInt(&bOk, 10);
    QString sStop = sText.mid(17, 2) + sText.mid(20, 2) + sText.mid(23, 2) + sText.mid(26, 3);
    int iStop = sStop.toInt(&bOk, 10);
    if (iStar >= iStop)
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: In >= Out").arg(iLine).arg(iRows);
        return true;
    }
     if (iStar < iPrev)
    {
        gFileErro += QString("|%1 (file line %2) - Timecode: In %3 < previous %4").arg(iLine).arg(iRows).arg(iStar).arg(iPrev);
        return true;
    }
    iPrev = iStop;
    return true;
}

bool winMain::fFileSrtxVeriText(int iRows, QString sText, int iLine)
{
    if (sText.length() < 1)
    {
        gFileErro += QString("|%1 (file line %2) - Text line: unexpected empty line").arg(iLine).arg(iRows);
        gFileErro += QString("|%1 (file line %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return false;
    }
    if (sText.length() > gRowsCharMaxi)
    {
        gFileErro += QString("|%1 (file line %2) - Text line: line length > %3 char.").arg(iLine).arg(iRows).arg(gRowsCharMaxi);
        return true;
    }
    for (int i = 0; i < sText.length(); i++)
    {
        if (!sText.at(i).isPrint())
        {
            gFileErro += QString("|%1 (file line %2) - Text line: non-printable character (at %3)").arg(iLine).arg(iRows).arg(i + 1);
            return true;
        }
    }
    return true;
}

bool winMain::fFileSrtxVeriBlan(int iRows, QString sText, int iLine)
{
    if (sText.length() > 0)
    {
        gFileErro += QString("|%1 (file line %2) - Line break not found, empty line expected").arg(iLine).arg(iRows);
        gFileErro += QString("|%1 (file line %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return false;
    }
    return true;
}

void winMain::fFileInfo()
{
    if (gAuto && gPlay) return;

    if (gFileInfo)
    {
        fFileInfoClos();
        fGridFocus();
        return;
    }

    int iRmax = 7;
    int iRowH = 18;
    int iCol0 = 250;
    int iCol1 = 330;
    int iL = -1;

    gInfoWidt = (iCol0 + iCol1) + 30;
    gInfoHeig = (iRowH * iRmax) + 10;
    gInfoLefx = 20;
    fWindScre("i");

    gFileInfo = true;

    diaInfo = new QDialog(this);
    diaInfo->setWindowTitle(fL("File info"));
    diaInfo->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    diaInfo->setCursor(Qt::ArrowCursor);
    diaInfo->setMinimumHeight(gInfoHeig);
    diaInfo->setMaximumHeight(gInfoHeig * 2);
    diaInfo->setMinimumWidth(gInfoWidt);
    diaInfo->setMaximumWidth(gInfoWidt * 2);
    diaInfo->setContentsMargins(0, 0, 0, 0);
    diaInfo->setStyleSheet(gGridStyl);
    connect(diaInfo, SIGNAL(finished(int)), this, SLOT(fFileInfoFini(int)));

    fFileInfoGeom();

    griInfo = new QTableWidget(diaInfo);
    griInfo->setGeometry(0, 0, gInfoWidt - 10, gInfoHeig - 10);
    griInfo->setSelectionMode(QAbstractItemView::NoSelection);
    griInfo->setStyleSheet(gGriIStyl);
    connect(griInfo, SIGNAL(cellClicked(int, int)), this, SLOT(fFileInfoGoto(int, int)));

    QHeaderView *hh = griInfo->horizontalHeader();
    hh->setFixedHeight(3);

    griInfo->setColumnCount(2);
    griInfo->setColumnWidth(0, iCol0);
    griInfo->setColumnWidth(1, iCol1);

    griInfo->setRowCount(iRmax);
    for (int iR = 0; iR < iRmax; iR++) {griInfo->setRowHeight(iR, iRowH);}

    QGridLayout *layInfo = new QGridLayout;
    layInfo->setContentsMargins(0, 0, 0, 0);
    layInfo->setHorizontalSpacing(0);
    layInfo->addWidget(griInfo, 0, 0);
    diaInfo->setLayout(layInfo);

    // infos -------------------------------------------

    QFileInfo fInfo = QFileInfo(gFile);
    QString sc = gFileEnco ? "ANSI" : "UTF8";
    QString cm = QString("%1").arg(gRowsNumb);
    QString rm = QString("%1").arg(gRowsMaxi-1);
    iL++;
    widInfoName = new QTableWidgetItem(fL("File name"));
    widInfoName->setBackground(gInfoBack);
    widInfoName->setForeground(gInfoColo);
    griInfo->setItem(iL, 0, widInfoName);
    QTableWidgetItem *vn = new QTableWidgetItem(fInfo.completeBaseName() + "." + fInfo.suffix());
    griInfo->setItem(iL, 1, vn);
    iL++;
    widInfoPath = new QTableWidgetItem(fL("Location folder"));
    widInfoPath->setBackground(gInfoBack);
    widInfoPath->setForeground(gInfoColo);
    griInfo->setItem(iL, 0, widInfoPath);
    QTableWidgetItem *vp = new QTableWidgetItem(fInfo.absolutePath());
    griInfo->setItem(iL, 1, vp);
    iL++;
    widInfoModi = new QTableWidgetItem(fL("Last modified"));
    widInfoModi->setBackground(gInfoBack);
    widInfoModi->setForeground(gInfoColo);
    griInfo->setItem(iL, 0, widInfoModi);
    QTableWidgetItem *vd = new QTableWidgetItem(fInfo.lastModified().toString("dd/MM/yyyy, hh:mm"));
    griInfo->setItem(iL, 1, vd);
    iL++;
    widInfoEnco = new QTableWidgetItem(fL("Encoding"));
    widInfoEnco->setBackground(gInfoBack);
    widInfoEnco->setForeground(gInfoColo);
    griInfo->setItem(iL, 0, widInfoEnco);
    QTableWidgetItem *vc = new QTableWidgetItem(sc);
    griInfo->setItem(iL, 1, vc);
    iL++;
    widInfoRows = new QTableWidgetItem(fL("Number of subtitles"));
    widInfoRows->setBackground(gInfoBack);
    widInfoRows->setForeground(gInfoColo);
    griInfo->setItem(iL, 0, widInfoRows);
    QTableWidgetItem *wr = new QTableWidgetItem(rm);
    griInfo->setItem(iL, 1, wr);    
    iL++;
    widInfoCols = new QTableWidgetItem(fL("Max. number of lines"));
    widInfoCols->setBackground(gInfoBack);
    widInfoCols->setForeground(gInfoColo);
    griInfo->setItem(iL, 0, widInfoCols);
    QTableWidgetItem *wc = new QTableWidgetItem(cm);
    griInfo->setItem(iL, 1, wc);

    if (gSrtx)
    {
        iL++;
        griInfo->insertRow(iL);
        griInfo->setRowHeight(iL, iRowH);

        QTableWidgetItem *wD = new QTableWidgetItem(fL("Last timecode"));
        wD->setBackground(gInfoBack);
        wD->setForeground(gInfoColo);
        griInfo->setItem(iL, 0, wD);
        QTableWidgetItem *vD = new QTableWidgetItem(gSrtxStop.left(8));
        griInfo->setItem(iL, 1, vD);
    }

    iL++;
    widInfoLine = new QTableWidgetItem(fL("Widest lines (sorted decreasingly)"));
    widInfoLine->setBackground(gInfoBack);
    widInfoLine->setForeground(gInfoColo);
    griInfo->setItem(iL, 0, widInfoLine);                                                   // gpb 120310
    QTableWidgetItem *vl = new QTableWidgetItem(QString("%1 - %2   (%3 pix)   (%4 c.)").arg(gFileMaxiRows[0]).arg(gFileMaxiColo[0] - 2).arg(gFileMaxiLeng[0]).arg(gFileMaxiChar[0]));
    vl->setIcon(gIconInfoGoto);
    griInfo->setItem(iL, 1, vl);

    for (int iM = 1; iM < 9; iM++)
    {
        if (gFileMaxiLine[iM] > 0 && gFileMaxiLine[iM] != gFileMaxiLine[iM-1])
        {
            iL++;
            griInfo->insertRow(iL);
            griInfo->setRowHeight(iL, iRowH);

            QTableWidgetItem *wM = new QTableWidgetItem("");
            wM->setBackground(gInfoBack);
            griInfo->setItem(iL, 0, wM);                                                            // gpb 120310
            QTableWidgetItem *vM = new QTableWidgetItem(QString("%1 - %2   (%3 pix)   (%4 c.)").arg(gFileMaxiRows[iM]).arg(gFileMaxiColo[iM] - 2).arg(gFileMaxiLeng[iM]).arg(gFileMaxiChar[iM]));
            vM->setIcon(gIconInfoGoto);
            griInfo->setItem(iL, 1, vM);
        }
    }

    if (!gFileErro.isEmpty())
    {
        QStringList lProb = gFileErro.split(QString("|"));

        iL++;
        griInfo->insertRow(iL);
        griInfo->setRowHeight(iL, iRowH);

        widInfoProb = new QTableWidgetItem(fL("Problem detected"));
        widInfoProb->setBackground(gErroBack);
        widInfoProb->setForeground(gErroColo);
        griInfo->setItem(iL, 0, widInfoProb);
        QTableWidgetItem *vp = new QTableWidgetItem(lProb[1]);
        vp->setIcon(gIconInfoGoto);
        griInfo->setItem(iL, 1, vp);

        for (int iP = 2; iP < lProb.count(); iP++)
        {
            iL++;
            griInfo->insertRow(iL);
            griInfo->setRowHeight(iL, iRowH);

            QTableWidgetItem *wP = new QTableWidgetItem("");
            wP->setBackground(gErroBack);
            griInfo->setItem(iL, 0, wP);
            QTableWidgetItem *vP = new QTableWidgetItem(lProb[iP]);
            vP->setIcon(gIconInfoGoto);
            griInfo->setItem(iL, 1, vP);
        }
    }

    // show infos --------------------------------------

    gInfoHeig = (iRowH * griInfo->rowCount()) + 10;
    if (gInfoHeig > 500) gInfoHeig = 500;
    diaInfo->setMaximumHeight(gInfoHeig);
    fWindScre("i");
    fFileInfoGeom();
    diaInfo->show();
}

void winMain::fFileInfoGeom()
{
    if (gFileInfo)
    {
        diaInfo->setGeometry(gInfoLefx, gInfoTopy, gInfoWidt, gInfoHeig);
        fWindPosiDial(diaInfo);
    }
}

void winMain::fFileInfoFini(int)
{
    gFileInfo = false;
    fGridFocus();
}

void winMain::fFileInfoClos()
{
    if (gFileInfo)
    {
        if (!diaInfo->isHidden()) diaInfo->close();
    }
    gFileInfo = false;
}

void winMain::fFileInfoGoto(int iR, int iC)
{
    if (iC != 1) return;

    QTableWidgetItem *wc = griInfo->currentItem();

    QIcon ic = wc->icon();
    if (ic.isNull()) return;

    QString sT = wc->text();
    QStringList lT = sT.split(QString(" "));
    iR = lT[0].toInt();
    iC = lT[2].toInt();
    griText->setCurrentCell(iR, iC, QItemSelectionModel::Rows);
    griText->scrollTo(griText->currentIndex(), QAbstractItemView::PositionAtCenter);
    fGridFocus();
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// help functions
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void winMain::fHelpDial()
{
    if (gAuto && gPlay) return;
    if (gHelp) fHelpDialClos(0);

    gHelp = true;

    gHelpWidt = 720;
    gHelpHeig = 750;
    gHelpLefx = 3;
    gHelpTopy = 3;

    diaHelp = new QDialog(this);
    diaHelp->setGeometry(gHelpLefx, gHelpTopy, gHelpWidt, gHelpHeig);
    diaHelp->setWindowTitle(fL("Help")+"  ·  Program version "+gVers);
    diaHelp->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    diaHelp->setCursor(Qt::ArrowCursor);
    diaHelp->setMinimumHeight(gHelpHeig);
    diaHelp->setMaximumHeight(gHelpHeig);
    diaHelp->setMinimumWidth(gHelpWidt);
    diaHelp->setMaximumWidth(gHelpWidt);
    diaHelp->setContentsMargins(0, 0, 0, 0);
    diaHelp->setStyleSheet(gGridStyl);
    connect(diaHelp, SIGNAL(finished(int)), this, SLOT(fHelpDialFini(int)));

    texHelp = new QTextEdit("");
    texHelp->setGeometry(gHelpLefx-1, gHelpTopy-1, gHelpWidt-1, gHelpHeig-1);
    texHelp->setReadOnly(true);
    texHelp->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    texHelp->setFrameShape(QFrame::NoFrame);
    texHelp->setContentsMargins(0, 0, 0, 0);
    texHelp->setFont(gRowsFont);
    texHelp->setStyleSheet(gHelpStyl);
    texHelp->setWordWrapMode(QTextOption::NoWrap);
    texHelp->document()->setDocumentMargin(0);
    texHelp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    layHelp = new QVBoxLayout;
    layHelp->setSpacing(0);
    layHelp->setContentsMargins(0, 0, 0, 0);
    layHelp->addWidget(texHelp);

    fraHelp = new QFrame(diaHelp);
    fraHelp->setFrameShape(QFrame::NoFrame);
    fraHelp->setGeometry(0, 0, gHelpWidt, gHelpHeig);
    fraHelp->setContentsMargins(0, 0, 0, 0);
    fraHelp->setLayout(layHelp);

    texHelp->setHtml(fHelpFileRead());

    diaHelp->show();
}

QString winMain::fHelpFileRead()
{
    oHelp.setFileName(":/Help/QSTit_Help_En.htm");
    oHelp.open(QIODevice::ReadOnly);
    QByteArray sHelp = oHelp.readAll();
    oConf.close();

    QTextCodec *codec;
    codec = QTextCodec::codecForName("UTF-8");
    return codec->toUnicode(sHelp);
}

void winMain::fHelpDialClos(int)
{
    if (gHelp) diaHelp->close();
    gHelp = false;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// other functions
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void winMain::fClearAllDial()                           // gpb 120220
{
    QMessageBox *qm = new QMessageBox(QMessageBox::Question, fL("Reset"), fL("Clear screen and\nreset file at beginning ?"), QMessageBox::Yes|QMessageBox::No, this);
    fWindPosiMess(qm);
    int iRep = qm->exec();
    if (iRep == QMessageBox::Yes) fClearAll();
}

void winMain::fClearAll()
{
    if (gAuto && gPlay) fAutoPaus();                     // gpb 110930

    fWindLogoHide();
    fWindClear();
    fRowsClear();
    fSettGeom();
    fSettClos();
    fGridGeom();
    fGridEditEnab();                                    // gpb 111123
    fFileInfoClos();
    fFileInfoGeom();
    fHelpDialClos(0);

    gPlay = false;                                      // gpb 110930
    gInit = false;                                      // gpb 110930
    gAcce = 0;                                          // gpb 110930
    gJump = 0;                                          // gpb 110930

    labTime->setText("00:00:00");
    labPuls->setText("");
    labJump->setText("");                               // gpb 110930

    if (gGridShow) griText->setCurrentCell(0, 1);       // gpb 110930
}

void winMain::fWorkLang()
{
    if (radEngl->isChecked()) gLang = 0;
    if (radFren->isChecked()) gLang = 1;
    if (radDutc->isChecked()) gLang = 2;

    griText->fWorkLang(gLang);

    butExit->setText(fL("Quit"));
    butFile->setText(fL("Open"));
    butSett->setText(fL("Settings"));
    butClea->setText(fL("Reset"));

    if (!gGridShow) fRowsInit();

    diaSett->setWindowTitle(fL("Settings"));
    labTaskShow->setText(fL("Show Taskbar"));
    radTaskShow->setText(fL("Yes"));
    radTaskHide->setText(fL("No"));
    labWindMenu->setText(fL("Menu location"));
    radWindMenT->setText(fL("Top"));
    radWindMenB->setText(fL("Bottom"));
    labFileEnco->setText(fL("File encoding"));
    labWorkLang->setText(fL("Interface language"));
    tabSett->setTabText(0, fL("Subtitles"));
    tabSett->setTabText(1, fL("Grid"));
    tabSett->setTabText(2, fL("General"));
    texRowsNumb->setText(fL("Lines"));
    labTextFont->setText(fL("Text"));
    labWindBack->setText(fL("Test screen"));
    radWindBacB->setText(fL("Off"));
    radWindBacG->setText(fL("On"));
    chkSecoText->setText(fL("Display one-line subtitles on bottom line"));
    chkSecoItal->setText(fL("Force italic for bottom lines"));
    texRowsLocV->setText(fL("V. position"));
    texRowsLocH->setText(fL("H. position"));
    texRowsHeig->setText(fL("Height"));
    texRowsWidt->setText(fL("Width"));
    texRowsSpac->setText(fL("Spacing"));
    labTextFont->setText(fL("Text"));
    butTextColo->setText(fL("Colour"));
    butTextBack->setText(fL("Colour"));
    butFont->setText(fL("Font"));
    labCharOutl->setText(fL("Outline"));
    butChar->setText(fL("Colour"));
    labCharThic->setText(fL("Outline"));
    radNone->setText(fL("None"));
    radThin->setText(fL("1px"));
    radBold->setText(fL("2px"));
    labTextAliH->setText(fL("H. align"));
    radLeft->setText(fL("Left"));
    radCenH->setText(fL("Center"));
    radRigh->setText(fL("Right"));
    labTextAliV->setText(fL("V. align"));
    radTopy->setText(fL("Top"));
    radCenV->setText(fL("Center"));
    radBott->setText(fL("Bottom"));
    texRowsBack->setText(fL("Background"));
    texRowsLoVm->setText(fL("Top"));
    texRowsLoVM->setText(fL("Bottom"));
    texRowsLoHm->setText(fL("Left"));
    texRowsLoHM->setText(fL("Right"));
    labGridFfam->setText(fL("Grid font"));
    labGridFsiz->setText(fL("Grid font size"));
    labGridHour->setText(fL("Hours format"));
    radGridHour->setText(fL("bold"));

    if (gFileInfo)
    {
        widInfoName->setText(fL("File name"));
        widInfoPath->setText(fL("Location folder"));
        widInfoModi->setText(fL("Last modified"));
        widInfoEnco->setText(fL("Encoding"));
        widInfoCols->setText(fL("Max. number of lines"));
        widInfoRows->setText(fL("Number of subtitles"));
        widInfoLine->setText(fL("Widest lines (sorted decreasingly)"));
    }

    butGridInfo->gLang = gLang;
    butGridSave->gLang = gLang;
    butGridUndo->gLang = gLang;
    butGridGoto->gLang = gLang;
    butGridFind->gLang = gLang;
    butGridEdit->gLang = gLang;
    butRoll->gLang = gLang;
    butProjUpup->gLang = gLang;
    butProjDown->gLang = gLang;
    butProjPlay->gLang = gLang;
    butProjDece->gLang = gLang;
    butProjAcce->gLang = gLang;
    butProjBack->gLang = gLang;
    butProjJump->gLang = gLang;
}

QString winMain::fL(QString sI)
{
    QString sO = sI;

    if (gLang > 0)
    {
        if      (sI == "Background")    sO = gLang == 1 ? "Fond de ligne"   : "Background";
        else if (sI == "black")         sO = gLang == 1 ? "noir"            : "zwart";
        else if (sI == "bottom")        sO = gLang == 1 ? "bas"             : "beneden";
        else if (sI == "Bottom")        sO = gLang == 1 ? "Bas"             : "Beneden";
        else if (sI == "Cancel")        sO = gLang == 1 ? "Abandon"         : "Cancel";
        else if (sI == "center")        sO = gLang == 1 ? "centre"          : "center";
        else if (sI == "Reset")         sO = gLang == 1 ? "Reset"           : "Reset";
        else if (sI == "File encoding") sO = gLang == 1 ? "Codage de caractères" : "File encoding";

        else if (sI == "Colors")        sO = gLang == 1 ? "Couleurs"        : "Kleuren";
        else if (sI == "Columns")       sO = gLang == 1 ? "Colonnes"        : "Zuilen";
        else if (sI == "Confirm")       sO = gLang == 1 ? "Confirmer"       : "Bevestigen";
        else if (sI == "Edit")          sO = gLang == 1 ? "Editer"          : "Edit";
        else if (sI == "Exit")          sO = gLang == 1 ? "Quitter"         : "Stop";
        else if (sI == "End")           sO = gLang == 1 ? "Fin"             : "Einde";
        else if (sI == "Find")          sO = gLang == 1 ? "Trouver"         : "Zoeken";
        else if (sI == "Folder")        sO = gLang == 1 ? "Répertoire"      : "Folder";
        else if (sI == "Fonts")         sO = gLang == 1 ? "Polices"         : "Fonts";
        else if (sI == "General")       sO = gLang == 1 ? "Général"         : "Algemeen";
        else if (sI == "Goto")          sO = gLang == 1 ? "Aller"           : "Gaan";
        else if (sI == "gray")          sO = gLang == 1 ? "gris"            : "grijs";
        else if (sI == "Grid")          sO = gLang == 1 ? "Grille"          : "Tabel";
        else if (sI == "Height")        sO = gLang == 1 ? "Hauteur"         : "Hoogte";
        else if (sI == "Info")          sO = gLang == 1 ? "Info"            : "Info";
        else if (sI == "left")          sO = gLang == 1 ? "gauche"          : "links";
        else if (sI == "Line")          sO = gLang == 1 ? "Ligne"           : "Regel";
        else if (sI == "Lines")         sO = gLang == 1 ? "Lignes"          : "Regels";
        else if (sI == "Location")      sO = gLang == 1 ? "Positionnement"  : "Stand";
        else if (sI == "Modify")        sO = gLang == 1 ? "Modifier"        : "Wijzigen";
        else if (sI == "Next")          sO = gLang == 1 ? "Suivant"         : "Volgende";
        else if (sI == "no")            sO = gLang == 1 ? "non"             : "neen";
        else if (sI == "none")          sO = gLang == 1 ? "aucun"           : "geen";
        else if (sI == "Open")          sO = gLang == 1 ? "Ouvrir"          : "Openen";
        else if (sI == "Outline")       sO = gLang == 1 ? "Contours"        : "Omtrek";
        else if (sI == "Previous")      sO = gLang == 1 ? "Précédent"       : "Voorige";
        else if (sI == "Reading...")    sO = gLang == 1 ? "Lecture..."      : "Lezen...";
        else if (sI == "right")         sO = gLang == 1 ? "droite"          : "recht";
        else if (sI == "Rows")          sO = gLang == 1 ? "Lignes"          : "Regels";
        else if (sI == "Save")          sO = gLang == 1 ? "Sauvegarder"     : "Opslaan";
        else if (sI == "Settings")      sO = gLang == 1 ? "Réglages"        : "Regelings";
        else if (sI == "Spacing")       sO = gLang == 1 ? "Espacement"      : "Spatiëring";
        else if (sI == "Texts")         sO = gLang == 1 ? "Textes"          : "Texten";
        else if (sI == "Thickness")     sO = gLang == 1 ? "Epaisseur"       : "Dikte";
        else if (sI == "top")           sO = gLang == 1 ? "haut"            : "boven";
        else if (sI == "Undo")          sO = gLang == 1 ? "Annuler"         : "Vernietigen";
        else if (sI == "Width")         sO = gLang == 1 ? "Largeur"         : "Breedte";
        else if (sI == "yes")           sO = gLang == 1 ? "oui"             : "ja";

        if (sI == "Text modified") sO = gLang == 1 ? "Texte modifié" : "Text verandert";
        else if (sI == "You changed some text(s)") sO = gLang == 1 ? "Le texte a été changé" : "De text was verandert";
        else if (sI == "Do you want to save them ?") sO = gLang == 1 ? "Voulez-vous le sauver ?" : "Wilt-u het opslaan ?";
        else if (sI == "Show Taskbar") sO = gLang == 1 ? "Voir Taskbar" : "Taskbar zien";
        else if (sI == "Menu location") sO = gLang == 1 ? "Position menu" : "Positie menu";
        else if (sI == "File encoding") sO = gLang == 1 ? "Codex fichier" : "Codex bestand";
        else if (sI == "Working language") sO = gLang == 1 ? "Langue de travail" : "Werk taal";
        else if (sI == "Screen color") sO = gLang == 1 ? "Couleur écran" : "Scherm kleur";
        else if (sI == "Single text line displayed on row 2") sO = gLang == 1 ? "Ligne 1 seule affichée en Ligne 2" : "Simpel regel 1 op Regel 2 getoond";
        else if (sI == "Second text line in italic") sO = gLang == 1 ? "2ème ligne de texte en italique" : "2de text regel cursief";
        else if (sI == "Line background") sO = gLang == 1 ? "Fond de ligne" : "Regel background";
        else if (sI == "Alignment Hor.") sO = gLang == 1 ? "Alignement Hor." : "Hor. plaatsing";
        else if (sI == "Alignment Vert.") sO = gLang == 1 ? "Alignement Vert." : "Vert. plaatsing";
        else if (sI == "Open a S-Title") sO = gLang == 1 ? "Ouvrir un S-Titre" : "Open een O-Titel";
        else if (sI == "S-Titles") sO = gLang == 1 ? "S-Titres" : "O-Titelen";
        else if (sI == "A S-Title is already loaded\nAre you sure ?") sO = gLang == 1 ? "Un S-Titre est déjà chargé\nEtes-vous sur?" : "Een O-Titel zit nu al in het geheuge\nBent-u zeker?";
        else if (sI == "Cannot read file %1:\n%2") sO = gLang == 1 ? "Problème de lecture de %1:\n%2" : "Kan niet lezen het bestand %1:\n%2";
        else if (sI == "Texts color") sO = gLang == 1 ? "Couleur des textes" : "Kleur van texten";
        else if (sI == "Outline color") sO = gLang == 1 ? "Couleur du contour" : "Omtrek kleur";
        else if (sI == "Location Vert.") sO = gLang == 1 ? "Position Vert." : "Stand Vert.";
        else if (sI == "Location Hor.") sO = gLang == 1 ? "Position Hor." : "Stand Hor.";
        else if (sI == "Grid font") sO = gLang == 1 ? "Police du Grid" : "Grid font";
        else if (sI == "Grid font size") sO = gLang == 1 ? "Taille police" : "Font middel";
        else if (sI == "Format preference") sO = gLang == 1 ? "Format préféré" : "Format voorkeur";
        else if (sI == "File name") sO = gLang == 1 ? "Nom du fichier" : "Naam bestand";
        else if (sI == "Last modified") sO = gLang == 1 ? "Modifié le" : "Wijzigd";
        else if (sI == "Widest lines (sorted decreasing)") sO = gLang == 1 ? "Lignes les + longues (ordre décroissant)" : "Langer regels (gesorteerd decreasing)";
        else if (sI == "Settings exist for that file") sO = gLang == 1 ? "Des réglages existent pour ce fichier" : "Opties bestaan voor dat bestand";
        else if (sI == "Do you want to use them ?") sO = gLang == 1 ? "Voulez-vous les utiliser ?" : "Wilt u ze gebruiken ?";
        else if (sI == "SRT file") sO = gLang == 1 ? "Fichier SRT" : "SRT bestand";
        else if (sI == "TXT file") sO = gLang == 1 ? "Fichier TXT" : "TXT bestand";
        else if (sI == "Problems (in source read)") sO = gLang == 1 ? "Problèmes (dans fichier lu)" : "Problemen (in bron-bestand)";
        else if (sI == "Edit (a text)") sO = gLang == 1 ? "Editer (un texte)" : "Correctie (één text)";
        else if (sI == "Infos (about the file)") sO = gLang == 1 ? "Infos (sur le fichier)" : "Infos (over het bestand)";
        else if (sI == "Save (change(s) made (with Edit) in text lines)") sO = gLang == 1 ? "Sauver les textes corrigés" : "Correcties opslaan";
        else if (sI == "Undo (change(s) made (with Edit) in text lines)") sO = gLang == 1 ? "Annuler les corrections" : "Overgave van correcties";
        else if (sI == "Goto (a line)") sO = gLang == 1 ? "Aller (à une ligne)" : "Gaan (naar een regel)";
        else if (sI == "Find (a text)") sO = gLang == 1 ? "Chercher (un mot)" : "Zoeken (woord)";
        else if (sI == "Hide/Show texts") sO = gLang == 1 ? "Cacher/Voir les textes" : "regels Verbergen/Zien";
        else if (sI == "Previous line") sO = gLang == 1 ? "Ligne précédente" : "Vorige regel";
        else if (sI == "Next line") sO = gLang == 1 ? "Ligne suivante" : "Volgende regel";
        else if (sI == "Start/Pause") sO = gLang == 1 ? "Démarrer/Pause" : "Starten/Pauzen";
        else if (sI == "Decelerate") sO = gLang == 1 ? "Ralentir" : "Vertragen";
        else if (sI == "Accelerate") sO = gLang == 1 ? "Accélérer" : "Versnellen";
        else if (sI == "Jump 1/2 sec. backward") sO = gLang == 1 ? "Saut 1/2 sec. en arrière" : "1/2 sec. achter sprong";
        else if (sI == "Jump 1/2 sec. foreward") sO = gLang == 1 ? "Saut 1/2 sec. en avant" : "1/2 sec. voor sprong";
        else if (sI == "Don't save settings") sO = gLang == 1 ? "Ne pas sauvegarder les réglages" : "Regelings niet opslaan";
        else if (sI == "Save settings as global settings") sO = gLang == 1 ? "Associer les réglages au programme" : "Regelings aan het programma te verbinden";
        else if (sI == "Save settings as settings for this file") sO = gLang == 1 ? "Associer les réglages à ce fichier" : "Regelings aan dit bestand te verbinden";
        else if (sI == "Problem encoutered, see [Infos]") sO = gLang == 1 ? "Problème, voir [Infos]" : "Probleem, zie [Infos]";
        else if (sI == "Hours format") sO = gLang == 1 ? "Heures (format)" : "Uren formaat";
        else if (sI == "Widest") sO = gLang == 1 ? "Long.max." : "Max.lengte";
    }
    return sO;
}

void winMain::keyPressEvent(QKeyEvent *qe)
{
    if (qe->modifiers() == Qt::NoModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_N:         {fRowsShow(-1);break;}
            case Qt::Key_P:         {fAutoAcce();break;}
            case Qt::Key_Plus:      {fAutoAcce();break;}
            case Qt::Key_M:         {fAutoDece();break;}
            case Qt::Key_Minus:     {fAutoDece();break;}
            case Qt::Key_F1:        {fHelpDial();break;}
            case Qt::Key_PageUp:    {fRowsPosi(sliRowsLocV->value()+1);break;}
            case Qt::Key_PageDown:  {fRowsPosi(sliRowsLocV->value()-1);break;}
            case Qt::Key_Home:      {fRowsLocH(sliRowsLocH->value()+1);break;}
            case Qt::Key_End:       {fRowsLocH(sliRowsLocH->value()-1);break;}
            case Qt::Key_Up:        {fButtPrev();break;}
            case Qt::Key_Down:      {fButtNext();break;}
            case Qt::Key_Left:      {fAutoBack();break;}
            case Qt::Key_Right:     {fAutoJump();break;}
            case Qt::Key_Space:     {if (gAuto) {fAutoStar();} else {fButtNext();}
					break;}
            default:                {QWidget::keyPressEvent(qe);}
        }
    }
    else if (qe->modifiers() == Qt::ShiftModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_Plus:      {fAutoAcce();break;}
            default:                {QWidget::keyPressEvent(qe);}
        }
    }
    else if (qe->modifiers() == Qt::ControlModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_Q:         {fWindExitDial();break;}
            case Qt::Key_O:         {fFileDial();break;}
            case Qt::Key_I:         {fFileInfo();break;}
            case Qt::Key_S:         {fSettShow();break;}
            case Qt::Key_R:         {fClearAllDial();break;}
            case Qt::Key_E:         {fGridEditButt();break;}
            case Qt::Key_Z:         {fGridUndo();break;}
            default:                {QWidget::keyPressEvent(qe);}
        }
    }
    else if (qe->modifiers() == Qt::KeypadModifier)
    {
          switch (qe->key())
        {
            case Qt::Key_Plus:      {fAutoAcce();break;}
            case Qt::Key_Minus:     {fAutoDece();break;}
            case Qt::Key_Period:    {fRowsShow(-1);break;}
            case Qt::Key_9:         {fRowsPosi(sliRowsLocV->value()+1);break;}
            case Qt::Key_3:         {fRowsPosi(sliRowsLocV->value()-1);break;}
            case Qt::Key_7:         {fRowsLocH(sliRowsLocH->value()+1);break;}
            case Qt::Key_1:         {fRowsLocH(sliRowsLocH->value()-1);break;}
            case Qt::Key_8:         {fButtPrev();break;}
            case Qt::Key_2:         {fButtNext();break;}
            case Qt::Key_4:         {fAutoBack();break;}
            case Qt::Key_6:         {fAutoJump();break;}
            case Qt::Key_0:         {if (gAuto) {fAutoStar();} else {fButtNext();}
					break;}
            default:                {QWidget::keyPressEvent(qe);}
        }
    }

    else
    {
        switch (qe->key())
        {
            case Qt::Key_Escape:    {break;}
            case Qt::Key_Return:    {break;}
            case Qt::Key_Enter:     {break;}
            case Qt::Key_Tab:       {break;}
            default:                {QWidget::keyPressEvent(qe);}
        }
    }
}

void winMain::fConfRead()
{
    QString sLine;
    QStringList lText;
    QString sVari;
    QString sValu;
    QString sMess;

    oConf.setFileName(gConf);

    if (!oConf.open(QIODevice::ReadOnly)) return;

    while (!oConf.atEnd())
    {
        sLine = fFileLineForm(oConf.readLine());
        if(!sLine.isEmpty())
        {
            lText = sLine.split(QString("="));
            sVari = lText[0].trimmed();
            sValu = lText[1].trimmed();
            fConfConf(sVari, sValu);
        }
    }

    oConf.close();

    fWindBack();
    fWorkLang();
    fRowsNumb();
    fRowsFontChan();
    fGridFontFami();
    fGridFontSize();
    fWindScre("a");
}

void winMain::fConfConf(QString sVari, QString sValu)
{
    bool ok;

    if (sVari == "gScre")
    {
        gScre = sValu == "false" ? false : true;
        if (gScre) radWindMenB->setChecked(true);
        else radWindMenT->setChecked(true);
    }
    if (sVari == "gLang")
    {
        gLang = sValu.toInt(&ok, 10);
        if (gLang < 0 || gLang > 2) gLang = 0;
        if (gLang == 0) radEngl->setChecked(true);
        if (gLang == 1) radFren->setChecked(true);
        if (gLang == 2) radDutc->setChecked(true);
    }
    if (sVari == "gWindBack")
    {
        gWindBack = sValu;
        if (gWindBack == "#000000") radWindBacB->setChecked(true);
        if (gWindBack == "#575757") radWindBacG->setChecked(true);
    }
    if (sVari == "gRowsNumb")
    {
        gRowsNumb = sValu.toInt(&ok, 10);
        if (gRowsNumb < 1 || gRowsNumb > 4) gRowsNumb = 4;
        if (gRowsNumb == 1) radRow1->setChecked(true);
        if (gRowsNumb == 2) radRow2->setChecked(true);
        if (gRowsNumb == 3) radRow3->setChecked(true);
        if (gRowsNumb == 4) radRow4->setChecked(true);
    }
    if (sVari == "gRowsSpac")
    {
        gRowsSpac = sValu.toInt(&ok, 10);
        if (gRowsSpac < 1 || gRowsSpac > 50) gRowsSpac = 1;
        sliRowsSpac->setValue(gRowsSpac);               // gpg 120220
    }
    if (sVari == "gRowsHeig")                           // gpg 120220
    {
        int iRowsHeig = sValu.toInt(&ok, 10);
        sliRowsHeig->setValue(iRowsHeig);
        fRowsHeig(iRowsHeig);
    }
    if (sVari == "xRowsHeigMin")                        // gpg 120220
    {
        int iRowsHeigMin = sValu.toInt(&ok, 10);
        sliRowsHeig->setMinimum(iRowsHeigMin);
    }
    if (sVari == "xRowsHeigMax")                        // gpg 120220
    {
        int iRowsHeigMax = sValu.toInt(&ok, 10);
        sliRowsHeig->setMaximum(iRowsHeigMax);
    }
    if (sVari == "gRowsWidt")
    {
        gRowsWidt = sValu.toInt(&ok, 10);
        if (gRowsWidt < 300 || gRowsWidt > gRowsWmax) gRowsWidt = gRowsWmax;
        sliRowsWidt->setValue(gRowsWidt);
    }
    if (sVari == "xRowsWidtMin")                        // gpg 120220
    {
        int iRowsWidtMin = sValu.toInt(&ok, 10);
        sliRowsWidt->setMinimum(iRowsWidtMin);
    }
    if (sVari == "xRowsWidtMax")                        // gpg 120220
    {
        int iRowsWidtMax = sValu.toInt(&ok, 10);
        sliRowsWidt->setMaximum(iRowsWidtMax);
    }
    if (sVari == "xRowsFontName")
    {
        QString sFami = sValu;
        gRowsFont.setFamily(sFami);
    }
    if (sVari == "xRowsFontSize")
    {
        int iSize = sValu.toInt(&ok, 10);
        gRowsFont.setPointSize(iSize);
    }
    if (sVari == "xRowsFontWeig")
    {
        int iWeig = sValu.toInt(&ok, 10);
        gRowsFont.setWeight(iWeig);
    }
    if (sVari == "xRowsFontItal")
    {
        bool bItal = sValu == "true" ? true : false;
        gRowsFont.setItalic(bItal);
    }
    if (sVari == "gRowsLefx")
    {
        gRowsLefx = sValu.toInt(&ok, 10);
        int iLefx = -1 * (gRowsLefx - 1);
        sliRowsLocH->setValue(iLefx);
    }
    if (sVari == "gRowsTopy")
    {
        int iTopy = sValu.toInt(&ok, 10);
        sliRowsLocV->setValue(iTopy);
        gRowsTopy = iTopy;
    }
    if (sVari == "gRowsBack")
    {
        QString sBack = sValu;
        if (sBack.length() != 7 || !sBack.startsWith("#")) sBack = "#000000";
        gRowsBack = sBack;
    }
    if (sVari == "gRowsColo")
    {
        QString sColo = sValu;
        if (sColo.length() != 7 || !sColo.startsWith("#")) sColo = "#ffffff";
        gRowsColo = sColo;
    }
    if (sVari == "gGridHourBold")
    {
        gGridHourBold = sValu == "false" ? false : true;
        radGridHour->setChecked(gGridHourBold);
    }
    if (sVari == "gGridFontFami")
    {
        QString sGrid = sValu.left(5);
        if (sGrid != "Arial" && sGrid != "Lucid" && sGrid != "Trebu") sGrid = "Trebu";
        if (sGrid == "Trebu") radFam1->setChecked(true);
        if (sGrid == "Arial") radFam2->setChecked(true);
        if (sGrid == "Lucid") radFam3->setChecked(true);

    }
    if (sVari == "gGridFontSize")
    {
        int iGrid = sValu.toInt(&ok, 10);
        if (iGrid != 9 && iGrid != 11 && iGrid != 12) iGrid = 9;
        if (iGrid == 9) radSiz1->setChecked(true);
        if (iGrid == 11) radSiz2->setChecked(true);


        if (iGrid == 12) radSiz3->setChecked(true);
    }
    if (sVari == "gOutlColo")
    {
        QString sOutl = sValu;
        if (sOutl.length() != 7 || !sOutl.startsWith("#")) sOutl = "#eeeeee";
        gOutlColo = QColor(sOutl);
    }
    if (sVari == "gOutlThik")
    {
        int iThik = sValu.toInt(&ok, 10);
        if (iThik < 0 && iThik > 2) iThik = 0;
        if (iThik == 0) radNone->setChecked(true);
        if (iThik == 1) radThin->setChecked(true);
        if (iThik == 2) radBold->setChecked(true);
        gOutlThik = iThik;
    }
    if (sVari == "gGridEmpt")
    {
        QString sEmpt = sValu;
        if (sEmpt.length() != 7 || !sEmpt.startsWith("#")) sEmpt = "#aaaaaa";
        gGridEmpt = QColor(sEmpt);
    }
    if (sVari == "gSecoText")
    {
        gSecoText = sValu == "true" ? true : false;
        if (gSecoText) chkSecoText->setChecked(true);
    }
    if (sVari == "gSecoItal")
    {
        gSecoItal = sValu == "true" ? true : false;
        if (gSecoItal) chkSecoItal->setChecked(true);
    }
    if (sVari == "gFileEnco")
    {
        gFileEnco = sValu == "false" ? false : true;
        if (gFileEnco) radAnsi->setChecked(true);
        else radUtf8->setChecked(true);
    }
    if (sVari == "xHoriAlig")
    {
        QString sH = sValu;
        if (sH != "l" && sH != "c" && sH != "r") sH = "c";
        if (sH == "l") radLeft->setChecked(true);
        if (sH == "c") radCenH->setChecked(true);
        if (sH == "r") radRigh->setChecked(true);
    }
    if (sVari == "xVertAlig")
    {
        QString sV = sValu;
        if (sV != "t" && sV != "c" && sV != "b") sV = "t";
        if (sV == "t") radTopy->setChecked(true);
        if (sV == "c") radCenV->setChecked(true);
        if (sV == "b") radBott->setChecked(true);
    }
}

void winMain::fConfWrit()
{
    QString sConf = "";
    int iSize = gFile.size();
    QString sText = "";

    if (radExitSavN->isChecked()) return;
    if (radExitSavP->isChecked()) sConf = gConf;
    if (radExitSavF->isChecked()) sConf = gFile.mid(0, iSize - 4) + QString(".cfg");

    oConf.setFileName(sConf);
    if (!oConf.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    sText = sText + "gScre = " + (gScre ? "true" : "false") + "\n";
    sText = sText + QString("gLang = %1\n").arg(gLang);
    sText = sText + QString("gWindBack = %1\n").arg(gWindBack);
    sText = sText + QString("gRowsNumb = %1\n").arg(gRowsNumb);
    sText = sText + QString("gRowsSpac = %1\n").arg(gRowsSpac);
    sText = sText + QString("gRowsHeig = %1\n").arg(sliRowsHeig->value());          // gpg 120220
    sText = sText + QString("xRowsHeigMin = %1\n").arg(sliRowsHeig->minimum());     // gpg 120220
    sText = sText + QString("xRowsHeigMax = %1\n").arg(sliRowsHeig->maximum());     // gpg 120220
    sText = sText + QString("gRowsWidt = %1\n").arg(gRowsWidt);
    sText = sText + QString("xRowsWidtMin = %1\n").arg(sliRowsWidt->minimum());     // gpg 120220
    sText = sText + QString("xRowsWidtMax = %1\n").arg(sliRowsWidt->maximum());     // gpg 120220
    sText = sText + QString("xRowsFontName = %1\n").arg(gRowsFont.family());
    sText = sText + QString("xRowsFontSize = %1\n").arg(gRowsFont.pointSize());
    sText = sText + QString("xRowsFontWeig = %1\n").arg(gRowsFont.weight());
    sText = sText + "xRowsFontItal = " + (gRowsFont.italic() ? "true" : "false") + "\n";
    sText = sText + QString("gRowsLefx = %1\n").arg(gRowsLefx);
    sText = sText + QString("gRowsTopy = %1\n").arg(gRowsTopy);
    sText = sText + QString("gRowsBack = %1\n").arg(gRowsBack);
    sText = sText + QString("gRowsColo = %1\n").arg(gRowsColo);
    sText = sText + "gGridHourBold = " + (gGridHourBold ? "true" : "false") + "\n";
    sText = sText + QString("gGridFontFami = %1\n").arg(gGridFontFami);
    sText = sText + QString("gGridFontSize = %1\n").arg(gGridFontSize);
    sText = sText + QString("gOutlColo = %1\n").arg(gOutlColo.name());
    sText = sText + QString("gOutlThik = %1\n").arg(gOutlThik);
    sText = sText + QString("gGridEmpt = %1\n").arg(gGridEmpt.name());
    sText = sText + "gSecoText = " + (gSecoText ? "true" : "false") + "\n";
    sText = sText + "gSecoItal = " + (gSecoItal ? "true" : "false") + "\n";
    sText = sText + "gFileEnco = " + (gFileEnco ? "true" : "false") + "\n";

    if (radLeft->isChecked()) sText = sText + "xHoriAlig = l\n";                    // gpg 120220
    if (radCenH->isChecked()) sText = sText + "xHoriAlig = c\n";                    // gpg 120220
    if (radRigh->isChecked()) sText = sText + "xHoriAlig = r\n";                    // gpg 120220

    if (radTopy->isChecked()) sText = sText + "xVertAlig = t\n";                    // gpg 120220
    if (radCenV->isChecked()) sText = sText + "xVertAlig = c\n";                    // gpg 120220
    if (radBott->isChecked()) sText = sText + "xVertAlig = b\n";                    // gpg 120220

    oConf.write(sText.toAscii());
    oConf.close();
}

void winMain::fT()
{
    QPoint p = QCursor::pos();
    int iX = p.x();
    int iY = p.y();

    QLabel *labText = new QLabel(winWind);
    labText->setText("yep");
    labText->move(iX, iY);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// manual
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void winMain::fManuInit()
{
    gManu = true;
    gShow = true;
    gShowButt = true;
    gRows = griText->currentRow();                      // gpb 120406
    fMenuAdapt(1);
    fGridGeom();
}

void winMain::fButtPrev()                               // gpb 120406
{
    if (gShow)
    {
        if (griText->currentRow() > 0)
        {
            if (!gShowButt)
            {
                gRows = griText->currentRow()-1;
                griText->setCurrentCell(gRows, 1);
                griText->scrollTo(griText->currentIndex(), QAbstractItemView::PositionAtCenter);
            }
            else
            {
                fGridRows(gRows);
            }
            fGridFocus();
            if (gAuto) fAutoTimeInit();
        }
    }
    else
    {
        fRowsClear();
    }
    gShow = !gShow;
    gShowButt = false;
}

void winMain::fButtNext()                               // gpb 120406
{
    if (gShow)
    {
        if (griText->currentRow() < gRowsMaxi)
        {
            if (gShowButt)
            {
                gRows = griText->currentRow()+1;
                griText->setCurrentCell(gRows, 1);
                griText->scrollTo(griText->currentIndex(), QAbstractItemView::PositionAtCenter);
            }
            else
            {

                fGridRows(gRows);
            }
            fGridFocus();
            if (gAuto) fAutoTimeInit();
        }
    }
    else
    {
        fRowsClear();
    }
    gShow = !gShow;
    gShowButt = true;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// automatic
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void winMain::fAutoInit()
{
    gAuto = true;
    gShow = true;
    gShowButt = true;
    gRows = griText->currentRow();                      // gpb 120406
    gPlay = false;
    gInit = false;
    gRows = 0;
    gAcce = 0;
    gJump = 0;                                          // gpb 110930
    fMenuAdapt(2);
    fGridGeom();
}

void winMain::fAutoPaus()
{
    fGridEditEnab();
    butProjPlay->setIcon(gIconPlay);
    tmrAuto->stop();
}

void winMain::fAutoStar()
{
    gPlay = !gPlay;

    if (!gPlay) {fAutoPaus(); return;}


    fFileInfoClos();
    fGridEditDisa();

    butProjPlay->setIcon(gIconPaus);

    fRowsShow(true);

    if (!gInit)
    {
        fAutoStarInit();

        tmrAuto = new QTimer(this);
        connect(tmrAuto, SIGNAL(timeout()), this, SLOT(fAutoClok()));
        tmrAuto->start(gPuls);

        gInit = true;
    }
    else
    {
        tmrAuto->start();
    }
}

void winMain::fAutoStarInit()
{
    gRows = griText->currentRow();
    if (gRows == 0)                                     // gpb 120219
    {
        gRows = 1;
        griText->setCurrentCell(gRows, 1);
    }
    fAutoTimeInit();
}

void winMain::fAutoTimeInit()
{
    timAuto.setHMS(0,0,0,0);
    QString sT = griText->item(gRows, 1)->text();
    if (!sT.isEmpty()) timAuto = fAutoTimeConv(sT);
    labTime->setText(timAuto.toString("hh:mm:ss"));
}

QTime winMain::fAutoTimeConv(QString sT)
{
    int iH = sT.mid(0, 2).toInt();
    int iM = sT.mid(3, 2).toInt();
    int iS = sT.mid(6, 2).toInt();
    int iX = sT.mid(9, 3).toInt();
    QTime tR(iH, iM, iS, iX);
    return tR;
}

void winMain::fAutoClok()
{
    static int iJumpShow = 0;
    int iBeat = gPuls + gAcce;
    double dJump = (double)gJumpBase / 1000;

    timAuto = timAuto.addMSecs(iBeat + gJump);
    labTime->setText(timAuto.toString("hh:mm:ss"));

    fAutoAcceShow();

    if (gJump==0)
    {
        if (iJumpShow==0) labJump->setText("");
        else iJumpShow--;
    }
    else
    {
        if (gJump>0)
        {
            labJump->setText(QString("+%1").arg(dJump,0,'f',1));     // gpb 120408
        }
        else
        {
            labJump->setText(QString("-%1").arg(dJump,0,'f',1));    // gpb 120408
            fAutoJumpBack();
        }
        iJumpShow=20;
    }
    gJump=0;

    fAutoGridShow();
}
void winMain::fAutoAcceShow()                           // gpb 120407
{
    int iBeat = gPuls + gAcce;
    double dBeat = (double)iBeat / (double)gPuls;

    if (dBeat==1) labPuls->setText("");
    else labPuls->setText(QString("%1").arg(dBeat,0,'f',2));
}

void winMain::fAutoJumpBack()                           // gpb 120219
{
    int iPrev=gRows-1;

    if (iPrev<1) return;

    timStar = fAutoTimeConv(griText->item(iPrev, 1)->text());
    timStop = fAutoTimeConv(griText->item(iPrev, 2)->text());
    if (timAuto >= timStar  && timAuto < timStop) gRows=iPrev;
}

void winMain::fAutoGridShow()
{
    if (gRows > gRowsMaxi)
    {
        fRowsClear();
        gPlay = false;
        fAutoPaus();
        return;
    }
    timStop = fAutoTimeConv(griText->item(gRows, 2)->text());
    if (timAuto > timStop)
    {
        fRowsClear();
        gRows++;
        return;
    }
    timStar = fAutoTimeConv(griText->item(gRows, 1)->text());
    if (timAuto >= timStar)
    {
        griText->setCurrentCell(gRows, 1);
        griText->scrollTo(griText->currentIndex(), QAbstractItemView::PositionAtCenter);
    }
}

void winMain::fAutoAcce()                               // max will be a 9x speed -> gPuls(100) + 800 = 900 (9 times basic pulse)
{
    if (gAcce < 800) gAcce += 1;                        // gpb 120220
    fAutoAcceShow();                                    // gpb 120220
}

void winMain::fAutoDece()                               // min will be a half speed -> gPuls(100) - 50 = 50 (1/2 time basic pulse)
{
    if (gAcce > -50) gAcce -= 1;                        // gpb 120220
    fAutoAcceShow();                                    // gpb 120220
}

void winMain::fJumpBase(int iJ)                         // gpb 120408
{
    gJumpBase = iJ * 100;
}

void winMain::fAutoJump()
{
    if (gPlay) gJump = gJumpBase;                       // gpb 120408
}

void winMain::fAutoBack()
{
    if (gPlay) gJump = -1 * gJumpBase;                  // gpb 120408
}
