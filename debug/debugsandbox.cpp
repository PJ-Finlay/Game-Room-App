#include "debugsandbox.h"

#include <QDebug>
#include "debug/unittests/testdirectory.h"
#include "cli.h"

//Temporary Includes
#include "../ui/widgets/game_widgets/game_elements/general/piecebasedgamewidget.h"

void DebugSandbox::test()
{
    PieceBasedGameWidget* w = new PieceBasedGameWidget();
    QPixmap pixmap(":/images/individual_games/tic_tac_toe/Board.png");
    w->setBackground(pixmap);
    Piece p("id",pixmap,.33,.33,.33,0);

    w->addPiece(p);
    w->show();

}

void DebugSandbox::cli()
{
    CLI::play();
}

void DebugSandbox::unitests()
{
    TestDirectory::allTests();
}

