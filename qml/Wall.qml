import QtQuick 2.0

import BattleFieldObjects 1.0

Wall {
    id: wall

    Image {
        id: img
        sourceSize.width: 100
        sourceSize.height: 100
        source: modelData.imgPath
        rotation: modelData.direction
    }
}

