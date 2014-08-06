#-------------------------------------------------
#
# Project created by QtCreator 2014-08-05T20:12:04
#
#-------------------------------------------------

QT       += core gui
QT 	 += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Counter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingswindow.cpp

HEADERS  += mainwindow.h \
    settingswindow.h

FORMS    += mainwindow.ui \
    settingswindow.ui

CONFIG += mobility
MOBILITY = 

