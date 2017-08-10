import QtQuick 2.0

Rectangle {
    width: 1024
    height: 768
    color: "black"

    Wall {
        id: brick_wall
        width: 100
        height: 100
        Image {
            id: img
            visible: false
            sourceSize.width: 100
            sourceSize.height: 100
            source: "qrc:/resources/img/brick_wall.png"
        }
    }
}
