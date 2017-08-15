#ifndef AITANK_H
#define AITANK_H

#include "tank.h"

class AITank : public Tank {
public:
    AITank(QQuickItem *parent = Q_NULLPTR);

public:
    virtual void setPosX(qreal);
    virtual void setPosY(qreal);

protected:
    void timerEvent(QTimerEvent *);

private:
    void initAI();
    // Provides the AI rotation
    void control();
};

#endif // AITANK_H
