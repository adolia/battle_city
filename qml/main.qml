import QtQuick 2.8
import QtMultimedia 5.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1024
    height: 768

    Audio {
        id: introSound
        objectName: "introSound"
        autoPlay: true
        loops: 1
        source: "qrc:/resources/audio/battle_city_intro.mp3"
    }


}