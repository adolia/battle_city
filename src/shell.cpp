#include "shell.h"

Shell::Shell(QQuickItem *parent): StageObject(parent)
{
    connect(this, &Shell::explosion, this, &Shell::onExplosion);
}

void Shell::setPosX(qreal x)
{
    QQuickItem *_obj = this->checkCollisions(x, this->y());

        if (_obj)
            emit explosion(_obj);
        else
            QQuickItem::setX(x);

}

void Shell::setPosY(qreal y)
{
    QQuickItem *_obj = this->checkCollisions(this->x(), y);

        if (_obj)
            emit explosion(_obj);
        else
            QQuickItem::setY(y);

}

void Shell::destroy()
{
    this->setLiveStatus(false);
}

void Shell::onExplosion(QQuickItem *obj)
{
    this->setLiveStatus(false);
    StageObject * _obj= dynamic_cast<StageObject*>(obj);
        // Check if item is a custom StageObject
        if (_obj)
            _obj->destroy();
}
