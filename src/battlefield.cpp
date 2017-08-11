#include "battlefield.h"

BattleField::BattleField(QWindow *parent) : QQuickView(parent)
{
     initBattleField();
}

BattleField::BattleField(QQmlEngine *engine, QWindow *parent) : QQuickView(engine, parent),
    objFactory(new StageObjectsFactory())
{
    initBattleField();
}

BattleField::BattleField(const QUrl &source, QWindow *parent) : QQuickView(source, parent),
    objFactory(new StageObjectsFactory())
{
     initBattleField();
}
BattleField::~BattleField()
{
    delete objFactory;
}

inline void BattleField::initBattleField()
{
    this->objFactory->setEngine(engine());
    this->objFactory->setContext(rootContext());
    this->objFactory->setStageObjectsList(&objList);
    QRectF geometry = {
        50,
        50,
        100,
        100
    };
    this->objFactory->create(ObjectType::B_WALL, StageObject::MovingDirection::UP, geometry, Q_NULLPTR);
    this->objFactory->create(ObjectType::A_WALL, StageObject::MovingDirection::UP, geometry, Q_NULLPTR);
   // rootContext()->setContextProperty("battle", QVariant::fromValue(objList));
}

