#include "QSTit_diaGrid.h"

diaSettW::diaSettW(QWidget *parent) : QDialog(parent)
{
    parWin = parent;
}

void diaSettW::keyPressEvent(QKeyEvent *qe)
{
    QApplication::sendEvent(parWin, new QKeyEvent(QEvent::KeyPress, qe->key(), qe->modifiers(), "", false, 1));
}

diaGridW::diaGridW(QWidget *parent, QFrame *menu) : QDialog(parent)
{
    parEnt = parent;
    parMen = menu;
}

void diaGridW::moveEvent(QMoveEvent *e)
{
    static int pDt=0;

    QRect rP = parEnt->frameGeometry();
    int iPl = rP.left();
    int iPb = rP.bottom();
    int iPw = rP.width();

    QRect rD = this->frameGeometry();
    int iDl = rD.left();
    int iDt = rD.top();
    int iDb = rD.bottom();
    int iDh = rD.height();
    int iDw = rD.width();

    QRect rM = parMen->frameGeometry();
    int iMl = rM.left();
    int iMt = rM.top();
    int iMb = rM.bottom();
    int iMh = rM.height();
    int iMw = rM.width();

    QPoint o = e->oldPos();

    if (iDl < iPl)
    {
        iDl=iPl;
        iDt=pDt;
        iMl=iDl+(iDw/2)-(iMw/2);
        iMt=iDb+1;
        parMen->move(iMl,iMt);
        this->move(iDl,iDt);
    }
    else if (iDl+iDw > iPw)
    {
        iDl=iPw-iDw;
        iDt=pDt;
        iMl=iDl+((iDw-iMw)/2);
        iMt=iDb+1;
        parMen->move(iMl,iMt);
        this->move(iDl,iDt);
    }
    else if (iMb <= iPb)
    {
        iMl=iDl+((iDw-iMw)/2);
        iMt=iDb+1;
        parMen->move(iMl,iMt);
    }
    else
    {
        iDl=o.x();
        iDt=iPb-iMh-iDh-1;
        iMl=iDl+((iDw-iMw)/2);
        iMt=iDb+1;
        parMen->move(iMl,iMt);
        this->move(iDl,iDt);
    }

    pDt=iDt;
}

void diaGridW::resizeEvent(QResizeEvent *e)
{
    QRect rD = this->frameGeometry();
    int iDl = rD.left();
    int iDb = rD.bottom();
    int iDw = rD.width();

    QRect rM = parMen->frameGeometry();
    int iMl = rM.left();
    int iMt = rM.top();
    int iMw = rM.width();

    iMl=iDl+(iDw/2)-(iMw/2);
    iMt=iDb+1;
    parMen->move(iMl,iMt);
}

diaGridC::diaGridC(QWidget *parent, QSlider *slider, QWidget *wind) : QTableWidget(parent)
{
    parEnt = parent;
    parSli = slider;
    parWin = wind;

    gLang = 0;

    gIconGoto = QPixmap(":Imag/QSTit_okok.png");
    gIconFind = QPixmap(":Imag/QSTit_okok.png");
    gIconCanc = QPixmap(":Imag/QSTit_canc.png");
    gIconDial = QPixmap(":Imag/QSTit_gray.png");
    gIconFlag = QPixmap(":Imag/QSTit_flag.png");

    gFindText = "";
    gFindFrom = 0;
}

void diaGridC::keyPressEvent(QKeyEvent *qe)
{
    if (qe->modifiers() == Qt::NoModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_Exclam:    {fGridMarkRows();break;}
            case Qt::Key_F3:        {if (!gFindText.isEmpty()) fGridFindLoop(gFindText, gFindFrom);
                                     break;}
            default:
            {
                QApplication::sendEvent(parWin, new QKeyEvent(QEvent::KeyPress, qe->key(), qe->modifiers(), "", false, 1));
            }
        }
    }
    else if (qe->modifiers() == Qt::ControlModifier)
    {
        switch (qe->key())
        {
            case Qt::Key_G:         {fGridGoto();break;}
            case Qt::Key_F:         {fGridFind();break;}
            default:
            {
                QApplication::sendEvent(parWin, new QKeyEvent(QEvent::KeyPress, qe->key(), qe->modifiers(), "", false, 1));
            }
        }
    }
    else
    {
        QApplication::sendEvent(parWin, new QKeyEvent(QEvent::KeyPress, qe->key(), qe->modifiers(), "", false, 1));
    }
}

