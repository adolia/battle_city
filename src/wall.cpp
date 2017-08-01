#include "wall.h"

Wall::Wall()
{
}
QString Wall::getObjectImgPath() const {
    QString wall_name = "";
    switch (this->_walltype) {
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
