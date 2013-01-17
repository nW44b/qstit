#include <QApplication>
#include "QSTit_winMain.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setWindowIcon(QPixmap("./Imag/QSTit_gray.png"));
    app.setFont(QFont("trebuchet ms", 9, QFont::Normal, false));

    QString sStyl = "QFrame#fraMenu {border:1px solid #ffffff;background-color:#151515;color:#ffffff;} ";
    sStyl = sStyl + "QPushButton {min-height:20px;max-height:20px;min-width:70px;max-width:90px;background-color:#202020;color:#ffffff;border:1px solid #555555;border-radius:3px;text-align:left;padding-left:2px;} ";
    sStyl = sStyl + "QPushButton:hover {border-color:#6666ff;} ";
    sStyl = sStyl + "QTabWidget {font:arial normal 8px;background-color:#151515;color:#ffffff;border:none;} ";
    sStyl = sStyl + "QTabWidget::pane {font:arial normal 8px;background-color:#151515;color:#ffffff;border:none;} ";
    sStyl = sStyl + "QTabWidget::tab-bar {font:arial normal 8px;background-color:#151515;color:#ffffff;} ";
    sStyl = sStyl + "QTabWidget::tab {border:1px solid #ffffff;border-bottom-color:#151515;margin:5px;width:70px;height:20px;} ";
    sStyl = sStyl + "QTabBar::tab:selected {background-color:#151515;color:#6666ff;width:70px;height:20px;margin-bottom:1px;margin-right:6px;border:1px solid #555555;border-radius:3px;} ";
    sStyl = sStyl + "QTabBar::tab:!selected {background-color:#151515;color:#ffffff;width:70px;height:20px;margin-bottom:1px;margin-right:6px;border:1px solid #555555;border-radius:3px;} ";
    sStyl = sStyl + "QTabBar::tab:hover {border-color:#6666ff;} ";
    sStyl = sStyl + "QTabBar::tab:hover {border-color:#6666ff;} ";
    sStyl = sStyl + "QHeaderView::section {background-color:#ffffff;color:#000000;font:lucida normal 9px;border:1px solid #cccccc;border-top:1px solid #ffffff;} ";

    app.setStyleSheet(sStyl);

    winMain wMain;
    wMain.show();
    return app.exec();
}
