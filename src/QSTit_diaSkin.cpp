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
    return "font:bold;color:#0055aa;padding-left:10px;";
}
QString fStylButt()
{
    return "height:20px;width:40px;background-color:#202020;color:#ffffff;border:1px solid #202020;border-radius:3px;text-align:left;padding-left:2px;";
}
QString fStylClos()
{
    return "QToolButton {image:url(:/Imag/QSTit_clos.png);border:none;background-color:transparent;} QToolButton:hover {image:url(:/Imag/QSTit_clos_over.png);background-color:transparent;}";
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
    //this->setFrameShape(QFrame::NoFrame);
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
    bLink=false;

    iPr=parWin->width()-1;
    iPb=parWin->height()-1;
    iPm=parWin->height()/2;

    if (iX==-1) iX=(parWin->width()-pWidt)/2;
    if (iY==-1) iY=parWin->height()-pHeig-1;

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

diaExitSkin::diaExitSkin(QWidget *parent,QFrame *menu,QString pTitl,int pWidt,int pHeig,int pLefx,int pTopy) : QDialog(parent)
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

    this->setParent(parWin);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    this->setModal(true);
    this->setMinimumSize(QSize(pWidt,pHeig));
    this->setMaximumSize(QSize(pWidt,pHeig));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(iLefx,iTopy,pWidt,pHeig);

    QString sAppFont=qApp->font().family();

    QString sStyl="QDialog {font:normal 11px "+sAppFont+";color:#ffffff;background-color:#000000;border:1px solid #0055aa;border-radius:3px;}";
    sStyl+="QLabel {font:bold 11px "+sAppFont+";background-color:transparent;color:#0055aa;border:1px solid #0055aa;border-radius:3px;text-align:left;padding-left:5px;}";
    sStyl+="QPushButton {min-height:20px;max-height:20px;min-width:70px;max-width:90px;background-color:#202020;color:#ffffff;border:1px solid #555555;border-radius:3px;text-align:left;padding-left:2px;}";
    sStyl+="QPushButton:hover {border-color:#0055aa;}";
    this->setStyleSheet(sStyl);

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
void diaExitSkin::fGridClos()
{
    emit sClosed();
    this->close();
}
void diaExitSkin::fRePosi()
{
    int iX=fCalcPosX(this->frameGeometry().width());
    int iY=fCalcPosY(this->frameGeometry().height(),parMen);
    this->move(iX,iY);
}
void diaExitSkin::mousePressEvent(QMouseEvent *e)
{
    iCx=e->globalX();
    iCy=e->globalY();
    this->raise();
    this->setFocus();
}
void diaExitSkin::mouseMoveEvent(QMouseEvent *e)
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
void diaExitSkin::keyPressEvent(QKeyEvent *e)
{
    if (e->key()==Qt::Key_Escape) {fGridClos();}
    else {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, e->key(),e->modifiers(),"",false,1));}
}

//-------------------------------------------------------------------------------------------------

diaConfSkin::diaConfSkin(QWidget *parent,QFrame *menu,QString pTitl,int pWidt,int pHeig,int pLefx,int pTopy) : QDialog(parent)
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

    this->setParent(parWin);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    this->setModal(true);
    this->setMinimumSize(QSize(pWidt,pHeig));
    this->setMaximumSize(QSize(pWidt,pHeig));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(iLefx,iTopy,pWidt,pHeig);

    QString sAppFont=qApp->font().family();

    QString sStyl="QDialog {font:normal 11px "+sAppFont+";color:#ffffff;background-color:#151515;border:1px solid #0055aa;border-radius:3px;}";
    sStyl+="QLabel {font:bold 11px "+sAppFont+";background-color:transparent;color:#ffffff;border:1px solid #0055aa;border-radius:3px;text-align:left;padding-left:5px;}";
    sStyl+="QPushButton {min-height:20px;max-height:20px;min-width:70px;max-width:90px;background-color:#202020;color:#ffffff;border:1px solid #555555;border-radius:3px;text-align:left;padding-left:2px;}";
    sStyl+="QPushButton:hover {border-color:#0055aa;}";
    this->setStyleSheet(sStyl);

    labTitl = new QLabel(pTitl,this);
    labTitl->setStyleSheet("font:bold;color:#ffffff;padding-left:10px;");
    labTitl->setMinimumSize(pWidt,30);
    labTitl->move(0,0);
}
void diaConfSkin::fRePosi()
{
    int iX=fCalcPosX(this->frameGeometry().width());
    int iY=fCalcPosY(this->frameGeometry().height(),parMen);
    this->move(iX,iY);
}
void diaConfSkin::mousePressEvent(QMouseEvent *e)
{
    iCx=e->globalX();
    iCy=e->globalY();
    this->raise();
    this->setFocus();
}
void diaConfSkin::mouseMoveEvent(QMouseEvent *e)
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
void diaConfSkin::keyPressEvent(QKeyEvent *e)
{
    if (e->key()==Qt::Key_Escape) {}
    else {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, e->key(),e->modifiers(),"",false,1));}
}

