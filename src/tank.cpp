#include "tank.h"

Tank::Tank(QQuickItem *parent): StageObject(parent)
{
    shell = new StageObjectsFactory();
}

Tank::~Tank()
{
    delete shell;
}

/**
 * @brief Tank::setLives
 * @param value
 */
void Tank::setLives(int value)
{
    this->_lives = value;
    emit livesChanged(value);
}

/**
 * @brief Tank::destroy
 */
void Tank::destroy()
{
    this->setLives(this->getLives() - 1);
}

void Tank::respawnPlayer(int lives)
{
    if (lives > 0) {
       this->setMoveStatus(false);
       this->setDirection(MovingDirection::UP);
       this->setPosition (player_spawn[0]);
    }
}

/**
 * @brief Tank::setPosX
 * @param x
 */
void Tank::setPosX(qreal x)
{
    if (!this->checkCollisions(x, this->y()) && x >= 0 && x < parentItem()->width() - this->width())
        QQuickItem:setX(x);
}
/**
 * @brief Tank::setPosY
 * @param y
 */
void Tank::setPosY(qreal y)
{
    if (!this->checkCollisions(this->x(), y) && y >= 0 && y < parentItem()->height() - this->height())
        QQuickItem:setY(y);
}

/**
 * @brief Tank::shoot
 */
void Tank::shoot()
{
   emit shot();

   MovingDirection direction = this->getDirection();

    bool movesHorizontally = (direction == MovingDirection::RIGHT || direction == MovingDirection::LEFT),
            movesLeft = (direction == MovingDirection::LEFT),
            movesUp = (direction == MovingDirection::UP);

    qreal x = this->x(), y = this->y(), width = this->width(), height = this->height();

    QRectF params  = {
        movesHorizontally
            ? (movesLeft
                ? (x - 1)
                : (x + width + 1))
            : (x + ((width - 4) / 2)),
        movesHorizontally
            ? (y + ((height - 7) / 2))
            : (movesUp
                ? (y - 1)
                : (y + height + 1)),
        width / 12,
        height / 5
    };

    shell->create(ObjectType::SHELL, direction, SHELL_SPEED, params, parentItem());
}
