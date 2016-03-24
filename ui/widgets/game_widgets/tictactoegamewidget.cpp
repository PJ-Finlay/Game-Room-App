#include "tictactoegamewidget.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QResizeEvent>

TicTacToeGameWidget::TicTacToeGameWidget(QWidget* parent) : GameWidget(parent)
{
    layout = new QVBoxLayout(this);
    this->setLayout(layout);
    gameState = "_________";
    scene = new ClickableScene(this);
    view = new QGraphicsView(scene,this);
    layout->addWidget(view);
    background = new QGraphicsPixmapItem();
    placedPieces = QList<QGraphicsItem*>();
}

void TicTacToeGameWidget::resizeEvent(QResizeEvent *event)
{
    //Clear placed pieces
    placedPieces.clear();

    //Reset the scene/view
    layout->removeWidget(view);
    delete scene;
    delete view;
    scene = new ClickableScene(this);
    view = new QGraphicsView(scene,this);
    layout->addWidget(view);
    QObject::connect(scene,SIGNAL(clicked(int,int)),this,SLOT(squareClicked(int,int)));

    //Redraw the background
    QPixmap pixmap(":/images/individual_games/tic_tac_toe/Board.png");
    pixmap = pixmap.scaled(event->size().width() - 50,event->size().height() - 50,Qt::KeepAspectRatio);
    background = new QGraphicsPixmapItem(pixmap);
    scene->addItem(background);

    //Redraw the pieces
    setGameState(gameState);

    //Show the view if it is not already visible
    view->show();
}

void TicTacToeGameWidget::drawPiece(int x, int y, bool isX)
{
    const int margin = scene->width() / 24; // The margin between the piece and the board lines

    //Get the path to the image to be placed
    QString imagePath = ":/images/individual_games/tic_tac_toe/";
    if(isX){
        imagePath += "X.png";
    }else{
        imagePath += "O.png";
    }

    //Get the size and coordinates of the piece to place
    int squareWidth = scene->width()/3;
    int squareHeight = scene->height()/3;

    int sceneXPos = x * squareWidth;
    int sceneYPos = scene->height() - (squareHeight * y) - squareHeight;

    //Create the pixmap of the piece & resize it to the correct size
    QPixmap pixmap(imagePath);
    pixmap = pixmap.scaled(scene->width()/3 - margin * 2,scene->height()/3 - margin * 2);

    //Create the piece & add it to the scene & put it in the correct location
    QGraphicsPixmapItem* piece = new QGraphicsPixmapItem(pixmap);
    scene->addItem(piece);
    piece->setPos(sceneXPos + margin,sceneYPos + margin);

    //Add the piece to the list of placed pieces
    placedPieces.append(piece);
}

void TicTacToeGameWidget::setGameState(QString gameState)
{
    //Clear already placed pieces & reset the placedPieces list
    for(int i = 0; i < placedPieces.size(); i++){
        scene->removeItem(placedPieces.at(i));
    }
    placedPieces.clear();

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
}

void TicTacToeGameWidget::squareClicked(int x, int y)
{
    //Calculate the coordinates in TicTacToe coordinates of the click
    int squareX = (int)((x * 3) / scene->width());
    int squareY = -1 * ((int)((y * 3) / scene->height()) - 2);

    //Calculate the move that was made
    QString move = QString::number(squareX) + QString::number(squareY);

    //Emit the moveEntered signal with the move that was made
    emit moveEntered(move);
}
