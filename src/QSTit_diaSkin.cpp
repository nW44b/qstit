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

#include "QSTit_diaSkin.h"

int fCalcPosX(int iWidt)
{
    int iPr=QApplication::desktop()->width();
    return (iPr-iWidt)/2;
}
int fCalcPosY(int iHeig,QFrame *parMen)
{
    int iPm=QApplication::desktop()->height()/2;
    if(parMen->frameGeometry().y()>iPm) {return parMen->frameGeometry().y()-iHeig;}
    else {return parMen->frameGeometry().bottom()+1;}
}
QString fStylFram()
{
    return "font:normal 11px "+qApp->font().family()+";background-color:#151515;color:#ffffff;border:1px solid #0055aa;border-radius:3px;";
}
QString fStylTitl()
{
    return "font:bold;color:#0055aa;padding-left:7px;";
}
QString fStylButt()
{
    return "height:20px;width:40px;background-color:#202020;color:#ffffff;border:1px solid #202020;border-radius:3px;text-align:left;padding-left:2px;";
}
QString fStylClos()
{
    return "QToolButton {image:url(:/Imag/QSTit_clos.png);border:none;} QToolButton:hover {image:url(:/Imag/QSTit_clos_over.png);}";
}
void fWait(int ms)
{
    #ifdef Q_OS_WIN
        Sleep(uint(ms));
    #else
        struct timespec ts={ ms/1000,(ms%1000)*1000*1000};
        nanosleep(&ts,NULL);
    #endif
}
//-------------------------------------------------------------------------------------------------

rowSkin::rowSkin(QWidget *parent,int pWidt,int pHeig) : QFrame(parent)
{
    parWin=parent;

    iW=pWidt;
    iH=pHeig;
    iX=1;
    iY=1;

    iPr=QApplication::desktop()->width()-1;
    iPb=QApplication::desktop()->height()-1;
    iPm=QApplication::desktop()->height()/2;

    this->setStyleSheet("border:none;border-radius:0px;");
    this->setFrameShape(QFrame::NoFrame);
    this->setContentsMargins(0,0,0,0);
    this->setCursor(QCursor(QPixmap(":/Imag/QSTit_curH.png"),-1,-1));
    this->setGeometry(iX,iY,iW,iH);
    this->show();
    this->raise();
}
void rowSkin::mousePressEvent(QMouseEvent *e)
{
    iCx=e->globalX();
    iCy=e->globalY();
}
void rowSkin::mouseMoveEvent(QMouseEvent *e)
{
    int jX=iX+e->globalX()-iCx;
    if (jX<1) jX=1;
    if (jX>iPr-iW) jX=iPr-iW;
    int jY=iY+e->globalY()-iCy;
    if (jY<1) jY=1;
    if (jY>iPb-iH) jY=iPb-iH;
    iX=jX;
    iY=jY;
    this->move(iX,iY);
    iCx=e->globalX();
    iCy=e->globalY();
    emit sMoved();
}
void rowSkin::keyPressEvent(QKeyEvent *e)
{
    QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, e->key(),e->modifiers(),"",false,1));
}

//-------------------------------------------------------------------------------------------------

menuSkin::menuSkin(QWidget *parent,int pWidt,int pHeig,int pLefx,int pTopy) : QFrame(parent)
{
    parWin=parent;
    iX=pLefx;
    iY=pTopy;
    iW=pWidt;
    iH=pHeig;
    bLink=true;

    iPr=QApplication::desktop()->width()-1;
    iPb=QApplication::desktop()->height()-1;
    iPm=QApplication::desktop()->height()/2;

    if (iX==-1) iX=(QApplication::desktop()->width()-pWidt)/2;
    if (iY==-1) iY=QApplication::desktop()->height()-pHeig-1;

    this->setStyleSheet("background-color:#101010;color:#ffffff;border:none;");
    this->setFrameShape(QFrame::NoFrame);
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(iX,iY,iW,iH);
    this->setFocusPolicy(Qt::NoFocus);                  // important for keyboard events
    this->show();
    this->raise();
}
void menuSkin::mousePressEvent(QMouseEvent *e)
{
    iCx=e->globalX();
    iCy=e->globalY();
    this->raise();
    this->setFocus();
}
void menuSkin::mouseMoveEvent(QMouseEvent *e)
{
    if(bLink) return;
    int jX=iX+e->globalX()-iCx;
    if (jX<1) jX=1;
    if (jX>iPr-iW) jX=iPr-iW;
    int jY=iY+e->globalY()-iCy;
    if (jY<1) jY=1;
    if (jY>iPb-iH) jY=iPb-iH;
    iX=jX;
    iY=jY;
    this->move(iX,iY);
    iCx=e->globalX();
    iCy=e->globalY();
    emit sMoved();
}
void menuSkin::keyPressEvent(QKeyEvent *e)
{
    QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, e->key(),e->modifiers(),"",false,1));
}

