#ifndef STAGEOBJECTSFACTORY_H
#define STAGEOBJECTSFACTORY_H

#include "stageobject.h"

class StageObjectsFactory
{
    static StageListModel *stageListModel;
    /* Disable copy constructor and an assignment operator */
    Q_DISABLE_COPY(StageObjectsFactory)


public:
    StageObjectsFactory();
    static void setStageObjectsList(StageListModel *list) {
        StageObjectsFactory::stageListModel = list;
    }

public:
    StageObject * create(ObjectType type,
                         MovingDirection direction,
                         const QRectF &params,
                         QQuickItem *sceneContext);
};

#endif // STAGEOBJECTSFACTORY_H
