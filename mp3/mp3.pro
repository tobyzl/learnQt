#-------------------------------------------------
#
# Project created by QtCreator 2016-10-13T15:54:26
#
#-------------------------------------------------

QT       += core gui multimedia winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mp3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    musicplayer.cpp

HEADERS  += mainwindow.h \
    musicplayer.h

FORMS    += mainwindow.ui
