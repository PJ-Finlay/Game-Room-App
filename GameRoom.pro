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
    ui/views/gamechooser.cpp \
    ui/views/gameplay.cpp \
    games/game.cpp \
    mainview.cpp \
    gamelist.cpp \
    games/individual_game/tictactoe.cpp \
    ui/widgets/gamechooserbutton.cpp

HEADERS  += \
    ui/views/gamechooser.h \
    ui/views/gameplay.h \
    games/game.h \
    mainview.h \
    gamelist.h \
    games/individual_game/tictactoe.h \
    ui/widgets/gamechooserbutton.h
