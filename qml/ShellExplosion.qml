import QtQuick 2.4
import QtMultimedia 5.4

AnimatedImage
{
    height: 38
    width: 34
    fillMode: Image.Stretch
    source: "qrc:/resources/img/shell_explosion.gif"
    playing: false
    visible: playing

    property bool solid: false
    property bool isExplosion: true
    property int player: -1

    signal finishedAnimation()

    function startAnimation()
    {
        bulletExplosionSound.play()
        playing = true;
        explosionTimer.restart();
    }

    SoundEffect {
        id: bulletExplosionSound
        volume: .3
        source: "qrc:/resources/audio/explosion.wav"
    }

    Timer
    {
        id: explosionTimer
        interval: 1000
        running: false
        repeat: false
        onTriggered: finishedAnimation()
    }
}
