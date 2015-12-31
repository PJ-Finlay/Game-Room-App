#include "gamestate.h"

#include <QDebug>

GameState::GameState()
{
    undoEnabled = false;

}

void GameState::makeMove(QString move)
{
    undoRecord.append(this->getGameState());
    updateGameState(move);
}

bool GameState::getUndoEnabled()
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

int GameState::undosRemaining()
{
    return undoRecord.size();
}

double GameState::competitivePosition(int player)
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

#ifdef QT_DEBUG
void GameState::printGameState()
{
    qDebug() << this->getGameState();
}
#endif
