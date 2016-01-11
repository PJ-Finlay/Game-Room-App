#include "gamestate.h"

#include <QDebug>
#include <QStringList>

GameState::GameState()
{
    undoEnabled = false;

}

bool GameState::isValidMove(QString move) const
{
    QStringList validMoves = findValidMoves();
    if(validMoves.contains(move)){
        return true;
    }else{
        return false;
    }
}

void GameState::makeMove(QString move)
{
    undoRecord.append(this->getGameState());
    updateGameState(move);
}

bool GameState::getUndoEnabled() const
{
    return this->undoEnabled;
}

void GameState::enableUndo()
{
    undoRecord = QList<QString>();
    this->undoEnabled = true;
}

void GameState::undoMove()
{
    if(!undoRecord.isEmpty()){
        this->setGameState(undoRecord.takeLast());
    }
}

int GameState::undosRemaining() const
{
    return undoRecord.size();
}

double GameState::competitivePosition(int player) const
{
    int winner = this->findWinners();
    if(winner == -1){//Game will continue
        return 0;
    }
    if(winner == 0){//Game is a tie
        return 0;
    }
    if(winner == player){//Player has won
        return 1;
    }else{ //Another player has won
        return -1;
    }
}

void GameState::printGameState() const
{
    qDebug() << this->getGameState();
}
