#include "piecebasedgamewidget.h"

#include <QGraphicsPixmapItem>

PieceBasedGameWidget::PieceBasedGameWidget(QWidget *parent) : GameWidget(parent)
{
    layout = new QVBoxLayout(this);
    this->setLayout(layout);
    gameState = "_________";
    widthHeightRatio = 1;
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
    int height = scene ->height();

    layout->removeWidget(view);

    scene->deleteLater();
    view->deleteLater();

    scene = new ClickableScene(this);
    view = new QGraphicsView(scene,this);


    layout->addWidget(view);

    QObject::connect(scene,SIGNAL(clicked(int,int)),this,SLOT(sceneClicked(int,int)));
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(background.scaled(width,height,Qt::KeepAspectRatio));
    scene->addItem(backgroundItem);

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

void PieceBasedGameWidget::setWidthHeightRatio(float ratio)
{
    widthHeightRatio = ratio;
}

float PieceBasedGameWidget::getWidthHeightRatio()
{
    return widthHeightRatio;
}

void PieceBasedGameWidget::resizeEvent(QResizeEvent *event)
{

    int height = event->size().height() - 30;
    int width = height * widthHeightRatio;
    if(width > event->size().width() - 30){
        width = event->size().width() - 30;
        height = width / widthHeightRatio;
    }
    scene->setSceneRect(0,0,width,height);
    //Redraw the pieces
    renderPieces();

}

void PieceBasedGameWidget::sceneClicked(int x, int y)
{
    double relativeX = x/scene->width();
    double relativeY = y/scene->height();
    emit boardClicked(relativeX,relativeY);
}
