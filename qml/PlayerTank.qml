import QtQuick 2.0
import QtMultimedia 5.5
import QtGraphicalEffects 1.0
import BattleObjects 1.0

Tank {
    id: player_tank
    lives: 3
    objectName: "player_tank"

    // Emit when the player lives count falls to zero
    signal playerIsDead

    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/resources/img/user_tank.png"
        rotation: player_tank.direction
    }
    // The glow effect that appears while the player spawns
    Glow {
            // Used for smooth glow animation
            property double opacityFactor: 0

        id: respawnGlow
        anchors.fill: img
        opacity: opacityFactor * 0.1
        radius: 10
        samples: 21
        color: "white"
        source: img
        rotation: player_tank.direction
        // Applies pulse animation effect on glow effect
        Behavior on opacityFactor { NumberAnimation {} }
    }
    Timer {
        property int value: 0
        id: spawn_timeout
        repeat: false
        running: false
        interval: 800
        onTriggered: {
            respawn_player(value)
        }
    }
    Timer {
        // A glow pulse counter
        property int ticks: 0
        id: glowTimer
        repeat: true
        running: false
        interval: 500

        onTriggered: {
            if (ticks > 6) {
                ticks = 0;
                glowTimer.stop();
                respawnGlow.opacityFactor = 0;
            }
            else {
                respawnGlow.opacityFactor = respawnGlow.opacityFactor > 0 ? 0 : 10
                ticks++;
            }
        }
    }

    SoundEffect {
        id: shotSound
        source: "qrc:/resources/audio/shot.wav"
    }

    SoundEffect {
        id: explosionSound
        source: "qrc:/resources/audio/explosion.wav"
    }
    SoundEffect {
        id: movingSound
        source: "qrc:/resources/audio/user_moving.wav"
    }
    function respawn_player(value) {
        value = parseInt(value)
        if (value > 0) {
            respawnGlow.opacityFactor = 10;
            glowTimer.start();
            respawn(value);
            visible = true;
        } else {
            visible = false;
            moving = false;
            playerIsDead();
        }
    }
    onLivesChanged: {
        var tankExplosion = Qt.createComponent("TankExplosion.qml");
        var obj = tankExplosion.createObject(parent);
        obj.anchors.centerIn = player_tank
        obj.width = player_tank.width * 2
        obj.height = player_tank.height * 2.4
        obj.startAnimation()
        explosionSound.play();
        visible = false;

        spawn_timeout.value = value;
        spawn_timeout.start();

    }

    onShot: {
        shotSound.play()
    }

    Keys.onPressed: {
        movingSound.play()
    }


}
