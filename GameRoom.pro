QT += core gui
QT += widgets

CONFIG += c++11

TARGET = GameRoom
TEMPLATE = app

release: DESTDIR = ../gameroom_build/release
debug:   DESTDIR = ../gameroom_build/debug
OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

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
    games/individual_game/checkers.cpp \
    ai/computer_players/checkerscomputerplayer.cpp \
    debug/unittests/othertest/othertests.cpp \
    gamestate/elements/deck.cpp \
    gamestate/elements/card.cpp \
    gamestate/individual_game_states/heartsgamestate.cpp

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
    games/individual_game/checkers.h \
    ai/computer_players/checkerscomputerplayer.h \
    debug/unittests/othertest/othertests.h \
    gamestate/elements/deck.h \
    gamestate/elements/card.h \
    gamestate/individual_game_states/heartsgamestate.h
