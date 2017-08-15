#ifndef WALL_H
#define WALL_H

#include "stageobject.h"

/**
 * @brief The Wall class is an object to describe bricks on the battle fileld
 */

class Wall : public StageObject {
    Q_OBJECT
    Q_ENUMS(WallType)
    Q_PROPERTY(bool destructable READ isDestructable)
    Q_PROPERTY(WallType type READ getWallType WRITE setWallType)

protected:


public:
    /**
     * @brief The WallType enum describes wall type
     */

    enum WallType {
        BRICKWALL,
        ARMORWALL,
        EMPTY
    };

    explicit Wall(QQuickItem *parent = Q_NULLPTR);
    explicit Wall(WallType type, QQuickItem *parent = Q_NULLPTR);

    /* Virtual method to get Object method path */
    virtual QString getImgPath() const;

    /* returns destructable wall property */
    bool isDestructable() const { return this->_destructable; }

    /* returns Wall type value */
    WallType getWallType() const { return this->_wall_type; }
    void setWallType(WallType type);

    /* Class destructor */
    ~Wall();

    // Destroy wall object
    virtual void destroy();

private:
    /* Indicates if wall can be destructed by shell */
    bool _destructable;
    /* Determine which type of wall are used */
    WallType _wall_type;

};

#endif // WALL_H
