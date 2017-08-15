#ifndef SHELL_H
#define SHELL_H

#include "stageobject.h"

class Shell : public StageObject
{
    Q_OBJECT

public:
    explicit Shell(QQuickItem *parent = Q_NULLPTR);

    virtual void destroy();
    virtual void setPosX(qreal);
    virtual void setPosY(qreal);

signals:
    void explosion(QQuickItem *);

private slots:
    void onExplosion(QQuickItem *);

};

#endif // SHELL_H
