#include "piecebasedgamewidget.h"

#include <QGraphicsPixmapItem>

PieceBasedGameWidget::PieceBasedGameWidget(QWidget *parent) : GameWidget(parent)
{
    layout = new QVBoxLayout(this);
    this->setLayout(layout);
    gameState = "_________";
    scene = new ClickableScene(this);
    view = new QGraphicsView(scene,this);
    layout->addWidget(view);
    placedPieces = QList<Piece>();

    //Create the Background
    QPixmap temp;
    background = temp;

}

void PieceBasedGameWidget::setBackground(QPixmap pixmap)
{
    this->background = pixmap;
}

void PieceBasedGameWidget::addPiece(Piece newPiece)
{
    placedPieces.append(newPiece);
}

void PieceBasedGameWidget::clearPieces()
{
    placedPieces.clear();
}

QList<Piece> PieceBasedGameWidget::getPlacedPieces() const
{
    return placedPieces;
}

void PieceBasedGameWidget::renderPieces()
{
    int width = scene->width();
    int height = scene->height();

    for(int i = 0; i < placedPieces.size(); i++){
        Piece piece = placedPieces.at(i);

        //Create the pixmap of the piece & resize it to the correct size
        QPixmap pixmap = piece.getPixmap();
        pixmap = pixmap.scaled(piece.getXSize() * width,piece.getYSize() * height);

        //Create the piece & add it to the scene & put it in the correct location
        QGraphicsPixmapItem* graphicsItem = new QGraphicsPixmapItem(pixmap);
        scene->addItem(graphicsItem);
        graphicsItem->setPos(piece.getX() * width,piece.getY() * height);
    }
}

void PieceBasedGameWidget::resizeEvent(QResizeEvent *event)
{
    //Reset the scene/view
    layout->removeWidget(view);
    delete scene;
    delete view;
    scene = new ClickableScene(this);
    view = new QGraphicsView(scene,this);
    layout->addWidget(view);

    QObject::connect(scene,SIGNAL(clicked(int,int)),this,SLOT(sceneClicked(int,int)));

    //Redraw the background
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(background.scaled(event->size().width() - 50,event->size().height() - 50,Qt::KeepAspectRatio));
    scene->addItem(backgroundItem);

    //Redraw the pieces
    renderPieces();

    //Show the view if it is not already visible
    //view->show();
}

void PieceBasedGameWidget::sceneClicked(int x, int y)
{
    double relativeX = x/scene->width();
    double relativeY = y/scene->height();
    emit boardClicked(relativeX,relativeY);
}
