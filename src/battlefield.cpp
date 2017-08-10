#include "battlefield.h"
#include "stageobject.h"
BattleField::BattleField(QWindow *parent) : QQuickView(parent)
{
}

BattleField::BattleField(QQmlEngine *engine, QWindow *parent) : QQuickView(engine, parent),
    objectsFactory(new StageObjectsFactory())
{
    initBattleField();
}

BattleField::BattleField(const QUrl &source, QWindow *parent) : QQuickView(source, parent)
{
}
BattleField::~BattleField()
{
    delete objectsFactory;
}

inline void BattleField::initBattleField()
{
    this->objectsFactory->setStageObjectsList(&objList);
    QRectF geometry = {};
    this->objectsFactory->create(ObjectType::TYPE_WALL, MovingDirection::UP, geometry, Q_NULLPTR);
}
