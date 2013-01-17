#include "QSTit_diaExpl.h"

butToolC::butToolC(QWidget *wParent) : QToolButton(wParent)
{
    parPare = wParent;
}

bool butToolC::event(QEvent *event)                     // gpb 120310
{
     if (event->type() == QEvent::ToolTip)
     {
        QHelpEvent *helpEvent = static_cast<QHelpEvent *>(event);
        QPoint qPos = helpEvent->globalPos();
        qPos.setX(qPos.x()-2);
        qPos.setY(qPos.y()-42);
        QString sText = fL(this->parText);
        QToolTip::showText(qPos, sText);
        return true;
     }
     return QWidget::event(event);
}

void butToolC::mousePressEvent(QMouseEvent *qe)
{
    if (qe->button() != Qt::RightButton)
    {
        QToolButton::mousePressEvent(qe);
        return;
    }
    QToolTip::hideText();                               // gpb 120310
}

void butToolC::keyPressEvent(QKeyEvent *qe)
{
    switch (qe->key())
    {
        case Qt::Key_Escape:
            break;

        case Qt::Key_Return:
            break;

        case Qt::Key_Enter:
            break;

        case Qt::Key_Space:
            if (qe->modifiers() == Qt::NoModifier)
            {
                QApplication::sendEvent(this, new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier, "", false, 1));
                break;
            }
            if (qe->modifiers() == Qt::ShiftModifier)
            {
                QApplication::sendEvent(this, new QKeyEvent(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier, "", false, 1));
                break;
            }

        default:
            QToolButton::keyPressEvent(qe);
    }
}

void butToolC::fGridHelp()
{
    QDesktopWidget *wScre = QApplication::desktop();
    QRect rAvai = wScre->availableGeometry();
    int iAvaiHeig = rAvai.height();

    QString sText = fL(parText);
    int iText = 6 * sText.length();

    QPoint pCurs = QCursor::pos();

    int gHelpLefx = pCurs.x()+9;
    int gHelpTopy = pCurs.y()+17;
    int gHelpWidt = 20+iText;
    int gHelpHeig = 30;
    int iLineWidt = gHelpWidt-10;
    int iLineHeig = 20;

    if (gHelpTopy+gHelpHeig > iAvaiHeig) gHelpTopy = iAvaiHeig-gHelpHeig-30;

    diaHelp = new QDialog(parPare);
    diaHelp->setWindowTitle(fL("Help"));
    diaHelp->setWindowFlags(Qt::Tool);
    diaHelp->setCursor(Qt::ArrowCursor);
    diaHelp->setMinimumWidth(gHelpWidt);
    diaHelp->setMaximumWidth(gHelpWidt);
    diaHelp->setMinimumHeight(gHelpHeig);
    diaHelp->setMaximumHeight(gHelpHeig+200);
    diaHelp->setGeometry(gHelpLefx, gHelpTopy, gHelpWidt, gHelpHeig);
    diaHelp->move(gHelpLefx, gHelpTopy);                // necessary!

    QString sStyl = "background-color:#151515;color:#ffffff; ";
    sStyl = sStyl + "QPushButton {min-height:20px;max-height:20px;min-width:70px;max-width:70px;background-color:#202020;color:#ffffff;border:1px solid #555555;border-radius:3px;text-align:left;padding-left:2px;} ";
    sStyl = sStyl + "QPushButton:hover {border-color:#6666ff;} ";
    diaHelp->setStyleSheet(sStyl);

    labHelp = new QLabel(sText, diaHelp);
    labHelp->setStyleSheet("color:#ffffff;");
    labHelp->setGeometry(5, 3, iLineWidt, iLineHeig);

    diaHelp->exec();
}

QString butToolC::fL(QString sI)                        // gpb 120315
{
    QString sO = sI;

    if (gLang > 0)
    {
        if (sI == "Help") sO = gLang == 1 ? "Aide" : "Hulp";
        else if (sI == "Edit text/timecode") sO = gLang == 1 ? "Éditer texte/timecode" : "Editie";
        else if (sI == "File info") sO = gLang == 1 ? "Info sur le fichier" : "File info";
        else if (sI == "Save modified file as...") sO = gLang == 1 ? "Enregistrer le fichier modifié sous..." : "Correcties opslaan";
        else if (sI == "Undo changes (in reverse chronology)") sO = gLang == 1 ? "Annuler les changements (antichronologiquement)" : "Overgave van correcties";
        else if (sI == "Go to line...") sO = gLang == 1 ? "Aller à la ligne..." : "Gaan naar lijn...";
        else if (sI == "Find...") sO = gLang == 1 ? "Chercher..." : "Zoeken...";
        else if (sI == "Hide/Show screen") sO = gLang == 1 ? "Cacher/afficher l'écran" : "Hide/Show screen";
        else if (sI == "Previous subtitle") sO = gLang == 1 ? "sous-titre précédent" : "Vorige ondertitel";
        else if (sI == "Next subtitle") sO = gLang == 1 ? "sous-titre suivant" : "Volgende ondertitel";
        else if (sI == "Start/Pause timer [Space]") sO = gLang == 1 ? "Démarrer/Pause [Espace]" : "Starten/Pauzen";
        else if (sI == "Decelerate [- or M]") sO = gLang == 1 ? "Ralentir [- ou M]" : "Decelerate";
        else if (sI == "Accelerate [+ or P]") sO = gLang == 1 ? "Accélérer [+ ou P]" : "Accelerate";
        else if (sI == "Jump backwards") sO = gLang == 1 ? "Saut en arrière" : "Jump backwards";
        else if (sI == "Jump forward") sO = gLang == 1 ? "Saut en avant" : "Jump forward";
    }
    return sO;
}
