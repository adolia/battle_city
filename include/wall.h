#ifndef WALL_H
#define WALL_H

#include "include/stageobject.h"
/**
 * @brief The WallType enum describes wall type
 */
enum WallType {
    BRICKWALL,
    ARMORWALL,
    EMPTY
};

/**
 * @brief The Wall class is an object to describe bricks on the battle fileld
 */

class Wall : public StageObject {
    Q_OBJECT
    Q_PROPERTY(bool destructable READ isDestructable)
    Q_PROPERTY(WallType type READ getWallType)

protected:
    Wall(QQuickItem *parent = Q_NULLPTR);

public:
    /* Virtual method to get Object method path */
    virtual QString getImgPath() const;

    /* returns destructable wall property */
    bool isDestructable() const { return this->_destructable; }

    /* returns Wall type value */
    WallType getWallType() const { return this->_wall_type; }

    /* Class destructor */
    ~Wall() {};

private:
    /* Indicates if wall can be destructed by shell */
    const bool _destructable;
    /* Determine which type of wall are used */
    const WallType _wall_type;

};

#endif // WALL_H