//-------------------------------------------------------------------------------------------------

diaSkin::diaSkin(QWidget *parent,QFrame *menu,QString pTitl,int pWidt,int pHeig,int pLefx,int pTopy) : QFrame(parent)
{
    parWin=parent;
    parMen=menu;
    int iLefx=pLefx;
    int iTopy=pTopy;

    iPr=QApplication::desktop()->width()-1;
    iPb=QApplication::desktop()->height()-1;
    iPm=QApplication::desktop()->height()/2;

    if (iLefx==-1) iLefx=fCalcPosX(pWidt);
    if (iTopy==-1) iTopy=fCalcPosY(pHeig,parMen);

    this->setStyleSheet(fStylFram());
    this->setMinimumSize(QSize(pWidt,pHeig));
    this->setMaximumSize(QSize(pWidt,pHeig));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(iLefx,iTopy,pWidt,pHeig);

    labTitl = new QLabel(pTitl,this);
    labTitl->setStyleSheet(fStylTitl());
    labTitl->setMinimumSize(pWidt,30);
    labTitl->move(0,0);

    QToolButton *butClos=new QToolButton(this);
    butClos->setStyleSheet(fStylClos());
    butClos->setContentsMargins(0,0,0,0);
    butClos->resize(16,16);
    butClos->move(pWidt-22,7);
    butClos->setAutoRepeat(false);
    connect(butClos,SIGNAL(clicked()),this,SLOT(fGridClos()));

    this->hide();
}
void diaSkin::fGridClos()
{
    emit sClosed();
    this->close();
}
void diaSkin::fRePosi()
{
    int iX=fCalcPosX(this->frameGeometry().width());
    int iY=fCalcPosY(this->frameGeometry().height(),parMen);
    this->move(iX,iY);
}
void diaSkin::mousePressEvent(QMouseEvent *e)
{
    iCx=e->globalX();
    iCy=e->globalY();
    this->raise();
    this->setFocus();
}
void diaSkin::mouseMoveEvent(QMouseEvent *e)
{
    static int iM=0;
    if (++iM%2==0)
    {
        int nFx=this->frameGeometry().x()+e->globalX()-iCx;
        if (nFx<1) nFx=1;
        if (nFx>iPr-this->frameGeometry().width()) nFx=iPr-this->frameGeometry().width();
        int nFy=this->frameGeometry().y()+e->globalY()-iCy;
        if (nFy<1) nFy=1;
        if (nFy>iPb-this->frameGeometry().height()) nFy=iPb-this->frameGeometry().height();
        this->move(nFx,nFy);
        iCx=e->globalX();
        iCy=e->globalY();
        iM=0;
    }
}
void diaSkin::keyPressEvent(QKeyEvent *e)
{
    if (e->key()==Qt::Key_Escape) {fGridClos();}
    else {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, e->key(),e->modifiers(),"",false,1));}
}

//-------------------------------------------------------------------------------------------------

grpSkin::grpSkin(QWidget *parent,int pWidt,int pHeig,int pLefx,int pTopy) : QFrame(parent)
{
    this->setStyleSheet("background-color:#222222;color:#ffffff;border:1px solid #222222;border-radius:3px;");
    this->setMinimumSize(QSize(pWidt,pHeig));
    this->setMaximumSize(QSize(pWidt,pHeig));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(pLefx,pTopy,pWidt,pHeig);
    this->show();
}

//-------------------------------------------------------------------------------------------------

