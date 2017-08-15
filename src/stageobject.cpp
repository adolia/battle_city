#include "stageobject.h"

StageObject::StageObject(QQuickItem *parent) : QQuickItem(parent),
    _alive(true),
    _moving(false)
{
}

/**
 * @brief set Object moving direction
 * @param new_direction
 * @return void
 */
void StageObject::setDirection(MovingDirection new_direction){
    if(this->direction != new_direction){
        this->direction = new_direction;
        emit directionChanged(new_direction);
    }
}

/**
 * @brief Set object speed value
 * @param new_speed
 */
void StageObject::setSpeed(int new_speed){
    this->speed = new_speed;
    speedChanged(new_speed);
}

/**
 * @brief Set object live status
 * @param live_status
 * @return void
 */
void StageObject::setLiveStatus(const bool live_status){
    this->_alive = live_status;
    liveStatusChanged(live_status);
}

/**
 * @brief StageObject::checkCollision
 * Custom collider, checks if there is an object on the way.
 * @param posX
 * @param posY
 * @return
 */
QQuickItem* StageObject::checkCollisions(qreal posX, qreal posY)
{
    qreal x = this->x(), y = this->y(), width = this->width(), height = this->height();

    bool movesHorizontally = (posY - y == 0),
         movesLeft = (posX - x < 0),
           movesUp = (posY - y < 0);

    QPointF points[] = {
        {
        /*x1*/ movesHorizontally ? (movesLeft ? (x - 1) : ((x + 1) + width)) : posX,
        /*y1*/ movesHorizontally ? posY : (movesUp ? (y - 1) : ((y + 1) + height))
        },
        {
        /*x2*/ movesHorizontally ? (movesLeft ? posX : (posX + width)) : posX,
        /*y2*/ movesHorizontally ? posY : (movesUp ? posY : (posY + height))
        },
        {
        /*x3*/ movesHorizontally ? (movesLeft ? (x - 1) : ((x + 1) + width)) : (posX + width),
        /*y3*/ movesHorizontally ? (posY + height) : (movesUp ? (y - 1) : ((y + 1) + height))
        },
        {
        /*x4*/ movesHorizontally ? (movesLeft ? posX : (posX + width)) : posX + width,
        /*y4*/ movesHorizontally ? (posY + height) : (movesUp ? posY : (posY + height))
        },
        {
        /*x5*/ movesHorizontally ? (movesLeft ? posX : (posX + width)) : posX + (width / 2),
        /*y5*/ movesHorizontally ? (posY + height / 2) : (movesUp ? posY : (posY + height))
        }
    };

    for (const QPointF &point : points)
    {
        QQuickItem * _obj= parentItem()->childAt(point.x(), point.y());
        // Check if there is an item at the given point
        if (_obj)
            return _obj;
    }

    return Q_NULLPTR;
}


/**
 * @brief Set Object position by X coordinate
 * @param x
 */
void StageObject::setPosX(qreal x){
    QQuickItem::setX(x);
}

/**
 * @brief Set object position by Y coordinate
 * @param y
 */
void StageObject::setPosY(qreal y){
    QQuickItem::setY(y);
}

/**
 * @brief StageObject::move
 */
void StageObject::move()
{
    switch(this->getDirection()) {
    case MovingDirection::UP:
        this->setPosY(this->y() - this->getSpeed());
        break;
    case MovingDirection::DOWN:
        this->setPosY(this->y() + this->getSpeed());
        break;
    case MovingDirection::RIGHT:
        this->setPosX(this->x() + this->getSpeed());
        break;
    case MovingDirection::LEFT:
        this->setPosX(this->x() - this->getSpeed());
        break;
    default:
        break;
    }
}