void diaGridC::fGridGoto()
{
    QWidget *wp = parentWidget();

    int iLineWidt = 100;
    int iLineHeig = 20;
    int gGotoLefx = wp->frameGeometry().x() + 20;
    int gGotoTopy = wp->frameGeometry().y() - 10;
    int gGotoWidt = iLineWidt + 90;
    int gGotoHeig = 70;

    diaGoto = new QDialog(this);
    diaGoto->setWindowTitle(fL("Go to..."));
    diaGoto->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    diaGoto->setCursor(Qt::ArrowCursor);
    diaGoto->setMinimumWidth(gGotoWidt);
    diaGoto->setMaximumWidth(gGotoWidt);
    diaGoto->setMinimumHeight(gGotoHeig);
    diaGoto->setMaximumHeight(gGotoHeig);
    diaGoto->setGeometry(gGotoLefx, gGotoTopy, gGotoWidt, gGotoHeig);
    diaGoto->move(gGotoLefx, gGotoTopy);                // necessary!

    QString sStyl = "background-color:#151515;color:#ffffff; ";
    sStyl = sStyl + "QPushButton {min-height:20px;max-height:20px;min-width:70px;max-width:70px;background-color:#202020;color:#ffffff;border:1px solid #555555;border-radius:3px;text-align:left;padding-left:2px;} ";
    sStyl = sStyl + "QPushButton:hover {border-color:#6666ff;} ";
    diaGoto->setStyleSheet(sStyl);

    ediGoto = new QLineEdit();
    ediGoto->setStyleSheet("border:1px solid #202020;background-color:#ffffff;color:#000000;");
    ediGoto->setFont(QFont("Courier New", 9, QFont::Normal, false));
    ediGoto->setEchoMode(QLineEdit::Normal);
    ediGoto->setText("");
    ediGoto->setGeometry(5, 5, iLineWidt, iLineHeig);
    ediGoto->setFocus();
    connect(ediGoto, SIGNAL(returnPressed()), this, SLOT(fGridGotoLine()));

    QLabel *labGoto = new QLabel(QString("Row 1 -> %1").arg(rowCount() - 2));
    labGoto->setStyleSheet("color:#555555;");

    QPushButton *butGotoSave = new QPushButton(gIconGoto, fL("OK"));
    connect(butGotoSave, SIGNAL(clicked()), this, SLOT(fGridGotoLine()));

    QPushButton *butGotoCanc = new QPushButton(gIconCanc, fL("Cancel"));
    connect(butGotoCanc, SIGNAL(clicked()), this, SLOT(fGridGotoCanc()));

    QGridLayout *boxGotoButt = new QGridLayout;
    boxGotoButt->addWidget(ediGoto, 0, 0);
    boxGotoButt->addWidget(labGoto, 1, 0);
    boxGotoButt->addWidget(butGotoSave, 0, 1);
    boxGotoButt->addWidget(butGotoCanc, 1, 1);

    QFrame *fraGotoButt = new QFrame;
    fraGotoButt->setLayout(boxGotoButt);

    QGridLayout *layGoto = new QGridLayout;
    layGoto->setContentsMargins(0, 0, 0, 0);
    layGoto->setHorizontalSpacing(0);
    layGoto->addWidget(fraGotoButt, 0, 1);
    diaGoto->setLayout(layGoto);

    gGridGoto = false;
    diaGoto->exec();

    if (gGridGoto)
    {
        QString sR = ediGoto->text();
        int iR = sR.toInt();
        setCurrentCell(iR, 3, QItemSelectionModel::Rows);
        scrollTo(currentIndex(), QAbstractItemView::PositionAtCenter);
    }

    activateWindow();
    setFocus(Qt::OtherFocusReason);
}

void diaGridC::fGridGotoCanc()
{
    gGridGoto = false;
    diaGoto->done(0);
}

void diaGridC::fGridGotoLine()
{
    QString sR = ediGoto->text();
    int iR = sR.toInt();
    int iM = rowCount()-1;
    if (iR > 0 && iR < iM)
    {
        gGridGoto = true;
        diaGoto->done(0);
    }
}

