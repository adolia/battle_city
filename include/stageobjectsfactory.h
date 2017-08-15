#ifndef STAGEOBJECTSFACTORY_H
#define STAGEOBJECTSFACTORY_H

#include <QQmlContext>
#include "stageobject.h"

class StageObjectsFactory
{
    /* Disable copy constructor and an assignment operator */
    Q_DISABLE_COPY(StageObjectsFactory)

    static QQmlEngine *engine;
    static QQmlContext *context;
    static StageListModel *stageListModel;

public:
    StageObjectsFactory();
    static void initFactory(StageListModel *list, QQmlEngine *engine, QQmlContext *context) {
        StageObjectsFactory::stageListModel = list;
        StageObjectsFactory::engine = engine;
        StageObjectsFactory::context = context;
    }

public:
    StageObject * create(ObjectType type,
                         StageObject::MovingDirection direction,
                         int speed,
                         const QRectF &params,
                         QQuickItem *sceneContext);
};

#endif // STAGEOBJECTSFACTORY_H
