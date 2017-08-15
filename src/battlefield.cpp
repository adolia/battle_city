#include <QTimer>
#include <algorithm>
#include "battlefield.h"
#include "tank.h"
#include "aitank.h"
#include "defs.h"

extern QPointF player_spawn[];

QPointF BattleField::ai_spawn_points[] =
{
   /* Initial ai tanks spawn points*/
    { 15,  20 }, { 720,  20 },
    { 15, 620 }, { 720, 620 },
};

BattleField::BattleField(QWindow *parent) : QQuickView(parent),
    _enemies_to_spawn(ENEMIES_COUNT),
    _alive_enemies(0)
{
     initBattleField();
}

BattleField::BattleField(QQmlEngine *engine, QWindow *parent) : QQuickView(engine, parent),
    objFactory(new StageObjectsFactory()),
    _enemies_to_spawn(ENEMIES_COUNT),
    _alive_enemies(0)
{
    initBattleField();
}

BattleField::BattleField(const QUrl &source, QWindow *parent) : QQuickView(source, parent),
    objFactory(new StageObjectsFactory()),
    _enemies_to_spawn(ENEMIES_COUNT),
    _alive_enemies(0)
{
     initBattleField();
}
BattleField::~BattleField()
{
    delete objFactory;
}

/**
 * @brief BattleField::initPlayer
 * Initializes player item and add it to ListModel
 */
inline void BattleField::initPlayer()
{
    // The player item can be set only once
    /*QRectF params = {
        player_spawn[0].x(),
        player_spawn[0].y(),
        WIDTH,
        HEIGHT
    };

    Tank *player = dynamic_cast<Tank*>(this->objFactory->create(ObjectType::PLAYERTANK,
                                                                StageObject::MovingDirection::UP,
                                                                PLAYER_TANK_SPEED,
                                                                params,
                                                                rootObject()));
                                                                */
    Tank *player = rootObject()->findChild<Tank*>("player_tank");
    if (player != Q_NULLPTR)
    {
        player->setObjectType(ObjectType::PLAYERTANK);
        player->setSpeed(PLAYER_TANK_SPEED);
        // Set the player respawn handler
        connect(player, &Tank::respawn, player, &Tank::respawnPlayer);
        objList.append(dynamic_cast<StageObject*>(player));
    } else {
        qDebug() << "Player does not created";
    }

}

/**
 * @brief BattleScene::initStatusPanel
 * Binds the field values to the qml control panel
 */
void BattleField::initControlPanel()
{
    QQuickItem * panel = rootObject()->findChild<QQuickItem*>("controlPanel");

    // Bind the scene variable change to the StatusPanel property
    connect(this, &BattleField::enemiesToSpawnChanged, panel, [=] (int enemiesLeft) {
        panel->setProperty("enemiesLeft", enemiesLeft);
    });

}

/**
 * @brief BattleField::initBattleField
 */
inline void BattleField::initBattleField()
{
    this->objFactory->initFactory(&objList, engine(), rootContext());
    this->initPlayer();

    /* Initialize the pseudo-random number generator for choosing spawn points */
    qsrand(time(NULL));
    // Initialize the control panel with the scene values
    this->initControlPanel();
    this->setWinEvent();
    // Spawn initial amount of enemies
    this->createEnemies();
    // Starting the timer that manages move event handling
    startTimer(FRAMES);
}

/**
 * @brief BattleField::getPlayer
 * @return
 */
Tank * BattleField::getPlayer()
{
    // Get player instance from ListModel

    Tank *_player = dynamic_cast<Tank*>(objList.first());
    if (_player && _player->getObjectType() == PLAYERTANK){
        return _player;
    }

    return Q_NULLPTR;

}

/**
 *  Creates the initial amount of enemies
 */
void BattleField::createEnemies()
{
    // Becase the initial enemy spawn points are the
    // corners of the map we starting from the 3-d point
    std::for_each(&ai_spawn_points[0], std::end(ai_spawn_points), [this] (const QPointF &p)
    {
        spawn(p);
    });
}

/**
 *  Spawn an enemy randomly at one of the predefined spawn points
 */
inline void BattleField::spawnEnemy()
{
    // Get a random number in the range of [1; size)
    auto spawnIdx = (qrand() % (std::size(ai_spawn_points))) + 1;
    this->spawn(ai_spawn_points[spawnIdx]);
}

/**
 * @brief BattleField::directSpawn
 * Spawn an enemy at the given point
 * @param pos
 * @return A pointer to the created item
 */
