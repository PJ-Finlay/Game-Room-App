#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QVBoxLayout>

#include "games/game.h"

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    QVBoxLayout* layout;
    QWidget* currentWidget;


signals:

public slots:
    void openGame(Game game);
};

#endif // MAINVIEW_H
