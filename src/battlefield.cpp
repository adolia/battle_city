#include "battlefield.h"

BattleField::BattleField(QWindow *parent) : QQuickView(parent)
{
}

BattleField::BattleField(QQmlEngine *engine, QWindow *parent) : QQuickView(engine, parent),
    objFactory(new StageObjectsFactory())
{
    initBattleField();
}

BattleField::BattleField(const QUrl &source, QWindow *parent) : QQuickView(source, parent)
{
}
BattleField::~BattleField()
{
    delete objFactory;
}

inline void BattleField::initBattleField()
{
    this->objFactory->setStageObjectsList(&objList);
    QRectF geometry = {};
    this->objFactory->create(ObjectType::B_WALL, MovingDirection::UP, geometry, Q_NULLPTR);
    this->objFactory->create(ObjectType::A_WALL, MovingDirection::UP, geometry, Q_NULLPTR);

    this->rootContext()->setContextProperty("battleModel", QVariant::fromValue(objList));
}

