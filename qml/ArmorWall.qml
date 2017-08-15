import QtQuick 2.0

import BattleObjects 1.0

Wall {
    id: armor_wall
    type: Wall.ARMORWALL
    objectName: "wall"

    Image {
        id: img
        anchors.fill: parent
        sourceSize.width: 50
        sourceSize.height: 50
        source: armor_wall.imgPath
    }
}
