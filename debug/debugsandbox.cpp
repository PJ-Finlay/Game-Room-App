#include "debugsandbox.h"

#include <QDebug>
#include "debug/unittests/testdirectory.h"
#include "cli.h"
#include <iostream>
#include <string>

//Temporary Includes
#include "../ui/widgets/game_widgets/checkersgamewidget.h"
#include "../gamestate/individual_game_states/checkersgamestate.h"
#include "../ui/widgets/game_widgets/tictactoegamewidget.h"
#include "../gamestate/individual_game_states/tictactoegamestate.h"

using namespace std;


void DebugSandbox::test()
{
    //CheckersGameState g;
    TicTacToeGameState g;
    g.initializeGame();
    g.printGameState();

    //CheckersGameWidget* w = new CheckersGameWidget;
    TicTacToeGameWidget* w = new TicTacToeGameWidget;
    w->setGameState(g.getGameState());
    w->show();

    while(true){
        w->setGameState(g.getGameState());
        string input;
        cin >> input;
        //QString move = QString::fromStdString(string);
       g.makeMove(QString::fromStdString(input));
    }

}

void DebugSandbox::cli()
{
    CLI::play();
}

void DebugSandbox::unitests()
{
    TestDirectory::allTests();
}

