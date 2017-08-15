import QtQuick 2.0
import QtMultimedia 5.5
import QtGraphicalEffects 1.0
import BattleObjects 1.0

AITank {
    id: enemy_tank
    lives: 1
    moving: true
    objectName: "enemy_tank"

    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/resources/img/enemy_tank.gif"
        rotation: enemy_tank.direction
    }
    SoundEffect {
        id: explosionSound
        source: "qrc:/resources/audio/explosion.wav"
    }

    onLivesChanged: {
       // var tankExplosion = Qt.createComponent("TankExplosion.qml");
       // var obj = tankExplosion.createObject(parent);
       // obj.finishedAnimation.connect(obj.destroy);
       // obj.anchors.centerIn = enemy_tank
       // obj.width = enemy_tank.width * 2
       // obj.height = enemy_tank.height * 2.4
       // obj.startAnimation()
       explosionSound.play();

       if (value <= 0) {
           alive = false;
       }
    }

}
