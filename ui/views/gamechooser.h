#ifndef GAMECHOOSER_H
#define GAMECHOOSER_H

#include <QWidget>

class GameChooser : public QWidget
{
    Q_OBJECT
public:
    GameChooser(QWidget *parent = 0);

signals:
    void gameChosen();

public slots:
    void selectGame();
};

#endif // GAMECHOOSER_H
