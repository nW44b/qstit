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

#include "QSTit_winMain.h"
#include "QSTit_diaGrid.h"
#include "QSTit_diaButt.h"
#include "QSTit_diaSkin.h"

winMain::winMain()
{
    gVers="2.3";
    gLang=0;            // 0=english,1=other (from QSTit_Lang.txt)
    gWork=false;
    gManu=false;
    gAuto=false;
    gSrtx=false;        // true=srt,false=txt
    gPuls=100;          // basic timeout interval in mls (100/1000=0.1 sec)
    gAcce=0;            // accelerator in mls
    gJump=0;            // jump step
    gJumpBase=500;      // jump base
    gFileEnco=true;
    gHelpDial=false;    // on screen or not
    gExitDial=false;
    gFileDial=false;
    gFontDial=false;
    gColoDial=false;
    gBackDial=false;
    gOutlDial=false;
    gGridDial=false;
    gFileInfo=false;

    gWindWidt=QApplication::desktop()->width();
    gWindHeig=QApplication::desktop()->height();

    gRowsNumb=4;
    gRowsMaxi=0;

    gRowsBack="#000000";
    gRowsColo="#ffffff";
    gOutlColo=QColor("#eeeeee");
    gGridBack="#222222";
    gGridColo="#ffffff";
    gErroBack="#ff0000";
    gErroColo="#ffffff";

    gSystFontFami=qApp->font().family();
    gRowsFont=QFont(qApp->font().family(),22,QFont::Normal,false);
    gGridFont=QFont(qApp->font().family(),9,QFont::Normal,false);

    gGriCStyl="background-color:#222222;color:#ffffff;selection-background-color:#0055aa;selection-color:#000000;border:none;";
    gExplDisa="color:#555555;border:none;";
    gClokStyl="font:normal 11px "+gSystFontFami+";background-color:#000000;color:#ffffff;border:1px solid #000000;border-radius:3px;";
    gTimeStyl="font:normal 11px "+gSystFontFami+";background-color:#000000;color:#ffffff;border:1px solid #000000;border-radius:3px;";
    gPulsStyl="font:normal 10px "+gSystFontFami+";background-color:#000000;color:#ffffff;border:1px solid #000000;border-radius:3px;height:20px;width:20px;";
    gExplStyl="font:normal 9px "+gSystFontFami+";color:#555555;border:none;";
    gSpinStyl="height:24px;color:#ffffff;border:1px solid #777777;background-color:#eeeeee;color:#000000;";
    fWindStyle();

    gSecoText=false;
    gSecoItal=false;
    gGridEdit=true;
    gGridSave=false;
    gGridColoDark=true;
    gOutlThik=0;

    this->setGeometry(0,0,gWindWidt,gWindHeig);
    this->setWindowFlags(Qt::FramelessWindowHint);

    gExitDial=false;
    gSettShow=false;
    gGridShow=false;

    fLangFileRead();
    fWindCrea();
    fMenuCrea();
    fRowsCrea();
    fSettCrea();
    fGridCrea();
    fWindLogo();
    fRowsInit();
    fRowsShow(1);

    gConf="./QSTit.cfg";
    fConfRead();

    fraMenu->setFocus();
}

//=================================================================================================
// main window functions
//=================================================================================================

void winMain::fWindCrea()
{
    winWind=new QWidget(this,Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::X11BypassWindowManagerHint);
    winWind->showFullScreen();
    this->setFixedSize(gWindWidt,gWindHeig);
    winWind->setGeometry(0,0,gWindWidt,gWindHeig);
    winWind->setContentsMargins(0,0,0,0);
    winWind->setCursor(QCursor(QPixmap(":/Imag/QSTit_curV.png"),-1,-1));
}
void winMain::fWindStyle()
{
    QString sStyl="* {background-color:#000000;color:#ffffff;border:none;}";
    sStyl+="QLabel {font:normal 11px "+gSystFontFami+";background-color:#151515;border:none;}";
    sStyl+="QSlider::groove:vertical {background-color:#0055aa;border:1px solid #222222;border-radius:6px;}";
    sStyl+="QSlider::sub-page:vertical {background-color:#222222;border:1px solid #222222;border-radius:6px;}";
    sStyl+="QSlider::handle:vertical {image:url(:/Imag/QSTit_butY.png);border:none;}";
    sStyl+="QRadioButton {border:none;min-height:16px;max-height:16px;min-width:64px;}";
    sStyl+="QRadioButton::indicator:checked {image:url(:/Imag/QSTit_butY.png);}";
    sStyl+="QRadioButton::indicator:unchecked {image:url(:/Imag/QSTit_butN.png);}";
    sStyl+="QMessageBox {background-color:#151515;color:#ffffff;border:1px solid #0055aa;border-radius:3px;}";
    sStyl+="QPushButton {min-height:20px;max-height:20px;min-width:70px;max-width:90px;background-color:#202020;color:#ffffff;border:1px solid #555555;border-radius:3px;text-align:left;padding-left:2px;}";
    sStyl+="QPushButton:hover {border-color:#0055aa;}";
    sStyl+="QTabWidget {background-color:#151515;color:#ffffff;border:none;}";
    sStyl+="QTabWidget::pane {background-color:#151515;color:#ffffff;border:none;margin:0 0 0 0;}";
    sStyl+="QTabWidget::tab-bar {background-color:#151515;color:#ffffff;}";
    sStyl+="QTabWidget::tab {border:1px solid #ffffff;border-bottom-color:#151515;margin:5px;width:70px;height:20px;}";
    sStyl+="QTabBar::tab:selected {background-color:#0055aa;color:#000000;width:70px;height:20px;margin-bottom:1px;margin-right:6px;border:1px solid #555555;border-radius:3px;}";
    sStyl+="QTabBar::tab:!selected {background-color:#151515;color:#ffffff;width:70px;height:20px;margin-bottom:1px;margin-right:6px;border:1px solid #555555;border-radius:3px;}";
    sStyl+="QTabBar::tab:hover {border-color:#0055aa;}";
    sStyl+="QTableCornerButton::section {background:"+gGridBack+";color:"+gGridBack+";border:none;border-bottom:1px solid #777777;}";
    sStyl+="QHeaderView::section:horizontal {background-color:"+gGridBack+";color:"+gGridBack+";border:none;}";
    sStyl+="QHeaderView::section:vertical {font:normal 11px "+gSystFontFami+";background:"+gGridBack+";color:"+gGridColo+";border:1px solid #777777;border-top:0px solid "+gGridBack+";}";
    sStyl+="QToolTip {font:normal 11px "+gSystFontFami+";background-color:#32cd32;color:#000000;border-style:outset;border:1px solid #32cd32;padding:0px;}";
    sStyl+="QScrollBar:vertical {width:10px;background-color:#aaaaaa;margin:10 0 10 0;}";
    sStyl+="QScrollBar::handle:vertical {background-color:#777777;min-height:30px;border-radius:4px;}";
    sStyl+="QScrollBar::handle:hover {background-color:#0055aa;}";
    sStyl+="QScrollBar::add-line:vertical {background-image:url(:/Imag/QSTit_scro_down.png); height:12px; subcontrol-position:bottom;subcontrol-origin:margin;}";
    sStyl+="QScrollBar::sub-line:vertical {background-image:url(:/Imag/QSTit_scro_upup.png);height:12px;subcontrol-position:top;subcontrol-origin:margin;}";
    sStyl+="QScrollBar::add-page:vertical {background:none;}";
    sStyl+="QScrollBar::sub-page:vertical {background:none;}";
    sStyl+="QScrollBar:horizontal {height:10px;background-color:#aaaaaa;margin:0 10px 0 10px;}";
    sStyl+="QScrollBar::handle:horizontal {background-color:#777777;min-width:30px;border-radius:4px;}";
    sStyl+="QScrollBar::handle:hover {background-color:#0055aa;}";
    sStyl+="QScrollBar::add-line:horizontal {background-image: url(:/Imag/QSTit_scro_righ.png); width:12px; subcontrol-position:right;subcontrol-origin:margin;}";
    sStyl+="QScrollBar::sub-line:horizontal {background-image: url(:/Imag/QSTit_scro_left.png);width:12px;subcontrol-position:left;subcontrol-origin:margin;}";
    sStyl+="QScrollBar::add-page:horizontal {background:none;}";
    sStyl+="QScrollBar::sub-page:horizontal {background:none;}";
    qApp->setStyleSheet(sStyl);
}
void winMain::fWindBack()
{
    if (radWindBacB->isChecked()) winWind->setStyleSheet("background-color:#000000;color:#ffffff;border:none;");
    if (radWindBacG->isChecked()) winWind->setStyleSheet("background-color:#333333;color:#ffffff;border:none;");
}
void winMain::fWindClear() {radWindBacB->setChecked(true);fWindBack();}
void winMain::fWindTask()
{
    gWindHeig=QApplication::desktop()->height();
    if(radTaskShow->isChecked()) {gWindHeig=QApplication::desktop()->availableGeometry().height();}
    this->setFixedSize(gWindWidt,gWindHeig);
    winWind->setGeometry(0,0,gWindWidt,gWindHeig);
    gMenuTopy=gWindHeig-gMenuHeig-1;
    fraMenu->move(gMenuLefx,gMenuTopy);
    diaSett->fRePosi();
    if (gGridShow) diaGrid->fRePosi();
}
void winMain::fWindExitDial()
{
    if (gExitDial) {fWindExitCanc();return;}
    gExitDial=true;

    fGridModi();

    int iWidt=300;
    int iHeig=150;

    QString sStyl="color:#ffffff;border:none;";
    QString sStyD="color:#555555;border:none;";

    diaExit=new diaSkin(winWind,fraMenu,fL("diaExit"),iWidt,iHeig,-1,-1);
    connect(diaExit,SIGNAL(sClosed()),this,SLOT(fWindExitClos()));

    radExitSavN=new QRadioButton(fL("radExitSavN"),diaExit);
    radExitSavN->move(10,40);
    radExitSavN->setChecked(true);
    radExitSavN->setStyleSheet(sStyl);

    radExitSavP=new QRadioButton(fL("radExitSavP"),diaExit);
    radExitSavP->move(10,60);
    radExitSavP->setStyleSheet(sStyl);

    radExitSavF=new QRadioButton(fL("radExitSavF"),diaExit);
    radExitSavF->move(10,80);
    if (gFile.size()>4) {radExitSavF->setStyleSheet(sStyl);}
    else {radExitSavF->setStyleSheet(sStyD);radExitSavF->setEnabled(false);}

    butExitSave=new butToolC(diaExit,QPixmap(":/Imag/QSTit_exit.png"),"L"+fL("butExitSave"),false);
    butExitSave->move((iWidt-32)/2,105);
    connect(butExitSave,SIGNAL(clicked()),this,SLOT(fWindExit()));

    diaExit->show();
    diaExit->setFocus();
}
void winMain::fWindExitClos() {gExitDial=false;}
void winMain::fWindExitCanc() {diaExit->close();gExitDial=false;}
void winMain::fWindExit() {fFileLogx();fConfWrit();QApplication::quit();}
void winMain::fWindLogo()
{
    QPixmap oLogo=QPixmap(":/Imag/QSTit_logo.png");
    int iWidt=oLogo.width();
    int iHeig=oLogo.height();
    int iLefx=(gWindWidt-iWidt)/2;
    int iTopy=(gWindHeig-iHeig)/2;

    labLogo=new QLabel(winWind);
    labLogo->setStyleSheet("background-color:#000000;");
    labLogo->setPixmap(oLogo);
    labLogo->setGeometry(iLefx,iTopy,iWidt,iHeig);
}
void winMain::fWindLogoHide() {labLogo->setHidden(true);}
void winMain::fWindLogoFade() {if (faderWidget) faderWidget->close();faderWidget=new FaderWidget(labLogo);faderWidget->start();}

//=================================================================================================
// menu functions
//=================================================================================================

void winMain::fMenuCrea()
{
    gMenuWidt=226;
    gMenuHeig=40;

    gMenuLefx=(gWindWidt-gMenuWidt)/2;
    gMenuTopy=gWindHeig-gMenuHeig-1;

    fraMenu=new menuSkin(winWind,226,40,-1,-1);
    connect(fraMenu,SIGNAL(sMoved()),this,SLOT(fRowsStat()));

    butExit=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_exit.png"),"L"+fL("butExit"),false);
    butExit->move(gMenuWidt-40,3);
    connect(butExit,SIGNAL(clicked()),this,SLOT(fWindExitDial()));

    butHelp=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_help_enab.png"),"M"+fL("butHelp"),false);
    butHelp->move(gMenuWidt-77,6);
    connect(butHelp,SIGNAL(clicked()),this,SLOT(fHelpDial()));

    butFile=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_file.png"),"L"+fL("butFile"),false);
    butFile->move(gMenuWidt-120,3);
    connect(butFile,SIGNAL(clicked()),this,SLOT(fFileDial()));

    butSett=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_sett.png"),"L"+fL("butSett"),false);
    butSett->move(gMenuWidt-160,3);
    connect(butSett,SIGNAL(clicked()),this,SLOT(fSettShow()));

    labClok=new QLabel("00:00:00",fraMenu);
    labClok->setToolTip(fL("labClok"));
    labClok->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labClok->setStyleSheet(gClokStyl);
    labClok->setGeometry(gMenuWidt-220,7,54,20);
    tmrClok=new QTimer(this);
    connect(tmrClok,SIGNAL(timeout()),this,SLOT(fMenuClok()));
    tmrClok->start(1000);

    butRoll=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_roll_open.png"),"L"+fL("butRoll"),false);
    butRoll->move(10,3);
    connect(butRoll,SIGNAL(clicked()),this,SLOT(fRowsShowSlot()));
    butRoll->hide();

    labTime=new QLabel("00:00:00",fraMenu);
    labTime->setToolTip(fL("labTime"));
    labTime->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labTime->setStyleSheet(gTimeStyl);
    labTime->setGeometry(70,7,70,20);
    labTime->hide();

    butProjUpup=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_upup.png"),"L"+fL("butProjUpup"),true);
    butProjUpup->move(200,3);
    connect(butProjUpup,SIGNAL(clicked()),this,SLOT(fButtPrev()));
    butProjUpup->hide();

    butProjDown=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_down.png"),"L"+fL("butProjDown"),true);
    butProjDown->move(250,3);
    connect(butProjDown,SIGNAL(clicked()),this,SLOT(fButtNext()));
    butProjDown->hide();

    butProjPlay=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_play.png"),"R"+fL("butProjPlay"),false);
    butProjPlay->move(300,3);
    connect(butProjPlay,SIGNAL(clicked()),this,SLOT(fAutoStar()));
    butProjPlay->hide();

    butProjDece=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_dece.png"),"L"+fL("butProjDece"),true);
    butProjDece->move(380,3);
    connect(butProjDece,SIGNAL(clicked()),this,SLOT(fAutoDece()));
    butProjDece->hide();

    texPuls=new QLabel("Speed",fraMenu);
    texPuls->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    texPuls->setContentsMargins(0,0,0,0);
    texPuls->setStyleSheet(gExplStyl);
    texPuls->setGeometry(416,1,26,15);
    texPuls->hide();

    labPuls=new QLabel("",fraMenu);
    labPuls->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labPuls->setStyleSheet(gPulsStyl);
    labPuls->setGeometry(416,16,26,20);
    labPuls->hide();

    butProjAcce=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_acce.png"),"L"+fL("butProjAcce"),true);
    butProjAcce->move(441,3);
    connect(butProjAcce,SIGNAL(clicked()),this,SLOT(fAutoAcce()));
    butProjAcce->hide();

    butProjBack=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_jump_back.png"),"L"+fL("butProjBack"),false);
    butProjBack->move(491,3);
    connect(butProjBack,SIGNAL(clicked()),this,SLOT(fAutoBack()));
    butProjBack->hide();

    texJump=new QLabel("Jump",fraMenu);
    texJump->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    texJump->setContentsMargins(0,0,0,0);
    texJump->setStyleSheet(gExplStyl);
    texJump->setGeometry(528,1,26,15);
    texJump->hide();

    labJump=new QLabel("",fraMenu);
    labJump->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labJump->setStyleSheet(gPulsStyl);
    labJump->setGeometry(528,16,26,20);
    labJump->hide();

    butProjJump=new butToolC(fraMenu,QPixmap(":/Imag/QSTit_jump.png"),"L"+fL("butProjJump"),false);
    butProjJump->move(552,3);
    connect(butProjJump,SIGNAL(clicked()),this,SLOT(fAutoJump()));
    butProjJump->hide();
}
void winMain::fMenuAdapt(int m)                         // 0=init,1=manu,2=auto
{
    gMenuHeig=40;
    if (m==0) gMenuWidt=226;
    else if (m==1) gMenuWidt=364;
    else if (m==2) gMenuWidt=717;
    gMenuLefx=(gWindWidt-gMenuWidt)/2;
    gMenuTopy=fraMenu->frameGeometry().y();
    fraMenu->iW=gMenuWidt;
    fraMenu->resize(gMenuWidt,gMenuHeig);
    fraMenu->move(gMenuLefx,gMenuTopy);

    int iP=gMenuWidt;
    iP-=40;butExit->move(iP,3);
    iP-=37;butHelp->move(iP,6);
    iP-=43;butFile->move(iP,3);
    iP-=40;butSett->move(iP,3);
    iP-=60;labClok->setGeometry(iP,7,54,20);
    if (m==0)
    {
        butRoll->hide();
        labTime->hide();
        butProjUpup->hide();
        butProjDown->hide();
        butProjPlay->hide();
        butProjDece->hide();
        texPuls->hide();
        labPuls->hide();
        butProjAcce->hide();
        butProjBack->hide();
        texJump->hide();
        labJump->hide();
        butProjJump->hide();
    }
    else if (m==1)
    {
        iP=0;
        iP+=5;butRoll->move(iP,3);butRoll->show();
        labTime->hide();
        iP+=55;butProjUpup->move(iP,3);butProjUpup->show();
        iP+=40;butProjDown->move(iP,3);butProjDown->show();
        butProjPlay->hide();
        butProjDece->hide();
        texPuls->hide();
        labPuls->hide();
        butProjAcce->hide();
        butProjBack->hide();
        texJump->hide();
        labJump->hide();
        butProjJump->hide();
    }
    else if (m==2)
    {
        iP=0;
        iP+=5;butRoll->move(iP,3);butRoll->show();
        labTime->hide();
        iP+=55;butProjUpup->move(iP,3);butProjUpup->show();
        iP+=40;butProjDown->move(iP,3);butProjDown->show();
        iP+=42;labTime->setGeometry(iP,7,54,20);labTime->show();
        iP+=64;butProjPlay->move(iP,3);butProjPlay->show();
        iP+=80;butProjDece->move(iP,3);butProjDece->show();
        iP+=34;texPuls->setGeometry(iP, 1,26,15);texPuls->show();
               labPuls->setGeometry(iP,16,26,20);labPuls->show();
        iP+=25;butProjAcce->move(iP,3);butProjAcce->show();
        iP+=50;butProjBack->move(iP,3);butProjBack->show();
        iP+=34;texJump->setGeometry(iP, 1,26,15);texJump->show();
               labJump->setGeometry(iP,16,26,20);labJump->show();
        iP+=25;butProjJump->move(iP,3);butProjJump->show();
    }
    fRowsStat();
}
void winMain::fMenuClok()
{
    static int iP=0;
    labClok->setText(QTime::currentTime().toString("hh:mm:ss"));
    iP++;
    if (iP==1) fWindLogoFade();
    if (iP==3) fWindLogoHide();
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
    labJump->hide();
    butProjJump->hide();
    fMenuAdapt(0);
}

//=================================================================================================
// rows functions
//=================================================================================================

