import QtQuick 2.0

import BattleFieldObjects 1.0

Wall {
    id: brick_wall
    type: Wall.BRICKWALL
    direction: Wall.UP

    Image {
        id: img
        sourceSize.width: 50
        sourceSize.height: 50
        source: brick_wall.imgPath
        rotation: brick_wall.direction
    }
}

