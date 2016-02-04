#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <memory>

#include "games/game.h"

/**
 * @brief The MainView class is a widget that contains all of the other widgets that will be shown on screen. It manages switching between different views by displaying them within itself.
 */
class MainView : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new MainView object
     * @param The QWidget pointer of the main views parent
     */
    explicit MainView(QWidget *parent = 0);

public slots:
    /**
     * @brief Slot to change the view to a GamePlay QWidget, and pass it the Game parameter
     * @param game The game that will be played
     */
    void openGame(std::shared_ptr<Game> game);

    /**
     * @brief Slot to change the view to the GameChooser QWidget
     */
    void openGameChooser();

private:
    void swapViews(QWidget* newView);
    QVBoxLayout* layout;
    QWidget* currentWidget;

};

#endif // MAINVIEW_H