bool messSkin::fMess(QWidget *parent,QFrame *menu,QString sMess,QString sBut1,QString sBut2)
{
    parWin=parent;
    parMen=menu;

    qApp->beep();

    QStringList lMess=sMess.split(QString("|"));

    QString texMess=lMess[0].trimmed()+" ";
    if (lMess.size()>1) texMess+="\n"+lMess[1].trimmed();
    if (lMess.size()>2) texMess+="\n"+lMess[2].trimmed();
    if (lMess.size()>3) texMess+="\n"+lMess[3].trimmed();
    if (lMess.size()>4) texMess+="\n"+lMess[4].trimmed();

    messBox.setParent(parWin);
    messBox.setWindowFlags(Qt::ToolTip);
    messBox.setIcon(QMessageBox::NoIcon);
    messBox.setText(texMess);
    messBox.setStyleSheet("font:normal 11px "+qApp->font().family()+";background-color:#32cd32;color:#000000;border:none;");

    bY=messBox.addButton(sBut1,QMessageBox::YesRole);
    bY->setStyleSheet(fStylButt());
    messBox.setDefaultButton(bY);
    if (!sBut2.isEmpty())
    {
        bN=messBox.addButton(sBut2,QMessageBox::NoRole);
        bN->setStyleSheet(fStylButt());
        messBox.setDefaultButton(bN);
    }
    messBox.show();
    messBox.move(fCalcPosX(messBox.frameGeometry().width()),fCalcPosY(messBox.frameGeometry().height(),parMen));
    messBox.exec();
    bool bRepo=false;
    if (messBox.clickedButton()==bY) bRepo=true;
    return bRepo;
}

//-------------------------------------------------------------------------------------------------

diaColoSkin::diaColoSkin(QWidget *parent,QFrame *menu,QString pTitl,QString pColo) : QFrame(parent)
{
    parWin=parent;
    parMen=menu;

    int pWidt=500;
    int pHeig=380;
    int iLefx=-1;
    int iTopy=-1;

    iPr=QApplication::desktop()->width()-1;
    iPb=QApplication::desktop()->height()-1;
    iPm=QApplication::desktop()->height()/2;

    if (iLefx==-1) iLefx=fCalcPosX(pWidt);
    if (iTopy==-1) iTopy=fCalcPosY(pHeig,parMen);

    this->setStyleSheet(fStylFram());
    this->setMinimumSize(QSize(pWidt,pHeig));
    this->setMaximumSize(QSize(pWidt,pHeig));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(iLefx,iTopy,pWidt,pHeig);
    this->move(iLefx,iTopy);

    QLabel *labTitl = new QLabel(pTitl,this);
    labTitl->setStyleSheet(fStylTitl());
    labTitl->setMinimumSize(pWidt,30);
    labTitl->move(0,0);

    QToolButton *butClos=new QToolButton(this);
    butClos->setStyleSheet(fStylClos());
    butClos->setContentsMargins(0,0,0,0);
    butClos->resize(16,16);
    butClos->move(pWidt-22,7);
    butClos->setAutoRepeat(false);
    connect(butClos,SIGNAL(clicked()),this,SLOT(fGridClos()));

    diaColo=new QColorDialog(this);
    diaColo->setWindowFlags(Qt::SubWindow);
    diaColo->setOption(QColorDialog::DontUseNativeDialog);
    diaColo->setCursor(Qt::ArrowCursor);
    diaColo->setCurrentColor(QColor(pColo));
    diaColo->move(1,30);
    connect(diaColo,SIGNAL(colorSelected(QColor)),this,SLOT(fColorGet(QColor)));
    connect(diaColo,SIGNAL(rejected()),this,SLOT(fGridClos()));

    QString sStyl="QColorDialog {background-color:#151515;border:none;}";
    sStyl+="QWidget {border:none;}";
    sStyl+="QLabel {background-color:#151515;}";
    sStyl+="QPushButton {min-height:20px;max-height:20px;min-width:50px;max-width:110px;background-color:#202020;color:#ffffff;border:1px solid #151515;border-radius:3px;text-align:left;padding-left:5px;}";
    sStyl+="QPushButton:hover {border-color:#0055aa;}";
    sStyl+="QSpinBox {height:24px;color:#ffffff;border:1px solid #777777;background-color:#eeeeee;color:#000000;}";
    sStyl+="QFocusFrame {border:1px solid #eeeeee;}";
    diaColo->setStyleSheet(sStyl);

    diaColo->show();
    this->show();
    this->setFocus();
}
void diaColoSkin::fColorGet(QColor cColo)
{
    diaColo->close();
    this->close();
    emit sColorGet(cColo);
}
void diaColoSkin::fGridClos()
{
    diaColo->close();
    this->close();
    emit sClosed();
}
void diaColoSkin::mousePressEvent(QMouseEvent *event)
{
    iCx=event->globalX();
    iCy=event->globalY();
    this->raise();
    this->setFocus();
}
void diaColoSkin::mouseMoveEvent(QMouseEvent *event)
{
    static int iM=0;
    if (++iM%2==0)
    {
        int nFx=this->frameGeometry().x()+event->globalX()-iCx;
        if (nFx<1) nFx=1;
        if (nFx>iPr-this->frameGeometry().width()) nFx=iPr-this->frameGeometry().width();
        int nFy=this->frameGeometry().y()+event->globalY()-iCy;
        if (nFy<1) nFy=1;
        if (nFy>iPb-this->frameGeometry().height()) nFy=iPb-this->frameGeometry().height();
        this->move(nFx,nFy);
        iCx=event->globalX();
        iCy=event->globalY();
        iM=0;
    }
}
void diaColoSkin::keyPressEvent(QKeyEvent *qe)
{
    if (qe->key()==Qt::Key_Escape) fGridClos();
    else {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, qe->key(),qe->modifiers(),"",false,1));}
}

