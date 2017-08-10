#ifndef STAGEOBJECTSFACTORY_H
#define STAGEOBJECTSFACTORY_H
#include "stageobject.h"

class StageObjectsFactory
{
    /* Disable copy constructor and an assignment operator */
    Q_DISABLE_COPY(StageObjectsFactory)
    static QList<StageObject*> *StageObjectsList;

public:
    StageObjectsFactory();
    static void setStageObjectsList(QList<StageObject*> *list) {StageObjectsFactory::StageObjectsList = list;}
public:
    StageObject* create(ObjectType type,
                         MovingDirection direction,
                         const QRectF &params,
                         QQuickItem *sceneContext);
};

#endif // STAGEOBJECTSFACTORY_H
