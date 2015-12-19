#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QWidget>

class Game
{
public:
    Game();
    QString getName();
    void setName(QString name);
    QWidget* getGameWidget();


private:
    QString name;

};

#endif // GAME_H
