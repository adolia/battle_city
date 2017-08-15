import QtQuick 2.0

Image {
    property int number
    property int spawnValue

    width: 20
    height: 20
    source: "qrc:/resources/img/enemy_tank.gif"
    visible: number > spawnValue ? false : true
}