//-------------------------------------------------------------------------------------------------

bool messSkin::fMess(QWidget *parent,QFrame *menu,QString sMess,QString sBut1,QString sBut2)
{
    parWin=parent;
    parMen=menu;

    qApp->beep();
    QString sAppFont=qApp->font().family();

    int iW=0,iH=0,lW=0,lH=0;

    QStringList lMess=sMess.split(QString("|"));

    lMess[0]=lMess[0].trimmed();
    QString texMess=lMess[0],sW=lMess[0];
    lH=18;
    lW=lMess[0].size();
    if (lMess.size()>1) {lH+=18;lMess[1]=lMess[1].trimmed();texMess+="\n"+lMess[1];if(lW<lMess[1].size()) sW=lMess[1];}
    if (lMess.size()>2) {lH+=18;lMess[2]=lMess[2].trimmed();texMess+="\n"+lMess[2];if(lW<lMess[2].size()) sW=lMess[2];}
    if (lMess.size()>3) {lH+=18;lMess[3]=lMess[3].trimmed();texMess+="\n"+lMess[3];if(lW<lMess[3].size()) sW=lMess[3];}
    if (lMess.size()>4) {lH+=18;lMess[4]=lMess[4].trimmed();texMess+="\n"+lMess[4];if(lW<lMess[4].size()) sW=lMess[4];}

    QFont fT=QFont(sAppFont,11,QFont::Normal,false);
    QFontMetrics mT=QFontMetrics(fT);
    lW=mT.width(sW);
    #ifdef Q_OS_WIN32
    lW=lW/1.25;
    #endif
    if (lW%2!=0) lW+=1;
    iW=20+lW;if (iW<180) iW=180;
    iH=50+lH;

    this->setParent(parWin);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    this->setModal(true);
    this->setMinimumSize(QSize(iW,iH));
    this->setMaximumSize(QSize(iW,iH));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);

    QString sStyl="QDialog {font:normal 11px "+sAppFont+";color:#000000;background-color:#151515;border:1px solid #33ff33;border-radius:3px;}";
    sStyl+="QLabel {font:normal 11px "+sAppFont+";color:#000000;background-color:#33ff33;border:none;text-align:left;padding-left:5px;}";
    sStyl+="QPushButton {font:normal 11px "+sAppFont+";height:20px;;width:70px;background-color:#202020;color:#ffffff;border:1px solid #555555;border-radius:3px;text-align:left;padding-left:2px;}";
    sStyl+="QPushButton:hover {border-color:#cccccc;}";
    this->setStyleSheet(sStyl);

    QLabel *labBack=new QLabel(this);
    labBack->setText("");
    labBack->setGeometry(1,1,iW-2,iH-2);

    QLabel *labMess=new QLabel(this);
    labMess->setText(texMess);
    labMess->setGeometry((iW-lW)/2,10,lW,lH);

    bY=new QPushButton(QPixmap(":/Imag/QSTit_okok.png"),sBut1,this);
    bY->setIconSize(QSize(16,16));
    bY->resize(70,20);
    if (!sBut2.isEmpty()) bY->move(iW/2-80,iH-30); else  bY->move(iW/2-35,iH-30);
    bY->setFocus();
    connect(bY,SIGNAL(clicked()),this,SLOT(fButY()));

    if (!sBut2.isEmpty())
    {
        bN=new QPushButton(QPixmap(":/Imag/QSTit_canc.png"),sBut2,this);
        bN->setIconSize(QSize(16,16));
        bN->resize(70,20);
        bN->move(iW/2+7,iH-30);
        bN->setFocus();
        connect(bN,SIGNAL(clicked()),this,SLOT(fButN()));
    }
    this->move(fCalcPosX(iW),fCalcPosY(iH,parMen));
    this->exec();
    return bOk;
}

