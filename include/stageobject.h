#ifndef STAGEOBJECT_H
#define STAGEOBJECT_H

#include <QtQuick/QQuickItem>
#include "defs.h"

class StageObject;

typedef QList<StageObject*> StageListModel;

/**
 * @brief The ObjectType  battle field objects
 */
enum ObjectType{
    PLAYERTANK,
    AITANK,
    SHELL,
    B_WALL,
    A_WALL,
    USERBASE,
    NONE_TYPE
};


/**
 *  @brief The StageObject class is a base class for each visual object (Item)
 **/
class StageObject : public QQuickItem
{
    /* Declare default width & hight object values */
    Q_OBJECT

    Q_ENUMS(MovingDirection)
    Q_PROPERTY(QString imgPath READ getImgPath CONSTANT)
    Q_PROPERTY(MovingDirection direction READ getDirection WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(int speed READ getSpeed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(bool alive READ isAlive WRITE setLiveStatus NOTIFY liveStatusChanged)
    Q_PROPERTY(bool moving READ isMoving WRITE setMoveStatus )
    Q_PROPERTY(ObjectType objectType READ getObjectType WRITE setObjectType)

    /* Disable copy constructor and an assignment operator */
    Q_DISABLE_COPY(StageObject)
    // StageObject(const StageObject &) = default;
    // StageObject & operator = (const StageObject &) { return *this; }

protected:
    /* protect cosnstructor to create Abstract class */
    StageObject(QQuickItem *parent = Q_NULLPTR);

public:
    /**
     * @brief Moving direction related to rotation property in degrees
     **/
    enum MovingDirection{
        UP,
        RIGHT = 90,
        DOWN  = 180,
        LEFT  = 270,
        NONE  = 360
    };
    /* Path to object's image  getter & setter */
    virtual QString getImgPath() const{ return this->_img_path; }
    void setImgPath(const QString& path) { this->_img_path = path; }

    /* Object type getter $ setter */
    ObjectType getObjectType() const { return this->objectType; }
    void setObjectType(ObjectType type) { this->objectType = type; }

    /* Object moving direction getter & setter */
    MovingDirection getDirection() const { return this->direction; }
    void setDirection(MovingDirection new_direction);

    /* Object speed getter $ setter */
    int getSpeed() const { return this->speed; }
    void setSpeed(int new_speed);

    /* Object live status getter & setter */
    bool isAlive() const { return this->_alive.load(); }
    void setLiveStatus(const bool live_status);

    /* Object moving status getter & setter */
    bool isMoving() const { return this->_moving.load(); }
    void setMoveStatus(bool move_status) { this->_moving = move_status; }
    void move();

    // Provides Items collision detection
    virtual QQuickItem *checkCollisions(qreal newX, qreal newY);

    /* Setters for x & y position
     * Note: Need to call basic QQuickItem setX and setY inside
     */
    virtual void setPosX(qreal);
    virtual void setPosY(qreal);

    // Destroy an Item, should be implemented
    virtual void destroy() = 0;


signals:
    /* Signals are sent when changes should be propagated to QML */
    void directionChanged(MovingDirection);
    void speedChanged(int);
    void liveStatusChanged(const bool);

protected:
    ObjectType objectType;
    /* Object moving direction in degrees */
    MovingDirection direction;
    int speed;

private:
    /* Object image path */
    QString _img_path;
    /* use atomic */
    std::atomic<bool> _alive;
    std::atomic<bool> _moving;
};

#endif // STAGEOBJECT_H
