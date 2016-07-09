#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T23:41:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = LOL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    champion.cpp \
    networkrequest.cpp \
    lolstaticdata.cpp \
    riotparser.cpp \
    summoner.cpp \
    matchlist.cpp

HEADERS  += mainwindow.h \
    champion.h \
    networkrequest.h \
    lolstaticdata.h \
    riotparser.h \
    summoner.h \
    matchlist.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=gnu++11