void messSkin::fButY() {bOk=true;this->done(0);}
void messSkin::fButN() {bOk=false;this->done(0);}

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

    QList<QPushButton *> butt=diaColo->findChildren<QPushButton *>();
    butt[0]->setText("Add to custom");
    butt[0]->setIconSize(QSize(0,0));
    butt[0]->setStyleSheet("height:20px;width:90px;background-color:#151515;color:#555555;border:none;padding-left:2px;");
    butt[1]->setText("Confirm");
    butt[1]->setIcon(QPixmap(":/Imag/QSTit_okok.png"));
    butt[1]->setIconSize(QSize(16,16));
    butt[1]->setStyleSheet("height:20px;width:70px;background-color:#151515;color:#ffffff;border:1px solid #0055aa;border-radius:3px;text-align:left;padding-left:2px;");
    butt[2]->setText("Cancel");
    butt[2]->setIcon(QPixmap(":/Imag/QSTit_canc.png"));
    butt[2]->setIconSize(QSize(16,16));
    butt[2]->setStyleSheet("height:20px;width:70px;background-color:#151515;color:#ffffff;border:1px solid #0055aa;border-radius:3px;text-align:left;padding-left:2px;");

    QString sStyl="QColorDialog {background-color:#151515;border:none;}";
    sStyl+="QWidget {border:none;}";
    sStyl+="QLabel {background-color:#151515;}";
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

    QList<QPushButton *> butt=diaFont->findChildren<QPushButton *>();
    butt[0]->setText("Confirm");
    butt[0]->setIcon(QPixmap(":/Imag/QSTit_okok.png"));
    butt[0]->setIconSize(QSize(16,16));
    butt[0]->setStyleSheet("font:normal 11px "+sAppFont+";height:20px;width:70px;background-color:#151515;color:#ffffff;border:1px solid #0055aa;border-radius:3px;text-align:left;padding-left:2px;");
    butt[1]->setText("Cancel");
    butt[1]->setIcon(QPixmap(":/Imag/QSTit_canc.png"));
    butt[1]->setIconSize(QSize(16,16));
    butt[1]->setStyleSheet("font:normal 11px "+sAppFont+";height:20px;width:70px;background-color:#151515;color:#ffffff;border:1px solid #0055aa;border-radius:3px;text-align:left;padding-left:2px;");

    QString sStyl="QFontDialog {background-color:#151515;border:none;}";
    sStyl+="QWidget {border:none;}";
    sStyl+="QLabel {font:normal 11px "+sAppFont+";background-color:#151515;}";
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

    int pWidt=642;
    int pHeig=307;
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

    diaFile->setLabelText(QFileDialog::Accept,"Ouvrir");
    diaFile->setLabelText(QFileDialog::Reject,"Abandon");

    diaFile->setOption(QFileDialog::DontUseNativeDialog);
    diaFile->setSizeGripEnabled(false);
    diaFile->setCursor(Qt::ArrowCursor);
    diaFile->setFileMode(QFileDialog::ExistingFile);
    diaFile->setViewMode(QFileDialog::Detail);
    diaFile->setAcceptMode(QFileDialog::AcceptOpen);
    diaFile->move(1,30);
    diaFile->setFixedHeight(276);
    connect(diaFile,SIGNAL(fileSelected(QString)),this,SLOT(fFileGet(QString)));
    connect(diaFile,SIGNAL(rejected()),this,SLOT(fGridClos()));

    QList<QPushButton *> butt=diaFile->findChildren<QPushButton *>();
    butt[0]->setText("Confirm");
    butt[0]->setIcon(QPixmap(":/Imag/QSTit_okok.png"));
    butt[0]->setIconSize(QSize(16,16));
    butt[0]->setStyleSheet("height:20px;width:70px;background-color:#151515;color:#ffffff;border:1px solid #0055aa;border-radius:3px;text-align:left;padding-left:2px;");
    butt[1]->setText("Cancel");
    butt[1]->setIcon(QPixmap(":/Imag/QSTit_canc.png"));
    butt[1]->setIconSize(QSize(16,16));
    butt[1]->setStyleSheet("height:20px;width:70px;background-color:#151515;color:#ffffff;border:1px solid #0055aa;border-radius:3px;text-align:left;padding-left:2px;");

    QString sStyl="QFileDialog {background-color:#151515;border:none;}";
    sStyl+="QWidget {border:none;}";
    sStyl+="QLabel {background-color:#151515;border:none;}";
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
    this->setMinimumSize(QSize(iW,(18*7)+38));
    this->setMaximumSize(QSize(iW,(18*15)+38));
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
        if (iY<1) iY=1;
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

//-------------------------------------------------------------------------------------------------

diaHelpSkin::diaHelpSkin(QWidget *parent,QFrame *menu,QString pTitl,int pWidt,int pHeig,int pLefx,int pTopy) : QFrame(parent)
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
    this->setMinimumSize(QSize(iW,236));
    this->setMaximumSize(QSize(iW,iH));
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
void diaHelpSkin::fGridClos()
{
    emit sClosed();
    this->close();
}
void diaHelpSkin::fGridSizeVert(bool pB,int pD)
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
        if (iY<1) iY=1;
        this->move(iX,iY);
        QList<QTextEdit *> widg=this->findChildren<QTextEdit *>();
        widg[0]->resize(widg[0]->frameGeometry().width(),iH-33);
        fGridSizeBord();
    }
}
void diaHelpSkin::fGridSizeBord()
{
    fraSizB->setGeometry(0,iH-5,iW,5);fraSizB->raise();
}
void diaHelpSkin::mousePressEvent(QMouseEvent *e)
{
    bSizT=(e->y()>=0 && e->y()<=5)?true:false;
    bSizB=(e->y()>=iH-5 && e->y()<=iH)?true:false;
    iCx=e->globalX();
    iCy=e->globalY();
}
void diaHelpSkin::mouseMoveEvent(QMouseEvent *e)
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
void diaHelpSkin::keyPressEvent(QKeyEvent *e)
{
    if (e->key()==Qt::Key_Escape) {fGridClos();}
    else {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress, e->key(),e->modifiers(),"",false,1));}
}
