#-------------------------------------------------
#
# Project created by QtCreator 2015-11-21T11:49:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameRoom
TEMPLATE = app


SOURCES += main.cpp\
        uiwidget.cpp \
    ui/views/view.cpp \
    ui/views/gamechooser.cpp \
    ui/views/gameplay.cpp \
    games/game.cpp

HEADERS  += uiwidget.h \
    ui/views/view.h \
    ui/views/gamechooser.h \
    ui/views/gameplay.h \
    games/game.h
