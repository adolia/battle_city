#ifndef STAGEOBJECT_H
#define STAGEOBJECT_H

#include <QtQuick/QQuickItem>

/**
 *  @brief The StageObject class is a base class for each visual object (Item)
 **/
class StageObject : public QQuickItem
{
    Q_OBJECT
    /* Copy constructor */
    StageObject(const StageObject &) = default;
    StageObject & operator = (const StageObject &) { return *this; }

protected:
    /* protect cosnstructor to create Abstract class */
    StageObject(QQuickItem *parent = Q_NULLPTR);

public:
    /* Moving direction */
    enum MovingDirection {
        MOVING_UP,
        MOVING_DOWN,
        MOVING_LEFT,
        MOVING_RIGHT,
        MOVING_NONE
    };

signals:

public slots:
};

#endif // STAGEOBJECT_H
