TEMPLAE = app
TARGET = person

QT += core
QT -= gui

DESTDIR = ../exe

CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    main.cpp

HEARDS += personinterface.h

HEADERS += \
    personinterface.h

