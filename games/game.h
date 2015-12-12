#ifndef GAME_H
#define GAME_H

#include <QString>

class Game
{
public:
    Game();
    QString getName();
    void setName(QString name);

private:
    QString name;

};

#endif // GAME_H
