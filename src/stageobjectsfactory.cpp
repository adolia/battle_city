#include "stageobjectsfactory.h"

StageListModel * StageObjectsFactory::stageListModel = Q_NULLPTR;
QQmlEngine * StageObjectsFactory::engine = Q_NULLPTR;
QQmlContext * StageObjectsFactory::context = Q_NULLPTR;

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
                                         StageObject::MovingDirection direction,
                                         int speed,
                                         const QRectF &params,
                                         QQuickItem *stageContext)
{
    QQuickItem *_object = Q_NULLPTR;
    QString url;

    switch (type) {
        case PLAYERTANK:
            url = "qrc:/qml/PlayerTank.qml";
            break;
        case AITANK:
            url = "qrc:/qml/EnemyTank.qml";
            break;
        case SHELL:
            url = "qrc:/qml/Shell.qml";
            break;
        case B_WALL:
        case A_WALL:
            qDebug() << "No need to create new wall dynamically";
        default:
            return Q_NULLPTR;
    }
    try {
        QQmlComponent component(engine, QUrl(url));
        _object = qobject_cast<QQuickItem*>(component.create(context));
        // set needed objects properties
        _object->setParentItem(stageContext);
        _object->setProperty("x", params.x());
        _object->setProperty("y", params.y());
        _object->setProperty("speed", speed);
        _object->setProperty("direction", direction);
        _object->setProperty("width", params.width());
        _object->setProperty("height", params.height());
        // add object to list model
        stageListModel->append((StageObject*)_object);

    } catch (...) {
        qDebug() << "Can not instanciate new Item";
    }

    return (StageObject*)_object;
}


