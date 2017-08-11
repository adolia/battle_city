#include "wall.h"

Wall::Wall(const bool destructable, WallType type, QQuickItem *parent) :
    StageObject(parent),
    _destructable(destructable),
    _wall_type(type)
{
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
