#include "minimax.h"

#include <QStringList>
#include <QDebug>

QString Minimax::pickMove(GameState* gamestate)
{
    QStringList moves = gamestate->findValidMoves();
    double bestMove = -1;
    int bestMoveIndex = 0;
    for(int i = 0; i < moves.size(); i++){
    //for(int i = moves.size() - 1; i >= 0; i--){
      int valueOfMove = Minimax::getValueOfMove(gamestate,moves.at(i));
      if(valueOfMove > bestMove){
          bestMoveIndex = i;
          bestMove = valueOfMove;
      }

    }


    return moves.at(bestMoveIndex);

}

double Minimax::getValueOfMove(GameState* gamestate, QString move, int maxDepth, int currentDepth)
{
    if(currentDepth >= maxDepth){
        return gamestate->competitivePosition(gamestate->getTurn());
    }

    QString initialState = gamestate->getGameState(); //Save the initial state of the gamestate object so that it is not modified over the course of the method
    int playerID = gamestate->getTurn();

    //Find out if the game is over
    gamestate->makeMove(move);
    int winner = gamestate->findWinners();
    if(winner > -1){//If a winner is found
        if(winner == 0){//There was a tie
            return 0;
        }
        if(winner == playerID){
            return 1;
        } else{
            return -1;
        }
    }
    //Find the value of the opponents best move
    QStringList moves = gamestate->findValidMoves();
    double bestMove = -1;
    for(int i = 0; i < moves.size(); i++){
        int valueOfMove = getValueOfMove(gamestate,moves.at(i), maxDepth, currentDepth + 1);
        if(valueOfMove > bestMove){
            bestMove = valueOfMove;
        }
    }

    int inverse = -1 * bestMove;

    gamestate->setGameState(initialState); //Reset the value of the gamestate object

    return inverse;
}
