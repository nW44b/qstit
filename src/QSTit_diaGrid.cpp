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

#include "QSTit_diaGrid.h"
#include "QSTit_diaSkin.h"
#include "QSTit_diaButt.h"

diaGridSkin::diaGridSkin(QWidget *parent,menuSkin *menu,QString pTitl,int pWidt,int pHeig) : QFrame(parent)
{
    parWin=parent;
    parMen=menu;

    iPr=QApplication::desktop()->width()-1;
    iPb=QApplication::desktop()->height()-1;
    iPm=QApplication::desktop()->height()/2;
    sPf=qApp->font().family();

    bLink=true;

    iW=pWidt;
    iH=pHeig;
    iX=fCalcPosX(iW);
    iY=fCalcPosY(iH,parMen);

    this->setStyleSheet(fStylFram());
    this->setMinimumSize(QSize(500,iH));
    this->setMaximumSize(QSize(iW,iH+164));
    this->setContentsMargins(0,0,0,0);
    this->setCursor(Qt::ArrowCursor);
    this->setGeometry(iX,iY,iW,iH);
    this->setHidden(true);

    labTitl=new QLabel(pTitl,this);
    labTitl->setStyleSheet(fStylTitl());
    labTitl->resize(iW,30);
    labTitl->move(0,0);

    labSizV=new QLabel("",this);
    labSizV->setStyleSheet("border:none;font:3px normal;background-color:#151515;color:#151515;");
    labSizV->setContentsMargins(0,0,0,0);
    labSizV->setCursor(QPixmap(":/Imag/QSTit_size_vert.png"));
    labSizV->resize(iW-4,4);
    labSizV->move(2,1);

    labSizH=new QLabel("",this);
    labSizH->stackUnder(labTitl);
    labSizH->setStyleSheet("border:none;font:3px normal;background-color:#151515;color:#151515;");
    labSizH->setContentsMargins(0,0,0,0);
    labSizH->setCursor(QPixmap(":/Imag/QSTit_size.png"));
    labSizH->resize(4,iH-4);
    labSizH->move(pWidt-5,2);
}
void diaGridSkin::fRePosi()
{
    iX=fCalcPosX(iW);
    if (bLink) iY=fCalcPosY(iH,parMen);
    bool bLinkSave=bLink;
    bLink=false;                                        // supress link to avoid menu repositioning
    this->move(iX,iY);
    bLink=bLinkSave;
}
void diaGridSkin::fGridLink()
{
    bool bL=!bLink;                                     // must be so due to fMenuMove that may change bLink
    parMen->bLink=bL;
    if (bL)
    {
        fRePosi();
        fMenuMove();
    }
    bLink=bL;
}
void diaGridSkin::fMenuMove()
{
    int mX,mY;
    if(this->frameGeometry().y()>iPm)
    {
        mX=iX+((iW-parMen->frameGeometry().width())/2);
        mY=iY+this->frameGeometry().height();
    }
    else
    {
        mX=iX+((iW-parMen->frameGeometry().width())/2);
        mY=iY-parMen->frameGeometry().height();
    }
    parMen->iX=mX;
    parMen->iY=mY;
    parMen->move(mX,mY);
}
void diaGridSkin::fGridSizeVert(int iD)
{
    static int iM=0;
    if (++iM%6==0)                                      // 6*3=18
    {
        iM=0;
        int jH=iH+(iD*18);
        if (jH>=this->minimumHeight() && jH<=this->maximumHeight())
        {
            iH=jH;
            this->resize(iW,iH);
            if (bLink) fRePosi();
            else
            {
                if (iY>iPb-iH) iY=iPb-iH;
                this->move(iX,iY);
            }
            QList<diaGridC *> widg=this->findChildren<diaGridC *>();
            widg[0]->resize(widg[0]->frameGeometry().width(),iH-33);
            labSizH->resize(4,iH-4);
            if (bLink) fMenuMove();
        }
    }
}
void diaGridSkin::fGridSizeInit(int pW)
{
    iW=pW;
    this->resize(iW,iH);
    int iw=iW-81;
    QList<diaGridC *> widg=this->findChildren<diaGridC *>();
    widg[0]->resize(iw,iH-33);
    widg[0]->setColumnWidth(3,iWid3);dPou3=(double)iWid3/iw;
    widg[0]->setColumnWidth(4,iWid4);dPou4=(double)iWid4/iw;
    widg[0]->setColumnWidth(5,iWid5);dPou5=(double)iWid5/iw;
    widg[0]->setColumnWidth(6,iWid6);dPou6=(double)iWid6/iw;
    labTitl->resize(iW,30);
    labSizV->resize(iW-4,4);
    labSizH->move(iW-5,2);
    QList<butToolC *> butt=this->findChildren<butToolC *>();
    butt[0]->move(iW-69,butt[0]->frameGeometry().y());
    butt[1]->move(iW-39,butt[1]->frameGeometry().y());
    butt[2]->move(iW-69,butt[2]->frameGeometry().y());
    butt[3]->move(iW-39,butt[3]->frameGeometry().y());
    butt[4]->move(iW-69,butt[4]->frameGeometry().y());
    butt[5]->move(iW-39,butt[5]->frameGeometry().y());
    butt[6]->move(iW-69,butt[6]->frameGeometry().y());
    butt[7]->move(iW-39,butt[7]->frameGeometry().y());
    if (bLink) fMenuMove();
}
void diaGridSkin::fGridSizeHori(int pW)
{
    int jW=pW-this->frameGeometry().x();
    if (jW>=this->minimumWidth() && jW<=this->maximumWidth())
    {
        iW=jW;
        this->resize(iW,iH);
        int iw=iW-81;
        QList<diaGridC *> widg=this->findChildren<diaGridC *>();
        widg[0]->resize(iw,widg[0]->frameGeometry().height());
        if (nColo>0) widg[0]->setColumnWidth(3,(int)iw*dPou3);
        if (nColo>1) widg[0]->setColumnWidth(4,(int)iw*dPou4);
        if (nColo>2) widg[0]->setColumnWidth(5,(int)iw*dPou5);
        if (nColo>3) widg[0]->setColumnWidth(6,(int)iw*dPou6);
        labTitl->resize(iW,30);
        labSizV->resize(iW-4,4);
        labSizH->move(iW-5,2);
        QList<butToolC *> butt=this->findChildren<butToolC *>();
        butt[0]->move(iW-69,butt[0]->frameGeometry().y());
        butt[1]->move(iW-39,butt[1]->frameGeometry().y());
        butt[2]->move(iW-69,butt[2]->frameGeometry().y());
        butt[3]->move(iW-39,butt[3]->frameGeometry().y());
        butt[4]->move(iW-69,butt[4]->frameGeometry().y());
        butt[5]->move(iW-39,butt[5]->frameGeometry().y());
        butt[6]->move(iW-69,butt[6]->frameGeometry().y());
        butt[7]->move(iW-39,butt[7]->frameGeometry().y());
        if (bLink) fMenuMove();
    }
}
void diaGridSkin::mousePressEvent(QMouseEvent *e)
{
    bSizV=(e->y()>0 && e->y()<5)?true:false;
    bSizH=(e->y()>0 && e->x()>iW-5)?true:false;
    iCx=e->globalX();
    iCy=e->globalY();
}
void diaGridSkin::mouseMoveEvent(QMouseEvent *e)
{
    if (bSizV)
    {
        int iD=iCy-e->globalY();
        if (iD>0) fGridSizeVert(1);
        if (iD<0) fGridSizeVert(-1);
        iCx=e->globalX();
        iCy=e->globalY();
    }
    else if (bSizH)
    {
        fGridSizeHori(e->globalX());
        iCx=e->globalX();
        iCy=e->globalY();
    }
    else
    {
        int jX=iX+e->globalX()-iCx;
        if (jX<1) jX=1;
        if (jX>iPr-iW) jX=iPr-iW;
        int jY=iY+e->globalY()-iCy;
        if (jY<1) jY=1;
        if (bLink && jY<41) jY=41;
        if (jY>iPb-iH) jY=iPb-iH;
        if (bLink && jY>iPb-iH-40) jY=iPb-iH-40;
        iX=jX;
        iY=jY;
        this->move(iX,iY);
        iCx=e->globalX();
        iCy=e->globalY();
        emit sMoved();
    }
}
void diaGridSkin::moveEvent(QMoveEvent *e)
{
    iX=this->frameGeometry().x();
    iY=this->frameGeometry().y();
    if (bLink) fMenuMove();
}
void diaGridSkin::fWorkLang(QStringList pCode,QStringList pText)
{
    gLangCode=pCode;
    gLangText=pText;
}
QString diaGridSkin::fL(QString sI)
{
    int i=gLangCode.indexOf(sI,0);
    if (i>-1) sI=gLangText.at(i);
    return sI;
}

