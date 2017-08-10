import QtQuick 2.0

import BattleFieldObjects 1.0

Wall {
    id: wall
    type: Wall.ARMORWALL

    Image {
        id: img
        sourceSize.width: 100
        sourceSize.height: 100
        source: wall.imgPath
        rotation: wall.direction
    }
}

