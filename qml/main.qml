import QtQuick 2.8
import QtMultimedia 5.9

BattleField {
    visible: true
    width: 900
    height: 700

    Audio {
        id: introSound
        objectName: "introSound"
        autoPlay: true
        loops: 1
        source: "qrc:/resources/audio/battle_city_intro.mp3"
    }


}
