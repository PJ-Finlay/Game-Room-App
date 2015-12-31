#include "gamestatestests.h"


#include <QDebug>
#include <QStringList>

#include "../../gamestate/individual_game_states/tictactoegamestate.h"

bool GameStatesTests::testTicTacToeGameState()
{
    bool allTestsPassed = true;

    TicTacToeGameState t;

    //Testing setGameState, and getGameState
    t.setGameState(QString("XXXOOOXXX"));
    if(t.getGameState().compare("XXXOOOXXX") != 0){
        qDebug() << "updateGameState or getGameState not working correctly";
        allTestsPassed = false;
    }
    t.setGameState(QString("X_OO_X__X"));
    if(t.getGameState().compare("X_OO_X__X") != 0){
        qDebug() << "updateGameState or getGameState not working correctly";
        allTestsPassed = false;
    }
    t.setGameState(QString("X_XXO_XOO"));
    if(t.getGameState().compare("X_XXO_XOO") != 0){
        qDebug() << "updateGameState or getGameState not working correctly";
        allTestsPassed = false;
    }
    t.setGameState(QString("XXXXXXXXX"));
    if(t.getGameState().compare("XXXXXXXXX") != 0){
        qDebug() << "updateGameState or getGameState not working correctly";
        allTestsPassed = false;
    }
    t.setGameState(QString("_________"));
    if(t.getGameState().compare("_________") != 0){
        qDebug() << "updateGameState or getGameState not working correctly";
        allTestsPassed = false;
    }

    //Testing setGameState for proper turn handling
    /**
    t.initializeGame();
    if(t.getTurn() != 1){
        qDebug() << "setGameState not setting turn correcctly";
        allTestsPassed = false;
    }
**/



    //Testing initializeGame
    t.initializeGame();
    if(t.getGameState().compare("_________") != 0){
        qDebug() << "initializeGame not working correctly";
        allTestsPassed = false;
    }

    //Testing setGameState
    t.setGameState(QString("X________"));
    if(t.getGameState().compare("X________") != 0){
        qDebug() << "setGameState not working correctly";
        allTestsPassed = false;
    }
    t.setGameState(QString("________O"));
    if(t.getGameState().compare("________O") != 0){
        qDebug() << "setGameState not working correctly";
        allTestsPassed = false;
    }
    t.setGameState(QString("XOXOXOXOX"));
    if(t.getGameState().compare("XOXOXOXOX") != 0){
        qDebug() << "setGameState not working correctly";
        allTestsPassed = false;
    }
    t.setGameState(QString("XOOOXOOOX"));
    if(t.getGameState().compare("XOOOXOOOX") != 0){
        qDebug() << "setGameState not working correctly";
        allTestsPassed = false;
    }

    //Testing isValidMove
    t.initializeGame();
    if(!t.isValidMove(QString("00"))){
        qDebug() << "isValidMove not working correctly";
        allTestsPassed = false;
    }
    t.setGameState("X________");
    if(t.isValidMove(QString("02"))){
        qDebug() << "isValidMove not working correctly";
        allTestsPassed = false;
    }
    t.setGameState("____O____");
    if(t.isValidMove(QString("11"))){
        qDebug() << "isValidMove not working correctly";
        allTestsPassed = false;
    }

    //Testing updateGameState
    t.initializeGame();
    t.updateGameState(QString("00"));
    if(t.getGameState().compare("______X__") != 0){
        qDebug() << "updateGameState not working";
        allTestsPassed = false;
    }
    t.updateGameState(QString("11"));
    if(t.getGameState().compare("____O_X__") != 0){
        qDebug() << "updateGameState not working";
        allTestsPassed = false;
    }
    t.updateGameState(QString("20"));
    if(t.getGameState().compare("____O_X_X") != 0){
        qDebug() << "updateGameState not working";
        allTestsPassed = false;
    }
    t.updateGameState(QString("02"));
    if(t.getGameState().compare("O___O_X_X") != 0){
        qDebug() << "updateGameState not working";
        allTestsPassed = false;
    }

    //Testing findWinners
    t.initializeGame();
    if(t.findWinners() != -1){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    t.setGameState("XOOX_XOXX");
    if(t.findWinners() != -1){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    t.setGameState("XOXXOXOXO");
    if(t.findWinners() != 0){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    //Test rows
    t.setGameState("XXX______");
    if(t.findWinners() != 1){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    t.setGameState("___OOO___");
    if(t.findWinners() != 2){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    t.setGameState("______XXX");
    if(t.findWinners() != 1){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    //Test columns
    t.setGameState("O__O__O__");
    if(t.findWinners() != 2){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    t.setGameState("_X__X__X_");
    if(t.findWinners() != 1){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    t.setGameState("__O__O__O");
    if(t.findWinners() != 2){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    //Test Diags
    t.setGameState("X___X___X");
    if(t.findWinners() != 1){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    t.setGameState("__O_O_O__");
    if(t.findWinners() != 2){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    //Test full board
    t.setGameState("XXXOOXOXX");
    if(t.findWinners() != 1){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }
    t.setGameState("OOOXXOXOO");
    if(t.findWinners() != 2){
        qDebug() << "findWinners not working";
        allTestsPassed = false;
    }

    //Testing enableUndo and getUndoEnabled
    if(t.getUndoEnabled() != false){
        qDebug() << "enableUndo or getUndoEnabled not working";
        allTestsPassed = false;
    }
    t.enableUndo();
    if(t.getUndoEnabled() != true){
        qDebug() << "enableUndo or getUndoEnabled not working";
        allTestsPassed = false;
    }

    //Testing undoMove
    t.initializeGame();
    t.enableUndo();
    t.makeMove(QString("02"));
    t.makeMove(QString("01"));
    t.makeMove(QString("00"));
    t.undoMove();
    if(t.getGameState().compare("X__O_____") != 0){
        qDebug() << "undoMove not working";
        allTestsPassed = false;
    }
    t.makeMove(QString("22"));
    if(t.getGameState().compare("X_XO_____") != 0){
        qDebug() << "undoMove not working";
        allTestsPassed = false;
    }
    t.makeMove(QString("11"));
    if(t.getGameState().compare("X_XOO____") != 0){
        qDebug() << "undoMove not working";
        allTestsPassed = false;
    }
    t.undoMove();
    t.undoMove();
    if(t.getGameState().compare("X__O_____") != 0){
        qDebug() << "undoMove not working";
        allTestsPassed = false;
    }

    //Testing findValidMoves
    t.initializeGame();
    QStringList validMoves = t.findValidMoves();
    QStringList expectedValue;
    expectedValue.append(QString("00"));
    expectedValue.append(QString("01"));
    expectedValue.append(QString("02"));
    expectedValue.append(QString("10"));
    expectedValue.append(QString("11"));
    expectedValue.append(QString("12"));
    expectedValue.append(QString("20"));
    expectedValue.append(QString("21"));
    expectedValue.append(QString("22"));
    validMoves.sort();
    expectedValue.sort();
    if(validMoves.operator !=(expectedValue)){
        qDebug() << "findValidMoves not working";
        allTestsPassed = false;
    }

    t.setGameState("X________");
    validMoves = t.findValidMoves();
    expectedValue = QStringList();
    expectedValue.append(QString("00"));
    expectedValue.append(QString("01"));
    expectedValue.append(QString("10"));
    expectedValue.append(QString("11"));
    expectedValue.append(QString("12"));
    expectedValue.append(QString("20"));
    expectedValue.append(QString("21"));
    expectedValue.append(QString("22"));
    validMoves.sort();
    expectedValue.sort();
    if(validMoves.operator !=(expectedValue)){
        qDebug() << "findValidMoves not working";
        allTestsPassed = false;
    }

    t.setGameState("XOXOXOXOX");
    validMoves = t.findValidMoves();
    if(validMoves.size() != 0){
        qDebug() << "findValidMoves not working";
        allTestsPassed = false;
    }

    t.setGameState("X_XXXXXXX");
    validMoves = t.findValidMoves();
    expectedValue = QStringList();
    expectedValue.append(QString("12"));
    validMoves.sort();
    expectedValue.sort();
    if(validMoves.operator !=(expectedValue)){
        qDebug() << "findValidMoves not working";
        allTestsPassed = false;
    }

    if(!allTestsPassed){
        qDebug() << "TicTacToeGameState Failed";
    }
    return allTestsPassed;
}
