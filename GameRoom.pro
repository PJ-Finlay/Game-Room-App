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
    games/game.cpp \
    gamelist.cpp \
    games/individual_game/tictactoe.cpp \
    gamestate/individual_game_states/tictactoegamestate.cpp \
    gamestate/gamestate.cpp \
    debug/debugsandbox.cpp \
    debug/unittests/testdirectory.cpp \
    ai/algorithms/minimax.cpp \
    debug/unittests/aialgorithm/aialgorithmtester.cpp \
    ai/computer_players/computerplayer.cpp \
    ai/computer_players/tictactoecomputerplayer.cpp \
    debug/cli.cpp \
    debug/unittests/gametests/checkerstests.cpp \
    debug/unittests/gametests/tictactoetests.cpp \
    gamestate/individual_game_states/checkersgamestate.cpp \
    games/individual_game/checkers.cpp



HEADERS  += \
    games/game.h \
    gamelist.h \
    games/individual_game/tictactoe.h \
    gamestate/individual_game_states/tictactoegamestate.h \
    gamestate/gamestate.h \
    debug/debugsandbox.h \
    debug/unittests/testdirectory.h \
    ai/algorithms/minimax.h \
    debug/unittests/aialgorithm/aialgorithmtester.h \
    ai/computer_players/computerplayer.h \
    ai/computer_players/tictactoecomputerplayer.h \
    debug/cli.h \
    games/game_type/cardgame.h \
    debug/unittests/gametests/checkerstests.h \
    debug/unittests/gametests/tictactoetests.h \
    gamestate/individual_game_states/checkersgamestate.h \
    games/individual_game/checkers.h

CONFIG += c++11
