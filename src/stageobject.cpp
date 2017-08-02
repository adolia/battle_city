#include "include/stageobject.h"

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
void StageObject::setDirection(int new_direction){
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
