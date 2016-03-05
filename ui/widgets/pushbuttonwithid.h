#ifndef PUSHBUTTONWITHID_H
#define PUSHBUTTONWITHID_H

#include <QPushButton>

/**
 * @brief The PushButtonWithId class inherits QPushButton with the added functionality of having an id attribute with setter/getter methods.
 * It also adds the functionality of having a clicked(QString) signal that passes the id of the button.
 */
class PushButtonWithId : public QPushButton
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new PushButtonWithId object
     * @param id The id of the new PushButtonWithId
     * @param parent The parent QWidget
     */
    PushButtonWithId(QString id,QWidget* parent = 0);

    /**
     * @brief Construct a new PushButtonWithId object
     * @param id The id of the new PushButtonWithId
     * @param text The text to be displayed on the button
     * @param parent The parent QWidget
     */
    PushButtonWithId(QString id, QString text, QWidget* parent = 0);

    /**
     * @brief Gets the id of the PushButtonWithId
     * @return The id
     */
    QString getId() const;

    /**
     * @brief Sets the id of the PushButtonWithId
     * @param value The value to be set
     */
    void setId(const QString &value);
    
private:
    QString id;

public slots:
    void clicked(); //Used internally to convert clicked(bool) to clicked(QString id)

signals:
    /**
     * @brief This signal is emitted when a QPushButton would have emitted a clicked(bool) signal.
     * It also provides the id of the PushButtonWithId
     * @param id The id of the PushButtonWithId
     */
    void clicked(QString id);


};

#endif // PUSHBUTTONWITHID_H
