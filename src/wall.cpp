#include "wall.h"

Wall::Wall(QQuickItem *parent) :
    StageObject(parent)
{
}

Wall::Wall(WallType type, QQuickItem *parent) :
    StageObject(parent)
{
    this->setWallType(type);
}
/**
 * @brief Wall::getImgPath get texture path
 * @return
 */
QString Wall::getImgPath() const {
    QString wall_name = "";
    switch (this->_wall_type) {
    case BRICKWALL:
        wall_name = "brick_wall";
        break;
    case ARMORWALL:
        wall_name = "armor_wall";
        break;
    default:
        wall_name = "empty";
        break;
    }
    return "qrc:/resources/img/" + wall_name + ".png";
}
/**
 * @brief Wall::setWallType
 * @param type
 */
void Wall::setWallType(WallType type) {
    this->_wall_type = type;
    switch (this->_wall_type) {
    case BRICKWALL:
        this->_destructable = true;
        break;
    default:
        this->_destructable = false;
        break;
    }
}
