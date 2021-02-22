QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        src/login.cpp \
        src/main.cpp \
        ui/crimestatsmain.cpp

FORMS += \
    ui/crimestatsmain.ui \
    ui/login.ui

HEADERS += \
    headers/login.h \
    ui/crimestatsmain.h

BUILD += \
    build/ui_login.h

QT += widgets

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