//-------------------------------------------------------------------------------------------------

diaFontSkin::diaFontSkin(QWidget *parent,QFrame *menu,QString pTitl,QFont pFont) : QFrame(parent)
{
    parWin=parent;
    parMen=menu;

    int pWidt=505;
    int pHeig=395;
    int iLefx=-1;
    int iTopy=-1;

    iPr=QApplication::desktop()->width()-1;
    iPb=QApplication::desktop()->height()-1;
    iPm=QApplication::desktop()->height()/2;

    QString sAppFont=qApp->font().family();

    if (iLefx==-1) iLefx=fCalcPosX(pWidt);
    if (iTopy==-1) iTopy=fCalcPosY(pHeig,parMen);

    this->setStyleSheet("background-color:#151515;color:#ffffff;border:1px solid #0055aa;border-radius:3px;");
    this->setMinimumSize(QSize(pWidt,pHeig));
    this->setMaximumSize(QSize(pWidt,pHeig));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(iLefx,iTopy,pWidt,pHeig);
    this->move(iLefx,iTopy);

    QLabel *labTitl = new QLabel(pTitl,this);
    labTitl->setStyleSheet(fStylTitl());
    labTitl->setMinimumSize(pWidt,30);
    labTitl->move(0,0);

    QToolButton *butClos=new QToolButton(this);
    butClos->setStyleSheet(fStylClos());
    butClos->setContentsMargins(0,0,0,0);
    butClos->resize(16,16);
    butClos->move(pWidt-22,7);
    butClos->setAutoRepeat(false);
    connect(butClos,SIGNAL(clicked()),this,SLOT(fGridClos()));

    diaFont=new QFontDialog(this);
    diaFont->setOption(QFontDialog::DontUseNativeDialog);
    diaFont->setWindowFlags(Qt::SubWindow);
    diaFont->setSizeGripEnabled(false);
    diaFont->setCursor(Qt::ArrowCursor);
    diaFont->setCurrentFont(pFont);
    diaFont->move(1,30);
    connect(diaFont,SIGNAL(fontSelected(QFont)),this,SLOT(fFontGet(QFont)));
    connect(diaFont,SIGNAL(rejected()),this,SLOT(fGridClos()));

    QString sStyl="QFontDialog {background-color:#151515;border:none;}";
    sStyl+="QWidget {border:none;}";
    sStyl+="QLabel {font:normal 11px "+sAppFont+";background-color:#151515;}";
    sStyl+="QPushButton {font:normal 11px "+sAppFont+";min-height:20px;max-height:20px;min-width:50px;max-width:110px;background-color:#202020;color:#ffffff;border:1px solid #151515;border-radius:3px;text-align:left;padding-left:5px;}";
    sStyl+="QPushButton:hover {border-color:#0055aa;}";
    sStyl+="QGroupBox {margin-top:7px;border:1px solid #555555;}";
    sStyl+="QGroupBox::title {font:normal 11px "+sAppFont+";subcontrol-origin:margin;subcontrol-position:top left;border:none;}";
    sStyl+="QComboBox {font:normal 11px "+sAppFont+";background-color:#cccccc;color:#000000;border:none;}";
    sStyl+="QComboBox:editable {background-color:#aaaaaa;color:#000000;border:1px solid #555555;}";
    sStyl+="QComboBox:!editable {background-color:#aaaaaa;color:#000000;border:none;}";
    sStyl+="QComboBox QAbstractItemView {selection-background-color:#aaaaaa;color:#000000;border:none;}";
    sStyl+="QAbstractScrollArea {font:normal 11px "+sAppFont+";background-color:#cccccc;color:#000000;border:1px solid #aaaaaa;}";
    sStyl+="QLineEdit {background-color:#aaaaaa;color:#000000;border:none;selection-background-color:#0055aa;selection-color:#000000;}";
    diaFont->setStyleSheet(sStyl);

    diaFont->show();
    this->show();
    this->setFocus();
}
void diaFontSkin::fFontGet(QFont cFont)
{
    diaFont->close();
    this->close();
    emit sFontGet(cFont);
}
void diaFontSkin::fGridClos()
{
    diaFont->close();
    this->close();
    emit sClosed();
}
void diaFontSkin::mousePressEvent(QMouseEvent *event)
{
    iCx=event->globalX();
    iCy=event->globalY();
    this->raise();
    this->setFocus();
}
void diaFontSkin::mouseMoveEvent(QMouseEvent *event)
{
    static int iM=0;
    if (++iM%2==0)
    {
        int nFx=this->frameGeometry().x()+event->globalX()-iCx;
        if (nFx<1) nFx=1;
        if (nFx>iPr-this->frameGeometry().width()) nFx=iPr-this->frameGeometry().width();
        int nFy=this->frameGeometry().y()+event->globalY()-iCy;
        if (nFy<1) nFy=1;
        if (nFy>iPb-this->frameGeometry().height()) nFy=iPb-this->frameGeometry().height();
        this->move(nFx,nFy);
        iCx=event->globalX();
        iCy=event->globalY();
        iM=0;
    }
}
void diaFontSkin::keyPressEvent(QKeyEvent *qe)
{
    if (qe->key()==Qt::Key_Escape) fGridClos();
    else {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, qe->key(),qe->modifiers(),"",false,1));}
}

