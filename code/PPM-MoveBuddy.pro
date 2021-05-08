QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    src/communitypagewindow.cpp \
    src/crimestatsmap.cpp \
    src/navwindow.cpp \
    src/profile.cpp \
    src/main.cpp \
    src/crimestatsmain.cpp \
    src/mainwindow.cpp \

FORMS += \
    ui/communitypagewindow.ui \
    ui/crimestatsmap.ui \
    ui/navwindow.ui \
    ui/profile.ui \
    ui/mainwindow.ui \
    ui/crimestatsmain.ui

HEADERS += \
    headers/crimestatsmain.h \
    headers/mainwindow.h \
    headers/profile.h \
    headers/navwindow.h \
    headers/crimestatsmap.h \
    headers/communitypagewindow.h

BUILD += \
    build/ui_mainwindow.h

QT += widgets
