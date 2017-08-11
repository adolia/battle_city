#ifndef STAGEOBJECTSFACTORY_H
#define STAGEOBJECTSFACTORY_H

#include <QQmlContext>
#include <QVariant>
#include "stageobject.h"

class StageObjectsFactory
{
    static StageListModel *stageListModel;
    static QQmlEngine *engine;
    static QQmlContext *context;
    /* Disable copy constructor and an assignment operator */
    Q_DISABLE_COPY(StageObjectsFactory)


public:
    StageObjectsFactory();
    void setStageObjectsList(StageListModel *list) {
        StageObjectsFactory::stageListModel = list;
    }
    void setEngine(QQmlEngine *engine) {
        StageObjectsFactory::engine = engine;
    }
    void setContext(QQmlContext *context) {
        StageObjectsFactory::context = context;
    }

public:
    StageObject * create(ObjectType type,
                         StageObject::MovingDirection direction,
                         const QRectF &params,
                         QQuickItem *sceneContext);
};

#endif // STAGEOBJECTSFACTORY_H
