#include "checkers.h"

#include "../../ai/computer_players/checkerscomputerplayer.h"
#include "../../gamestate/individual_game_states/checkersgamestate.h"
#include "../../ui/widgets/game_widgets/checkersgamewidget.h"

Checkers::Checkers() : Game()
{
    this->setName("Checkers");
}

std::shared_ptr<GameState> Checkers::getGameState() const
{
    std::shared_ptr<CheckersGameState> toReturn(new CheckersGameState());
    return toReturn;
}

std::shared_ptr<ComputerPlayer> Checkers::getComputerPlayer() const
{
    std::shared_ptr<CheckersComputerPlayer> toReturn(new CheckersComputerPlayer());
    return toReturn;
}

GameWidget *Checkers::getGameWidget() const
{
    return new CheckersGameWidget();
}
