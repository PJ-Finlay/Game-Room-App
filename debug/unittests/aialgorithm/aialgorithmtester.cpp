#include "aialgorithmtester.h"

#include <QDebug>
#include <QString>

#include "../../../ai/algorithms/minimax.h"
#include "../../../gamestate/individual_game_states/tictactoegamestate.h"

bool AIAlgorithmTester::testMinimax()
{
    bool allTestsPassed = true;

    TicTacToeGameState g;
    g.initializeGame();
    g.setGameState(QString("XX_OO____"));
    if(Minimax::pickMove(&g).compare("22") != 0){
        qDebug() << "Minimax not working with TicTacToe";
        allTestsPassed = false;
    }

    g.setGameState(QString("_X_XOO___"));
    if(Minimax::pickMove(&g).compare("02") != 0){
        qDebug() << "Minimax not working with TicTacToe";
        allTestsPassed = false;
    }

    g.setGameState(QString("XX_OO_X__"));
    if(Minimax::pickMove(&g).compare("21") != 0){
        qDebug() << "Minimax not working with TicTacToe";
        allTestsPassed = false;
    }

    return allTestsPassed;
}
