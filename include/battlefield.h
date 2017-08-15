#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QtQuick/QQuickView>
#include "stageobjectsfactory.h"
#include "tank.h"

/**
 * @brief The BattleField class for main view
 */
class BattleField : public QQuickView
{
    Q_OBJECT

    StageListModel objList;
    StageListModel wallsList;
    StageObjectsFactory *objFactory;
    /* predefined default spawn points */
    static QPointF ai_spawn_points[];

public:
    explicit BattleField(QWindow *parent = Q_NULLPTR);
    explicit BattleField(QQmlEngine *engine, QWindow *parent);
    explicit BattleField(const QUrl &source, QWindow *parent = Q_NULLPTR);

    StageListModel getListModel() { return objList; }
    ~BattleField();

signals:
    void enemiesToSpawnChanged(int);
    void aliveEnemiesChanged(int);
    void win();

protected:
    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);
    virtual void timerEvent(QTimerEvent *);

private:
    void initBattleField();
    void initPlayer();
    void initControlPanel();
    void setWinEvent();
    // Creates a new enemy at a random spawn point
    void spawnEnemy();
    // Creates the initial amount of enemies at their base spawn points
    void createEnemies();
    // Checks the enemies count and spawns another one if necessary
    void checkAliveEnemies();
    Tank * spawn(const QPointF &position);
    Tank * getPlayer();
    /* Removes the given StageObject item */
    void removeItem(StageObject *item);

public:
    int getEnemiesToSpawn() const { return this->_enemies_to_spawn; }
    int getAliveEnemies() const { return this->_alive_enemies;  }

    void setEnemiesToSpawn(int count);
    void setAliveEnemies(int count);

private:
    int _enemies_to_spawn;
    int _alive_enemies;
};

#endif // BATTLEFIELD_H