//-------------------------------------------------------------------------------------------------

diaFileSkin::diaFileSkin(QWidget *parent,QFrame *menu,QString pTitl,QString pFold,QString pFile,QString pType) : QFrame(parent)
{
    parWin=parent;
    parMen=menu;

    int pWidt=643;
    int pHeig=440;
    int iLefx=-1;
    int iTopy=-1;

    iPr=QApplication::desktop()->width()-1;
    iPb=QApplication::desktop()->height()-1;
    iPm=QApplication::desktop()->height()/2;

    if (iLefx==-1) iLefx=fCalcPosX(pWidt);
    if (iTopy==-1) iTopy=fCalcPosY(pHeig,parMen);

    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setStyleSheet(fStylFram());
    this->setMinimumSize(QSize(pWidt,pHeig));
    this->setMaximumSize(QSize(pWidt,pHeig));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(iLefx,iTopy,pWidt,pHeig);
    this->move(iLefx,iTopy);

    QLabel *labTitl = new QLabel(pTitl,this);
    labTitl->setStyleSheet(fStylTitl());
    labTitl->setMinimumSize(pWidt,30);
    labTitl->move(0,0);

    QToolButton *butClos=new QToolButton(this);
    butClos->setStyleSheet(fStylClos());
    butClos->setContentsMargins(0,0,0,0);
    butClos->resize(16,16);
    butClos->move(pWidt-22,7);
    butClos->setAutoRepeat(false);
    connect(butClos,SIGNAL(clicked()),this,SLOT(fGridClos()));

    diaFile=new QFileDialog(this,"","","Supported (*.srt *.txt)");
    diaFile->setWindowFlags(Qt::SubWindow);
    diaFile->setLabelText(QFileDialog::LookIn,pFold);
    diaFile->setLabelText(QFileDialog::FileName,pFile);
    diaFile->setLabelText(QFileDialog::FileType,pType);
    diaFile->setOption(QFileDialog::DontUseNativeDialog);
    diaFile->setSizeGripEnabled(false);
    diaFile->setCursor(Qt::ArrowCursor);
    diaFile->setFileMode(QFileDialog::ExistingFile);
    diaFile->setViewMode(QFileDialog::Detail);
    diaFile->setAcceptMode(QFileDialog::AcceptOpen);
    diaFile->move(1,30);
    connect(diaFile,SIGNAL(fileSelected(QString)),this,SLOT(fFileGet(QString)));
    connect(diaFile,SIGNAL(rejected()),this,SLOT(fGridClos()));

    QString sStyl="QFileDialog {background-color:#151515;border:none;}";
    sStyl+="QWidget {border:none;}";
    sStyl+="QLabel {background-color:#151515;border:none;}";
    sStyl+="QPushButton {min-height:20px;max-height:20px;min-width:50px;max-width:110px;background-color:#202020;color:#ffffff;border:1px solid #151515;border-radius:3px;text-align:left;padding-left:5px;}";
    sStyl+="QPushButton:hover {border-color:#0055aa;}";
    sStyl+="QGroupBox {margin-top:7px;border:1px solid #555555;}";
    sStyl+="QGroupBox::title {subcontrol-origin:margin;subcontrol-position:top left;border:none;}";
    sStyl+="QComboBox {background-color:#cccccc;color:#000000;border:none;}";
    sStyl+="QComboBox:editable {background-color:#aaaaaa;color:#000000;border:1px solid #555555;}";
    sStyl+="QComboBox:!editable {background-color:#aaaaaa;color:#000000;border:none;}";
    sStyl+="QComboBox QAbstractItemView {selection-background-color:#aaaaaa;color:#000000;border:none;}";
    sStyl+="QHeaderView::section:horizontal {background-color:#aaaaaa;color:#000000;border:none;}";
    sStyl+="QAbstractScrollArea {background-color:#cccccc;color:#000000;border:1px solid #aaaaaa;}";
    sStyl+="QLineEdit {background-color:#aaaaaa;color:#000000;border:none;selection-background-color:#0055aa;selection-color:#000000;}";
    diaFile->setStyleSheet(sStyl);

    diaFile->show();
    this->show();
    this->setFocus();
}
void diaFileSkin::fFileGet(QString cFile)
{
    diaFile->close();
    this->close();
    emit sFileGet(cFile);

}
void diaFileSkin::fGridClos()
{
    diaFile->close();
    this->close();
    emit sClosed();
}
void diaFileSkin::mousePressEvent(QMouseEvent *event)
{
    iCx=event->globalX();
    iCy=event->globalY();
    this->raise();
    this->setFocus();
}
void diaFileSkin::mouseMoveEvent(QMouseEvent *event)
{
    static int iM=0;
    if (++iM%2==0)
    {
        int nFx=this->frameGeometry().x()+event->globalX()-iCx;
        if (nFx<1) nFx=1;
        if (nFx>iPr-this->frameGeometry().width()) nFx=iPr-this->frameGeometry().width();
        int nFy=this->frameGeometry().y()+event->globalY()-iCy;
        if (nFy<1) nFy=1;
        if (nFy>iPb-this->frameGeometry().height()) nFy=iPb-this->frameGeometry().height();
        this->move(nFx,nFy);
        iCx=event->globalX();
        iCy=event->globalY();
        iM=0;
    }
}
void diaFileSkin::keyPressEvent(QKeyEvent *qe)
{
    if (qe->key()==Qt::Key_Escape) fGridClos();
    else {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, qe->key(),qe->modifiers(),"",false,1));}
}

