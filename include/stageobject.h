#ifndef STAGEOBJECT_H
#define STAGEOBJECT_H

#include <QtQuick/QQuickItem>

/**
 * @brief Moving direction related to rotation property in degrees
 **/
enum MovingDirection {
    MOVING_UP,
    MOVING_RIGHT = 90,
    MOVING_DOWN  = 180,
    MOVING_LEFT  = 270,
    MOVING_NONE  = 360
};

/**
 *  @brief The StageObject class is a base class for each visual object (Item)
 **/
class StageObject : public QQuickItem
{
    /* Declare default width & hight object values */
    Q_OBJECT
    Q_PROPERTY(QString imgPath READ getImgPath CONSTANT)
    Q_PROPERTY(int direction READ getDirection WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(int speed READ getSpeed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(bool alive READ isAlive WRITE setLiveStatus NOTIFY liveStatusChanged)
    Q_PROPERTY(bool moving READ isMoving WRITE setMoveStatus)

    /* Copy constructor */
    StageObject(const StageObject &) = default;
    StageObject & operator = (const StageObject &) { return *this; }

protected:
    /* protect cosnstructor to create Abstract class */
    StageObject(QQuickItem *parent = Q_NULLPTR);

public:
    /* Path to object's image  getter & setter */
    virtual QString getImgPath() const{ return this->_img_path; }
    void setImgPath(const QString& path) { this->_img_path = path; }

    /* Object moving direction getter & setter */
    int getDirection() const { return this->direction; }
    void setDirection(int new_direction);

    /* Object speed getter $ setter */
    int getSpeed() const { return this->speed; }
    void setSpeed(int new_speed);

    /* Object live status getter & setter */
    bool isAlive() const { return this->_alive.load(); }
    void setLiveStatus(const bool live_status);

    /* Object moving status getter & setter */
    bool isMoving() const { return this->_moving.load(); }
    void setMoveStatus(bool move_status) { this->_moving = move_status; }

    /* Setters for x & y position
     * Note: Need to call basic QQuickItem setX and setY inside
     */
    virtual void setPosX(qreal);
    virtual void setPosY(qreal);


signals:
    /* Signals are sent when changes should be propagated to QML */
    void directionChanged(int);
    void speedChanged(int);
    void liveStatusChanged(const bool);

protected:
    /* Object moving direction in degrees */
    int direction;
    int speed;

private:
    /* Object image path */
    QString _img_path;
    /* use atomic */
    std::atomic<bool> _alive;
    std::atomic<bool> _moving;
};

#endif // STAGEOBJECT_H
