#ifndef PIECE_H
#define PIECE_H
#include <QGraphicsPixmapItem>

/**
 * @brief The Piece class is used with the PieceBasedGameWidget class to provide an easier interface for using
 * QGraphicsScenes for games that use pieces.
 * id - The id of the piece or type of piece
 * pixmap - image representation of the piece
 * xSize - the size of the piece relative to the viewframe (0-1)
 * ySize - same as xSize except for y
 * x - x coordinate of the piece (0-1)
 * y - y coordinate of the piece (0-1)
 */
class Piece
{
public:
    Piece(QString id, QPixmap pixmap, float xSize = 0, float ySize = 0, float x = 0, float y = 0);


    QString getId() const;
    void setId(const QString &value);

    float getXSize() const;
    void setXSize(float value);

    float getYSize() const;
    void setYSize(float value);

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

    QPixmap getPixmap() const;
    void setPixmap(const QPixmap &value);

private:
    QString id;
    QPixmap pixmap;
    float xSize;
    float ySize;
    float x;
    float y;
};

#endif // PIECE_H
