#include "stageobjectsfactory.h"
#include "wall.h"

StageListModel * StageObjectsFactory::stageListModel = Q_NULLPTR;

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
    if (stageListModel)
    {
        switch (type) {
        case PLAYERTANK:
            break;
        case AITANK:

            break;
        case SHELL:

            break;
        case B_WALL:
            factoryObject = new Wall(true, BRICKWALL);
            break;
        case A_WALL:
            factoryObject = new Wall(false, ARMORWALL);
            break;
        default:
            break;
        }
        stageListModel->append((StageObject*)factoryObject);

    }

    return (StageObject*)factoryObject;
}


