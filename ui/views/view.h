#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

/**
 * @brief A QWidget that takes up the entire users screen at a time. A MainView switches between different Views.
 * The View provides the Normal view functionality which auto sets the vertical size policy to fixed then sets the parents alignment to Qt::AlignTop
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

    /**
     * @brief Gets if the view is a "Normal View"
     * @return If the view is a normal view
     */
    bool getIsNormalView() const;

    /**
     * @brief Sets if the view is a "Normal View"
     * @param value If the view should be a "Normal View"
     */
    void setIsNormalView(bool value);

private:
    bool isNormalView;

signals:

public slots:
};

#endif // VIEW_H
