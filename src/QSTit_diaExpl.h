#ifndef H_TOOLBUTT
#define H_TOOLBUTT

#include <QtGui>
#include <QToolButton>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>

class butToolC : public QToolButton
{
    Q_OBJECT

    public:

    butToolC(QWidget *wParent);

    public:

    QWidget     *parPare;
    QString     winTitl;
    QString     parText;
    int         gLang;
    QDialog     *diaHelp;
    QLabel      *labHelp;
    QLineEdit   *ediHelp;

    void fGridHelp();
    QString fL(QString);

    protected:

    virtual void mousePressEvent(QMouseEvent *qe);
    virtual void keyPressEvent(QKeyEvent *qe);
    bool event(QEvent *event);
};

#endif
