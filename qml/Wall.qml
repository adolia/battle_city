import QtQuick 2.0

import BattleFieldObjects 1.0

Wall {
    id: wall

    Image {
        id: img
        sourceSize.width: 256
        sourceSize.height: 256
        source: wall.imgPath
    }
}

