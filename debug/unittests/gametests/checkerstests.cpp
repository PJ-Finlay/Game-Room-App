#include "checkerstests.h"

#include <QDebug>

#include "../../../gamestate/individual_game_states/checkersgamestate.h"

bool CheckersTests::allTests()
{
    bool allTestsPassed = true;

    if(!testCheckersGameState()) allTestsPassed = false;

    if(!allTestsPassed) qDebug() << "Checkers Failed";

    return allTestsPassed;
}

bool CheckersTests::testCheckersGameState()
{
    bool allTestsPassed = true;

    CheckersGameState g;

    //Test getTurn
    if(g.getTurn() != 1){
        allTestsPassed = false;
        qDebug() << "Getting or setting turn not working correctly";
    }

    //Test setGameState and getGameState
    g.setGameState(QString("____________________________r______b_____r_b____________________1"));
    if(g.getGameState().compare("____________________________r______b_____r_b____________________1") != 0){
        allTestsPassed = false;
        qDebug() << "setGameState or getGamestate not working";
    }
    g.setGameState(QString("____________________________r______b_____r_b____________________2"));
    if(g.getGameState().compare("____________________________r______b_____r_b____________________2") != 0){
        allTestsPassed = false;
        qDebug() << "setGameState or getGamestate not working";
    }
    g.setGameState(QString("b___________________________r______b_____r_b____________________1"));
    if(g.getGameState().compare("b___________________________r______b_____r_b____________________1") != 0){
        allTestsPassed = false;
        qDebug() << "setGameState or getGamestate not working";
    }
    g.setGameState(QString("____________________________r______b_____r_b___________________r1"));
    if(g.getGameState().compare("____________________________r______b_____r_b___________________r1") != 0){
        allTestsPassed = false;
        qDebug() << "setGameState or getGamestate not working";
    }

    //Testing findValidMoves
    g.setGameState("________________________________________________________________1");
    if(g.findValidMoves().join(",").compare("") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("________________________________________________________b_______1");
    if(g.findValidMoves().join(",").compare("0011") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("_______________________________________________________________b1");
    if(g.findValidMoves().join(",").compare("7061") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("______________________________________________________r________b1");
    if(g.findValidMoves().join(",").compare("7052") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("______________________________________________________r________b2");
    if(g.findValidMoves().join(",").compare("6150") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("b_______________________________________________________________2");
    if(g.findValidMoves().join(",").compare("") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("b_______________________________________________________________1");
    if(g.findValidMoves().join(",").compare("") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("r_______________________________________________________________1");
    if(g.findValidMoves().join(",").compare("") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("r_______________________________________________________________2");
    if(g.findValidMoves().join(",").compare("0716") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("r________b______________________________________________________2");
    if(g.findValidMoves().join(",").compare("0725") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("r________b______________________________________________________1");
    if(g.findValidMoves().join(",").compare("1627") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("_______r________________________________________________________2");
    if(g.findValidMoves().join(",").compare("7766") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("_______r______b_________________________________________________2");
    if(g.findValidMoves().join(",").compare("7755") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("_____________________b_____________________r____________________1");
    QStringList validMoves = g.findValidMoves();
    if(!validMoves.contains("5566") || !validMoves.contains("5546") || validMoves.size() != 2){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("_____________________b_____________________r____________________2");
    validMoves = g.findValidMoves();
    if(!validMoves.contains("3221") || !validMoves.contains("3241") || validMoves.size() != 2){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    //Do tests with kings
    g.setGameState("B_______________________________________________________________1");
    if(g.findValidMoves().join(",").compare("0716") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("B_______________________________________________________________2");
    if(g.findValidMoves().join(",").compare("") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("_______________________________________________________________R2");
    if(g.findValidMoves().join(",").compare("7061") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("_______________________________________________________________R1");
    if(g.findValidMoves().join(",").compare("") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("______________________________________________________b________R2");
    if(g.findValidMoves().join(",").compare("7052") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("______________________________________________________B________R2");
    if(g.findValidMoves().join(",").compare("7052") != 0){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }
    g.setGameState("______________________________________________________B________R1");
    validMoves = g.findValidMoves();
    if(!validMoves.contains("6150") || !validMoves.contains("6172") || !validMoves.contains("6152") || validMoves.size() != 3){
        allTestsPassed = false;
        qDebug() << "findValidMoves not working correctly";
    }

    //Test findWinners
    g.setGameState("________________________________________________________________2");
    if(g.findWinners() != 0){
        allTestsPassed = false;
        qDebug() << "findWinners not working correctly";
    }
    g.setGameState("_________________________b______________________________________2");
    if(g.findWinners() != 1){
        allTestsPassed = false;
        qDebug() << "findWinners not working correctly";
    }
    g.setGameState("_________________________b______________________________________1");
    if(g.findWinners() != 1){
        allTestsPassed = false;
        qDebug() << "findWinners not working correctly";
    }
    g.setGameState("_________________________r______________________________________1");
    if(g.findWinners() != 2){
        allTestsPassed = false;
        qDebug() << "findWinners not working correctly";
    }
    g.setGameState("_________________________R______________________________________1");
    if(g.findWinners() != 2){
        allTestsPassed = false;
        qDebug() << "findWinners not working correctly";
    }
    g.setGameState("_________________________B______________________________________1");
    if(g.findWinners() != 1){
        allTestsPassed = false;
        qDebug() << "findWinners not working correctly";
    }
    g.setGameState("_________________________R_____________B________________________1");
    if(g.findWinners() != -1){
        allTestsPassed = false;
        qDebug() << "findWinners not working correctly";
    }
    g.setGameState("_________________________R______________________RRBbr___________1");
    if(g.findWinners() != -1){
        allTestsPassed = false;
        qDebug() << "findWinners not working correctly";
    }

    //Testing initializeGame
    g.initializeGame();
    g.printGameState();

    return allTestsPassed;
}
