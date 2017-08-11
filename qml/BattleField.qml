import QtQuick 2.0

Rectangle {
    width: 1024
    height: 768
    color: "black"

    Repeater {
        model: battleModel
        Wall { }
    }
}