void diaGridC::fGridFind()
{
    QWidget *wp = parentWidget();

    int iLineWidt = 100;
    int iLineHeig = 20;
    int gFindLefx = wp->frameGeometry().x() + 20;
    int gFindTopy = wp->frameGeometry().y() - 10;
    int gFindWidt = iLineWidt + 90;
    int gFindHeig = 70;

    diaFind = new QDialog(this);
    diaFind->setWindowTitle(fL("Find..."));
    diaFind->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    diaFind->setCursor(Qt::ArrowCursor);
    diaFind->setMinimumWidth(gFindWidt);
    diaFind->setMaximumWidth(gFindWidt);
    diaFind->setMinimumHeight(gFindHeig);
    diaFind->setMaximumHeight(gFindHeig);
    diaFind->setGeometry(gFindLefx, gFindTopy, gFindWidt, gFindHeig);
    diaFind->move(gFindLefx, gFindTopy);    // needed!

    QString sStyl = "background-color:#151515;color:#ffffff; ";
    sStyl = sStyl + "QPushButton {min-height:20px;max-height:20px;min-width:70px;max-width:70px;background-color:#202020;color:#ffffff;border:1px solid #555555;border-radius:3px;text-align:left;padding-left:2px;} ";
    sStyl = sStyl + "QPushButton:hover {border-color:#6666ff;} ";
    diaFind->setStyleSheet(sStyl);

    ediFind = new QLineEdit();
    ediFind->setStyleSheet("border:1px solid #202020;background-color:#ffffff;color:#000000;");
    ediFind->setFont(QFont("Courier New", 9, QFont::Normal, false));
    ediFind->setEchoMode(QLineEdit::Normal);
    ediFind->setText(gFindText);
    ediFind->setGeometry(5, 5, iLineWidt, iLineHeig);
    ediFind->setFocus();
    connect(ediFind, SIGNAL(returnPressed()), this, SLOT(fGridFindLine()));

    QLabel *labFind = new QLabel(QString(fL("F3 -> next")));
    labFind->setStyleSheet("color:#555555;");

    QPushButton *butFindSave = new QPushButton(gIconFind, fL("OK"));
    connect(butFindSave, SIGNAL(clicked()), this, SLOT(fGridFindWord()));

    QPushButton *butFindCanc = new QPushButton(gIconCanc, fL("Cancel"));
    connect(butFindCanc, SIGNAL(clicked()), this, SLOT(fGridFindCanc()));

    QGridLayout *boxFindButt = new QGridLayout;
    boxFindButt->addWidget(ediFind, 0, 0);
    boxFindButt->addWidget(labFind, 1, 0);
    boxFindButt->addWidget(butFindSave, 0, 1);
    boxFindButt->addWidget(butFindCanc, 1, 1);

    QFrame *fraFindButt = new QFrame;
    fraFindButt->setLayout(boxFindButt);

    QGridLayout *layFind = new QGridLayout;
    layFind->setContentsMargins(0, 0, 0, 0);
    layFind->setHorizontalSpacing(0);
    layFind->addWidget(fraFindButt, 0, 1);
    diaFind->setLayout(layFind);

    gGridFind = false;
    diaFind->exec();

    if (gGridFind)
    {
        QString sT = ediFind->text();
        if (!sT.isEmpty())
        {
            gFindText = sT;
            gFindFrom = 0;
            fGridFindLoop(gFindText, gFindFrom);
        }
    }

    activateWindow();
    setFocus(Qt::OtherFocusReason);
}

void diaGridC::fGridFindCanc()
{
    gGridFind = false;
    diaFind->done(0);
}

void diaGridC::fGridFindWord()
{
    gGridFind = true;
    diaFind->done(0);
}

void diaGridC::fGridFindLoop(QString pText, int pFrom)
{
    QString sFind = pText.toLower();
    int iR;
    int iRM = rowCount();
    int iC;
    int iCM = columnCount();
    QTableWidgetItem *it;
    QString st;

    for (iR = pFrom; iR < iRM; iR++)
    {
        for (iC = 1; iC < iCM; iC++)
        {
            if (columnWidth(iC) > 0)
            {
                it = item(iR, iC);
                st = it->text().toLower();
                if (st.indexOf(sFind) != -1)
                {
                    setCurrentCell(iR, iC, QItemSelectionModel::Rows);
                    gGridFind = true;
                    gFindFrom = iR + 1;
                    diaFind->done(0);
                    return;
                }
            }
        }
    }
    QMessageBox::information(this, fL("Find..."), fL("End of file reached"));
}

void diaGridC::fGridMarkRows()
{
    int iR = currentRow();

    if (iR == 0 || iR == rowCount()-1) return;

    QTableWidgetItem *wi = item(iR, 0);

    if (wi->text() == "E") return;

    QIcon ic = wi->icon();
    if (!ic.isNull())
    {
        QTableWidgetItem *wi = new QTableWidgetItem("", 0);
        wi->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        setItem(iR, 0, wi);
    }
    else
    {
        QTableWidgetItem *wi = item(iR, 0);
        wi->setIcon(gIconFlag);
        wi->setText("I");
    }
}

void diaGridC::fWorkLang(int pLang)
{
    gLang = pLang;
}

QString diaGridC::fL(QString sI)
{
    QString sO = sI;

    if (gLang > 0)
    {
        if (sI == "Go to row...")         sO = gLang == 1 ? "Aller à la ligne..."     : "Gaan naar lijn...";
        if (sI == "Cancel")                 sO = gLang == 1 ? "Annuler"                 : "Annuleren";
        if (sI == "Find...")         sO = gLang == 1 ? "Rechercher..."    : "Zoeken...";
        if (sI == "F3 -> next")             sO = gLang == 1 ? "F3 -> suivant"           : "F3 -> volgende";
        if (sI == "End of file reached")         sO = gLang == 1 ? "Fin du fichier atteinte"       : "End of file reached";
    }
    return sO;
}
