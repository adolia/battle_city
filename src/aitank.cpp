#include "aitank.h"

AITank::AITank(QQuickItem *parent): Tank(parent)
{
    initAI();
}

inline void AITank::initAI()
{
    startTimer(AI_TICK_IVAL);
}

inline void AITank::control()
{
    StageObject::MovingDirection newDirection = StageObject::MovingDirection::UP;
    int rotationClockwise = qrand() % 2;


    if (rotationClockwise) {
        newDirection = static_cast<StageObject::MovingDirection>(this->getDirection() == StageObject::MovingDirection::LEFT
                ? StageObject::MovingDirection::UP
                : this->getDirection() + 90);
    }
    else {
        newDirection =  static_cast<StageObject::MovingDirection>(this->getDirection() ==  StageObject::MovingDirection::UP
                ?  StageObject::MovingDirection::LEFT
                : this->getDirection() - 90);
    }
    this->setDirection(newDirection);
}

void AITank::setPosX(qreal x)
{
    if (!checkCollisions(x, this->y()) && x >= 0 && x < parentItem()->width() - this->width()) {
        QQuickItem::setX(x);
    }
    else {
        // Occasional rotate
        int rotation = qrand() % 2;
        if (rotation) {
            this->control();
        }
    }
}

void AITank::setPosY(qreal y)
{
    if (!checkCollisions(this->x(), y) && y >= 0 && y < parentItem()->height() - this->height()) {
        QQuickItem::setY(y);
    }
    else {
          // Occasional rotate
        int occasionalRotate = qrand() % 2;
        if (occasionalRotate) {
            this->control();
        }
    }
}

void AITank::timerEvent(QTimerEvent *)
{
    this->move();
    this->shoot();
}