//-------------------------------------------------------------------------------------------------

diaGridC::diaGridC(diaGridSkin *parent,QWidget *wind,QFrame *menu) : QTableWidget(parent)
{
    parEnt=parent;
    parWin=wind;
    parMen=menu;
    gFindText="";
    gFindFrom=0;
}
void diaGridC::keyPressEvent(QKeyEvent *e)
{
    if (e->modifiers()==Qt::NoModifier)
    {
        switch (e->key())
        {
            case Qt::Key_Exclam:    {fGridMarkRows();break;}
            case Qt::Key_F3:        {if (!gFindText.isEmpty()) {fGridFindLoop(gFindText,gFindFrom);}};break;
            default: {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress,e->key(),e->modifiers(),"",false,1));}
        }
    }
    else if (e->modifiers()==Qt::ControlModifier)
    {
        switch (e->key())
        {
            case Qt::Key_G:         {fGridGoto();break;}
            case Qt::Key_F:         {fGridFind();break;}
            default: {QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress,e->key(),e->modifiers(),"",false,1));}
        }
    }
    else
    {
        QApplication::sendEvent(parWin,new QKeyEvent(QEvent::KeyPress,e->key(),e->modifiers(),"",false,1));
    }
}
void diaGridC::fGridGoto()
{
    QString sPf=qApp->font().family();

    int iLineWidt=50;
    int iLineHeig=20;
    int iWidt=iLineWidt+95;
    int iHeig=65;
    int iLefx=parEnt->frameGeometry().x()+parEnt->frameGeometry().width()-iWidt-79;
    int iTopy=parEnt->frameGeometry().y()+2;

    diaGoto=new QDialog(parEnt);
    diaGoto->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    diaGoto->setModal(true);
    diaGoto->setCursor(Qt::ArrowCursor);
    diaGoto->setMinimumSize(iWidt,iHeig);
    diaGoto->setMaximumSize(iWidt,iHeig);
    diaGoto->move(iLefx,iTopy);

    QString sStyl="QDialog {font:normal 11px "+sPf+";background-color:#32cd32;color:#000000;border:none}";
    sStyl+="QLineEdit {background-color:#ffffff;color:#000000;border:1px solid #202020;font:11px normal courier new;}";
    sStyl+="QLabel {background-color:#32cd32;color:#202020;border:none;text-align:left;}";
    sStyl+="QPushButton {background-color:#202020;color:#ffffff;border:none;text-align:left;padding-left:2px;}";
    diaGoto->setStyleSheet(sStyl);

    ediGoto=new QLineEdit(diaGoto);
    ediGoto->setEchoMode(QLineEdit::Normal);
    ediGoto->setText("");
    ediGoto->setGeometry(10,10,iLineWidt,iLineHeig);
    ediGoto->setFocus();
    connect(ediGoto,SIGNAL(returnPressed()),this,SLOT(fGridGotoLine()));

    QLabel *labGoto=new QLabel(QString("1 -> %1").arg(rowCount()-2),diaGoto);
    labGoto->move(10,35);

    QPushButton *butGotoSave=new QPushButton(QPixmap(":Imag/QSTit_okok.png"),fL("butGridGotoSave"),diaGoto);
    butGotoSave->setIconSize(QSize(16,16));
    butGotoSave->resize(70,20);
    butGotoSave->move(iLineWidt+15,10);
    connect(butGotoSave,SIGNAL(clicked()),this,SLOT(fGridGotoLine()));

    QPushButton *butGotoCanc=new QPushButton(QPixmap(":Imag/QSTit_canc.png"),fL("butGridGotoCanc"),diaGoto);
    butGotoCanc->setIconSize(QSize(16,16));
    butGotoCanc->resize(70,20);
    butGotoCanc->move(iLineWidt+15,35);
    connect(butGotoCanc,SIGNAL(clicked()),this,SLOT(fGridGotoCanc()));

    gGridGoto=false;
    diaGoto->exec();

    if (gGridGoto)
    {
        QString sR=ediGoto->text();
        int iR=sR.toInt();
        setCurrentCell(iR,3,QItemSelectionModel::Rows);
        scrollTo(currentIndex(),QAbstractItemView::PositionAtCenter);
    }

    activateWindow();
    setFocus();
}
void diaGridC::fGridGotoCanc()
{
    gGridGoto=false;
    diaGoto->done(0);
}
void diaGridC::fGridGotoLine()
{
    QString sR=ediGoto->text();
    int iR=sR.toInt();
    int iM=rowCount()-1;
    if (iR>0&&iR<iM)
    {
        gGridGoto=true;
        diaGoto->done(0);
    }
}
void diaGridC::fGridFind()
{
    QString sPf=qApp->font().family();

    int iLineWidt=100;
    int iLineHeig=20;
    int iWidt=iLineWidt+95;
    int iHeig=65;
    int iLefx=parEnt->frameGeometry().x()+parEnt->frameGeometry().width()-iWidt-79;
    int iTopy=parEnt->frameGeometry().y()+2;

    diaFind=new QDialog(parEnt);
    diaFind->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    diaFind->setModal(true);
    diaFind->setCursor(Qt::ArrowCursor);
    diaFind->setMinimumSize(iWidt,iHeig);
    diaFind->setMaximumSize(iWidt,iHeig);
    diaFind->move(iLefx,iTopy);

    QString sStyl="QDialog {font:normal 11px "+sPf+";background-color:#32cd32;color:#000000;border:none}";
    sStyl+="QLineEdit {background-color:#ffffff;color:#000000;border:1px solid #202020;}";
    sStyl+="QLabel {background-color:#32cd32;color:#202020;border:none;text-align:left;}";
    sStyl+="QPushButton {background-color:#202020;color:#ffffff;border:none;text-align:left;padding-left:2px;}";
    diaFind->setStyleSheet(sStyl);

    ediFind=new QLineEdit(diaFind);
    ediFind->setEchoMode(QLineEdit::Normal);
    ediFind->setText("");
    ediFind->setGeometry(10,10,iLineWidt,iLineHeig);
    ediFind->setFocus();
    connect(ediFind,SIGNAL(returnPressed()),this,SLOT(fGridFindWord()));

    QLabel *labFind=new QLabel(fL("labGridFind"),diaFind);
    labFind->move(10,35);

    QPushButton *butFindSave=new QPushButton(QPixmap(":Imag/QSTit_okok.png"),fL("butGridFindSave"),diaFind);
    butFindSave->setIconSize(QSize(16,16));
    butFindSave->resize(70,20);
    butFindSave->move(iLineWidt+15,10);
    connect(butFindSave,SIGNAL(clicked()),this,SLOT(fGridFindWord()));

    QPushButton *butFindCanc=new QPushButton(QPixmap(":Imag/QSTit_canc.png"),fL("butGridFindCanc"),diaFind);
    butFindCanc->setIconSize(QSize(16,16));
    butFindCanc->resize(70,20);
    butFindCanc->move(iLineWidt+15,35);
    connect(butFindCanc,SIGNAL(clicked()),this,SLOT(fGridFindCanc()));

    gGridFind=false;
    diaFind->exec();

    if (gGridFind)
    {
        QString sT=ediFind->text();
        if (!sT.isEmpty())
        {
            gFindText=sT;
            gFindFrom=0;
            fGridFindLoop(gFindText,gFindFrom);
        }
    }

    activateWindow();
    setFocus();
}
void diaGridC::fGridFindCanc()
{
    gGridFind=false;
    diaFind->done(0);
}
void diaGridC::fGridFindWord()
{
    gGridFind=true;
    diaFind->done(0);
}
void diaGridC::fGridFindLoop(QString pText,int pFrom)
{
    QString sFind=pText.toLower();
    int iR;
    int iRM=rowCount();
    int iC;
    int iCM=columnCount();
    QTableWidgetItem *it;
    QString st;

    for (iR=pFrom; iR<iRM; iR++)
    {
        for (iC=1; iC<iCM; iC++)
        {
            if (columnWidth(iC)>0)
            {
                it=item(iR,iC);
                st=it->text().toLower();
                if (st.indexOf(sFind)!=-1)
                {
                    setCurrentCell(iR,iC,QItemSelectionModel::Rows);
                    gGridFind=true;
                    gFindFrom=iR+1;
                    diaFind->done(0);
                    return;
                }
            }
        }
    }
    messSkin cM;
    cM.fMess(this,parMen,fL("butGridFindEnd"),fL("butOkOk"),"");
}
void diaGridC::fGridMarkRows()
{
    int iR=currentRow();

    if (iR==0||iR==rowCount()-1) return;

    QTableWidgetItem *wi=item(iR,0);

    if (wi->text()=="E") return;

    QIcon ic=wi->icon();
    if (!ic.isNull())
    {
        QTableWidgetItem *wi=new QTableWidgetItem("",0);
        wi->setFlags(Qt::NoItemFlags|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        setItem(iR,0,wi);
    }
    else
    {
        QTableWidgetItem *wi=item(iR,0);
        wi->setIcon(QPixmap(":Imag/QSTit_flag.png"));
        wi->setText("I");
    }
}
void diaGridC::fWorkLang(QStringList pCode,QStringList pText)
{
    gLangCode=pCode;
    gLangText=pText;
}
QString diaGridC::fL(QString sI)
{
    int i=gLangCode.indexOf(sI,0);
    if (i>-1) sI=gLangText.at(i);
    return sI;
}
/*
    ════════════════════════════════════════════════════════════════════════════════
    Code analysis/programming:  Georges Piedboeuf-Boen  georges.pi.bo@gmail.com
    Functional analysis:        Laurent Tenzer          lt@nova-cinema.org
    Project origin:             Cinéma Nova             http://www.nova-cinema.org
    Made in Brussels            Belgium                 http://www.brussels.be
    ════════════════════════════════════════════════════════════════════════════════
*/
