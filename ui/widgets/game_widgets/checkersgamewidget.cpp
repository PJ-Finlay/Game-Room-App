#include "checkersgamewidget.h"

#include "../../../gamestate/individual_game_states/checkersgamestate.h"

CheckersGameWidget::CheckersGameWidget(QWidget* parent) : PieceBasedGameWidget(parent)
{
    QPixmap background(":/images/individual_games/chess/Board.png");
    this->setBackground(background);
    gameState = "_________";
    selectedSpace = "";
    selectionMade = false;
    QObject::connect(this,SIGNAL(boardClicked(double,double)),this,SLOT(squareClicked(double,double)));
}

void CheckersGameWidget::drawPiece(int x, int y, bool isRed, bool isKing)
{
    //Get the path to the image to be placed
    QString imagePath = ":/images/individual_games/checkers/";
    QString colorString = "Black";
    if(isRed){
        colorString = "Red";
    }
    imagePath += colorString;

    if(isKing){
        imagePath += "King";
    }

    imagePath += ".png";

    //Get the size and coordinates of the piece to place
    float xPos = ((float)x) / 8;
    float yPos = .875 - (((float)y)/8);

    //Create the pixmap of the piece & resize it to the correct size
    QPixmap pixmap(imagePath);

    float marginPercentage = .2;

    Piece p(imagePath,pixmap,.125 * (1-marginPercentage),.125 * (1-marginPercentage),xPos + 0.5 * marginPercentage * .125 ,yPos + 0.5 * marginPercentage * .125);
    this->addPiece(p);
}

void CheckersGameWidget::setGameState(QString gameState)
{
    this->clearPieces();
    //reset the internal record of the gameState
    this->gameState = gameState;

    //Loop through the gamestate and draw the appropriate pieces
    for(int i = 0; i < 64; i++){ //loop through the gameState string's characters
        if(gameState.mid(i,1).compare("r") == 0){
            drawPiece(i % 8, 7 - (i / 8),true,false);
        }
        else if(gameState.mid(i,1).compare("b") == 0){
            drawPiece(i % 8, 7 - (i / 8),false,false);
        }
        else if(gameState.mid(i,1).compare("R") == 0){
            drawPiece(i % 8, 7 - (i / 8),true,true);
        }
        else if(gameState.mid(i,1).compare("B") == 0){
            drawPiece(i % 8, 7 - (i / 8),false,true);
        }

    }
    this->renderPieces();
}

void CheckersGameWidget::squareClicked(double x, double y)
{
    //Calculate the coordinates in TicTacToe coordinates of the click
    int squareX = (int)(x * 8);
    int squareY = -1 * ((int)(y * 8)) + 7;

    //Calculate the move that was made
    QString move = QString::number(squareX) + QString::number(squareY);

    if(!selectionMade){
        selectedSpace = move;

        //Add a piece to highlight the selected square
        QPixmap pixmap(":/images/individual_games/chess/HighlightSquare.png");
        float xPos = ((float)squareX) / 8;
        float yPos = .875 - (((float)squareY)/8);
        Piece p("",pixmap,.125,.125,xPos,yPos);
        this->insert(0,p); //Moves piece to first index so it is rendered before any of the pieces
        this->renderPieces();
    }else{
        //Emit the moveEntered signal with the move that was made
        emit moveEntered(selectedSpace + move);
        this->setGameState(gameState);
        selectedSpace = "";
    }
    selectionMade = !selectionMade;
}