//-------------------------------------------------------------------------------------------------

diaInfoSkin::diaInfoSkin(QWidget *parent,QFrame *menu,QString pTitl,int pWidt,int pHeig,int pLefx,int pTopy) : QFrame(parent)
{
    parWin=parent;
    parMen=menu;

    iPr=QApplication::desktop()->width()-1;
    iPb=QApplication::desktop()->height()-1;
    iPm=QApplication::desktop()->height()/2;

    iW=pWidt;
    iH=pHeig;
    iX=pLefx;if (iX==-1) iX=fCalcPosX(iW);
    iY=pTopy;if (iY==-1) iY=fCalcPosY(iH,parMen);

    sStylBord="border:none;background-color:transparent;";

    this->setStyleSheet(fStylFram());
    this->setMinimumSize(QSize(iW,(18*7)+36));
    this->setMaximumSize(QSize(iW,(18*16)+36));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(iX,iY,iW,iH);

    labTitl = new QLabel(pTitl,this);
    labTitl->setStyleSheet(fStylTitl());
    labTitl->setMinimumSize(pWidt,30);
    labTitl->move(0,0);

    QToolButton *butClos=new QToolButton(this);
    butClos->setStyleSheet(fStylClos());
    butClos->setContentsMargins(0,0,0,0);
    butClos->resize(16,16);
    butClos->move(pWidt-22,7);
    butClos->setAutoRepeat(false);
    connect(butClos,SIGNAL(clicked()),this,SLOT(fGridClos()));

    fraSizT=new QFrame(this);
    fraSizT->setGeometry(0,0,iW,5);
    fraSizT->raise();
    fraSizT->setCursor(QPixmap(":/Imag/QSTit_size_vert.png"));
    fraSizT->setFrameShape(QFrame::NoFrame);
    fraSizT->setStyleSheet(sStylBord);
    fraSizB=new QFrame(this);
    fraSizB->setGeometry(0,iH-5,iW,5);
    fraSizB->raise();
    fraSizB->setCursor(QPixmap(":/Imag/QSTit_size_vert.png"));
    fraSizB->setFrameShape(QFrame::NoFrame);
    fraSizB->setStyleSheet(sStylBord);

    this->setHidden(true);
}
void diaInfoSkin::fGridClos()
{
    emit sClosed();
    this->close();
}
void diaInfoSkin::fRePosi()
{
    int iX=fCalcPosX(this->frameGeometry().width());
    int iY=fCalcPosY(this->frameGeometry().height(),parMen);
    this->move(iX,iY);
}
void diaInfoSkin::fGridSizeVert(bool pB,int pD)
{
    int jH;
    if (pB) jH=iH-pD;
    else jH=iH+pD;
    if (jH>=this->minimumHeight() && jH<=this->maximumHeight())
    {
        iH=jH;
        this->resize(iW,iH);
        if (!pB) iY-=pD;
        if (iY>iPb-iH) iY=iPb-iH;
        this->move(iX,iY);
        QList<QTableWidget *> widg=this->findChildren<QTableWidget *>();
        widg[0]->resize(widg[0]->frameGeometry().width(),iH-33);
        fGridSizeBord();
    }
}
void diaInfoSkin::fGridSizeBord()
{
    fraSizB->setGeometry(0,iH-5,iW,5);
}
void diaInfoSkin::mousePressEvent(QMouseEvent *e)
{
    bSizT=(e->y()>=0 && e->y()<=5)?true:false;
    bSizB=(e->y()>=iH-5 && e->y()<=iH)?true:false;
    iCx=e->globalX();
    iCy=e->globalY();
}
void diaInfoSkin::mouseMoveEvent(QMouseEvent *e)
{
    if (bSizT) {fGridSizeVert(false,iCy-e->globalY());iCx=e->globalX();iCy=e->globalY();}
    else if (bSizB) {fGridSizeVert(true,iCy-e->globalY());iCx=e->globalX();iCy=e->globalY();}
    else
    {
        int nFx=this->frameGeometry().x()+e->globalX()-iCx;
        if (nFx<1) nFx=1;
        if (nFx>iPr-this->frameGeometry().width()) nFx=iPr-this->frameGeometry().width();
        int nFy=this->frameGeometry().y()+e->globalY()-iCy;
        if (nFy<1) nFy=1;
        if (nFy>iPb-this->frameGeometry().height()) nFy=iPb-this->frameGeometry().height();
        iX=nFx;
        iY=nFy;
        this->move(iX,iY);
        iCx=e->globalX();
        iCy=e->globalY();
    }
}
void diaInfoSkin::keyPressEvent(QKeyEvent *e)
{
    if (e->key()==Qt::Key_Escape) {fGridClos();}
    else {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, e->key(),e->modifiers(),"",false,1));}
}
