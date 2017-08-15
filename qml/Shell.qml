import QtQuick 2.5
import QtMultimedia 5.5
import BattleObjects 1.0

Shell {
    id: shell
    moving: true
    objectName: "shell"

    Image {
        id: shell_img
        anchors.fill: parent
        source: "qrc:/resources/img/shell.png"
        rotation: shell.direction
    }
}
