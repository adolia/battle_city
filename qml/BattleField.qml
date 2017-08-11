import QtQuick 2.0

Rectangle {
    width: 1024
    height: 768
    color: "black"

    BrickWall {
        id: b_wall
        x: 50
        y: 50
        width: 100
        height: 100
    }
    ArmorWall {
        x: 100
        y: 100
        width: 50
        height: 50
    }
    PlayerBase {
            anchors.left: b_wall.right
            anchors.bottom: b_wall.bottom
            anchors.leftMargin: 4
    }
}
