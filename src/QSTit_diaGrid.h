#ifndef H_WINGRID
#define H_WINGRID

#include <QtGui>
#include <QTableWidget>
#include <QKeyEvent>
#include <QEvent>
#include <QDialog>

class diaSettW : public QDialog
{
    Q_OBJECT

    public:

    diaSettW(QWidget *);

    public:

    QWidget     *parWin;

    protected:

    virtual void keyPressEvent(QKeyEvent *qe);
};

class diaGridW : public QDialog
{
    Q_OBJECT

    public:

    diaGridW(QWidget *, QFrame *);

    public:

    QWidget     *parEnt;
    QFrame      *parMen;

    protected:

    void moveEvent(QMoveEvent *event);
    virtual void resizeEvent(QResizeEvent *qe);
};

class diaGridC : public QTableWidget
{
    Q_OBJECT

    public:

    diaGridC(QWidget*, QSlider*, QWidget*);

    public:

    QWidget     *parEnt;
    QSlider     *parSli;
    QWidget     *parWin;

    QPixmap     gIconGoto;
    QPixmap     gIconFind;
    QPixmap     gIconCanc;
    QPixmap     gIconDial;
    QPixmap     gIconFlag;

    int         gLang;
    bool        gGridGoto;
    bool        gGridFind;
    QString     gFindText;
    int         gFindFrom;

    QDialog     *diaGoto;
    QDialog     *diaFind;
    QLineEdit   *ediGoto;
    QLineEdit   *ediFind;

    void        fGridGoto();
    void        fGridFind();
    void        fGridFindLoop(QString, int);
    void        fGridMarkRows();

    void fWorkLang(int gLang);
    QString fL(QString);

    public slots:

    void fGridGotoCanc();
    void fGridGotoLine();
    void fGridFindCanc();
    void fGridFindWord();

    protected:

    virtual void keyPressEvent(QKeyEvent *qe);
};

#endif
