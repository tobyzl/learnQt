#-------------------------------------------------
#
# Project created by QtCreator 2016-10-12T10:43:56
#
#-------------------------------------------------

QT += widgets multimedia winextras multimediawidgets webkitwidgets network

TARGET = movie
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loadmoviethread.cpp \
    thread.cpp

HEADERS  += mainwindow.h \
    loadmoviethread.h \
    thread.h

FORMS    += mainwindow.ui
