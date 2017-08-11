import QtQuick 2.0

import BattleFieldObjects 1.0

Wall {
    id: armor_wall
    type: Wall.ARMORWALL
    direction: Wall.UP

    Image {
        id: img
        sourceSize.width: 50
        sourceSize.height: 50
        source: armor_wall.imgPath
        rotation: armor_wall.direction
    }
}
