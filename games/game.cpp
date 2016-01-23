#include "game.h"

#include <QLabel>

#include "../gamestate/individual_game_states/tictactoegamestate.h" //Should be temporary
#include "../ai/computer_players/tictactoecomputerplayer.h" //Should be temporary

QString Game::getName() const{
    return this->name;
}

void Game::setName(QString name){
    this->name = name;
}

QWidget* Game::getGameWidget() const{
    QLabel* p = new QLabel(getName());
    return p;
}

std::shared_ptr<GameState> Game::getGameState() const
{
    qDebug() << "Game.h - getGameState";
    std::shared_ptr<TicTacToeGameState> toReturn(new TicTacToeGameState());
    return toReturn;
}

std::shared_ptr<ComputerPlayer> Game::getComputerPlayer() const
{
    qDebug() << "Game.h - getComputerPlayer";
    std::shared_ptr<TicTacToeComputerPlayer> toReturn(new TicTacToeComputerPlayer());
    return toReturn;
}


