#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

/**
 * @brief A QWidget that takes up the entire users screen at a time. A MainView switches between different Views
 */
class View : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a View object
     * @param The pointer of the parent QWidget
     */
    explicit View(QWidget *parent);

signals:

public slots:
};

#endif // VIEW_H
