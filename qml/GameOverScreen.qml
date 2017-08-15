import QtQuick 2.3
import QtMultimedia 5.3

Item {
    visible: true
    width: 1024
    height: 768
    Image {
        id: img
        visible: true
        anchors.fill: parent
        source: "qrc:/resources/img/game_over.png"
    }
    Audio {
        id: goSound
        objectName: "goSound"
        autoPlay: true
        loops: 1
        source: "qrc:/resources/audio/battle_city_game_over.mp3"
    }

}