Tank* BattleField::spawn(const QPointF &pos)
{
    Tank *_player = this->getPlayer();

    QRectF params = {
         pos.x(),
         pos.y(),
        (_player->width()  / 10.0) + _player->width(),
        (_player->height() / 10.0) + _player->height(),
    };
    StageObject::MovingDirection direction = (pos.y() > (this->height() / 2))
            ? StageObject::MovingDirection::UP : StageObject::MovingDirection::DOWN;

    auto enemy = objFactory->create(AITANK, direction, AI_TANK_SPEED, params, rootObject());

    this->setAliveEnemies(this->getAliveEnemies() + 1);
    this->setEnemiesToSpawn(this->getEnemiesToSpawn() - 1);

    return (Tank*)enemy;
}

/**
 *  Checks the enemies count and spawns another one if necessary
 */
inline void BattleField::checkAliveEnemies()
{
    if (this->getAliveEnemies() < MAX_ALIVE_ENEMIES && this->getEnemiesToSpawn() > 0)
    {
        QTimer::singleShot(ENEMY_RESPAWN_IVAL, [this] () {
            spawnEnemy();
        });
    }
}

void BattleField::setEnemiesToSpawn(int count)
{
    this->_enemies_to_spawn = count;
    emit enemiesToSpawnChanged(count);
}

void BattleField::setAliveEnemies(int count)
{
    this->_alive_enemies = count;
    emit aliveEnemiesChanged(count);
}

/**
 * @brief BattleField::setWinEvent
 */
void BattleField::setWinEvent()
{
    QQuickItem * screen = rootObject()->findChild<QQuickItem*>("win_screen");

    connect(this, &BattleField::aliveEnemiesChanged, screen, [=] (int enemiesLeft) {
        if (enemiesLeft == 0 && this->getEnemiesToSpawn() <= 0) {
            screen->setProperty("text", "Win");
            screen->setProperty("visible", true);
        }
    });
}
/**
 * @brief BattleField::keyPressEvent
 * @param e
 */
void BattleField::keyPressEvent(QKeyEvent *e)
{
    Tank *_player = this->getPlayer();

    if (e && _player) {
        switch(e->key()) {
        case Qt::Key_Up:
            _player->setDirection(StageObject::MovingDirection::UP);
            _player->setMoveStatus(true);
            break;
        case Qt::Key_Down:
            _player->setDirection(StageObject::MovingDirection::DOWN);
            _player->setMoveStatus(true);
            break;
        case Qt::Key_Left:
            _player->setDirection(StageObject::MovingDirection::LEFT);
            _player->setMoveStatus(true);
            break;
        case Qt::Key_Right:
            _player->setDirection(StageObject::MovingDirection::RIGHT);
            _player->setMoveStatus(true);
            break;
        case Qt::Key_Space:
            _player->shoot();
        }
    }
}

void BattleField::keyReleaseEvent(QKeyEvent *e)
{
    Tank *_player = this->getPlayer();

    if (e && _player) {
        switch(e->key()) {
        case Qt::Key_Up:
            if (_player->getDirection() == StageObject::MovingDirection::UP)
                _player->setMoveStatus(false);
            break;
        case Qt::Key_Down:
            if (_player->getDirection() == StageObject::MovingDirection::DOWN)
                _player->setMoveStatus(false);
            break;
        case Qt::Key_Left:
            if (_player->getDirection() == StageObject::MovingDirection::LEFT)
                _player->setMoveStatus(false);
            break;
        case Qt::Key_Right:
            if (_player->getDirection() == StageObject::MovingDirection::RIGHT)
                _player->setMoveStatus(false);
            break;
        }
    }
}

/**
 * @brief BattleScene::removeItem
 * @param item
 */
void BattleField::removeItem(StageObject *item)
{
    Tank * tank = dynamic_cast<Tank*>(item);

    // Check if item is an enemy unit
    if (tank) {
        this->setAliveEnemies(this->getAliveEnemies() - 1);
        this->checkAliveEnemies();
    }

    delete item;
}

/**
 *  Main scene event. Performs all actions on every scene object
 */
void BattleField::timerEvent(QTimerEvent *)
{
    for (auto it = objList.crbegin(); it != objList.crend(); ++it)
    {
        StageObject *item = *it;

        if (item->isAlive()) {
            if (item->isMoving())
                item->move();

        } else {
            objList.removeOne(item);
            this->removeItem(item);
        }
    }
}
