import QtQuick 2.0

Rectangle {
    width: 1024
    height: 768
    color: "black"

    Wall {
        id: brick_wall
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: 100
        height: 100
        x: 50
        y: 50
    }
}
