import QtQuick 2.0

import BattleFieldObjects 1.0

Wall {
    id: wall
    width: wall.width
    height: wall.height

    Image {
        id: img
        visible: false
        sourceSize.width: 256
        sourceSize.height: 256
        source: wall.img_path
    }
}

