#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QVBoxLayout>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    QVBoxLayout* layout;
    QWidget* currentWidget;


signals:

public slots:
    void openGame();
};

#endif // MAINVIEW_H
