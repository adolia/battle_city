#ifndef TANK_H
#define TANK_H

#include "stageobjectsfactory.h"

class Tank : public StageObject {
    Q_OBJECT

    Q_PROPERTY(int lives READ getLives WRITE setLives NOTIFY livesChanged)

    StageObjectsFactory *shell;
public:

    explicit Tank(QQuickItem *parent = Q_NULLPTR);

    ~Tank();

    void setLives(int value);
    int getLives() const { return this->_lives; }

    // Destroy current item
    virtual void destroy();
    virtual void setPosX(qreal);
    virtual void setPosY(qreal);

signals:
    void livesChanged(int value);
    void respawn(int value);
    void shot();

public slots:
    void shoot();
    void respawnPlayer(int lives);


private:
    int _lives;
};

#endif // TANK_H
