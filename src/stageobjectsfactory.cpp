#include "stageobjectsfactory.h"
#include "wall.h"

QList<StageObject*> *StageObjectsFactory::StageObjectsList = Q_NULLPTR;

StageObjectsFactory::StageObjectsFactory()
{
}

/**
 * @brief StageObjectsFactory::create metod to create Stage objects instances
 * @param type
 * @param direction
 * @param params
 * @param sceneContext
 * @return
 */
StageObject* StageObjectsFactory::create(ObjectType type,
                                         MovingDirection direction,
                                         const QRectF &params,
                                         QQuickItem *sceneContext)
{
    QQuickItem *factoryObject = Q_NULLPTR;
    switch (type) {
    case TYPE_PLAYERTANK:
        break;
    case TYPE_AITANK:

        break;
    case TYPE_SHELL:

        break;
    case TYPE_WALL:
        factoryObject = new Wall(parent, true, BRICKWALL);
        break;
    default:
        break;
    }
    return (StageObject*)factoryObject;
}


