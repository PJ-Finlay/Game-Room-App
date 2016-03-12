#include "tictactoegamewidget.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QResizeEvent>


#include <QDebug>

TicTacToeGameWidget::TicTacToeGameWidget(QWidget* parent) : GameWidget(parent)
{
    gameState = "_________";
    scene = new ClickableScene(this);
    view = new QGraphicsView(scene,this);
    background = new QGraphicsPixmapItem();
}

void TicTacToeGameWidget::resizeEvent(QResizeEvent *event)
{
    //Reset the scene/view
    delete scene;
    delete view;
    scene = new ClickableScene(this);
    view = new QGraphicsView(scene,this);
    QObject::connect(scene,SIGNAL(clicked(int,int)),this,SLOT(squareClicked(int,int)));

    //Redraw the background
    QPixmap pixmap(":/images/individual_games/tic_tac_toe/Board.png");
    pixmap = pixmap.scaled(event->size().width(),event->size().height());
    background = new QGraphicsPixmapItem(pixmap);
    scene->addItem(background);

    //Redraw the pieces
    setGameState(gameState);

    //Show the view if it is not already visible
    view->show();
}

void TicTacToeGameWidget::drawPiece(int x, int y, bool isX)
{
    const int margin = this->width() / 24;

    QString imagePath = ":/images/individual_games/tic_tac_toe/";
    if(isX){
        imagePath += "X.png";
    }else{
        imagePath += "O.png";
    }

    int squareWidth = this->width()/3;
    int squareHeight = this->height()/3;

    int sceneXPos = x * squareWidth;
    int sceneYPos = this->height() - (squareHeight * y) - squareHeight;


    QPixmap pixmap(imagePath);
    pixmap = pixmap.scaled(this->width()/3 - margin * 2,this->height()/3 - margin * 2);
    QGraphicsPixmapItem* piece = new QGraphicsPixmapItem(pixmap);
    scene->addItem(piece);
    piece->setPos(sceneXPos + margin,sceneYPos + margin);

}

void TicTacToeGameWidget::setGameState(QString gameState)
{
    this->gameState = gameState;
    for(int i = 0; i < 9; i++){ //loop through the gameState string's characters
        if(gameState.mid(i,1).compare("X") == 0){
            drawPiece(i % 3, 2 - (i / 3),true);
        }
        if(gameState.mid(i,1).compare("O") == 0){
            drawPiece(i % 3, 2 - (i / 3),false);
        }
    }
}

void TicTacToeGameWidget::squareClicked(int x, int y)
{
    int squareX = (int)((x * 3) / this->width());
    int squareY = (int)((y * 3) / this->height());
    squareY -= 2;
    squareY *= -1;
    QString move = QString::number(squareX) + QString::number(squareY);
    emit moveEntered(move);
}