void winMain::fRowsCrea()
{
    gRowsHone=30;
    gRowsSpac=1;
    gRowsWbas=gWindWidt-2;
    int gRowsHbas=(gRowsHone*gRowsNumb)+(gRowsSpac*(gRowsNumb-1));

    gRowsFont.setFamily(qApp->font().family());
    gRowsFont.setPointSize(22);
    gRowsFont.setWeight(50);
    gRowsFont.setItalic(false);
    gRowsBack="#000000";
    gRowsColo="#ffffff";

    objRow0.text="";
    objRow0.show=true;
    objRow0.font.setFamily(qApp->font().family());
    objRow0.font.setPointSize(22);
    objRow0.font.setWeight(50);
    objRow0.font.setItalic(false);
    objRow0.colB=QColor("#000000");
    objRow0.colF=QColor("#ffffff");
    objRow0.widt=gWindWidt-2;
    objRow0.heig=30;
    objRow0.spac=1;
    objRow0.rota=0;
    objRow0.savH=30;
    objRow0.savS=1;

    fRowsBase(1,0);
    fRowsBase(2,31);
    fRowsBase(3,62);
    fRowsBase(4,93);

    fraRows=new rowSkin(winWind,gRowsWbas,gRowsHbas);
    fraRows->stackUnder(fraMenu);
    connect(fraRows,SIGNAL(sMoved()),this,SLOT(fRowsStat()));

    texRow1=new QLabel(fraRows);
    texRow1->setGeometry(0,0,objRow1.widt,objRow1.heig);
    texRow1->move(objRow1.x,objRow1.y);

    texRow2=new QLabel(fraRows);
    texRow2->setGeometry(0,0,objRow2.widt,objRow2.heig);
    texRow2->move(objRow2.x,objRow2.y);

    texRow3=new QLabel(fraRows);
    texRow3->setGeometry(0,0,objRow3.widt,objRow3.heig);
    texRow3->move(objRow3.x,objRow3.y);

    texRow4=new QLabel(fraRows);
    texRow4->setGeometry(0,0,objRow4.widt,objRow4.heig);
    texRow4->move(objRow4.x,objRow4.y);

    gRowsHcenPrev=0;
    gRowsVcenPrev=0;

    butRowsCent=new QToolButton(fraRows);
    butRowsCent->setIcon(QPixmap(":/Imag/QSTit_cent.png"));
    butRowsCent->setStyleSheet("border:none;");
    butRowsCent->setContentsMargins(0,0,0,0);
    butRowsCent->setIconSize(QSize(16,16));
    butRowsCent->setAutoRepeat(false);
    butRowsCent->setGeometry(gRowsHcen-7,gRowsVcen-7,16,16);
    butRowsCent->hide();
}
void winMain::fRowsBase(int iR,int iY)
{
    objRows *objRowx=&objRow1;
    if (iR==2) objRowx=&objRow2;
    if (iR==3) objRowx=&objRow3;
    if (iR==4) objRowx=&objRow4;
    objRowx->text=objRow0.text;
    objRowx->show=objRow0.show;
    objRowx->font=objRow0.font;
    objRowx->colB=objRow0.colB;
    objRowx->colF=objRow0.colF;
    objRowx->widt=objRow0.widt;
    objRowx->heig=objRow0.heig;
    objRowx->spac=0;if (iR<4) objRowx->spac=objRow0.spac;
    objRowx->rota=objRow0.rota;
    objRowx->savH=objRow0.savH;
    objRowx->savS=0;if (iR<4) objRowx->savS=objRow0.savS;
    objRowx->x=0;
    objRowx->y=iY;
}
void winMain::fRowsAdapt()
{
    texRow1->setGeometry(objRow1.x,objRow1.y,objRow1.widt,objRow1.heig);
    objRow2.y=objRow1.y+objRow1.heig+objRow1.spac;
    texRow2->setGeometry(objRow2.x,objRow2.y,objRow2.widt,objRow2.heig);
    objRow3.y=objRow2.y+objRow2.heig+objRow2.spac;
    texRow3->setGeometry(objRow3.x,objRow3.y,objRow3.widt,objRow3.heig);
    objRow4.y=objRow3.y+objRow3.heig+objRow3.spac;
    texRow4->setGeometry(objRow4.x,objRow4.y,objRow4.widt,objRow4.heig);
    fraRows->iH=objRow4.y+objRow4.heig-objRow1.x;
    gRowsHcen=fraRows->iW/2;
    gRowsVcen=fraRows->iH/2;
    fraRows->iX+=gRowsHcenPrev-gRowsHcen;if (fraRows->iX<1) fraRows->iX=1;
    fraRows->iY+=gRowsVcenPrev-gRowsVcen;if (fraRows->iY<1) fraRows->iY=1;
    gRowsHcenPrev=gRowsHcen;
    gRowsVcenPrev=gRowsVcen;
    fraRows->setGeometry(fraRows->iX,fraRows->iY,fraRows->iW,fraRows->iH);
    fRowsStat();
    fRowsTextForm();
}
void winMain::fRowsStat()
{
    spiShedHei1->blockSignals(true);spiShedHei1->setValue(objRow1.heig);spiShedHei1->blockSignals(false);
    spiShedHei2->blockSignals(true);spiShedHei2->setValue(objRow2.heig);spiShedHei2->blockSignals(false);
    spiShedHei3->blockSignals(true);spiShedHei3->setValue(objRow3.heig);spiShedHei3->blockSignals(false);
    spiShedHei4->blockSignals(true);spiShedHei4->setValue(objRow4.heig);spiShedHei4->blockSignals(false);

    spiShedSpa1->blockSignals(true);spiShedSpa1->setValue(objRow1.spac);spiShedSpa1->blockSignals(false);
    spiShedSpa2->blockSignals(true);spiShedSpa2->setValue(objRow2.spac);spiShedSpa2->blockSignals(false);
    spiShedSpa3->blockSignals(true);spiShedSpa3->setValue(objRow3.spac);spiShedSpa3->blockSignals(false);

    spiShedRot1->blockSignals(true);spiShedRot1->setValue(objRow1.rota);spiShedRot1->blockSignals(false);
    spiShedRot2->blockSignals(true);spiShedRot2->setValue(objRow2.rota);spiShedRot2->blockSignals(false);
    spiShedRot3->blockSignals(true);spiShedRot3->setValue(objRow3.rota);spiShedRot3->blockSignals(false);
    spiShedRot4->blockSignals(true);spiShedRot4->setValue(objRow4.rota);spiShedRot4->blockSignals(false);

    labRowsLoca->setText(QString("Rows location = %1,%2").arg(fraRows->iX).arg(fraRows->iY));
    labRowsSize->setText(QString("Rows size = %1,%2").arg(fraRows->iW).arg(fraRows->iH));
    labRowsCent->setText(QString("Rows center = %1,%2").arg(fraRows->iX+gRowsHcen).arg(fraRows->iY+gRowsVcen));
    labMenuSize->setText(QString("Menu location = %1,%2").arg(fraMenu->frameGeometry().x()).arg(fraMenu->frameGeometry().y()));
    labMenuLoca->setText(QString("Menu size = %1,%2").arg(fraMenu->frameGeometry().width()).arg(fraMenu->frameGeometry().height()));
    labScreSize->setText(QString("Screen size = %1,%2").arg(gWindWidt).arg(gWindHeig));
    labGridCol3->setText(QString("Grid c-1 width = %1").arg(griText->columnWidth(3)));
    labGridCol4->setText(QString("Grid c-2 width = %1").arg(griText->columnWidth(4)));
    labGridCol5->setText(QString("Grid c-3 width = %1").arg(griText->columnWidth(5)));
    labGridCol6->setText(QString("Grid c-4 width = %1").arg(griText->columnWidth(6)));
}
void winMain::fRowsFramHeig() {fraRows->iH=objRow4.y+objRow4.heig-objRow1.x;fRowsFramPosi();}
void winMain::fRowsChck()
{
    radRow1->setChecked(false);
    radRow2->setChecked(false);
    radRow3->setChecked(false);
    radRow4->setChecked(false);
    if (gRowsNumb>=1) radRow1->setChecked(true);
    if (gRowsNumb>=2) radRow2->setChecked(true);
    if (gRowsNumb>=3) radRow3->setChecked(true);
    if (gRowsNumb==4) radRow4->setChecked(true);
}
void winMain::fRowsInit()
{
    butRowsCent->hide();
    if (!gSettShow && !gGridShow)
    {
        fRowsNumb();
        fRowsFramInit();
        fRowsClear();
        fRowsShow(1);
    }
    if (gSettShow && !gGridShow)
    {
        QString s1=fL("fRowsInit")+" 1 - "+fL("fRowsInit")+" 1";
        QString s2=fL("fRowsInit")+" 2 - "+fL("fRowsInit")+" 2";
        QString s3=fL("fRowsInit")+" 3 - "+fL("fRowsInit")+" 3";
        QString s4=fL("fRowsInit")+" 4 - "+fL("fRowsInit")+" 4";

        if (gSecoText) s2=fL("fRowsInit")+" 2 / "+fL("fRowsInit")+" 1";
        if (gSecoItal) s2="<i>"+s2+"</i>";

        objRow1.text=s1;
        objRow2.text=s2;
        objRow3.text=s3;
        objRow4.text=s4;

        fRowsFramInit();
        fRowsTextForm();
        fRowsShow(1);
    }
}
void winMain::fRowsFram() {fraRows->setGeometry(fraRows->iX,fraRows->iY,fraRows->iW,fraRows->iH);fRowsStat();}
void winMain::fRowsFramCent() {gRowsHcen=fraRows->iW/2;gRowsVcen=fraRows->iH/2;}
void winMain::fRowsFramInit() {fraRows->iW=gWork ? gFileMaxiLeng[0]:gWindWidt-2;fRowsFramHeig();}
void winMain::fRowsFramPosi()
{
    fRowsFramCent();
    fraRows->iX+=gRowsHcenPrev-gRowsHcen;if (fraRows->iX<1) fraRows->iX=1;
    fraRows->iY+=gRowsVcenPrev-gRowsVcen;if (fraRows->iY<1) fraRows->iY=1;
    gRowsHcenPrev=gRowsHcen;
    gRowsVcenPrev=gRowsVcen;
    butRowsCent->hide();
    fRowsFram();
}
void winMain::fRowsLocU() {if (fraRows->iY>1) {fraRows->iY--;fRowsFram();}}
void winMain::fRowsLocUFast()
{
    if (fraRows->iY>1) {fraRows->iY-=5;if (fraRows->iY<1) {fraRows->iY=1;};fRowsFram();}
}
void winMain::fRowsLocL() {if (fraRows->iX>1) {fraRows->iX--;fRowsFram();}}
void winMain::fRowsLocLFast()
{
    if (fraRows->iX>1) {fraRows->iX-=5;if (fraRows->iX<1) {fraRows->iX=1;};fRowsFram();}
}
void winMain::fRowsLocC()
{
    butRowsCent->setGeometry(gRowsHcen-8,gRowsVcen-8,16,16);
    if(butRowsCent->isHidden()) butRowsCent->show();
    else butRowsCent->hide();
}
void winMain::fRowsLocR() {if (fraRows->iX+fraRows->iW<gWindWidt-1) {fraRows->iX++;fRowsFram();}}
void winMain::fRowsLocRFast()
{
    if (fraRows->iX+fraRows->iW<gWindWidt-1)
    {
        fraRows->iX+=5;
        if (fraRows->iX+fraRows->iW>gWindWidt-1) fraRows->iX=gWindWidt-fraRows->iW-1;
        fRowsFram();
    }
}
void winMain::fRowsLocD() {if (fraRows->iY<gWindHeig-fraRows->iH-1) {fraRows->iY++;fRowsFram();}}
void winMain::fRowsLocDFast()
{
    if (fraRows->iY<gWindHeig-fraRows->iH-1)
    {
        fraRows->iY+=5;
        if (fraRows->iY>gWindHeig-fraRows->iH-1) fraRows->iY=gWindHeig-fraRows->iH-1;
        fRowsFram();
    }
}
void winMain::fRowsDimH(int pH)
{
    fraRows->iW=pH;
    objRow1.widt=pH;
    objRow2.widt=pH;
    objRow3.widt=pH;
    objRow4.widt=pH;
    fRowsAdapt();
}
void winMain::fRowsDimV(int pV)
{
    objRow1.heig=pV;objRow1.savH=pV;
    objRow2.heig=pV;objRow2.savH=pV;
    objRow3.heig=pV;objRow3.savH=pV;
    objRow4.heig=pV;objRow4.savH=pV;
    fRowsAdapt();
}
void winMain::fShedHeig(int)
{
    objRow1.heig=spiShedHei1->value();
    objRow2.heig=spiShedHei2->value();
    objRow3.heig=spiShedHei3->value();
    objRow4.heig=spiShedHei4->value();
    fRowsAdapt();
}
void winMain::fRowsSpac(int pS)
{
    if (objRow1.show) {objRow1.spac=pS;spiShedSpa1->setValue(pS);objRow1.savS=pS;}
    if (objRow2.show) {objRow2.spac=pS;spiShedSpa2->setValue(pS);objRow2.savS=pS;}
    if (objRow3.show) {objRow3.spac=pS;spiShedSpa3->setValue(pS);objRow3.savS=pS;}
    fRowsAdapt();
    gRowsSpac=pS;
}
void winMain::fShedSpac(int)
{
    objRow1.spac=spiShedSpa1->value();
    objRow2.spac=spiShedSpa2->value();
    objRow3.spac=spiShedSpa3->value();
    fRowsAdapt();
}
void winMain::fRowsRota(int pR)
{
    objRow1.rota=pR;
    objRow2.rota=pR;
    objRow3.rota=pR;
    objRow4.rota=pR;
    fRowsAdapt();
}
void winMain::fShedRota(int)
{
    objRow1.rota=spiShedRot1->value();
    objRow2.rota=spiShedRot2->value();
    objRow3.rota=spiShedRot3->value();
    objRow4.rota=spiShedRot4->value();
    fRowsAdapt();
}
void winMain::fRowsTextForm()
{
    fRowsTextDraw(1);
    fRowsTextDraw(2);
    fRowsTextDraw(3);
    fRowsTextDraw(4);
}
void winMain::fRowsTextDraw(int iR)
{
    QLabel  *lText=texRow1;
    QString sText;
    QFont   fText;
    QColor  cFore;
    QColor  cBack;
    int     iRota=0;

    switch (iR)
    {
        case 1: {lText=texRow1;sText=objRow1.text;fText=objRow1.font;cFore=objRow1.colF;cBack=objRow1.colB;iRota=objRow1.rota;break;}
        case 2: {lText=texRow2;sText=objRow2.text;fText=objRow2.font;cFore=objRow2.colF;cBack=objRow2.colB;iRota=objRow2.rota;break;}
        case 3: {lText=texRow3;sText=objRow3.text;fText=objRow3.font;cFore=objRow3.colF;cBack=objRow3.colB;iRota=objRow3.rota;break;}
        case 4: {lText=texRow4;sText=objRow4.text;fText=objRow4.font;cFore=objRow4.colF;cBack=objRow4.colB;iRota=objRow4.rota;}
    }
    QString sStyl=QString("<style>p{");
    sStyl+=QString("color:%1;").arg(cFore.name());
    sStyl+=QString("background-color:%1;").arg(cBack.name());
    sStyl+=QString("font-family:%1;").arg(fText.family());
    sStyl+=QString("font-size:%1px;").arg(fText.pointSize());
    if (fText.bold()) sStyl+=QString("font-weight:bold;");
    if (fText.italic()) sStyl+=QString("font-style:italic;");
    if (fText.underline()) sStyl+=QString("text-decoration:underline;");
    sStyl+=QString("}</style>");
    if (radLeft->isChecked()) sStyl+=QString("<p align=left>");
    if (radCenH->isChecked()) sStyl+=QString("<p align=center>");
    if (radRigh->isChecked()) sStyl+=QString("<p align=right>");

    QPixmap pixRows(lText->width(),lText->height());
    pixRows.fill(cBack);

    QPainter painter(&pixRows);

    QTextDocument doc;
    doc.setDocumentMargin(0);
    doc.setPageSize(QSizeF((qreal)lText->width(),(qreal)lText->height()));
    doc.setHtml(sStyl+sText+"</p>");
    doc.setTextWidth(lText->width());

    if (gOutlThik!=0)
    {
        QPen pen;
        pen.setStyle(Qt::SolidLine);
        pen.setColor(gOutlColo);
        pen.setWidth(gOutlThik);

        QTextCharFormat format;
        format.setTextOutline(pen);

        QTextCursor cursor(&doc);
        cursor.select(QTextCursor::Document);
        cursor.mergeCharFormat(format);
    }

    if (radTopy->isChecked()) painter.translate(0,0);
    if (radCenV->isChecked()) painter.translate(0,(lText->height()/2)-(doc.size().height()/2));
    if (radBott->isChecked()) painter.translate(0,(lText->height())-(doc.size().height()));

    if (iRota!=0)
    {
        qreal rRota=((qreal)iRota/100)*-1;
        painter.translate(lText->width()/2,lText->height()/2);
        painter.rotate(rRota);
        painter.translate(-lText->width()/2,-lText->height()/2);
    }

    QRect rect=QRect(0,0,lText->width(),lText->height());
    doc.drawContents(&painter,rect);

    lText->setPixmap(pixRows);
}
void winMain::fRowsOutlDial()
{
    if (gOutlDial) {diaColo->close();gOutlDial=false;return;}
    gOutlDial=true;
    diaColo=new diaColoSkin(winWind,fraMenu,fL("diaColoOutl"),gOutlColo.name());
    connect(diaColo,SIGNAL(sClosed()),this,SLOT(fOutlDialClos()));
    connect(diaColo,SIGNAL(sColorGet(QColor)),this,SLOT(fRowsOutlGet(QColor)));
}
void winMain::fOutlDialClos() {gOutlDial=false;}
void winMain::fRowsOutlGet(QColor cColo)
{
    gOutlColo=cColo;
    fRowsTextForm();
    gOutlDial=false;
}
void winMain::fRowsOutlSlid(int pO) {gOutlThik=pO;fRowsTextForm();}
void winMain::fRowsSeco(int iChck)
{
    gSecoText=iChck ? true:false;
    if (gWork) fGridRows(griText->currentRow());
    else fRowsInit();
}
void winMain::fRowsItal(int iChck)
{
    gSecoItal=iChck ? true:false;
    if (gWork) fGridRows(griText->currentRow());
    else fRowsInit();
}
void winMain::fRowsColo() {gShed=0;fRowsColoDial();}
void winMain::fRowsCol1() {gShed=1;fRowsColoDial();}
void winMain::fRowsCol2() {gShed=2;fRowsColoDial();}
void winMain::fRowsCol3() {gShed=3;fRowsColoDial();}
void winMain::fRowsCol4() {gShed=4;fRowsColoDial();}
void winMain::fRowsColoDial()
{
    if (gColoDial) {diaColo->close();gColoDial=false;return;}
    gColoDial=true;
    QString sC=gRowsColo;
    if (gShed==1) sC=objRow1.colF.name();
    if (gShed==2) sC=objRow2.colF.name();
    if (gShed==3) sC=objRow3.colF.name();
    if (gShed==4) sC=objRow4.colF.name();
    diaColo=new diaColoSkin(winWind,fraMenu,fL("diaTextColo"),sC);
    connect(diaColo,SIGNAL(sClosed()),this,SLOT(fColoDialClos()));
    connect(diaColo,SIGNAL(sColorGet(QColor)),this,SLOT(fRowsColoGet(QColor)));
}
void winMain::fColoDialClos() {gColoDial=false;}
void winMain::fRowsColoGet(QColor cColo)
{
    gColoDial=false;
    if (gShed==0 || gShed==1) objRow1.colF=cColo;
    if (gShed==0 || gShed==2) objRow2.colF=cColo;
    if (gShed==0 || gShed==3) objRow3.colF=cColo;
    if (gShed==0 || gShed==4) objRow4.colF=cColo;
    gRowsColo=cColo.name();
    fRowsTextForm();
    gColoDial=false;
}
void winMain::fRowsBack() {gShed=0;fRowsBackDial();}
void winMain::fRowsBac1() {gShed=1;fRowsBackDial();}
void winMain::fRowsBac2() {gShed=2;fRowsBackDial();}
void winMain::fRowsBac3() {gShed=3;fRowsBackDial();}
void winMain::fRowsBac4() {gShed=4;fRowsBackDial();}
void winMain::fRowsBackDial()
{
    if (gBackDial) {diaColo->close();gBackDial=false;return;}
    gBackDial=true;
    QString sC=gRowsBack;
    if (gShed==1) sC=objRow1.colB.name();
    if (gShed==2) sC=objRow2.colB.name();
    if (gShed==3) sC=objRow3.colB.name();
    if (gShed==4) sC=objRow4.colB.name();
    diaColo=new diaColoSkin(winWind,fraMenu,fL("diaRowsBack"),sC);
    connect(diaColo,SIGNAL(sClosed()),this,SLOT(fBackDialClos()));
    connect(diaColo,SIGNAL(sColorGet(QColor)),this,SLOT(fRowsBackGet(QColor)));
}
void winMain::fBackDialClos() {gBackDial=false;}
void winMain::fRowsBackGet(QColor cColo)
{
    gBackDial=false;
    if (gShed==0 || gShed==1) objRow1.colB=cColo;
    if (gShed==0 || gShed==2) objRow2.colB=cColo;
    if (gShed==0 || gShed==3) objRow3.colB=cColo;
    if (gShed==0 || gShed==4) objRow4.colB=cColo;
    gRowsBack=cColo.name();
    fRowsTextForm();
    gBackDial=false;
}
void winMain::fRowsClear() {objRow1.text="";objRow2.text="";objRow3.text="";objRow4.text="";fRowsTextForm();}
void winMain::fRowsTextAlig() {fRowsTextForm();}
void winMain::fRowsNumb()
{
    objRow1.show=radRow1->isChecked();
    objRow2.show=radRow2->isChecked();
    objRow3.show=radRow3->isChecked();
    objRow4.show=radRow4->isChecked();
    fRowsNumbAdap();
    if (gGridShow) fGridInit();
}
void winMain::fShedNumb()
{
    objRow1.show=radShedSho1->isChecked();
    objRow2.show=radShedSho2->isChecked();
    objRow3.show=radShedSho3->isChecked();
    objRow4.show=radShedSho4->isChecked();
    fRowsNumbAdap();
    if (gGridShow) fGridInit();
}
void winMain::fRowsNumbAdap()
{
    radShedSho1->blockSignals(true);radShedSho1->setChecked(objRow1.show);radShedSho1->blockSignals(false);
    radRow1->blockSignals(true);radRow1->setChecked(objRow1.show);radRow1->blockSignals(false);
    texRow1->setHidden(!objRow1.show);
    if (objRow1.show) {gRowsNumb=1;objRow1.heig=objRow1.savH;objRow1.spac=objRow1.savS;}
    else
    {
        if (objRow1.heig!=0) {objRow1.savH=objRow1.heig;objRow1.savS=objRow1.spac;}
        objRow1.heig=0;objRow1.spac=0;
    }
    spiShedHei1->blockSignals(true);spiShedHei1->setValue(objRow1.heig);spiShedHei1->blockSignals(false);
    spiShedSpa1->blockSignals(true);spiShedSpa1->setValue(objRow1.spac);spiShedSpa1->blockSignals(false);

    radShedSho2->blockSignals(true);radShedSho2->setChecked(objRow2.show);radShedSho2->blockSignals(false);
    radRow2->blockSignals(true);radRow2->setChecked(objRow2.show);radRow2->blockSignals(false);
    texRow2->setHidden(!objRow2.show);
    if (objRow2.show) {gRowsNumb=2;objRow2.heig=objRow2.savH;objRow2.spac=objRow2.savS;}
    else
    {
        if (objRow2.heig!=0) {objRow2.savH=objRow2.heig;objRow2.savS=objRow2.spac;}
        objRow2.heig=0;objRow2.spac=0;
    }
    spiShedHei2->blockSignals(true);spiShedHei2->setValue(objRow2.heig);spiShedHei2->blockSignals(false);
    spiShedSpa2->blockSignals(true);spiShedSpa2->setValue(objRow2.spac);spiShedSpa2->blockSignals(false);

    radShedSho3->blockSignals(true);radShedSho3->setChecked(objRow3.show);radShedSho3->blockSignals(false);
    radRow3->blockSignals(true);radRow3->setChecked(objRow3.show);radRow3->blockSignals(false);
    texRow3->setHidden(!objRow3.show);
    if (objRow3.show) {gRowsNumb=3;objRow3.heig=objRow3.savH;objRow3.spac=objRow3.savS;}
    else
    {
        if (objRow3.heig!=0) {objRow3.savH=objRow3.heig;objRow3.savS=objRow3.spac;}
        objRow3.heig=0;objRow3.spac=0;
    }
    spiShedHei3->blockSignals(true);spiShedHei3->setValue(objRow3.heig);spiShedHei3->blockSignals(false);
    spiShedSpa3->blockSignals(true);spiShedSpa3->setValue(objRow3.spac);spiShedSpa3->blockSignals(false);

    radShedSho4->blockSignals(true);radShedSho4->setChecked(objRow4.show);radShedSho4->blockSignals(false);
    radRow4->blockSignals(true);radRow4->setChecked(objRow4.show);radRow4->blockSignals(false);
    texRow4->setHidden(!objRow4.show);
    if (objRow4.show) {gRowsNumb=4;objRow4.heig=objRow4.savH;}
    else
    {
        if (objRow4.heig!=0) {objRow4.savH=objRow4.heig;}
        objRow4.heig=0;
    }
    spiShedHei4->blockSignals(true);spiShedHei4->setValue(objRow4.heig);spiShedHei4->blockSignals(false);

    fRowsAdapt();
}
void winMain::fRowsFont() {gShed=0;fRowsFontDial();}
void winMain::fRowsFon1() {gShed=1;fRowsFontDial();}
void winMain::fRowsFon2() {gShed=2;fRowsFontDial();}
void winMain::fRowsFon3() {gShed=3;fRowsFontDial();}
void winMain::fRowsFon4() {gShed=4;fRowsFontDial();}
void winMain::fRowsFontDial()
{
    if (gFontDial) {diaFont->close();gFontDial=false;return;}
    gFontDial=true;
    QFont fF=gRowsFont;
    if (gShed==1) fF=objRow1.font;
    if (gShed==2) fF=objRow2.font;
    if (gShed==3) fF=objRow3.font;
    if (gShed==4) fF=objRow4.font;
    diaFont=new diaFontSkin(winWind,fraMenu,fL("diaTextFont"),fF);
    connect(diaFont,SIGNAL(sClosed()),this,SLOT(fFontDialClos()));
    connect(diaFont,SIGNAL(sFontGet(QFont)),this,SLOT(fRowsFontGet(QFont)));
}
void winMain::fFontDialClos() {gFontDial=false;}
void winMain::fRowsFontGet(QFont pFont)
{
    if (gShed==0 || gShed==1) objRow1.font=pFont;
    if (gShed==0 || gShed==2) objRow2.font=pFont;
    if (gShed==0 || gShed==3) objRow3.font=pFont;
    if (gShed==0 || gShed==4) objRow4.font=pFont;
    gRowsFont=pFont;
    fRowsFontChan();
    gFontDial=false;
}
void winMain::fRowsFontChan()
{
    fRowsHeigCalc();
    fRowsWidtCalc();
    fRowsAdapt();
}
void winMain::fRowsHeigCalc()
{
    int iHone=gRowsFont.pointSize()+8;
    if (gShed==0 || gShed==1) objRow1.heig=iHone;
    if (gShed==0 || gShed==2) objRow2.heig=iHone;
    if (gShed==0 || gShed==3) objRow3.heig=iHone;
    if (gShed==0 || gShed==4) objRow4.heig=iHone;
    gRowsHone=iHone;
}
void winMain::fRowsWidtCalc()
{
    if (!gWork)
    {
        fraRows->iW=gWindWidt-fraRows->iX-1;
    }
    else
    {
        QFontMetrics mRows=QFontMetrics(gRowsFont);
        int iM;
        int iW;
        QString sT;

        for (iM=0; iM<9; iM++)
        {
            sT=griText->item(gFileMaxiRows[iM],gFileMaxiColo[iM])->text().trimmed();
            iW=mRows.width(sT)-(gRowsFont.pointSize()*5);
            if (gWork && iM==0 && iW>gRowsWbas)
            {
                messSkin cM;
                cM.fMess(this,fraMenu,fL("msgFontWideMess"),fL("butOkOk"),"");
            }
            gFileMaxiLeng[iM]=iW;
        }
        fraRows->iW=gFileMaxiLeng[0];
        if (fraRows->iX+fraRows->iW>=gWindWidt) fraRows->iW=gWindWidt-fraRows->iX-1;
    }
    objRow1.widt=fraRows->iW;
    objRow2.widt=fraRows->iW;
    objRow3.widt=fraRows->iW;
    objRow4.widt=fraRows->iW;
}
void winMain::fRowsShowSlot() {fRowsShow(-1);}
void winMain::fRowsShow(int pShow)
{
    static int sShow=1;

    if (pShow!=-1) sShow=pShow;
    else sShow=sShow==0 ? 1:0;
    if (sShow==1)   {fraRows->show();butRoll->setIcon(QPixmap(":/Imag/QSTit_roll_open.png"));}
    else            {fraRows->hide();butRoll->setIcon(QPixmap(":/Imag/QSTit_roll_clos.png"));}
}

