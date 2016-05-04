#include "piece.h"

Piece::Piece(QString id, QPixmap pixmap, float xSize, float ySize, float x, float y)
{
    this->id = id;
    this->pixmap = pixmap;
    this->xSize = xSize;
    this->ySize = ySize;
    this->x = x;
    this->y = y;
}

QString Piece::getId() const
{
    return id;
}

void Piece::setId(const QString &value)
{
    id = value;
}

float Piece::getXSize() const
{
    return xSize;
}

void Piece::setXSize(float value)
{
    xSize = value;
}

float Piece::getYSize() const
{
    return ySize;
}

void Piece::setYSize(float value)
{
    ySize = value;
}

float Piece::getX() const
{
    return x;
}

void Piece::setX(float value)
{
    x = value;
}

float Piece::getY() const
{
    return y;
}

void Piece::setY(float value)
{
    y = value;
}

QPixmap Piece::getPixmap() const
{
    return pixmap;
}

void Piece::setPixmap(const QPixmap &value)
{
    pixmap = value;
}
