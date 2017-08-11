#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QtQuick/QQuickView>
#include <QQmlContext>
#include <QVariant>

#include "stageobjectsfactory.h"


/**
 * @brief The BattleField class for main view
 */
class BattleField : public QQuickView
{
    Q_OBJECT
    StageListModel objList;
    StageObjectsFactory *objFactory;

public:
    explicit BattleField(QWindow *parent = Q_NULLPTR);
    explicit BattleField(QQmlEngine *engine, QWindow *parent);
    explicit BattleField(const QUrl &source, QWindow *parent = Q_NULLPTR);

    void setRootContext();

    ~BattleField();
private:
    void initBattleField();
};

#endif // BATTLEFIELD_H