//=================================================================================================
// grid functions
//=================================================================================================

void winMain::fGridCrea()
{
    gGridModi=0;
    gGridInfo=0;
    gGridRowsHeig=18;
    gGridWidt=gWindWidt-2;
    gGridHeig=36+(7*gGridRowsHeig);

    diaGrid=new diaGridSkin(winWind,fraMenu,fL("Grid"),gGridWidt,gGridHeig);
    diaGrid->fWorkLang(gLangCode,gLangText);
    connect(diaGrid,SIGNAL(sMoved()),this,SLOT(fRowsStat()));

    griText=new diaGridC(diaGrid,winWind,fraMenu);
    griText->setColumnCount(7);
    griText->setGeometry(2,31,gGridWidt-81,3+(7*gGridRowsHeig));
    griText->setSelectionBehavior(QAbstractItemView::SelectRows);
    griText->setSelectionMode(QAbstractItemView::SingleSelection);
    griText->setStyleSheet(gGriCStyl);
    connect(griText,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(fGridChan(int,int,int,int)));
    connect(griText,SIGNAL(cellClicked(int,int)),this,SLOT(fGridClic(int,int)));
    griText->fWorkLang(gLangCode,gLangText);

    butGridInfo=new butToolC(diaGrid,QPixmap(":/Imag/QSTit_info_enab.png"),"M"+fL("butGridInfo"),false);
    butGridInfo->move(gGridWidt-69,36);
    connect(butGridInfo,SIGNAL(clicked()),this,SLOT(fFileInfoDial()));

    butGridSave=new butToolC(diaGrid,QPixmap(":/Imag/QSTit_save_disa.png"),"M"+fL("butGridSave"),false);
    butGridSave->move(gGridWidt-39,36);
    connect(butGridSave,SIGNAL(clicked()),this,SLOT(fGridSave()));

    butGridEdit=new butToolC(diaGrid,QPixmap(":/Imag/QSTit_edit_enab.png"),"M"+fL("butGridEdit"),false);
    butGridEdit->move(gGridWidt-69,66);
    connect(butGridEdit,SIGNAL(clicked()),this,SLOT(fGridEditButt()));

    butGridUndo=new butToolC(diaGrid,QPixmap(":/Imag/QSTit_undo_disa.png"),"M"+fL("butGridUndo"),false);
    butGridUndo->move(gGridWidt-39,66);
    connect(butGridUndo,SIGNAL(clicked()),this,SLOT(fGridUndo()));

    butGridGoto=new butToolC(diaGrid,QPixmap(":/Imag/QSTit_goto_enab.png"),"M"+fL("butGridGoto"),false);
    butGridGoto->move(gGridWidt-69,96);
    connect(butGridGoto,SIGNAL(clicked()),this,SLOT(fGridGoto()));

    butGridFind=new butToolC(diaGrid,QPixmap(":/Imag/QSTit_find_enab.png"),"M"+fL("butGridFind"),false);
    butGridFind->move(gGridWidt-39,96);
    connect(butGridFind,SIGNAL(clicked()),this,SLOT(fGridFind()));

    butGridClea=new butToolC(diaGrid,QPixmap(":/Imag/QSTit_clea.png"),"M"+fL("butGridClea"),false);
    butGridClea->move(gGridWidt-69,126);
    connect(butGridClea,SIGNAL(clicked()),this,SLOT(fClearGrid()));

    butGridLink=new butToolC(diaGrid,QPixmap(":/Imag/QSTit_link_none.png"),"M"+fL("butLink"),false);
    butGridLink->move(gGridWidt-39,126);
    connect(butGridLink,SIGNAL(clicked()),this,SLOT(fGridLink()));
}
void winMain::fGridLink()
{
    diaGrid->fGridLink();
    if (diaGrid->bLink) butGridLink->setIcon(QPixmap(":/Imag/QSTit_link_none.png"));
    else butGridLink->setIcon(QPixmap(":/Imag/QSTit_link_done.png"));
}
void winMain::fGridColo()
{
    QString sSele="selection-background-color:#0055aa;selection-color:#000000;border:none;";

    if (!gGridColoDark) {gGridBack="#222222";gGridColo="#ffffff";gGridColoDark=true;}
    else                {gGridBack="#ffffff";gGridColo="#000000";gGridColoDark=false;}
    radGridColo->setChecked(gGridColoDark);
    gGriCStyl="background:"+gGridBack+";color:"+gGridColo+";"+sSele;
    griText->setStyleSheet(gGriCStyl);
    fWindStyle();
}
void winMain::fGridItemSetx(QString sText,int iR,int iC)
{
    QTableWidgetItem *wi=new QTableWidgetItem(sText,0);
    wi->setFont(gGridFont);
    wi->setFlags(Qt::NoItemFlags|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    griText->setItem(iR,iC,wi);
}
void winMain::fGridEditEnab()
{
    gGridEdit=true;
    butGridEdit->setIcon(QPixmap(":/Imag/QSTit_edit_enab.png"));
    butGridFind->setIcon(QPixmap(":/Imag/QSTit_find_enab.png"));
    butGridGoto->setIcon(QPixmap(":/Imag/QSTit_goto_enab.png"));
    butGridInfo->setIcon(QPixmap(":/Imag/QSTit_info_enab.png"));
    butHelp->setIcon(QPixmap(":/Imag/QSTit_help_enab.png"));
}
void winMain::fGridEditDisa()
{
    gGridEdit=false;
    butGridEdit->setIcon(QPixmap(":/Imag/QSTit_edit_disa.png"));
    butGridFind->setIcon(QPixmap(":/Imag/QSTit_find_disa.png"));
    butGridGoto->setIcon(QPixmap(":/Imag/QSTit_goto_disa.png"));
    butGridInfo->setIcon(QPixmap(":/Imag/QSTit_info_disa.png"));
    butHelp->setIcon(QPixmap(":/Imag/QSTit_help_disa.png"));
}
void winMain::fGridSaveIcon()
{
    if (diaGrid)
    {
        if (gGridModi>0)
        {
            butGridSave->setIcon(QPixmap(":/Imag/QSTit_save_enab.png"));
            butGridUndo->setIcon(QPixmap(":/Imag/QSTit_undo_enab.png"));
        }
        else
        {
            butGridSave->setIcon(QPixmap(":/Imag/QSTit_save_disa.png"));
            butGridUndo->setIcon(QPixmap(":/Imag/QSTit_undo_disa.png"));
        }
    }
}
void winMain::fGridZero()
{
    int iGrid;
    griText->setRowCount(2);
    griText->setColumnCount(7);
    if (gSrtx)
    {
        iGrid=0;
        fGridItemSetx("",iGrid,0);
        fGridItemSetx("00:00:00,000",iGrid,1);
        fGridItemSetx("00:00:00,000",iGrid,2);
        fGridItemSetx("",iGrid,3);
        fGridItemSetx("",iGrid,4);
        fGridItemSetx("",iGrid,5);
        fGridItemSetx("",iGrid,6);
        iGrid=1;
        fGridItemSetx("",iGrid,0);
        fGridItemSetx("99:99:99,999",iGrid,1);
        fGridItemSetx("99:99:99,999",iGrid,2);
        fGridItemSetx("",iGrid,3);
        fGridItemSetx("",iGrid,4);
        fGridItemSetx("",iGrid,5);
        fGridItemSetx("",iGrid,6);
    }
    else
    {
        iGrid=0;
        fGridItemSetx("",iGrid,0);
        fGridItemSetx("",iGrid,1);
        fGridItemSetx("",iGrid,2);
        fGridItemSetx("",iGrid,3);
        fGridItemSetx("",iGrid,4);
        fGridItemSetx("",iGrid,5);
        fGridItemSetx("",iGrid,6);
        iGrid=1;
        fGridItemSetx("",iGrid,0);
        fGridItemSetx("",iGrid,1);
        fGridItemSetx("",iGrid,2);
        fGridItemSetx("",iGrid,3);
        fGridItemSetx("",iGrid,4);
        fGridItemSetx("",iGrid,5);
        fGridItemSetx("",iGrid,6);
    }
}
void winMain::fGridTitle()
{
    QFileInfo fInfo=QFileInfo(gFile);
    QString sTitl=fInfo.fileName()+" | ";
    sTitl+=fL("diaGridTitlLine")+": "+QString("%1").arg(gRowsMaxi-1)+" | ";
    sTitl+=fL("diaGridTitlWidt")+": "+QString("%1").arg(gFileMaxiRows[0]);
    //if (gSrtx) sTitl+=  " | "+fL("diaGridTitlEnd")+": "+gSrtxStop.left(8);
    diaGrid->labTitl->setText(sTitl);
}
void winMain::fGridInit()
{
    for (int iR=0; iR<99; iR++)
    {
        gEditTextRows[iR]=0;
        gEditTextColu[iR]=0;
        gEditTextLine[iR]=0;
        gEditTextOldx[iR]="";
        gEditTextNewx[iR]="";
    }
    griText->horizontalHeader()->setFixedHeight(3);
    griText->verticalHeader()->setFixedWidth(31);
    fGridInitCols();
    fGridInitRows();
}
void winMain::fGridInitCols()
{
    int c;
    int cw;
    int cwTot=142;                              // 30+1 n°ligne,20+1 status,10+1 ascenseur,80+1 boutons
    int cwMax=(gWindWidt-2-cwTot)/gRowsNumb;

    for (c=0; c<7; c++) {griText->setColumnWidth(c,0);}
    griText->setColumnWidth(0,20);
    if (gSrtx)
    {
        QFontMetrics mGrid=QFontMetrics(gGridFont);
        cw=mGrid.width("99:99:99,999")+9;
        griText->setColumnWidth(1,cw);
        griText->setColumnWidth(2,cw);
        cwTot+=cw*2;
        cwMax=(gWindWidt-2-cwTot)/gRowsNumb;
    }
    for (c=3; c<7; c++)
    {
        cw=gFileMaxiColu[c-3];
        if (cw>0) cw+=9;
        if (cw>cwMax) cw=cwMax;
        cwTot+=cw;
        switch (c)
        {
            case 3: diaGrid->iWid3=cw;
            case 4: diaGrid->iWid4=cw;
            case 5: diaGrid->iWid5=cw;
            case 6: diaGrid->iWid6=cw;
        }
    }
    gGridWidt=cwTot;
    diaGrid->nColo=gRowsNumb;
    diaGrid->fGridSizeInit(cwTot);
    fRowsStat();
}
void winMain::fGridInitRows()
{
    for (int iR=0; iR<griText->rowCount(); iR++)
    {
        griText->setRowHeight(iR,gGridRowsHeig);
        griText->setVerticalHeaderItem(iR,new QTableWidgetItem(QString("%1").arg(iR)));
    }
}
void winMain::fGridShow(bool bShow)
{
    if (bShow)  {gGridShow=true;diaGrid->fRePosi();diaGrid->show();}
    else        {gGridShow=false;diaGrid->hide();}
}
QString winMain::fGridTextClean(QString sText)
{
    QString sT=sText.trimmed();
    sT.remove("<b>");sT.remove("</b>");
    sT.remove("<i>");sT.remove("</i>");
    sT.remove("<u>");sT.remove("</u>");
    return sT;
}
void winMain::fGridRows(int r)
{
    QString st1=griText->item(r,3)->text();
    QString st2="";

    if (gRowsNumb>1)
    {
        st2=griText->item(r,4)->text();
        if (gSecoText && st2.isEmpty())
        {
            st2=st1;
            st1="";
        }
        if (gSecoItal)
        {
            if (st2.indexOf("<i>")==-1) {st2="<i>"+st2+"</i>";}
            else {st2.remove("<i>");st2.remove("</i>");}
        }
    }
    objRow1.text=st1;
    if (gRowsNumb>1) objRow2.text=st2;
    if (gRowsNumb>2) objRow3.text=griText->item(r,5)->text();
    if (gRowsNumb>3) objRow4.text=griText->item(r,6)->text();
    fRowsTextForm();
}
void winMain::fGridChan(int iR,int iC,int,int) {griText->setCurrentCell(iR,iC);fGridRows(iR);}
void winMain::fGridClic(int iR,int iC)
{
    if (iC==0) {fGridMarkRows(iR);return;}
    if (gAuto && !gInit) {griText->setCurrentCell(iR,iC);fAutoStarInit();}
    if (gAuto && gInit)
    {
        if (gPlay) tmrAuto->stop();
        griText->setCurrentCell(iR,iC);
        fAutoStarInit();
        if (gPlay) tmrAuto->start();
    }
}
void winMain::fGridEditButt() {fGridEdit(griText->currentRow(),griText->currentColumn());}
void winMain::fGridEdit(int iR,int iC)
{
    if (!gGridEdit || iC==0 || iR==0 || iR==gRowsMaxi)
    {
        messSkin cM;cM.fMess(this,fraMenu,fL("msgGridEditMess"),fL("butOkOk"),"");return;
    }

    int iLineWidt=griText->columnWidth(iC)+50;
    int iLineHeig=20;
    int iWidt=iLineWidt+95;
    int iHeig=65;
    int iLefx=diaGrid->frameGeometry().x()+diaGrid->frameGeometry().width()-iWidt-79;
    int iTopy=diaGrid->frameGeometry().y()+2;

    diaEdit=new QDialog(diaGrid);
    diaEdit->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    diaEdit->setModal(true);
    diaEdit->setCursor(Qt::ArrowCursor);
    diaEdit->setMinimumSize(iWidt,iHeig);
    diaEdit->setMaximumSize(iWidt,iHeig);
    diaEdit->setGeometry(iLefx,iTopy,iWidt,iHeig);
    diaEdit->move(iLefx,iTopy);

    QString sStyl="QDialog {font:normal 11px "+gSystFontFami+";background-color:#32cd32;color:#000000;border:none}";
    sStyl+="QLineEdit {background-color:#ffffff;color:#000000;border:1px solid #202020;font:11px normal courier new;}";
    sStyl+="QLabel {background-color:#32cd32;color:#202020;border:none;text-align:left;}";
    sStyl+="QPushButton {background-color:#202020;color:#ffffff;border:none;text-align:left;padding-left:2px;}";
    diaEdit->setStyleSheet(sStyl);

    QTableWidgetItem *wi=griText->item(iR,iC);

    QLineEdit *ediLine=new QLineEdit(diaEdit);
    ediLine->setFont(gGridFont);
    ediLine->setEchoMode(QLineEdit::Normal);
    ediLine->setText(QString(wi->text()));
    ediLine->setGeometry(10,10,iLineWidt,iLineHeig);
    ediLine->setFocus();
    connect(ediLine,SIGNAL(returnPressed()),this,SLOT(fGridEditSave()));

    butEditSave=new QPushButton(QPixmap(":/Imag/QSTit_okok.png"),fL("butEditSave"),diaEdit);
    butEditSave->setIconSize(QSize(16,16));
    butEditSave->resize(70,20);
    butEditSave->move(iLineWidt+15,10);
    connect(butEditSave,SIGNAL(clicked()),this,SLOT(fGridEditSave()));

    butEditCanc=new QPushButton(QPixmap(":/Imag/QSTit_canc.png"),fL("butEditCanc"),diaEdit);
    butEditCanc->setIconSize(QSize(16,16));
    butEditCanc->resize(70,20);
    butEditCanc->move(iLineWidt+15,35);
    connect(butEditCanc,SIGNAL(clicked()),this,SLOT(fGridEditCanc()));

    gGridEditSave=false;
    QString sTextOrig=wi->text();

    diaEdit->exec();

    if (gGridEditSave && ediLine->isModified())
    {
        gGridSave=true;
        gGridModi++;
        wi->setText(ediLine->text());
        QTableWidgetItem *wic=griText->item(iR,0);
        wic->setIcon(QPixmap(":/Imag/QSTit_edit.png"));
        wic->setText("E");
        fGridSaveIcon();
        fGridRows(iR);
        fGridEditMemo(iR,iC,sTextOrig);
    }

    fGridFocus();
}
void winMain::fGridEditMemo(int iR,int iC,QString sTextOrig)
{
    QTableWidgetItem *wi=griText->item(iR,iC);
    gEditTextRows[gGridModi]=iR;
    gEditTextColu[gGridModi]=iC;
    gEditTextLine[gGridModi]=(iR+1) / 2;
    gEditTextOldx[gGridModi]=sTextOrig;
    gEditTextNewx[gGridModi]=wi->text();
}
void winMain::fGridEditCanc() {gGridEditSave=false;diaEdit->done(0);}
void winMain::fGridEditSave() {gGridEditSave=true;diaEdit->done(0);}
void winMain::fGridModi()
{
    if (gGridSave)
    {
        messSkin cM;
        if (cM.fMess(this,fraMenu,fL("GridTextModiMess"),fL("butYeYe"),fL("butNoNo"))) fGridSave();
    }
}
void winMain::fGridMarkRows(int iR)
{
    if (iR==0 || iR==gRowsMaxi) return;

    QTableWidgetItem *wi=griText->item(iR,0);

    if (wi->text()=="E") return;

    QIcon ic=wi->icon();

    if (!ic.isNull())
    {
        QTableWidgetItem *wi=new QTableWidgetItem("",0);
        wi->setFlags(Qt::NoItemFlags|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        griText->setItem(iR,0,wi);
        gGridInfo--;
    }
    else
    {
        QTableWidgetItem *wi=griText->item(iR,0);
        wi->setIcon(QPixmap(":/Imag/QSTit_flag.png"));
        wi->setText("I");
        gGridInfo++;
    }
}
void winMain::fGridUndo()
{
    if (!gGridEdit) return;
    if (gGridModi==0) return;

    int iR=gEditTextRows[gGridModi];
    int iC=gEditTextColu[gGridModi];

    griText->item(iR,iC)->setText(gEditTextOldx[gGridModi]);

    QTableWidgetItem *ic=new QTableWidgetItem("",0);
    ic->setFlags(Qt::NoItemFlags|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    griText->setItem(iR,0,ic);

    gGridModi--;
    if (gGridModi==0) gGridSave=false;
    fGridSaveIcon();
}
void winMain::fGridSave()
{
    if (!gGridSave) return;
    if (gAuto && gPlay) return;

    QString sFile=gFile;

    sFile=QFileDialog::getSaveFileName(this,"Save a S-Title",sFile,"QSTit (*.srt *.txt)");
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
void winMain::fGridFontDial()
{
    if (gGridDial) {diaFont->close();gGridDial=false;return;}
    gGridDial=true;
    diaFont=new diaFontSkin(winWind,fraMenu,fL("diaGridFont"),gGridFont);
    connect(diaFont,SIGNAL(sClosed()),this,SLOT(fGridFontClos()));
    connect(diaFont,SIGNAL(sFontGet(QFont)),this,SLOT(fGridFontGet(QFont)));
}
void winMain::fGridFontClos() {gGridDial=false;}
void winMain::fGridFontGet(QFont pFont)
{
    if (gGridFont!=pFont) {gGridFont=pFont;fGridFontSize();}
    gGridDial=false;
}
void winMain::fGridFontSize()
{
    if (gGridFont.pointSize()<8) gGridFont.setPointSize(8);
    if (gGridFont.pointSize()>16) gGridFont.setPointSize(16);
    if (gGridFont.pointSize()<=9) gGridRowsHeig=18;
    if (gGridFont.pointSize()==10) gGridRowsHeig=19;
    if (gGridFont.pointSize()>=11) gGridRowsHeig=20;
    if (gWork) fGridFontGrid();
}
void winMain::fGridFontGrid()
{
    int iR;
    int iC;
    int iRmax=gRowsMaxi;
    int iCmax=3+gRowsNumb;
    QTableWidgetItem *wi;
    QFontMetrics mGrid=QFontMetrics(gGridFont);
    QFontMetrics mRows=QFontMetrics(gRowsFont);

    fFileTextMaxi(-1,0,0,0,0,0);
    for (iR=0; iR<=iRmax; iR++)
    {
        for (iC=1; iC<iCmax; iC++)
        {
            wi=griText->item(iR,iC);
            wi->setFont(gGridFont);
            fFileTextMaxi(mGrid.width(wi->text()),mRows.width(wi->text()),wi->text().length(),iR,iR,iC);
        }
    }
    fGridInitCols();
    fGridInitRows();
}
void winMain::fGridGoto()
{
    if (gAuto && gPlay) return;
    QApplication::sendEvent(griText,new QKeyEvent(QEvent::KeyPress,Qt::Key_G,Qt::ControlModifier,"",false,1));
}
void winMain::fGridFind()
{
    if (gAuto && gPlay) return;
    QApplication::sendEvent(griText,new QKeyEvent(QEvent::KeyPress,Qt::Key_F,Qt::ControlModifier,"",false,1));
}
void winMain::fGridFocus() {diaGrid->activateWindow();griText->setFocus();}
void winMain::fGridColoTogg() {gGridColoDark=!radGridColo->isChecked();fGridColo();}

//=================================================================================================
// settings functions
//=================================================================================================

void winMain::fSettCrea()
{
    gSettShow=false;
    gSettWidt=690;
    gSettHeig=278;
    gSettLefx=0;
    gSettTopy=0;

    diaSett=new diaSkin(winWind,fraMenu,fL("butSett"),gSettWidt,gSettHeig,-1,-1);
    connect(diaSett,SIGNAL(sClosed()),this,SLOT(fSettClos()));

    tabSett=new QTabWidget(diaSett);
    tabSett->setTabPosition(QTabWidget::North);
    tabSett->setGeometry(gSettLefx,gSettTopy,gSettWidt,gSettHeig);
    tabSett->setGeometry(3,32,gSettWidt-4,gSettHeig-34);
    tabSett->setCursor(Qt::ArrowCursor);
    tabSett->setStyleSheet("border:none;");

    // page 1 - texts - rows --------------------------------------------------

    tabRows=new QWidget;
    tabRows->setStyleSheet("border:none;background-color:#151515;");

    texRowsNumb=new QLabel(fL("texRowsNumb"),tabRows);
    texRowsNumb->setMinimumWidth(70);
    texRowsNumb->move(10,10);
    grpSkin *grpRowsNumb=new grpSkin(tabRows,75,70,10,30);
    radRow1=new QRadioButton("1",grpRowsNumb);
    radRow1->setAutoExclusive(false);
    radRow1->setChecked(objRow1.show);
    radRow1->move(3,3);
    connect(radRow1,SIGNAL(clicked()),this,SLOT(fRowsNumb()));
    radRow2=new QRadioButton("2",grpRowsNumb);
    radRow2->setAutoExclusive(false);
    radRow2->setChecked(objRow2.show);
    radRow2->move(3,19);
    connect(radRow2,SIGNAL(clicked()),this,SLOT(fRowsNumb()));
    radRow3=new QRadioButton("3",grpRowsNumb);
    radRow3->setAutoExclusive(false);
    radRow3->setChecked(objRow3.show);
    radRow3->move(3,35);
    connect(radRow3,SIGNAL(clicked()),this,SLOT(fRowsNumb()));
    radRow4=new QRadioButton("4",grpRowsNumb);
    radRow4->setAutoExclusive(false);
    radRow4->setChecked(objRow4.show);
    radRow4->move(3,51);
    connect(radRow4,SIGNAL(clicked()),this,SLOT(fRowsNumb()));

    texRowsLoca=new QLabel(fL("texRowsLoca"),tabRows);
    texRowsLoca->setMinimumWidth(70);
    texRowsLoca->move(105,10);
    grpSkin *grpRowsLoca=new grpSkin(tabRows,75,70,105,30);
    butLocaUpup=new butToolX(grpRowsLoca);
    butLocaUpup->setText(fL("butLocaUpup"));
    butLocaUpup->setIcon(QPixmap(":/Imag/QSTit_xupx.png"));
    butLocaUpup->move(29,7);
    connect(butLocaUpup,SIGNAL(clicked()),this,SLOT(fRowsLocU()));
    butLocaLeft=new butToolX(grpRowsLoca);
    butLocaLeft->setText(fL("butLocaLeft"));
    butLocaLeft->setIcon(QPixmap(":/Imag/QSTit_xlef.png"));
    butLocaLeft->move(9,27);
    connect(butLocaLeft,SIGNAL(clicked()),this,SLOT(fRowsLocL()));
    butLocaCent=new butToolX(grpRowsLoca);
    butLocaCent->setText(fL("butLocaCent"));
    butLocaCent->setIcon(QPixmap(":/Imag/QSTit_cent.png"));
    butLocaCent->move(29,27);
    connect(butLocaCent,SIGNAL(clicked()),this,SLOT(fRowsLocC()));
    butLocaRigh=new butToolX(grpRowsLoca);
    butLocaRigh->setText(fL("butLocaRigh"));
    butLocaRigh->setIcon(QPixmap(":/Imag/QSTit_xrig.png"));
    butLocaRigh->move(49,27);
    connect(butLocaRigh,SIGNAL(clicked()),this,SLOT(fRowsLocR()));
    butLocaDown=new butToolX(grpRowsLoca);
    butLocaDown->setText(fL("butLocaDown"));
    butLocaDown->setIcon(QPixmap(":/Imag/QSTit_xdow.png"));
    butLocaDown->move(29,47);
    connect(butLocaDown,SIGNAL(clicked()),this,SLOT(fRowsLocD()));

    texRowsDime=new QLabel(fL("texRowsDime"),tabRows);
    texRowsDime->setMinimumWidth(70);
    texRowsDime->move(205,10);
    grpSkin *grpRowsDime=new grpSkin(tabRows,75,70,205,30);
    labRowsDimH=new QLabel("H.",grpRowsDime);
    labRowsDimH->setMaximumWidth(20);
    labRowsDimH->move(54,7);
    spiRowsDimH=new QSpinBox(grpRowsDime);
    spiRowsDimH->move(6,7);
    spiRowsDimH->setStyleSheet(gSpinStyl);
    spiRowsDimH->setRange(200,gWindWidt-2);
    spiRowsDimH->setSingleStep(2);
    spiRowsDimH->setValue(gWindWidt-2);
    connect(spiRowsDimH,SIGNAL(valueChanged(int)),this,SLOT(fRowsDimH(int)));
    labRowsDimV=new QLabel("V.",grpRowsDime);
    labRowsDimV->setMaximumWidth(20);
    labRowsDimV->move(54,32);
    spiRowsDimV=new QSpinBox(grpRowsDime);
    spiRowsDimV->move(6,32);
    spiRowsDimV->setStyleSheet(gSpinStyl);
    spiRowsDimV->setRange(20,100);
    spiRowsDimV->setValue(30);
    connect(spiRowsDimV,SIGNAL(valueChanged(int)),this,SLOT(fRowsDimV(int)));

    texRowsSpac=new QLabel(fL("texRowsSpac"),tabRows);
    texRowsSpac->setMinimumWidth(70);
    texRowsSpac->move(305,10);
    grpSkin *grpRowsSpac=new grpSkin(tabRows,75,40,305,30);
    spiRowsSpac=new QSpinBox(grpRowsSpac);
    spiRowsSpac->move(6,7);
    spiRowsSpac->setStyleSheet(gSpinStyl);
    spiRowsSpac->setRange(0,50);
    spiRowsSpac->setValue(1);
    connect(spiRowsSpac,SIGNAL(valueChanged(int)),this,SLOT(fRowsSpac(int)));

    texRowsBack=new QLabel(fL("texRowsBack"),tabRows);
    texRowsBack->setMinimumWidth(70);
    texRowsBack->move(405,10);
    grpSkin *grpRowsBack=new grpSkin(tabRows,75,40,405,30);
    butTextBack=new QPushButton(QPixmap(":/Imag/QSTit_colo.png")," "+fL("butTextBack"),grpRowsBack);
    butTextBack->move(3,3);
    connect(butTextBack,SIGNAL(clicked()),this,SLOT(fRowsBack()));

    labWindBack=new QLabel(fL("labWindBack"),tabRows);
    labWindBack->setMinimumWidth(70);
    labWindBack->move(600,10);
    grpSkin *grpWindBack=new grpSkin(tabRows,75,40,600,30);
    radWindBacB=new QRadioButton(fL("radWindBacB"),grpWindBack);
    radWindBacB->move(3,3);
    radWindBacB->setChecked(true);
    connect(radWindBacB,SIGNAL(clicked()),this,SLOT(fWindBack()));
    radWindBacG=new QRadioButton(fL("radWindBacG"),grpWindBack);
    radWindBacG->move(3,19);
    connect(radWindBacG,SIGNAL(clicked()),this,SLOT(fWindBack()));

    // page 1 - texts - texts -------------------------------------------------

    labSettLin1=new QLabel(tabRows);
    labSettLin1->setStyleSheet("background-color:#333333;");
    labSettLin1->setGeometry(10,110,665,1);

    labTextFont=new QLabel(fL("labTextFont"),tabRows);
    labTextFont->setMinimumWidth(70);
    labTextFont->move(10,120);
    grpSkin *grpTextFont=new grpSkin(tabRows,75,70,10,140);
    butFont=new QPushButton(QPixmap(":/Imag/QSTit_font.png")," "+fL("butFont"),grpTextFont);
    butFont->move(3,3);
    connect(butFont,SIGNAL(clicked()),this,SLOT(fRowsFont()));
    butTextColo=new QPushButton(QPixmap(":/Imag/QSTit_colo.png")," "+fL("butTextColo"),grpTextFont);
    butTextColo->move(3,28);
    connect(butTextColo,SIGNAL(clicked()),this,SLOT(fRowsColo()));

    labRowsOutl=new QLabel(fL("labRowsOutl"),tabRows);
    labRowsOutl->setMinimumWidth(70);
    labRowsOutl->move(105,120);
    grpSkin *grpRowsOutl=new grpSkin(tabRows,75,70,105,140);
    spiRowsOutl=new QSpinBox(grpRowsOutl);
    spiRowsOutl->move(6,7);
    spiRowsOutl->setStyleSheet(gSpinStyl);
    spiRowsOutl->setRange(0,10);
    spiRowsOutl->setValue(0);
    connect(spiRowsOutl,SIGNAL(valueChanged(int)),this,SLOT(fRowsOutlSlid(int)));
    butRowsOutl=new QPushButton(QPixmap(":/Imag/QSTit_colo.png")," "+fL("butRowsOutl"),grpRowsOutl);
    butRowsOutl->move(3,28);
    connect(butRowsOutl,SIGNAL(clicked()),this,SLOT(fRowsOutlDial()));

    texRowsRota=new QLabel(fL("texRowsRota"),tabRows);
    texRowsRota->setMinimumWidth(70);
    texRowsRota->move(205,120);
    grpSkin *grpRowsRota=new grpSkin(tabRows,75,40,205,140);
    spiRowsRota=new QSpinBox(grpRowsRota);
    spiRowsRota->move(6,7);
    spiRowsRota->setStyleSheet(gSpinStyl);
    spiRowsRota->setRange(-400,400);
    spiRowsRota->setValue(0);
    connect(spiRowsRota,SIGNAL(valueChanged(int)),this,SLOT(fRowsRota(int)));

    labTextAliH=new QLabel(fL("labTextAliH"),tabRows);
    labTextAliH->setMinimumWidth(80);
    labTextAliH->move(305,120);
    grpSkin *grpTextAliH=new grpSkin(tabRows,75,70,305,140);
    radLeft=new QRadioButton(fL("radLeft"),grpTextAliH);
    radLeft->move(3,3);
    connect(radLeft,SIGNAL(clicked()),this,SLOT(fRowsTextAlig()));
    radCenH=new QRadioButton(fL("radCenH"),grpTextAliH);
    radCenH->move(3,19);
    radCenH->setChecked(true);
    connect(radCenH,SIGNAL(clicked()),this,SLOT(fRowsTextAlig()));
    radRigh=new QRadioButton(fL("radRigh"),grpTextAliH);
    radRigh->move(3,35);
    connect(radRigh,SIGNAL(clicked()),this,SLOT(fRowsTextAlig()));

    labTextAliV=new QLabel(fL("labTextAliV"),tabRows);
    labTextAliV->setMinimumWidth(80);
    labTextAliV->move(405,120);
    grpSkin *boxTextAliV=new grpSkin(tabRows,75,70,405,140);
    radTopy=new QRadioButton(fL("radTopy"),boxTextAliV);
    radTopy->move(3,3);
    connect(radTopy,SIGNAL(clicked()),this,SLOT(fRowsTextAlig()));
    radCenV=new QRadioButton(fL("radCenV"),boxTextAliV);
    radCenV->move(3,19);
    radCenV->setChecked(true);
    connect(radCenV,SIGNAL(clicked()),this,SLOT(fRowsTextAlig()));
    radBott=new QRadioButton(fL("radBott"),boxTextAliV);
    radBott->move(3,35);
    connect(radBott,SIGNAL(clicked()),this,SLOT(fRowsTextAlig()));

    QPushButton *labVers=new QPushButton("    Vers. "+gVers,tabRows);
    labVers->setStyleSheet("color:#0055aa;border:1px solid #0055aa;padding:3px;");
    labVers->move(598,183);

    // page 2 - general -------------------------------------------------------

    tabGene=new QWidget;
    tabGene->setStyleSheet("border:none;background-color:#151515;");

    labGridFont=new QLabel(fL("labGridFont"),tabGene);
    labGridFont->setMinimumWidth(70);
    labGridFont->move(10,10);
    grpSkin *grpGridFont=new grpSkin(tabGene,75,40,10,30);
    butGridFont=new QPushButton(QPixmap(":/Imag/QSTit_font.png")," "+fL("butFont"),grpGridFont);
    butGridFont->move(3,3);
    connect(butGridFont,SIGNAL(clicked()),this,SLOT(fGridFontDial()));

    labGridColo=new QLabel(fL("labGridColo"),tabGene);
    labGridColo->setMinimumWidth(70);
    labGridColo->move(110,10);
    grpSkin *grpGridColo=new grpSkin(tabGene,75,25,110,30);
    radGridColo=new QRadioButton(fL("radGridColo"),grpGridColo);
    radGridColo->move(3,3);
    radGridColo->setChecked(gGridColoDark);
    connect(radGridColo,SIGNAL(clicked()),this,SLOT(fGridColoTogg()));

    labWorkLang=new QLabel(fL("labWorkLang"),tabGene);
    labWorkLang->setMinimumWidth(70);
    labWorkLang->move(310,10);
    grpSkin *grpWorkLang=new grpSkin(tabGene,75,40,310,30);
    radLangEngl=new QRadioButton("English",grpWorkLang);
    radLangEngl->move(3,3);
    connect(radLangEngl,SIGNAL(clicked()),this,SLOT(fLAll()));
    radLangOthe=new QRadioButton(fL("radLangOthe"),grpWorkLang);
    radLangOthe->move(3,19);
    connect(radLangOthe,SIGNAL(clicked()),this,SLOT(fLAll()));

    oLang.setFileName("./QSTit_Lang.txt");
    if (!oLang.exists()) {radLangOthe->setDisabled(true);radLangOthe->setStyleSheet(gExplDisa);}

    if (gLang==0) radLangEngl->setChecked(true);
    if (gLang==1) radLangOthe->setChecked(true);

    #ifdef Q_OS_WIN32
    labTaskShow=new QLabel(fL("labTaskShow"),tabGene);
    labTaskShow->setMinimumWidth(80);
    labTaskShow->move(410,10);
    grpSkin *grpTaskShow=new grpSkin(tabGene,75,40,410,30);
    radTaskShow=new QRadioButton(fL("radTaskShow"),grpTaskShow);
    radTaskShow->move(3,3);
    connect(radTaskShow,SIGNAL(clicked()),this,SLOT(fWindTask()));
    radTaskHide=new QRadioButton(fL("radTaskHide"),grpTaskShow);
    radTaskHide->move(3,19);
    radTaskHide->setChecked(true);
    connect(radTaskHide,SIGNAL(clicked()),this,SLOT(fWindTask()));
    #endif

    // page 2 - general - others ----------------------------------------------

    labSettLin2=new QLabel(tabGene);
    labSettLin2->setStyleSheet("background-color:#333333;");
    labSettLin2->setGeometry(10,110,665,1);

    chkSecoText=new QCheckBox(fL("chkSecoText"),tabGene);
    chkSecoText->setMinimumWidth(200);
    chkSecoText->move(10,120);
    connect(chkSecoText,SIGNAL(stateChanged(int)),this,SLOT(fRowsSeco(int)));

    chkSecoItal=new QCheckBox(fL("chkSecoItal"),tabGene);
    chkSecoItal->setMinimumWidth(200);
    chkSecoItal->move(10,140);
    connect(chkSecoItal,SIGNAL(stateChanged(int)),this,SLOT(fRowsItal(int)));

    labJumpBase=new QLabel(fL("labJumpBase"),tabGene);
    labJumpBase->setMinimumWidth(140);
    labJumpBase->move(357,120);
    spiJumpBase=new QSpinBox(tabGene);
    spiJumpBase->setStyleSheet(gSpinStyl);
    spiJumpBase->setRange(1,10);
    spiJumpBase->setValue(gJumpBase/100);
    spiJumpBase->move(310,120);
    connect(spiJumpBase,SIGNAL(valueChanged(int)),this,SLOT(fJumpBase(int)));

    grpSkin *grpSettBase=new grpSkin(tabGene,165,40,510,120);
    butSettBase=new QPushButton(QPixmap(":/Imag/QSTit_base.png")," "+fL("Back to factory settings"),grpSettBase);
    butSettBase->setStyleSheet("width:160;");
    butSettBase->move(3,3);
    connect(butSettBase,SIGNAL(clicked()),this,SLOT(fSettBase()));

    // page 3 - shed ----------------------------------------------------------

    tabShed=new QWidget;
    tabShed->setStyleSheet("border:none;background-color:#151515;");

    labRowsLoca=new QLabel(tabShed);
                labRowsLoca->setMinimumWidth(120);
                labRowsLoca->setStyleSheet(gExplStyl);
                labRowsLoca->move(10,10);
    labRowsSize=new QLabel(tabShed);
                labRowsSize->setMinimumWidth(120);
                labRowsSize->setStyleSheet(gExplStyl);
                labRowsSize->move(10,30);
    labRowsCent=new QLabel(tabShed);
                labRowsCent->setMinimumWidth(120);
                labRowsCent->setStyleSheet(gExplStyl);
                labRowsCent->move(10,50);
    labMenuSize=new QLabel(tabShed);
                labMenuSize->setMinimumWidth(120);
                labMenuSize->setStyleSheet(gExplStyl);
                labMenuSize->move(10,70);
    labMenuLoca=new QLabel(tabShed);
                labMenuLoca->setMinimumWidth(120);
                labMenuLoca->setStyleSheet(gExplStyl);
                labMenuLoca->move(10,90);
    labScreSize=new QLabel(tabShed);
                labScreSize->setMinimumWidth(120);
                labScreSize->setStyleSheet(gExplStyl);
                labScreSize->move(10,110);
    labGridCol3=new QLabel(tabShed);
                labGridCol3->setMinimumWidth(120);
                labGridCol3->setStyleSheet(gExplStyl);
                labGridCol3->move(10,130);
    labGridCol4=new QLabel(tabShed);
                labGridCol4->setMinimumWidth(120);
                labGridCol4->setStyleSheet(gExplStyl);
                labGridCol4->move(10,150);
    labGridCol5=new QLabel(tabShed);
                labGridCol5->setMinimumWidth(120);
                labGridCol5->setStyleSheet(gExplStyl);
                labGridCol5->move(10,170);
    labGridCol6=new QLabel(tabShed);
                labGridCol6->setMinimumWidth(120);
                labGridCol6->setStyleSheet(gExplStyl);
                labGridCol6->move(10,190);
    labShedShow=new QLabel(fL("labShedShow"),tabShed);
                labShedShow->setGeometry(150,30,92,20);
                labShedShow->setAlignment(Qt::AlignRight);
    labShedFont=new QLabel(fL("labShedFont"),tabShed);
                labShedFont->setGeometry(150,53,92,20);
                labShedFont->setAlignment(Qt::AlignRight);
    labShedFore=new QLabel(fL("labShedFore"),tabShed);
                labShedFore->setGeometry(150,78,92,20);
                labShedFore->setAlignment(Qt::AlignRight);
    labShedBack=new QLabel(fL("labShedBack"),tabShed);
                labShedBack->setGeometry(150,102,92,20);
                labShedBack->setAlignment(Qt::AlignRight);
    labShedHeig=new QLabel(fL("labShedHeig"),tabShed);
                labShedHeig->setGeometry(150,126,92,20);
                labShedHeig->setAlignment(Qt::AlignRight);
    labShedSpac=new QLabel(fL("labShedSpac"),tabShed);
                labShedSpac->setGeometry(150,151,92,20);
                labShedSpac->setAlignment(Qt::AlignRight);
    labShedRota=new QLabel(fL("labShedRota"),tabShed);
                labShedRota->setGeometry(150,176,92,20);
                labShedRota->setAlignment(Qt::AlignRight);
    labShedRow1=new QLabel(tabShed);
    labShedRow1->setStyleSheet("background-color:#333333;");
    labShedRow1->setGeometry(250,10,1,190);
    labShedTit1=new QLabel(fL("labShedTit1"),tabShed);    labShedTit1->move(259,10);
    radShedSho1=new QRadioButton(tabShed);
                radShedSho1->move(259,30);
                radShedSho1->setAutoExclusive(false);
                radShedSho1->setChecked(objRow1.show);
                connect(radShedSho1,SIGNAL(clicked()),this,SLOT(fShedNumb()));
    butShedFon1=new QPushButton(QPixmap(":/Imag/QSTit_font.png"),"",tabShed);
                butShedFon1->move(259,50);
                connect(butShedFon1,SIGNAL(clicked()),this,SLOT(fRowsFon1()));
    butShedFor1=new QPushButton(QPixmap(":/Imag/QSTit_colo.png"),"",tabShed);
                butShedFor1->move(259,75);
                connect(butShedFor1,SIGNAL(clicked()),this,SLOT(fRowsCol1()));
    butShedBac1=new QPushButton(QPixmap(":/Imag/QSTit_colo.png"),"",tabShed);
                butShedBac1->move(259,99);
                connect(butShedBac1,SIGNAL(clicked()),this,SLOT(fRowsBac1()));
    spiShedHei1=new QSpinBox(tabShed);
                spiShedHei1->move(259,125);
                spiShedHei1->setStyleSheet(gSpinStyl);
                spiShedHei1->setRange(0,100);
                spiShedHei1->setValue(objRow1.heig);
                connect(spiShedHei1,SIGNAL(valueChanged(int)),this,SLOT(fShedHeig(int)));
    spiShedSpa1=new QSpinBox(tabShed);
                spiShedSpa1->move(259,150);
                spiShedSpa1->setStyleSheet(gSpinStyl);
                spiShedSpa1->setRange(0,50);
                spiShedSpa1->setValue(objRow1.spac);
                connect(spiShedSpa1,SIGNAL(valueChanged(int)),this,SLOT(fShedSpac(int)));
    spiShedRot1=new QSpinBox(tabShed);
                spiShedRot1->move(259,175);
                spiShedRot1->setStyleSheet(gSpinStyl);
                spiShedRot1->setRange(-400,400);
                spiShedRot1->setValue(objRow1.rota);
                connect(spiShedRot1,SIGNAL(valueChanged(int)),this,SLOT(fShedRota(int)));
    labShedRow2=new QLabel(tabShed);
    labShedRow2->setStyleSheet("background-color:#333333;");
    labShedRow2->setGeometry(350,10,1,190);
    labShedTit2=new QLabel(fL("labShedTit2"),tabShed);    labShedTit2->move(359,10);
    radShedSho2=new QRadioButton(tabShed);
                radShedSho2->move(359,30);
                radShedSho2->setAutoExclusive(false);
                radShedSho2->setChecked(objRow2.show);
                connect(radShedSho2,SIGNAL(clicked()),this,SLOT(fShedNumb()));
    butShedFon2=new QPushButton(QPixmap(":/Imag/QSTit_font.png"),"",tabShed);
                butShedFon2->move(359,50);
                connect(butShedFon2,SIGNAL(clicked()),this,SLOT(fRowsFon2()));
    butShedFor2=new QPushButton(QPixmap(":/Imag/QSTit_colo.png"),"",tabShed);
                butShedFor2->move(359,75);
                connect(butShedFor2,SIGNAL(clicked()),this,SLOT(fRowsCol2()));
    butShedBac2=new QPushButton(QPixmap(":/Imag/QSTit_colo.png"),"",tabShed);
                butShedBac2->move(359,99);
                connect(butShedBac2,SIGNAL(clicked()),this,SLOT(fRowsBac2()));
    spiShedHei2=new QSpinBox(tabShed);
                spiShedHei2->move(359,125);
                spiShedHei2->setStyleSheet(gSpinStyl);
                spiShedHei2->setRange(0,100);
                spiShedHei2->setValue(objRow2.heig);
                connect(spiShedHei2,SIGNAL(valueChanged(int)),this,SLOT(fShedHeig(int)));
    spiShedSpa2=new QSpinBox(tabShed);
                spiShedSpa2->move(359,150);
                spiShedSpa2->setStyleSheet(gSpinStyl);
                spiShedSpa2->setRange(0,50);
                spiShedSpa2->setValue(objRow2.spac);
                connect(spiShedSpa2,SIGNAL(valueChanged(int)),this,SLOT(fShedSpac(int)));
    spiShedRot2=new QSpinBox(tabShed);
                spiShedRot2->move(359,175);
                spiShedRot2->setStyleSheet(gSpinStyl);
                spiShedRot2->setRange(-400,400);
                spiShedRot2->setValue(objRow3.rota);
                connect(spiShedRot2,SIGNAL(valueChanged(int)),this,SLOT(fShedRota(int)));
    labShedRow3=new QLabel(tabShed);
    labShedRow3->setStyleSheet("background-color:#333333;");
    labShedRow3->setGeometry(450,10,1,190);
    labShedTit3=new QLabel(fL("labShedTit3"),tabShed);    labShedTit3->move(459,10);
    radShedSho3=new QRadioButton(tabShed);
                radShedSho3->move(459,30);
                radShedSho3->setAutoExclusive(false);
                radShedSho3->setChecked(objRow3.show);
                connect(radShedSho3,SIGNAL(clicked()),this,SLOT(fShedNumb()));
    butShedFon3=new QPushButton(QPixmap(":/Imag/QSTit_font.png"),"",tabShed);
                butShedFon3->move(459,50);
                connect(butShedFon3,SIGNAL(clicked()),this,SLOT(fRowsFon3()));
    butShedFor3=new QPushButton(QPixmap(":/Imag/QSTit_colo.png"),"",tabShed);
                butShedFor3->move(459,75);
                connect(butShedFor3,SIGNAL(clicked()),this,SLOT(fRowsCol3()));
    butShedBac3=new QPushButton(QPixmap(":/Imag/QSTit_colo.png"),"",tabShed);
                butShedBac3->move(459,99);
                connect(butShedBac3,SIGNAL(clicked()),this,SLOT(fRowsBac3()));
    spiShedHei3=new QSpinBox(tabShed);
                spiShedHei3->move(459,125);
                spiShedHei3->setStyleSheet(gSpinStyl);
                spiShedHei3->setRange(0,100);
                spiShedHei3->setValue(objRow3.heig);
                connect(spiShedHei3,SIGNAL(valueChanged(int)),this,SLOT(fShedHeig(int)));
    spiShedSpa3=new QSpinBox(tabShed);
                spiShedSpa3->move(459,150);
                spiShedSpa3->setStyleSheet(gSpinStyl);
                spiShedSpa3->setRange(0,50);
                spiShedSpa3->setValue(objRow3.spac);
                connect(spiShedSpa3,SIGNAL(valueChanged(int)),this,SLOT(fShedSpac(int)));
    spiShedRot3=new QSpinBox(tabShed);
                spiShedRot3->move(459,175);
                spiShedRot3->setStyleSheet(gSpinStyl);
                spiShedRot3->setRange(-400,400);
                spiShedRot3->setValue(objRow1.rota);
                connect(spiShedRot3,SIGNAL(valueChanged(int)),this,SLOT(fShedRota(int)));
    labShedRow4=new QLabel(tabShed);
    labShedRow4->setStyleSheet("background-color:#333333;");
    labShedRow4->setGeometry(550,10,1,190);
    labShedTit4=new QLabel(fL("labShedTit4"),tabShed);    labShedTit4->move(559,10);
    radShedSho4=new QRadioButton(tabShed);
                radShedSho4->move(559,30);
                radShedSho4->setAutoExclusive(false);
                radShedSho4->setChecked(objRow4.show);
                connect(radShedSho4,SIGNAL(clicked()),this,SLOT(fShedNumb()));
    butShedFon4=new QPushButton(QPixmap(":/Imag/QSTit_font.png"),"",tabShed);
                butShedFon4->move(559,50);
                connect(butShedFon4,SIGNAL(clicked()),this,SLOT(fRowsFon4()));
    butShedFor4=new QPushButton(QPixmap(":/Imag/QSTit_colo.png"),"",tabShed);
                butShedFor4->move(559,75);
                connect(butShedFor4,SIGNAL(clicked()),this,SLOT(fRowsCol4()));
    butShedBac4=new QPushButton(QPixmap(":/Imag/QSTit_colo.png"),"",tabShed);
                butShedBac4->move(559,99);
                connect(butShedBac4,SIGNAL(clicked()),this,SLOT(fRowsBac4()));
    spiShedHei4=new QSpinBox(tabShed);
                spiShedHei4->move(559,125);
                spiShedHei4->setStyleSheet(gSpinStyl);
                spiShedHei4->setRange(0,100);
                spiShedHei4->setValue(objRow4.heig);
                connect(spiShedHei4,SIGNAL(valueChanged(int)),this,SLOT(fShedHeig(int)));
    spiShedRot4=new QSpinBox(tabShed);
                spiShedRot4->move(559,175);
                spiShedRot4->setStyleSheet(gSpinStyl);
                spiShedRot4->setRange(-400,400);
                spiShedRot4->setValue(objRow1.rota);
                connect(spiShedRot4,SIGNAL(valueChanged(int)),this,SLOT(fShedRota(int)));

    // add pages --------------------------------------------------------------

    tabSett->addTab(tabRows,fL("tabSett0"));
    tabSett->addTab(tabGene,fL("tabSett1"));
    tabSett->addTab(tabShed,fL("tabSett2"));
}
void winMain::fSettBase()
{
    gLang=0;
    gWork=false;
    gManu=false;
    gAuto=false;
    gSrtx=false;
    gPlay=false;
    gInit=false;
    gPuls=100;
    gAcce=0;
    gJump=0;
    gJumpBase=500;
    gRowsNumb=4;
    gRowsMaxi=0;
    gRowsBack="#000000";
    gRowsColo="#ffffff";
    gRowsSpac=1;
    gOutlColo=QColor("#eeeeee");
    gGridBack="#222222";
    gGridColo="#ffffff";
    gSecoText=false;
    gSecoItal=false;
    gGridEdit=true;
    gGridSave=false;
    gGridColoDark=true;
    gOutlThik=0;
    gExitDial=false;
    gSettShow=false;
    gGridShow=false;

    labTime->setText("00:00:00");
    labPuls->setText("");
    labJump->setText("");

    gRowsWbas=gWindWidt-2;
    int gRowsHbas=(gRowsHone*gRowsNumb)+(gRowsSpac*(gRowsNumb-1));
    gRowsFont.setFamily(qApp->font().family());
    gRowsFont.setPointSize(22);
    gRowsFont.setWeight(50);
    gRowsFont.setItalic(false);

    fLangFileRead();
    fWindClear();
    fWindStyle();

    fRowsBase(1,0);
    fRowsBase(2,31);
    fRowsBase(3,62);
    fRowsBase(4,93);
    fraRows->iX=1;
    fraRows->iY=1;
    fraRows->setGeometry(1,1,gRowsWbas,gRowsHbas);
    fraRows->move(1,1);
    gRowsHcenPrev=0;
    gRowsVcenPrev=0;
    fRowsAdapt();
    fRowsClear();
    fSettClos();
    spiRowsSpac->setValue(gRowsSpac);

    gMenuLefx=(gWindWidt-gMenuWidt)/2;
    gMenuTopy=gWindHeig-gMenuHeig-1;
    fraMenu->iX=gMenuLefx;
    fraMenu->iY=gMenuTopy;
    fraMenu->move(gMenuLefx,gMenuTopy);

    gGridModi=0;
    gGridInfo=0;
    gGridRowsHeig=18;
    gGridWidt=diaGrid->iW;
    gGridHeig=36+(7*gGridRowsHeig);
    diaGrid->iH=gGridHeig;
    diaGrid->fGridSizeInit(diaGrid->iW);
    diaGrid->iX=(gWindWidt-gGridWidt)/2;
    diaGrid->iY=gMenuTopy-gGridHeig;
    diaGrid->move(diaGrid->iX,diaGrid->iY);
    gGridFont=QFont(qApp->font().family(),9,QFont::Normal,false);

    fGridEditEnab();
    if (gFileInfo) {diaInfo->close();gFileInfo=false;}
    if (gHelpDial) {diaHelp->close();gHelpDial=false;}
}
void winMain::fSettShow()
{
    fWindLogoHide();
    if (gFileInfo) {diaInfo->close();gFileInfo=false;}
    if (gExitDial) {fWindExitCanc();}
    if (diaSett->isHidden())
    {
        diaSett->fRePosi();
        gSettShow=true;
        diaSett->show();
        diaSett->raise();
        diaSett->setFocus();
        if (!gWork)
        {
            radWindBacG->setChecked(true);
            fWindBack();
        }
    }
    else
    {
        fSettClos();
    }
    fRowsInit();
}
void winMain::fSettClos()
{
    gSettShow=false;
    fRowsInit();
    diaSett->setHidden(true);
    if (!gWork)
    {
        radWindBacB->setChecked(true);
        fWindBack();
    }
    if (gGridShow) fGridFocus();
}

//=================================================================================================
// file functions
//=================================================================================================

bool winMain::fFileConf()
{
    QString sConf=gFile.mid(0,gFile.size()-4)+QString(".cfg");
    oConf.setFileName(sConf);
    if (!oConf.exists()) return false;
    {
        messSkin cM;
        if (!cM.fMess(this,fraMenu,fL("FileConfExisMess"),fL("butYeYe"),fL("butNoNo"))) return false;
    }
    gConf=sConf;
    return true;
}
void winMain::fFileDial()
{
    if (gFileDial) {diaFile->close();gFileDial=false;return;}
    fWindLogoHide();
    if (gGridSave)
    {
        fGridModi();
    }
    else if (gGridShow)
    {
        messSkin cM;
        if (!cM.fMess(this,fraMenu,fL("FileProbOpenMess"),fL("butYeYe"),fL("butNoNo"))) return;
    }
    gFileDial=true;
    diaFile=new diaFileSkin(winWind,fraMenu,fL("diaFile"),fL("diaFileFolder"),fL("diaFileName"),fL("diaFileType"));
    connect(diaFile,SIGNAL(sFileGet(QString)),SLOT(fFileDialRepo(QString)));
    connect(diaFile,SIGNAL(sClosed()),SLOT(fFileDialCanc()));
}
void winMain::fFileDialCanc() {gFileDial=false;gFile="";fraMenu->setFocus();}
void winMain::fFileDialRepo(QString sRepo)
{
    gFileDial=false;
    gFile=sRepo;
    fraMenu->setFocus();
    if (gFile.isEmpty())
    {
        if (!gGridShow) diaGrid->hide();
    }
    else
    {
        fClearAll(false);
        if (fFileConf()) fConfRead();
        if (QFileInfo(gFile).suffix().toLower()==QString("srt")) gSrtx=true;
        else gSrtx=false;
        if (gSrtx) fFileReadSrtx();
        else fFileRead();
    }
}
void winMain::fFileRead()
{
    QString sLine,sGrid;
    int iGrid=0;
    int iLine=0;
    int iRows=0;
    int iColo=0;
    int iC,iT;
    QStringList lText;
    bool bStop=false;

    oFile.setFileName(gFile);

    if (!oFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        messSkin cM;
        cM.fMess(this,fraMenu,fL("FileProbWarnMess")+QString("|%1|%2").arg(gFile).arg(oFile.errorString()),fL("butOkOk"),"");
        return;
    }

    fFileEncoding(gFile);

    barSkin *barFile=new barSkin(winWind,fraMenu,gFile,fL("barFileReading"),220,90,-1,-1,fFileSize(gFile));

    gWork=true;
    gManu=true;
    gAuto=false;
    gGridModi=0;
    gGridSave=false;
    fGridSaveIcon();
    gGridInfo=0;
    fGridShow(false);
    fGridZero();
    gFileErro="";

    fFileTextMaxi(-1,0,0,0,0,0);

    QFontMetrics mGrid=QFontMetrics(gGridFont);
    QFontMetrics mRows=QFontMetrics(gRowsFont);

    QTextStream oStrm(&oFile);
    if (gFileEnco) oStrm.setCodec("ISO-8859-1");
    else oStrm.setCodec("UTF-8");

    while (!oStrm.atEnd() && !bStop)
    {
        barFile->setStep(++iRows);

        iLine++;
        sLine=oStrm.readLine(0).trimmed();
        lText=sLine.split(QString("\\"));

        griText->insertRow(++iGrid);
        fGridItemSetx("",iGrid,0);
        fGridItemSetx("",iGrid,1);
        fGridItemSetx("",iGrid,2);
        fGridItemSetx("",iGrid,3);
        fGridItemSetx("",iGrid,4);
        fGridItemSetx("",iGrid,5);
        fGridItemSetx("",iGrid,6);

        for (iT=0; iT<4; iT++)
        {
            iC=iT+3;
            if (lText.size()>iT)
            {
                sLine=fFileLineForm(lText[iT]);
                fGridItemSetx(sLine,iGrid,iC);
                sGrid=sLine;sLine=fGridTextClean(lText[iT]);
                bStop=fFileTextMaxi(mGrid.width(sGrid),mRows.width(sLine),sLine.length(),iGrid,iLine,iC);
                if (bStop) break;
            }
            else
            {
                fGridItemSetx("",iGrid,iC);
            }
        }

        if (lText.size()>iColo) iColo=lText.size();
    }
    oFile.close();
    barFile->close();

    if (bStop) return;

    gRowsMaxi=griText->rowCount()-1;
    gRowsNumb=iColo;
    fRowsChck();
    fRowsNumb();
    fRowsFontChan();
    fRowsFramInit();

    fGridInit();
    fGridTitle();
    fGridShow(true);

    fManuInit();
}
int winMain::fFileSize(QString sFile)
{
    int iSize=0;
    QByteArray aLine;
    QFile oFile;
    oFile.setFileName(sFile);
    oFile.open(QIODevice::ReadOnly|QIODevice::Text);
    while (!oFile.atEnd()) {aLine=oFile.readLine(0);iSize++;}
    oFile.close();
    return iSize;
}
void winMain::fFileEncoding(QString sFile)
{
    QFile oFile;
    oFile.setFileName(sFile);
    oFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray aText=oFile.readAll();
    gFileEnco=true;
    for (int i=0; i<aText.size(); i++) {if (aText.indexOf(QChar(195))>0) {gFileEnco=false;break;}}
    oFile.close();
}
QString winMain::fFileLineForm(QString sLine)
{
    sLine=sLine.trimmed();
    sLine.replace(QChar(9)," ");
    sLine.replace("  "," ");
    sLine.replace(" .",".");
    sLine.replace(" :",":");
    sLine.replace(" ;",";");
    sLine.replace(" ,",",");
    sLine.replace(" !","!");
    sLine.replace(" ?","?");
    sLine.replace("( ","(");
    sLine.replace(" )",")");
    sLine.replace("[ ","[");
    sLine.replace(" ]","]");
    sLine.replace("{ ","{");
    sLine.replace(" }","}");
    sLine.replace("<<","<");
    sLine.replace(">>",">");
    if (sLine.indexOf("</b>")!=-1 && sLine.indexOf("<b>")==-1) sLine.prepend("<b>");
    if (sLine.indexOf("<b>")!=-1 && sLine.indexOf("</b>")==-1) sLine.append("</b>");
    if (sLine.indexOf("</i>")!=-1 && sLine.indexOf("<i>")==-1) sLine.prepend("<i>");
    if (sLine.indexOf("<i>")!=-1 && sLine.indexOf("</i>")==-1) sLine.append("</i>");
    if (sLine.indexOf("</u>")!=-1 && sLine.indexOf("<u>")==-1) sLine.prepend("<u>");
    if (sLine.indexOf("<u>")!=-1 && sLine.indexOf("</u>")==-1) sLine.append("</u>");
    return sLine;
}

bool winMain::fFileTextMaxi(int iGrid,int iLeng,int iChar,int iRows,int iLine,int iC)
{
    if (iGrid<0)
    {
        for (iC=0; iC<4; iC++){gFileMaxiColu[iC]=0;}
        for (int iM=0; iM<9; iM++)
        {
            gFileMaxiGrid[iM]=0;
            gFileMaxiLeng[iM]=0;
            gFileMaxiChar[iM]=0;
            gFileMaxiRows[iM]=0;
            gFileMaxiColo[iM]=0;
            gFileMaxiLine[iM]=0;
        }
    }
    else
    {
        if (iLeng>gRowsWbas)
        {
            gFileErro+=QString("|%1 - text too wide").arg(iLine);
            messSkin cM;
            if (!cM.fMess(this,fraMenu,fL("FileProbWideMess").arg(iLine),fL("butYeYe"),fL("butNoNo"))) return true;
        }
        if (iGrid>gFileMaxiColu[iC-3])
        {
            gFileMaxiColu[iC-3]=iGrid;
        }
        for (int iM=0; iM<9; iM++)
        {
            if (iLeng==gFileMaxiLeng[iM]) break;
            if (iLeng>gFileMaxiLeng[iM])
            {
                for (int iN=8; iN>=iM; iN--)
                {
                    gFileMaxiGrid[iN]=gFileMaxiGrid[iN-1];
                    gFileMaxiLeng[iN]=gFileMaxiLeng[iN-1];
                    gFileMaxiChar[iN]=gFileMaxiChar[iN-1];
                    gFileMaxiRows[iN]=gFileMaxiRows[iN-1];
                    gFileMaxiColo[iN]=gFileMaxiColo[iN-1];
                    gFileMaxiLine[iN]=gFileMaxiLine[iN-1];
                }
                gFileMaxiGrid[iM]=iGrid;
                gFileMaxiLeng[iM]=iLeng;
                gFileMaxiChar[iM]=iChar;
                gFileMaxiRows[iM]=iRows;
                gFileMaxiColo[iM]=iC;
                gFileMaxiLine[iM]=iLine;
                break;
            }
        }
    }
    return false;
}
void winMain::fFileWrit(QString sFile)
{
    oFile.setFileName(sFile);
    if (!oFile.open(QIODevice::WriteOnly|QIODevice::Text)) return;

    gGridSave=false;

    QTableWidgetItem *it1;
    QTableWidgetItem *it2;
    QString sLine;
    QString st1;
    QString st2;

    for (int r=1; r<gRowsMaxi; r++)
    {
        sLine="";
        it1=griText->item(r,3);
        it2=griText->item(r,4);
        st1=it1->text();
        st2=it2->text();
        if (gSecoText && st1.isEmpty())
        {
            st1=st2;
            st2="";
        }
        sLine=st1;
        if (gRowsNumb>1)
        {
            if (!st2.isEmpty()) sLine=sLine+"\\"+st2;
        }
        if (gRowsNumb>2)
        {
            QTableWidgetItem *it3=griText->item(r,5);
            QString st3=it3->text();
            if (!st3.isEmpty()) sLine=sLine+"\\"+st3;
        }
        if (gRowsNumb>3)
        {
            QTableWidgetItem *it4=griText->item(r,6);
            QString st4=it4->text();
            if (!st4.isEmpty()) sLine=sLine+"\\"+st4;
        }
        sLine=sLine+"\n";
        oFile.write(sLine.toAscii());
    }
    oFile.close();
}
void winMain::fFileWritSrtx(QString sFile)
{
    oFile.setFileName(sFile);
    if (!oFile.open(QIODevice::WriteOnly|QIODevice::Text)) return;

    gGridSave=false;

    QString sLine;
    QString sNumb;
    QString sStar;
    QString sStop;
    QString sTex1;
    QString sTex2;
    int iR;

    for (iR=1; iR<gRowsMaxi; iR++)
    {
        sNumb=griText->verticalHeaderItem(iR)->text();
        sStar=griText->item(iR,1)->text();
        sStop=griText->item(iR,2)->text();
        sTex1=griText->item(iR,3)->text();
        sTex2=griText->item(iR,4)->text();
        if (gSecoText && sTex1.isEmpty())
        {
            sTex1=sTex2;
            sTex2="";
        }
        sLine=sNumb+"\n";
        sLine+=(sStar+" --> "+sStop+"\n");
        if (!sTex1.isEmpty()) sLine+=(sTex1+"\n");
        if (!sTex2.isEmpty()) sLine+=(sTex2+"\n");
        sLine+="\n";
        oFile.write(sLine.toAscii());
    }
    oFile.close();
}
void winMain::fFileLogx()
{
    int iR;
    int iRmaxi=griText->rowCount()-1;
    int iC;
    int r;
    QString sLine;

    if (!gFileErro.isEmpty())
    {
        QStringList lProb=gFileErro.split(QString("|"));

        for (int iP=1; iP<lProb.count(); iP++)
        {
            sLine=QString("[Error] line %1\n").arg(lProb[iP]);
            if (!fFlogOpen()) return;
            oFlog.write(sLine.toAscii());
        }
    }

    for (iR=0; iR<iRmaxi; iR++)
    {
        if (griText->item(iR,0)->text()=="I")
        {
            sLine=QString("[Marked] Row %1 Col 1 : ").arg(griText->verticalHeaderItem(iR)->text().toInt());
            sLine+=QString("Text ["+griText->item(iR,3)->text()+"...]\n");
            if (!fFlogOpen()) return;
            oFlog.write(sLine.toAscii());
        }
        if (griText->item(iR,0)->text()=="E")
        {
            for (r=1; r<=gGridModi; r++)
            {
                if (iR==gEditTextRows[r])
                {
                    iC=gEditTextColu[r];
                    if (!gSrtx) iC-=2;

                    sLine=QString("[Edited] Row %1 Col %2 : ").arg(gEditTextLine[r]).arg(iC);
                    sLine+=QString("Old ["+gEditTextOldx[r]+"]");
                    sLine+=QString(" -> New ["+gEditTextNewx[r]+"]\n");
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
    int iSize=gFile.size();
    QString sFlog=gFile.mid(0,iSize-4)+QString(".log");
    oFlog.setFileName(sFlog);
    return oFlog.open(QIODevice::WriteOnly|QIODevice::Text);
}
void winMain::fFileReadSrtx()
{
    QString sLine;
    int iGrid=0;
    int iLine=0;
    int iRows=0;
    int iColo=0;
    QStringList lText;
    int iStru=1;
    QString sNumb="";
    QString sStar="";
    QString sStop="";
    QString sTex1="",sGri1="";
    QString sTex2="",sGri2="";
    QString sTex3="",sGri3="";
    QString sTex4="",sGri4="";
    bool bOk=true;
    bool bStop=false;

    oFile.setFileName(gFile);

    if (!oFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        messSkin cM;
        cM.fMess(this,fraMenu,fL("FileProbWarnMess")+QString("|%1|%2").arg(gFile).arg(oFile.errorString()),fL("butOkOk"),"");
        return;
    }

    fFileEncoding(gFile);

    barSkin *barFile=new barSkin(winWind,fraMenu,gFile,fL("barFileReading"),220,90,-1,-1,fFileSize(gFile));

    gWork=true;
    gManu=false;
    gAuto=true;
    gGridModi=0;
    gGridSave=false;
    fGridSaveIcon();
    gGridInfo=0;
    fGridShow(false);
    fGridZero();
    gFileErro="";
    //gSrtxStop="";

    fFileTextMaxi(-1,0,0,0,0,0);

    QFontMetrics mGrid=QFontMetrics(gGridFont);
    QFontMetrics mRows=QFontMetrics(gRowsFont);

    QTextStream oStrm(&oFile);
    if (gFileEnco) oStrm.setCodec("ISO-8859-1");
    else oStrm.setCodec("UTF-8");

    while (!oStrm.atEnd() && !bStop)
    {
        barFile->setStep(++iRows);

        if (iStru==1 && !sNumb.isEmpty())
        {
            griText->insertRow(++iGrid);
            fGridItemSetx("",iGrid,0);
            fGridItemSetx(sStar,iGrid,1);
            fGridItemSetx(sStop,iGrid,2);
            fGridItemSetx(sTex1,iGrid,3);
            fGridItemSetx(sTex2,iGrid,4);
            fGridItemSetx(sTex3,iGrid,5);
            fGridItemSetx(sTex4,iGrid,6);

            sGri1=sTex1;sTex1=fGridTextClean(sTex1);
            sGri2=sTex2;sTex2=fGridTextClean(sTex2);
            sGri3=sTex3;sTex3=fGridTextClean(sTex3);
            sGri4=sTex4;sTex4=fGridTextClean(sTex4);

            bStop=fFileTextMaxi(mGrid.width(sGri1),mRows.width(sTex1),sTex1.length(),iGrid,iLine,3);
            if (bStop) break;
            bStop=fFileTextMaxi(mGrid.width(sGri2),mRows.width(sTex2),sTex2.length(),iGrid,iLine,4);
            if (bStop) break;
            bStop=fFileTextMaxi(mGrid.width(sGri3),mRows.width(sTex3),sTex3.length(),iGrid,iLine,5);
            if (bStop) break;
            bStop=fFileTextMaxi(mGrid.width(sGri4),mRows.width(sTex4),sTex4.length(),iGrid,iLine,6);
            if (bStop) break;

            sNumb="";
            sStar="";
            sStop="";
            sTex1="";
            sTex2="";
            sTex3="";
            sTex4="";
        }
        sLine=fFileLineForm(oStrm.readLine(0));

        if (iStru==1)
        {
            iLine=fFileSrtxVeriNumb(iRows,sLine,iLine);
            if (iLine<0)
            {
                bOk=false;
                break;
            }
            sNumb=sLine;
            iStru++;
        }
        else if (iStru==2)
        {
            if (!fFileSrtxVeriHour(iRows,sLine,iLine))
            {
                bOk=false;
                break;
            }
            lText=sLine.split(QString(" --> "));
            sStar=lText[0];
            sStop=lText[1];
            iStru++;
        }
        else if (iStru==3)
        {
            if (sLine.length()<1) iStru=1;              // line 1 could be optional
            else
            {
                fFileSrtxVeriText(iRows,sLine,iLine);
                iStru++;
            }
            sTex1=sLine.trimmed();
        }
        else if (iStru==4)
        {
            if (sLine.length()<1) iStru=1;              // line 2 is optional
            else
            {
                fFileSrtxVeriText(iRows,sLine,iLine);
                if (iColo<2) iColo=2;
                iStru++;
            }
            sTex2=sLine.trimmed();
        }
        else if (iStru==5)
        {
            if (sLine.length()<1) iStru=1;              // line 3 is optional
            else
            {
                fFileSrtxVeriText(iRows,sLine,iLine);
                if (iColo<3) iColo=3;
                iStru++;
            }
            sTex3=sLine.trimmed();
        }
        else if (iStru==6)
        {
            if (sLine.length()<1) iStru=1;              // line 4 is optional
            else
            {
                fFileSrtxVeriText(iRows,sLine,iLine);
                if (iColo<4) iColo=4;
                iStru++;
            }
            sTex4=sLine.trimmed();
        }
        else if (iStru==7)
        {
            if (!fFileSrtxVeriBlan(iRows,sLine,iLine))
            {
                bOk=false;
                break;
            }
            iStru=1;
        }
    }
    oFile.close();
    barFile->close();

    if (bStop) return;

    if (!sNumb.isEmpty())
    {
        griText->insertRow(++iGrid);
        fGridItemSetx("",iGrid,0);
        fGridItemSetx(sStar,iGrid,1);
        fGridItemSetx(sStop,iGrid,2);
        fGridItemSetx(sTex1,iGrid,3);
        fGridItemSetx(sTex2,iGrid,4);
        fGridItemSetx(sTex3,iGrid,5);
        fGridItemSetx(sTex4,iGrid,6);

        sTex1=fGridTextClean(sTex1);
        sTex2=fGridTextClean(sTex2);
        sTex3=fGridTextClean(sTex3);
        sTex4=fGridTextClean(sTex4);

        bStop=fFileTextMaxi(mGrid.width(sTex1),mRows.width(sTex1),sTex1.length(),iGrid,iLine,3);if (bStop) return;
        bStop=fFileTextMaxi(mGrid.width(sTex2),mRows.width(sTex2),sTex2.length(),iGrid,iLine,4);if (bStop) return;
        bStop=fFileTextMaxi(mGrid.width(sTex3),mRows.width(sTex3),sTex3.length(),iGrid,iLine,5);if (bStop) return;
        bStop=fFileTextMaxi(mGrid.width(sTex4),mRows.width(sTex4),sTex4.length(),iGrid,iLine,6);if (bStop) return;

        //gSrtxStop=sStop;
    }

    gRowsMaxi=griText->rowCount()-1;
    gRowsNumb=iColo;
    fRowsChck();
    fRowsNumb();
    fRowsFontChan();
    fRowsFramInit();

    fGridInit();
    fGridTitle();
    fGridShow(true);

    fAutoInit();

    if (!bOk) {messSkin cM;cM.fMess(this,fraMenu,fL("FileProbCritMess"),fL("butOkOk"),"");}
}

int winMain::fFileSrtxVeriNumb(int iRows,QString sText,int iLine)
{
    bool bOk;

    if (sText.length()<1)
    {
        gFileErro+=QString("|%1 (file %2) - Number,unexpected empty line").arg(iLine).arg(iRows);
        gFileErro+=QString("|%1 (file %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return -1;
    }
    if (!sText.at(0).isDigit())
    {
        gFileErro+=QString("|%1 (file %2) - Number,expected: %1").arg(iLine).arg(iRows);
        gFileErro+=QString("|%1 (file %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return -1;
    }
    int iTemp=sText.toInt(&bOk,10);
    if (iLine==0) iLine=iTemp;
    else iLine++;
    if (iLine!=iTemp)
    {
        gFileErro+=QString("|%1 (file %2) - Number,read: %3,expected: %1").arg(iLine).arg(iRows).arg(iTemp);
        iLine=iTemp;
    }
    return iLine;
}
bool winMain::fFileSrtxVeriHour(int iRows,QString sText,int iLine)
{
    static int iPrev=0;
    bool bOk;

    if (iLine==1) iPrev=0;

    if (sText.length()<1)
    {
        gFileErro+=QString("|%1 (file %2) - Hours,unexpected empty line").arg(iLine).arg(iRows);
        gFileErro+=QString("|%1 (file %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return false;
    }
    if (sText.length() != 29)
    {
        gFileErro+=QString("|%1 (file %2) - Hours,bad length (less or more than 29 char.)").arg(iLine).arg(iRows);
        gFileErro+=QString("|%1 (file %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return false;
    }
    if (!sText.at(0).isDigit() || !sText.at(1).isDigit() || !sText.at(17).isDigit() || !sText.at(18).isDigit())
    {
        gFileErro+=QString("|%1 (file %2) - Hours,bad hours format").arg(iLine).arg(iRows);
        return true;
    }
    if (sText.at(2) != ':' || sText.at(19) != ':')
    {
        gFileErro+=QString("|%1 (file %2) - Hours,bad time separator,':' expected").arg(iLine).arg(iRows);
        return true;
    }
    if (!sText.at(3).isDigit() || !sText.at(4).isDigit() || !sText.at(20).isDigit() || !sText.at(21).isDigit())
    {
        gFileErro+=QString("|%1 (file %2) - Hours,bad minutes format").arg(iLine).arg(iRows);
        return true;
    }
    if (sText.at(5) != ':' || sText.at(22) != ':')
    {
        gFileErro+=QString("|%1 (file %2) - Hours,bad time separator,':' expected").arg(iLine).arg(iRows);
        return true;
    }
    if (!sText.at(6).isDigit() || !sText.at(7).isDigit() || !sText.at(23).isDigit() || !sText.at(24).isDigit())
    {
        gFileErro+=QString("|%1 (file %2) - Hours,bad seconds format").arg(iLine).arg(iRows);
        return true;
    }
    if (sText.at(8) != ',' || sText.at(25) != ',')
    {
        gFileErro+=QString("|%1 - Hours,bad time separator,',' expected").arg(iLine).arg(iRows);
        return true;
    }
    if (!sText.at(9).isDigit() || !sText.at(10).isDigit() || !sText.at(11).isDigit() || !sText.at(26).isDigit() || !sText.at(27).isDigit() || !sText.at(28).isDigit())
    {
        gFileErro+=QString("|%1 (file %2) - Hours,bad milliseconds format").arg(iLine).arg(iRows);
        return true;
    }
    if (sText.mid(12,5)!=" --> ")
    {
        gFileErro+=QString("|%1 (file %2) - Hours,bad start/end separator,' --> ' expected").arg(iLine).arg(iRows);
        return true;
    }
    QString sStar=sText.mid(0,2)+sText.mid(3,2)+sText.mid(6,2)+sText.mid(9,3);
    int iStar=sStar.toInt(&bOk,10);
    QString sStop=sText.mid(17,2)+sText.mid(20,2)+sText.mid(23,2)+sText.mid(26,3);
    int iStop=sStop.toInt(&bOk,10);
    if (iStar>=iStop)
    {
        gFileErro+=QString("|%1 (file %2) - Hours,start >= end").arg(iLine).arg(iRows);
        return true;
    }
    if (iStar<iPrev)
    {
        gFileErro+=QString("|%1 (file %2) - Hours,start %3 < previous %4").arg(iLine).arg(iRows).arg(iStar).arg(iPrev);
        return true;
    }
    iPrev=iStop;
    return true;
}
bool winMain::fFileSrtxVeriText(int iRows,QString sText,int iLine)
{
    if (sText.length()<1)
    {
        gFileErro+=QString("|%1 (file %2) - Text,unexpected empty line").arg(iLine).arg(iRows);
        gFileErro+=QString("|%1 (file %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return false;
    }
    if (sText.length()>99)
    {
        gFileErro+=QString("|%1 (file %2) - Text,line length > 99 char.").arg(iLine).arg(iRows);
        return true;
    }
    for (int i=0; i<sText.length(); i++)
    {
        if (!sText.at(i).isPrint())
        {
            gFileErro+=QString("|%1 (file %2) - Text,non-printable (at %3)").arg(iLine).arg(iRows).arg(i+1);
            return true;
        }
    }
    return true;
}
bool winMain::fFileSrtxVeriBlan(int iRows,QString sText,int iLine)
{
    if (sText.length()>0)
    {
        gFileErro+=QString("|%1 (file %2) - Line break not found,empty line expected").arg(iLine).arg(iRows);
        gFileErro+=QString("|%1 (file %2) - STOPPED BEFORE FILE END").arg(iLine).arg(iRows);
        return false;
    }
    return true;
}

//=================================================================================================
// info functions
//=================================================================================================

void winMain::fFileInfoDial()
{
    if (!gGridShow || (gAuto && gPlay)) return;
    if (gFileInfo) {diaInfo->close();gFileInfo=false;return;}

    int iRmax=15;
    int iRowH=18;
    int iCol0=220;
    int iCol1=300;
    int iL=-1;
    int iWidt=(iCol0+iCol1)+34;
    int iHeig=(iRowH*iRmax)+38;
    int iLefx=diaGrid->frameGeometry().x()+diaGrid->frameGeometry().width()-iWidt-79;
    int iTopy=diaGrid->frameGeometry().y();

    if (iHeig>diaGrid->iH) iHeig=diaGrid->iH;

    gFileInfo=true;

    diaInfo=new diaSkin(winWind,fraMenu,fL("diaInfo"),iWidt,iHeig,iLefx,iTopy);
    connect(diaInfo,SIGNAL(sClosed()),this,SLOT(fFileInfoClos()));

    QString sStyl="QTableWidget {background-color:#222222;color:#ffffff;border:none;}";
    sStyl+="QTableCornerButton::section {background-color:#222222;color:#222222;border:none;border-bottom:1px solid #777777;}";
    sStyl+="QHeaderView {background-color:#222222;color:#222222;border:none;}";
    sStyl+="QHeaderView::section:horizontal {background-color:#222222;color:#222222;border:none;}";
    sStyl+="QHeaderView::section:vertical {font:normal 11px "+gSystFontFami+";background-color:#222222;color:#ffffff;border:1px solid #777777;border-top:0px solid #222222;}";
    sStyl+="QScrollBar:vertical {width:10px;background-color:#222222;margin:10 0 10 0;border:none;}";

    griInfo=new QTableWidget(diaInfo);
    griInfo->setGeometry(2,32,iWidt-4,iHeig-35);
    griInfo->setSelectionMode(QAbstractItemView::NoSelection);
    griInfo->setStyleSheet(sStyl);
    connect(griInfo,SIGNAL(cellClicked(int,int)),this,SLOT(fFileInfoGoto(int,int)));

    QHeaderView *hh=griInfo->horizontalHeader();
    hh->setFixedHeight(3);
    QHeaderView *hv=griInfo->verticalHeader();
    hv->setFixedWidth(20);

    griInfo->setColumnCount(2);
    griInfo->setColumnWidth(0,iCol0);
    griInfo->setColumnWidth(1,iCol1);

    griInfo->setRowCount(iRmax);
    for (int iR=0; iR<iRmax; iR++)
    {
        griInfo->setRowHeight(iR,iRowH);
    }

    QFileInfo fInfo=QFileInfo(gFile);

    iL++;
    griInfo->setItem(iL,0,new QTableWidgetItem(fL("widInfoName")));
    griInfo->setItem(iL,1,new QTableWidgetItem(fInfo.fileName()));
    iL++;
    griInfo->setItem(iL,0,new QTableWidgetItem(fL("widInfoPath")));
    griInfo->setItem(iL,1,new QTableWidgetItem(fInfo.absolutePath()));
    iL++;
    griInfo->setItem(iL,0,new QTableWidgetItem(fL("widInfoModi")));
    griInfo->setItem(iL,1,new QTableWidgetItem(fInfo.lastModified().toString("dd/MM/yyyy   hh:mm")));
    iL++;
    griInfo->setItem(iL,0,new QTableWidgetItem(fL("widInfoEnco")));
    griInfo->setItem(iL,1,new QTableWidgetItem(gFileEnco ? "ANSI":"UTF8"));
    iL++;
    griInfo->setItem(iL,0,new QTableWidgetItem(fL("widInfoCols")));
    griInfo->setItem(iL,1,new QTableWidgetItem(QString("%1").arg(gRowsNumb)));
    iL++;
    griInfo->setItem(iL,0,new QTableWidgetItem(fL("widInfoRows")));
    griInfo->setItem(iL,1,new QTableWidgetItem(QString("%1").arg(gRowsMaxi-1)));
/*
    if (gSrtx)
    {
        iL++;
        griInfo->insertRow(iL);
        griInfo->setRowHeight(iL,iRowH);
        griInfo->setItem(iL,0,new QTableWidgetItem(fL("GridLastItem")));
        griInfo->setItem(iL,1,new QTableWidgetItem(gSrtxStop.left(8)));
    }
*/
    iL++;
    griInfo->setItem(iL,0,new QTableWidgetItem(fL("widInfoLine")));
    QTableWidgetItem *vl=new QTableWidgetItem(QString("%1 - %2   (%3 pix)   (%4 c.)").arg(gFileMaxiRows[0]).arg(gFileMaxiColo[0]-2).arg(gFileMaxiLeng[0]).arg(gFileMaxiChar[0]));
    vl->setIcon(QPixmap(":/Imag/QSTit_info_goto.png"));
    griInfo->setItem(iL,1,vl);

    for (int iM=1; iM<9; iM++)
    {
        if (gFileMaxiLine[iM]>0 && gFileMaxiLine[iM] != gFileMaxiLine[iM-1])
        {
            iL++;
            QTableWidgetItem *wM=new QTableWidgetItem("");
            griInfo->setItem(iL,0,wM);
            QTableWidgetItem *vM=new QTableWidgetItem(QString("%1 - %2   (%3 pix)   (%4 c.)").arg(gFileMaxiRows[iM]).arg(gFileMaxiColo[iM]-2).arg(gFileMaxiLeng[iM]).arg(gFileMaxiChar[iM]));
            vM->setIcon(QPixmap(":/Imag/QSTit_info_goto.png"));
            griInfo->setItem(iL,1,vM);
        }
    }
    if (!gFileErro.isEmpty())
    {
        QStringList lProb=gFileErro.split(QString("|"));

        iL++;
        griInfo->insertRow(iL);
        griInfo->setRowHeight(iL,iRowH);

        QTableWidgetItem *widInfoProb=new QTableWidgetItem(fL("widInfoProb"));
        widInfoProb->setBackground(gErroBack);
        widInfoProb->setForeground(gErroColo);
        griInfo->setItem(iL,0,widInfoProb);
        QTableWidgetItem *vp=new QTableWidgetItem(lProb[1]);
        vp->setIcon(QPixmap(":/Imag/QSTit_info_goto.png"));
        griInfo->setItem(iL,1,vp);

        for (int iP=2; iP<lProb.count(); iP++)
        {
            iL++;
            griInfo->insertRow(iL);
            griInfo->setRowHeight(iL,iRowH);

            QTableWidgetItem *wP=new QTableWidgetItem("");
            wP->setBackground(gErroBack);
            griInfo->setItem(iL,0,wP);
            QTableWidgetItem *vP=new QTableWidgetItem(lProb[iP]);
            vP->setIcon(QPixmap(":/Imag/QSTit_info_goto.png"));
            griInfo->setItem(iL,1,vP);
        }
    }
    diaInfo->show();
    diaInfo->setFocus();
}
void winMain::fFileInfoClos() {gFileInfo=false;}
void winMain::fFileInfoGoto(int iR,int iC)
{
    if (iC!=1) return;
    QTableWidgetItem *wc=griInfo->currentItem();
    QIcon ic=wc->icon();
    if (ic.isNull()) return;
    QString sT=wc->text();
    QStringList lT=sT.split(QString(" "));
    iR=lT[0].toInt();
    iC=lT[2].toInt();
    griText->setCurrentCell(iR,iC,QItemSelectionModel::Rows);
    griText->scrollTo(griText->currentIndex(),QAbstractItemView::PositionAtCenter);
    fGridFocus();
}

//=================================================================================================
// help functions
//=================================================================================================

void winMain::fHelpDial()
{
    if (gAuto && gPlay) return;
    if (gHelpDial) {diaHelp->close();gHelpDial=false;return;}

    gHelpDial=true;
    int iWidt=710;
    int iHeig=650;

    diaHelp=new diaSkin(winWind,fraMenu,fL("diaHelp")+" | vers. "+gVers,iWidt,iHeig,1,1);
    connect(diaHelp,SIGNAL(sClosed()),this,SLOT(fHelpDialClos()));

    texHelp=new QTextEdit("",diaHelp);
    texHelp->setStyleSheet("QTextEdit {border:none;} QScrollBar:vertical {width:10px;background-color:#252525;margin:10 0 10 0;border:none;}");
    texHelp->setGeometry(3,31,iWidt-5,iHeig-33);
    texHelp->setReadOnly(true);
    texHelp->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    texHelp->setFrameShape(QFrame::NoFrame);
    texHelp->setContentsMargins(1,0,1,0);
    texHelp->setFont(gRowsFont);
    texHelp->setWordWrapMode(QTextOption::NoWrap);
    texHelp->document()->setDocumentMargin(0);
    texHelp->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    texHelp->setHtml(fHelpFileRead());

    diaHelp->show();
    diaHelp->setFocus();
}
void winMain::fHelpDialClos(){gHelpDial=false;}
QString winMain::fHelpFileRead()
{
    QString sFile=":/Help/QSTit_Help_En.htm";
    if (gLang==1)
    {
        oHelp.setFileName("./QSTit_Help.htm");
        if (oHelp.open(QIODevice::ReadOnly|QIODevice::Text)) {sFile=oHelp.fileName();oHelp.close();}
    }
    oHelp.setFileName(sFile);
    oHelp.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray sHelp=oHelp.readAll();
    oHelp.close();

    QTextCodec *codec;
    codec=QTextCodec::codecForName("UTF-8");
    return codec->toUnicode(sHelp);
}

//=================================================================================================
// language functions
//=================================================================================================

void winMain::fLangFileRead()
{
    QString sFile=":/Help/QSTit_Lang_En.txt";
    QString sLine;

    if (gLang==1)
    {
        oLang.setFileName("./QSTit_Lang.txt");
        if (oLang.open(QIODevice::ReadOnly|QIODevice::Text)){sFile=oLang.fileName();oLang.close();}
    }
    oLang.setFileName(sFile);
    if (!oLang.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        messSkin cM;
        cM.fMess(this,fraMenu,fL("FileProbWarnMess")+QString("|%1|%2").arg(sFile).arg(oLang.errorString()),fL("butOkOk"),"");
        return;
    }
    QByteArray aText=oLang.readAll();
    bool bAnsi=true;
    for (int i=0; i<aText.size(); i++) {if (aText.indexOf(QChar(195))>0) {bAnsi=false;break;}}
    oLang.close();
    oLang.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream oStrm(&oLang);
    if (bAnsi) oStrm.setCodec("ISO-8859-1");
    else oStrm.setCodec("UTF-8");

    sLine=oStrm.readLine(0);
    sLine=sLine.mid(0,19).trimmed();
    sLine=sLine.mid(1,sLine.size()-2);
    if (gLang==1) radLangOthe->setText(sLine);

    gLangCode.clear();
    gLangText.clear();

    while (!oStrm.atEnd())
    {
        sLine=oStrm.readLine(0);
        if(!sLine.isEmpty()) {gLangCode+=sLine.mid(0,19).trimmed();gLangText+=sLine.mid(20,99).trimmed();}
    }
    oLang.close();
}
QString winMain::fL(QString sI)
{
    int i=gLangCode.indexOf(sI,0);
    if (i>-1) sI=gLangText.at(i);
    return sI;
}
void winMain::fLAll()
{
    if (radLangEngl->isChecked()) gLang=0;
    if (radLangOthe->isChecked()) gLang=1;
    fLangFileRead();
    butExit->setText(fL("butExit"));
    butHelp->setText(fL("butHelp"));
    butFile->setText(fL("butFile"));
    butSett->setText(fL("butSett"));
    labClok->setToolTip(fL("labClok"));
    butRoll->setText(fL("butRoll"));
    labTime->setToolTip(fL("labTime"));
    butProjUpup->setText(fL("butProjUpup"));
    butProjDown->setText(fL("butProjDown"));
    butProjPlay->setText(fL("butProjPlay"));
    butProjDece->setText(fL("butProjDece"));
    butProjAcce->setText(fL("butProjAcce"));
    butProjBack->setText(fL("butProjBack"));
    butProjJump->setText(fL("butProjJump"));
    diaSett->labTitl->setText(fL("butSett"));
    tabSett->setTabText(0,fL("tabSett0"));
    tabSett->setTabText(1,fL("tabSett1"));
    tabSett->setTabText(2,fL("tabSett2"));
    texRowsLoca->setText(fL("texRowsLoca"));
    texRowsDime->setText(fL("texRowsDime"));
    butLocaUpup->setText(fL("butLocaUpup"));
    butLocaLeft->setText(fL("butLocaLeft"));
    butLocaCent->setText(fL("butLocaCent"));
    butLocaRigh->setText(fL("butLocaRigh"));
    butLocaDown->setText(fL("butLocaDown"));
/*
    butDimeDown->setText(fL("butDimeDown"));
    butDimeLeft->setText(fL("butDimeLeft"));
    butDimeRigh->setText(fL("butDimeRigh"));
    butDimeUpup->setText(fL("butDimeUpup"));
*/
    labTaskShow->setText(fL("labTaskShow"));
    radTaskShow->setText(fL("radTaskShow"));
    radTaskHide->setText(fL("radTaskHide"));
    labWorkLang->setText(fL("labWorkLang"));
    texRowsNumb->setText(fL("texRowsNumb"));
    labTextFont->setText(fL("labTextFont"));
    labWindBack->setText(fL("labWindBack"));
    radWindBacB->setText(fL("radWindBacB"));
    radWindBacG->setText(fL("radWindBacG"));
    chkSecoText->setText(fL("chkSecoText"));
    chkSecoItal->setText(fL("chkSecoItal"));
    labJumpBase->setText(fL("labJumpBase"));
    texRowsSpac->setText(fL("texRowsSpac"));
    texRowsRota->setText(fL("texRowsRota"));
    labTextFont->setText(fL("labTextFont"));
    butTextColo->setText(fL("butTextColo"));
    butTextBack->setText(fL("butTextBack"));
    butFont->setText(fL("butFont"));
    labRowsOutl->setText(fL("labRowsOutl"));
    butRowsOutl->setText(fL("butRowsOutl"));
    labTextAliH->setText(fL("labTextAliH"));
    radLeft->setText(fL("radLeft"));
    radCenH->setText(fL("radCenH"));
    radRigh->setText(fL("radRigh"));
    labTextAliV->setText(fL("labTextAliV"));
    radTopy->setText(fL("radTopy"));
    radCenV->setText(fL("radCenV"));
    radBott->setText(fL("radBott"));
    texRowsBack->setText(fL("texRowsBack"));
    butGridEdit->setText(fL("butGridEdit"));
    butGridInfo->setText(fL("butGridInfo"));
    butGridSave->setText(fL("butGridSave"));
    butGridUndo->setText(fL("butGridUndo"));
    butGridGoto->setText(fL("butGridGoto"));
    butGridFind->setText(fL("butGridFind"));
    labGridFont->setText(fL("labGridFont"));
    labGridColo->setText(fL("labGridColo"));
    radGridColo->setText(fL("radGridColo"));
    butGridClea->setText(fL("butGridClea"));
    butGridLink->setText(fL("butLink"));
    labShedShow->setText(fL("labShedShow"));
    labShedFont->setText(fL("labShedFont"));
    labShedFore->setText(fL("labShedFore"));
    labShedBack->setText(fL("labShedBack"));
    labShedHeig->setText(fL("labShedHeig"));
    labShedSpac->setText(fL("labShedSpac"));
    labShedRota->setText(fL("labShedRota"));
    labShedTit1->setText(fL("labShedTit1"));
    labShedTit2->setText(fL("labShedTit2"));
    labShedTit3->setText(fL("labShedTit3"));
    labShedTit4->setText(fL("labShedTit4"));
    diaGrid->fWorkLang(gLangCode,gLangText);
    griText->fWorkLang(gLangCode,gLangText);
    fRowsInit();
}

//=================================================================================================
// other functions
//=================================================================================================

void winMain::fClearAll(bool bMess)
{
    if (bMess) {messSkin cM;if (!cM.fMess(this,fraMenu,fL("msgCleaAllMess"),fL("butYeYe"),fL("butNoNo"))) return;}
    if (gAuto && gPlay) fAutoPaus();
    fWindLogoHide();
    fWindClear();
    fRowsFramPosi();
    fRowsShow(1);
    fRowsClear();
    fSettClos();
    diaGrid->fRePosi();
    fGridEditEnab();
    if (gFileInfo) {diaInfo->close();gFileInfo=false;}
    if (gHelpDial) {diaHelp->close();gHelpDial=false;}
    gPlay=false;
    gInit=false;
    gAcce=0;
    gJump=0;
    labTime->setText("00:00:00");
    labPuls->setText("");
    labJump->setText("");
    if (gGridShow) griText->setCurrentCell(0,1);
}
void winMain::fClearGrid()
{
    messSkin cM;
    if (!cM.fMess(this,fraMenu,fL("msgCleaGridMess"),fL("butYeYe"),fL("butNoNo"))) return;
    if (gAuto && gPlay) fAutoPaus();
    fWindLogoHide();
    fWindClear();
    fRowsShow(1);
    fRowsClear();
    fSettClos();
    fGridEditEnab();
    if (gFileInfo) {diaInfo->close();gFileInfo=false;}
    if (gHelpDial) {diaHelp->close();gHelpDial=false;}
    gPlay=false;
    gInit=false;
    gAcce=0;
    gJump=0;
    labTime->setText("00:00:00");
    labPuls->setText("");
    labJump->setText("");
    if (gGridShow) griText->setCurrentCell(0,1);
}

void winMain::keyPressEvent(QKeyEvent *qe)
{
    if (qe->modifiers()==Qt::NoModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_N:         {fRowsShow(-1);break;}
            case Qt::Key_P:         {fAutoAcce();break;}
            case Qt::Key_Plus:      {fAutoAcce();break;}
            case Qt::Key_M:         {fAutoDece();break;}
            case Qt::Key_Minus:     {fAutoDece();break;}
            case Qt::Key_F1:        {fHelpDial();break;}
            case Qt::Key_PageUp:    {fRowsLocU();break;}
            case Qt::Key_PageDown:  {fRowsLocD();break;}
            case Qt::Key_Home:      {fRowsLocL();break;}
            case Qt::Key_End:       {fRowsLocR();break;}
            case Qt::Key_Up:        {fButtPrev();break;}
            case Qt::Key_Down:      {fButtNext();break;}
            case Qt::Key_Left:      {fAutoBack();break;}
            case Qt::Key_Right:     {fAutoJump();break;}
            case Qt::Key_Space:     {gAuto ? fAutoStar():fButtNext();break;}
            default: {QWidget::keyPressEvent(qe);}
        }
    }
    else if (qe->modifiers()==Qt::ShiftModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_Plus:      {fAutoAcce();break;}
            case Qt::Key_PageUp:    {fRowsLocUFast();break;}
            case Qt::Key_PageDown:  {fRowsLocDFast();break;}
            case Qt::Key_Home:      {fRowsLocLFast();break;}
            case Qt::Key_End:       {fRowsLocRFast();break;}
            default: {QWidget::keyPressEvent(qe);}
        }
    }
    else if (qe->modifiers()==Qt::ControlModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_X:         {fWindExitDial();break;}
            case Qt::Key_O:         {fFileDial();break;}
            case Qt::Key_S:         {fSettShow();break;}
            case Qt::Key_R:         {fClearGrid();break;}
            case Qt::Key_I:         {fFileInfoDial();break;}
            case Qt::Key_E:         {fGridEditButt();break;}
            case Qt::Key_Z:         {fGridUndo();break;}
            case Qt::Key_Up:        {fRowsLocU();break;}
            case Qt::Key_Down:      {fRowsLocD();break;}
            case Qt::Key_Left:      {fRowsLocL();break;}
            case Qt::Key_Right:     {fRowsLocR();break;}
            default: {QWidget::keyPressEvent(qe);}
        }
    }
    else if (qe->modifiers()==Qt::AltModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_R:         {fClearAll(true);break;}
            default: {QWidget::keyPressEvent(qe);}
        }
    }
    else if (qe->modifiers()==Qt::KeypadModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_Plus:      {fAutoAcce();break;}
            case Qt::Key_Minus:     {fAutoDece();break;}
            case Qt::Key_Period:    {fRowsShow(-1);break;}
            case Qt::Key_9:         {fRowsLocU();break;}
            case Qt::Key_3:         {fRowsLocD();break;}
            case Qt::Key_7:         {fRowsLocL();break;}
            case Qt::Key_1:         {fRowsLocR();break;}
            case Qt::Key_8:         {fButtPrev();break;}
            case Qt::Key_2:         {fButtNext();break;}
            case Qt::Key_4:         {fAutoBack();break;}
            case Qt::Key_6:         {fAutoJump();break;}
            case Qt::Key_0:         {gAuto ? fAutoStar():fButtNext();break;}
            default: {QWidget::keyPressEvent(qe);}
        }
    }
    else
    {
        switch (qe->key())
        {
            case Qt::Key_Return:    {break;}
            case Qt::Key_Enter:     {break;}
            case Qt::Key_Tab:       {break;}
            default: {QWidget::keyPressEvent(qe);}
        }
    }
}

void winMain::fConfConf(QString sVari,QString sValu)
{
    bool ok;
    int iV;
    bool bV;
    QString sV;

    if (sVari=="Lang")
    {
        gLang=sValu.toInt(&ok,10);
        if (gLang<0 || gLang>1) gLang=0;
        if (gLang==0) radLangEngl->setChecked(true);
        else radLangOthe->setChecked(true);
        return;
    }
    if (sVari=="MenuLink")
    {
        bV=sValu=="true" ? true:false;
        diaGrid->bLink=bV;
        if (!bV) butGridLink->setIcon(QPixmap(":/Imag/QSTit_link_done.png"));
        return;
    }
    if (sVari=="Menu-X")        {fraMenu->iX=sValu.toInt(&ok,10);fraMenu->move(fraMenu->iX,fraMenu->iY);return;}
    if (sVari=="Menu-Y")        {fraMenu->iY=sValu.toInt(&ok,10);fraMenu->move(fraMenu->iX,fraMenu->iY);return;}
    if (sVari=="Menu-W")        {fraMenu->iW=gMenuWidt;fraMenu->iX=(gWindWidt-gMenuWidt)/2;fraMenu->move(fraMenu->iX,fraMenu->iY);return;}
    if (sVari=="Menu-H")        {fraMenu->iH=sValu.toInt(&ok,10);return;}
    if (sVari=="RowsNumb")      {gRowsNumb=sValu.toInt(&ok,10);if (gRowsNumb<1 || gRowsNumb>4) gRowsNumb=4;return;}
    if (sVari=="Row1Show")      {bV=sValu=="true" ? true:false;radRow1->setChecked(bV);return;}
    if (sVari=="Row2Show")      {bV=sValu=="true" ? true:false;radRow2->setChecked(bV);return;}
    if (sVari=="Row3Show")      {bV=sValu=="true" ? true:false;radRow3->setChecked(bV);return;}
    if (sVari=="Row4Show")      {bV=sValu=="true" ? true:false;radRow4->setChecked(bV);return;}
    if (sVari=="RowsSpac")      {iV=sValu.toInt(&ok,10);if (iV<1 || iV>50) iV=1;spiRowsSpac->setValue(iV);return;}
    if (sVari=="Row1Spac")      {iV=sValu.toInt(&ok,10);if (iV<0 || iV>50) iV=1;objRow1.spac=iV;return;}
    if (sVari=="Row2Spac")      {iV=sValu.toInt(&ok,10);if (iV<0 || iV>50) iV=1;objRow2.spac=iV;return;}
    if (sVari=="Row3Spac")      {iV=sValu.toInt(&ok,10);if (iV<0 || iV>50) iV=1;objRow3.spac=iV;return;}
    if (sVari=="Row4Spac")      {iV=sValu.toInt(&ok,10);if (iV<0 || iV>50) iV=1;objRow4.spac=iV;return;}
    if (sVari=="RowsHone")      {gRowsHone=sValu.toInt(&ok,10);if (gRowsHone<10 || gRowsHone>90) gRowsHone=30;return;}
    if (sVari=="Row1Heig")      {iV=sValu.toInt(&ok,10);if (iV<0 || iV>90) iV=30;objRow1.heig=iV;return;}
    if (sVari=="Row2Heig")      {iV=sValu.toInt(&ok,10);if (iV<0 || iV>90) iV=30;objRow2.heig=iV;return;}
    if (sVari=="Row3Heig")      {iV=sValu.toInt(&ok,10);if (iV<0 || iV>90) iV=30;objRow3.heig=iV;return;}
    if (sVari=="Row4Heig")      {iV=sValu.toInt(&ok,10);if (iV<0 || iV>90) iV=30;objRow4.heig=iV;return;}
    if (sVari=="Rows-X")        {fraRows->iX=sValu.toInt(&ok,10);return;}
    if (sVari=="Rows-Y")        {fraRows->iY=sValu.toInt(&ok,10);return;}
    if (sVari=="Rows-W")        {fraRows->iW=sValu.toInt(&ok,10);return;}
    if (sVari=="Row1FontName")  {objRow1.font.setFamily(sValu);return;}
    if (sVari=="Row2FontName")  {objRow2.font.setFamily(sValu);return;}
    if (sVari=="Row3FontName")  {objRow3.font.setFamily(sValu);return;}
    if (sVari=="Row4FontName")  {objRow4.font.setFamily(sValu);return;}
    if (sVari=="Row1FontSize")  {iV=sValu.toInt(&ok,10);objRow1.font.setPointSize(iV);return;}
    if (sVari=="Row2FontSize")  {iV=sValu.toInt(&ok,10);objRow2.font.setPointSize(iV);return;}
    if (sVari=="Row3FontSize")  {iV=sValu.toInt(&ok,10);objRow3.font.setPointSize(iV);return;}
    if (sVari=="Row4FontSize")  {iV=sValu.toInt(&ok,10);objRow4.font.setPointSize(iV);return;}
    if (sVari=="Row1FontWeig")  {iV=sValu.toInt(&ok,10);objRow1.font.setWeight(iV);return;}
    if (sVari=="Row2FontWeig")  {iV=sValu.toInt(&ok,10);objRow2.font.setWeight(iV);return;}
    if (sVari=="Row3FontWeig")  {iV=sValu.toInt(&ok,10);objRow3.font.setWeight(iV);return;}
    if (sVari=="Row4FontWeig")  {iV=sValu.toInt(&ok,10);objRow4.font.setWeight(iV);return;}
    if (sVari=="Row1FontItal")  {bV=sValu=="true" ? true:false;objRow1.font.setItalic(bV);return;}
    if (sVari=="Row2FontItal")  {bV=sValu=="true" ? true:false;objRow2.font.setItalic(bV);return;}
    if (sVari=="Row3FontItal")  {bV=sValu=="true" ? true:false;objRow3.font.setItalic(bV);return;}
    if (sVari=="Row4FontItal")  {bV=sValu=="true" ? true:false;objRow4.font.setItalic(bV);return;}
    if (sVari=="Row1TextColo")  {sV=sValu;if (sV.length() != 7 || !sV.startsWith("#")) sV="#ffffff";objRow1.colF=sV;return;}
    if (sVari=="Row2TextColo")  {sV=sValu;if (sV.length() != 7 || !sV.startsWith("#")) sV="#ffffff";objRow2.colF=sV;return;}
    if (sVari=="Row3TextColo")  {sV=sValu;if (sV.length() != 7 || !sV.startsWith("#")) sV="#ffffff";objRow3.colF=sV;return;}
    if (sVari=="Row4TextColo")  {sV=sValu;if (sV.length() != 7 || !sV.startsWith("#")) sV="#ffffff";objRow4.colF=sV;return;}
    if (sVari=="Row1BackColo")  {sV=sValu;if (sV.length() != 7 || !sV.startsWith("#")) sV="#000000";objRow1.colB=sV;return;}
    if (sVari=="Row2BackColo")  {sV=sValu;if (sV.length() != 7 || !sV.startsWith("#")) sV="#000000";objRow2.colB=sV;return;}
    if (sVari=="Row3BackColo")  {sV=sValu;if (sV.length() != 7 || !sV.startsWith("#")) sV="#000000";objRow3.colB=sV;return;}
    if (sVari=="Row4BackColo")  {sV=sValu;if (sV.length() != 7 || !sV.startsWith("#")) sV="#000000";objRow4.colB=sV;return;}
    if (sVari=="Grid-X")        {diaGrid->iX=sValu.toInt(&ok,10);diaGrid->move(diaGrid->iX,diaGrid->iY);return;}
    if (sVari=="Grid-Y")        {diaGrid->iY=sValu.toInt(&ok,10);diaGrid->move(diaGrid->iX,diaGrid->iY);return;}
    if (sVari=="Grid-W")        {diaGrid->iW=sValu.toInt(&ok,10);return;}
    if (sVari=="Grid-H")        {diaGrid->iH=sValu.toInt(&ok,10);return;}
    if (sVari=="GridFontFami")  {gGridFont.setFamily(sValu);return;}
    if (sVari=="GridFontSize")  {iV=sValu.toInt(&ok,10);gGridFont.setPointSize(iV);return;}
    if (sVari=="TextOutlColo")  {sV=sValu;if (sV.length() != 7 || !sV.startsWith("#")) sV="#eeeeee";gOutlColo=QColor(sV);return;}
    if (sVari=="TextOutlThik")  {gOutlThik=sValu.toInt(&ok,10);if (gOutlThik<0 && gOutlThik>10) gOutlThik=0;return;}
    if (sVari=="TextSecoText")  {gSecoText=sValu=="true" ? true:false;if (gSecoText) chkSecoText->setChecked(true);return;}
    if (sVari=="TextSecoItal")  {gSecoItal=sValu=="true" ? true:false;if (gSecoItal) chkSecoItal->setChecked(true);return;}
    if (sVari=="TextHoriAlig")
    {
        sV=sValu;
        if (sV != "l" && sV != "c" && sV != "r") sV="c";
        if (sV=="l") radLeft->setChecked(true);
        if (sV=="c") radCenH->setChecked(true);
        if (sV=="r") radRigh->setChecked(true);
        return;
    }
    if (sVari=="TextVertAlig")
    {
        sV=sValu;
        if (sV != "t" && sV != "c" && sV != "b") sV="t";
        if (sV=="t") radTopy->setChecked(true);
        if (sV=="c") radCenV->setChecked(true);
        if (sV=="b") radBott->setChecked(true);
        return;
    }
    if (sVari=="JumpBase")
    {
        gJumpBase=sValu.toInt(&ok,10);
        spiJumpBase->setValue(gJumpBase/100);
        return;
    }
}
void winMain::fConfRead()
{
    QString sLine;
    QStringList lText;
    QStringList lValu;
    QString sVari;
    QString sValu;

    oConf.setFileName(gConf);
    if (!oConf.open(QIODevice::ReadOnly|QIODevice::Text)) return;
    while (!oConf.atEnd())
    {
        sLine=fFileLineForm(oConf.readLine());
        if(!sLine.isEmpty())
        {
            lText=sLine.split(QString("="));
            sVari=lText[0].trimmed();
            lValu=lText[1].split(QString("'"));
            sValu=lValu[0].trimmed();
            fConfConf(sVari,sValu);
        }
    }
    oConf.close();

    int iX=fraRows->iX;
    int iY=fraRows->iY;
    if (gLang==1) fLAll();
    fRowsAdapt();
    fraRows->iX=iX;
    fraRows->iY=iY;
    fRowsFramCent();
    gRowsHcenPrev=gRowsHcen;
    gRowsVcenPrev=gRowsVcen;
    fRowsNumb();
    fGridFontSize();
}
void winMain::fConfWrit()
{
    QString sConf="";
    int iSize=gFile.size();
    QString sText="";

    if (radExitSavN->isChecked()) return;
    if (radExitSavP->isChecked()) sConf=gConf;
    if (radExitSavF->isChecked()) sConf=gFile.mid(0,iSize-4)+QString(".cfg");

    oConf.setFileName(sConf);
    if (!oConf.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    sText+=fConfWritLine(QString("Lang=%1").arg(gLang),                                         "0=english,1=other (from QSTit_Lang.txt)");
    sText+=fConfWritLine(QString("MenuLink=%1").arg(diaGrid->bLink ? "true":"false"),           "menu linked to grid");
    sText+=fConfWritLine(QString("Menu-X=%1").arg(fraMenu->iX),                                 "menu left");
    sText+=fConfWritLine(QString("Menu-Y=%1").arg(fraMenu->iY),                                 "menu top");
    sText+=fConfWritLine(QString("Menu-W=%1").arg(fraMenu->iW),                                 "menu width");
    sText+=fConfWritLine(QString("Menu-H=%1").arg(fraMenu->iH),                                 "menu height");
    sText+=fConfWritLine(QString("RowsNumb=%1").arg(gRowsNumb),                                 "number of rows (min=1,max=4)");
    sText+=fConfWritLine(QString("Row1Show=%1").arg(objRow1.show ? "true":"false"),             "row 1 shown");
    sText+=fConfWritLine(QString("Row2Show=%1").arg(objRow2.show ? "true":"false"),             "row 2 shown");
    sText+=fConfWritLine(QString("Row3Show=%1").arg(objRow3.show ? "true":"false"),             "row 3 shown");
    sText+=fConfWritLine(QString("Row4Show=%1").arg(objRow4.show ? "true":"false"),             "row 4 shown");
    sText+=fConfWritLine(QString("RowsSpac=%1").arg(gRowsSpac),                                 "space between rows (min=1,max=50)");
    sText+=fConfWritLine(QString("Row1Spac=%1").arg(objRow1.spac),                              "row 1 spacing");
    sText+=fConfWritLine(QString("Row2Spac=%1").arg(objRow2.spac),                              "row 2 spacing");
    sText+=fConfWritLine(QString("Row3Spac=%1").arg(objRow3.spac),                              "row 3 spacing");
    sText+=fConfWritLine(QString("RowsHone=%1").arg(gRowsHone),                                 "height of one row (default=30)");
    sText+=fConfWritLine(QString("Row1Heig=%1").arg(objRow1.heig),                              "row 1 height");
    sText+=fConfWritLine(QString("Row2Heig=%1").arg(objRow2.heig),                              "row 2 height");
    sText+=fConfWritLine(QString("Row3Heig=%1").arg(objRow3.heig),                              "row 3 height");
    sText+=fConfWritLine(QString("Row4Heig=%1").arg(objRow4.heig),                              "row 4 height");
    sText+=fConfWritLine(QString("Rows-X=%1").arg(fraRows->iX),                                 "rows frame left (default=1)");
    sText+=fConfWritLine(QString("Rows-Y=%1").arg(fraRows->iY),                                 "rows frame top (default=1)");
    sText+=fConfWritLine(QString("Rows-W=%1").arg(fraRows->iW),                                 "rows frame width");
    sText+=fConfWritLine(QString("Row1FontName=%1").arg(objRow1.font.family()),                 "row1 font");
    sText+=fConfWritLine(QString("Row1FontSize=%1").arg(objRow1.font.pointSize()),              "row1 font size");
    sText+=fConfWritLine(QString("Row1FontWeig=%1").arg(objRow1.font.weight()),                 "row1 font weight");
    sText+=fConfWritLine(QString("Row1FontItal=%1").arg(objRow1.font.italic() ? "true":"false"),"row1 font italic");
    sText+=fConfWritLine(QString("Row1TextColo=%1").arg(objRow1.colF.name()),                   "row1 text color (default=white)");
    sText+=fConfWritLine(QString("Row1BackColo=%1").arg(objRow1.colB.name()),                   "row1 backcolor (default=black)");
    sText+=fConfWritLine(QString("Row2FontName=%1").arg(objRow2.font.family()),                 "row2 font");
    sText+=fConfWritLine(QString("Row2FontSize=%1").arg(objRow2.font.pointSize()),              "row2 font size");
    sText+=fConfWritLine(QString("Row2FontWeig=%1").arg(objRow2.font.weight()),                 "row2 font weight");
    sText+=fConfWritLine(QString("Row2FontItal=%1").arg(objRow2.font.italic() ? "true":"false"),"row2 font italic");
    sText+=fConfWritLine(QString("Row2TextColo=%1").arg(objRow2.colF.name()),                   "row2 text color (default=white)");
    sText+=fConfWritLine(QString("Row2BackColo=%1").arg(objRow2.colB.name()),                   "row2 backcolor (default=black)");
    sText+=fConfWritLine(QString("Row3FontName=%1").arg(objRow3.font.family()),                 "row3 font");
    sText+=fConfWritLine(QString("Row3FontSize=%1").arg(objRow3.font.pointSize()),              "row3 font size");
    sText+=fConfWritLine(QString("Row3FontWeig=%1").arg(objRow3.font.weight()),                 "row3 font weight");
    sText+=fConfWritLine(QString("Row3FontItal=%1").arg(objRow3.font.italic() ? "true":"false"),"row3 font italic");
    sText+=fConfWritLine(QString("Row3TextColo=%1").arg(objRow3.colF.name()),                   "row3 text color (default=white)");
    sText+=fConfWritLine(QString("Row3BackColo=%1").arg(objRow3.colB.name()),                   "row3 backcolor (default=black)");
    sText+=fConfWritLine(QString("Row4FontName=%1").arg(objRow4.font.family()),                 "row4 font");
    sText+=fConfWritLine(QString("Row4FontSize=%1").arg(objRow4.font.pointSize()),              "row4 font size");
    sText+=fConfWritLine(QString("Row4FontWeig=%1").arg(objRow4.font.weight()),                 "row4 font weight");
    sText+=fConfWritLine(QString("Row4FontItal=%1").arg(objRow4.font.italic() ? "true":"false"),"row4 font italic");
    sText+=fConfWritLine(QString("Row4TextColo=%1").arg(objRow4.colF.name()),                   "row4 text color (default=white)");
    sText+=fConfWritLine(QString("Row4BackColo=%1").arg(objRow4.colB.name()),                   "row4 backcolor (default=black)");
    sText+=fConfWritLine(QString("Grid-X=%1").arg(diaGrid->iX),                                 "grid frame left");
    sText+=fConfWritLine(QString("Grid-Y=%1").arg(diaGrid->iY),                                 "grid frame top");
    sText+=fConfWritLine(QString("Grid-W=%1").arg(diaGrid->iW),                                 "grid frame width");
    sText+=fConfWritLine(QString("Grid-H=%1").arg(diaGrid->iH),                                 "grid frame height");
    sText+=fConfWritLine(QString("GridFontFami=%1").arg(gGridFont.family()),                    "grid font");
    sText+=fConfWritLine(QString("GridFontSize=%1").arg(gGridFont.pointSize()),                 "grid font size");
    sText+=fConfWritLine(QString("TextOutlColo=%1").arg(gOutlColo.name()),                      "text outline color");
    sText+=fConfWritLine(QString("TextOutlThik=%1").arg(gOutlThik),                             "text outline thickness");
    sText+=fConfWritLine(QString("TextSecoText=%1").arg(gSecoText ? "true":"false"),            "Single text line displayed on row 2");
    sText+=fConfWritLine(QString("TextSecoItal=%1").arg(gSecoItal ? "true":"false"),            "Second text line in italic");
    if (radLeft->isChecked()) sText+=fConfWritLine("TextHoriAlig=l",                            "text alignment horiz. left");
    if (radCenH->isChecked()) sText+=fConfWritLine("TextHoriAlig=c",                            "text alignment horiz. center");
    if (radRigh->isChecked()) sText+=fConfWritLine("TextHoriAlig=r",                            "text alignment horiz. right");
    if (radTopy->isChecked()) sText+=fConfWritLine("TextVertAlig=t",                            "text alignment vert. top");
    if (radCenV->isChecked()) sText+=fConfWritLine("TextVertAlig=c",                            "text alignment vert. center");
    if (radBott->isChecked()) sText+=fConfWritLine("TextVertAlig=b",                            "text alignment vert. bottom");
    sText+=fConfWritLine(QString("JumpBase=%1").arg(gJumpBase),                                 "jump base");

    oConf.write(sText.toAscii());
    oConf.close();
}
QString winMain::fConfWritLine(QString sText,QString sComm)
{
    QString sLine=sText+QString(39,' ');
    sLine.resize(39);
    sLine+="' "+sComm+"\n";
    return sLine;
}

//=================================================================================================
// manual
//=================================================================================================

void winMain::fManuInit()
{
    gManu=true;
    gShow=true;
    gShowButt=true;
    gRows=griText->currentRow();
    fMenuAdapt(1);
    griText->setFocus();
    griText->setCurrentCell(0,1);
}
void winMain::fButtPrev()
{
    if (!gGridShow) return;
    if (gShow)
    {
        if (griText->currentRow()>0)
        {
            if (!gShowButt)
            {
                gRows=griText->currentRow()-1;
                griText->setCurrentCell(gRows,1);
                griText->scrollTo(griText->currentIndex(),QAbstractItemView::PositionAtCenter);
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
    gShow=!gShow;
    gShowButt=false;
}
void winMain::fButtNext()
{
    if (!gGridShow) return;
    if (gShow)
    {
        if (griText->currentRow()<gRowsMaxi)
        {
            if (gShowButt)
            {
                gRows=griText->currentRow()+1;
                griText->setCurrentCell(gRows,1);
                griText->scrollTo(griText->currentIndex(),QAbstractItemView::PositionAtCenter);
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
    gShow=!gShow;
    gShowButt=true;
}

//=================================================================================================
// automatic
//=================================================================================================

void winMain::fAutoInit()
{
    gAuto=true;
    gShow=true;
    gShowButt=true;
    gRows=griText->currentRow();
    gPlay=false;
    gInit=false;
    gRows=0;
    gAcce=0;
    gJump=0;
    fMenuAdapt(2);
    diaGrid->fRePosi();
    griText->setFocus();
    griText->setCurrentCell(0,1);
}
void winMain::fAutoPaus()
{
    fGridEditEnab();
    butProjPlay->setIcon(QPixmap(":/Imag/QSTit_play.png"));
    tmrAuto->stop();
}
void winMain::fAutoStar()
{
    gPlay=!gPlay;
    if (!gPlay) {fAutoPaus();return;}
    if (gHelpDial) {diaHelp->close();gHelpDial=false;}
    if (gFileInfo) {diaInfo->close();gFileInfo=false;}
    fGridEditDisa();
    butProjPlay->setIcon(QPixmap(":/Imag/QSTit_paus.png"));
    fRowsShow(1);
    if (!gInit)
    {
        fAutoStarInit();
        tmrAuto=new QTimer(this);
        connect(tmrAuto,SIGNAL(timeout()),this,SLOT(fAutoClok()));
        tmrAuto->start(gPuls);
        gInit=true;
    }
    else
    {
        tmrAuto->start();
    }
}
void winMain::fAutoStarInit()
{
    gRows=griText->currentRow();
    if (gRows==0){gRows=1;griText->setCurrentCell(gRows,1);}
    fAutoTimeInit();
}
void winMain::fAutoTimeInit()
{
    timAuto.setHMS(0,0,0,0);
    QString sT=griText->item(gRows,1)->text();
    if (!sT.isEmpty()) timAuto=fAutoTimeConv(sT);
    labTime->setText(timAuto.toString("hh:mm:ss"));
}
QTime winMain::fAutoTimeConv(QString sT)
{
    int iH=sT.mid(0,2).toInt();
    int iM=sT.mid(3,2).toInt();
    int iS=sT.mid(6,2).toInt();
    int iX=sT.mid(9,3).toInt();
    if (iH==99) {iH=0;iM=0;iS=0;iX=0;}
    QTime tR(iH,iM,iS,iX);
    return tR;
}
void winMain::fAutoClok()
{
    static int iJumpShow=0;
    int iBeat=gPuls+gAcce;
    double dJump=(double)gJumpBase/1000;

    timAuto=timAuto.addMSecs(iBeat+gJump);
    labTime->setText(timAuto.toString("hh:mm:ss"));
    fAutoAcceShow();
    if (gJump==0)
    {
        if (iJumpShow==0) labJump->setText("");
        else iJumpShow--;
    }
    else
    {
        if (gJump>0) {labJump->setText(QString("+%1").arg(dJump,0,'f',1));}
        else {labJump->setText(QString("-%1").arg(dJump,0,'f',1));fAutoJumpBack();}
        iJumpShow=25;
    }
    gJump=0;
    fAutoGridShow();
}
void winMain::fAutoAcceShow()
{
    int iBeat=gPuls+gAcce;
    double dBeat=(double)iBeat/(double)gPuls;
    if (dBeat==1) labPuls->setText("");
    else labPuls->setText(QString("%1").arg(dBeat,0,'f',2));
}
void winMain::fAutoJumpBack()
{
    int iPrev=gRows-1;if (iPrev<1) return;
    timStar=fAutoTimeConv(griText->item(iPrev,1)->text());
    timStop=fAutoTimeConv(griText->item(iPrev,2)->text());
    if (timAuto>=timStar  && timAuto<timStop) gRows=iPrev;
}
void winMain::fAutoGridShow()
{
    if (gRows>gRowsMaxi) {gRows=gRowsMaxi;griText->setCurrentCell(gRows,1);fRowsClear();gPlay=false;fAutoPaus();return;}
    timStop=fAutoTimeConv(griText->item(gRows,2)->text());
    if (timAuto>timStop) {fRowsClear();gRows++;return;}
    timStar=fAutoTimeConv(griText->item(gRows,1)->text());
    if (timAuto>=timStar) {griText->setCurrentCell(gRows,1);griText->scrollTo(griText->currentIndex(),QAbstractItemView::PositionAtCenter);}
}
void winMain::fAutoAcce() {if (gAcce<800) gAcce+=1;fAutoAcceShow();}
void winMain::fAutoDece() {if (gAcce>-50) gAcce-=1;fAutoAcceShow();}
void winMain::fJumpBase(int iJ) {gJumpBase=iJ*100;}
void winMain::fAutoJump() {if (gPlay) gJump=gJumpBase;}
void winMain::fAutoBack() {if (gPlay) gJump=-1*gJumpBase;}
/*
    ════════════════════════════════════════════════════════════════════════════════
    Code analysis/programming:  Georges Piedboeuf-Boen  georges.pi.bo@gmail.com
    Functional analysis:        Laurent Tenzer          lt@nova-cinema.org
    Project origin:             Cinéma Nova             http://www.nova-cinema.org
    Made in Brussels            Belgium                 http://www.brussels.be
    ════════════════════════════════════════════════════════════════════════════════
*/
