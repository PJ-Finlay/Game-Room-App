#include "tictactoegamewidget.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QResizeEvent>

TicTacToeGameWidget::TicTacToeGameWidget(QWidget* parent) : PieceBasedGameWidget(parent)
{
    gameState = "_________";
    QPixmap background(":/images/individual_games/tic_tac_toe/Board.png");
    this->setBackground(background);
    QObject::connect(this,SIGNAL(boardClicked(double,double)),this,SLOT(squareClicked(double,double)));
}

void TicTacToeGameWidget::drawPiece(int x, int y, bool isX)
{

    //Get the path to the image to be placed
    QString imagePath = ":/images/individual_games/tic_tac_toe/";
    if(isX){
        imagePath += "X.png";
    }else{
        imagePath += "O.png";
    }

    //Get the size and coordinates of the piece to place
    float xPos = ((float)x) / 3;
    //int yPos = scene->height() - ((1/3) * y) - (1/3);
    float yPos = .66 - (((float)y)/3);

    //Create the pixmap of the piece & resize it to the correct size
    QPixmap pixmap(imagePath);

    Piece p(imagePath,pixmap,.33,.33,xPos,yPos);
    this->addPiece(p);
}

void TicTacToeGameWidget::setGameState(QString gameState)
{
    this->clearPieces();
    //reset the internal record of the gameState
    this->gameState = gameState;

    //Loop through the gamestate and draw the appropriate pieces
    for(int i = 0; i < 9; i++){ //loop through the gameState string's characters
        if(gameState.mid(i,1).compare("X") == 0){
            drawPiece(i % 3, 2 - (i / 3),true);
        }
        if(gameState.mid(i,1).compare("O") == 0){
            drawPiece(i % 3, 2 - (i / 3),false);
        }
    }
    this->renderPieces();
}

void TicTacToeGameWidget::squareClicked(double x, double y)
{
    //Calculate the coordinates in TicTacToe coordinates of the click
    int squareX = (int)(x * 3);
    int squareY = -1 * ((int)(y * 3)) + 2;

    //Calculate the move that was made
    QString move = QString::number(squareX) + QString::number(squareY);

    //Emit the moveEntered signal with the move that was made
    emit moveEntered(move);
}
