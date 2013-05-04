# QT += core gui   #default
# CONFIG += qt   #default
# TEMPLATE = app   #default

TARGET = qstit

MOC_DIR = ./tmp
OBJECTS_DIR = ./tmp

# Input
HEADERS += main.h \
           QSTit_diaButt.h \
           QSTit_diaGrid.h \
           QSTit_diaSkin.h \
           QSTit_fadShow.h \
           QSTit_winMain.h
SOURCES += main.cpp \
           QSTit_diaButt.cpp \
           QSTit_diaGrid.cpp \
           QSTit_diaSkin.cpp \
           QSTit_fadShow.cpp \
           QSTit_winMain.cpp
RESOURCES += QSTit.qrc

win32 {
    RC_FILE += QSTit.rc
}

unix {
    isEmpty(PREFIX) {
        PREFIX = /usr
    }
    BINDIR = $${PREFIX}/bin
    DATADIR =$${PREFIX}/share
    SHAREDIR = $${DATADIR}/$${TARGET}

    INSTALLS += target desktop icon512 iconscale

    target.path = $${BINDIR}
    
    desktop.path = $${DATADIR}/applications
    desktop.files += $${TARGET}.desktop

    icon512.path = $${DATADIR}/icons/hicolor/512x512/apps
    icon512.files += ./Imag/$${TARGET}.png

    iconscale.path = $${DATADIR}/icons/hicolor/scalable/apps
    iconscale.files += ./Imag/$${TARGET}.svg
}

macx {
    RC_FILE = ./Imag/$${TARGET}.icns
}
