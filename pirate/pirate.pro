#-------------------------------------------------
#
# Project created by QtCreator 2022-12-14T15:08:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pirate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    weapons1.cpp \
    weapons2.cpp \
    ckernel.cpp

HEADERS  += mainwindow.h \
    login.h \
    weapons1.h \
    weapons2.h \
    ckernel.h \
    packdef.h

FORMS    += mainwindow.ui \
    login.ui \
    weapons1.ui \
    weapons2.ui

RESOURCES += \
    res.qrc
