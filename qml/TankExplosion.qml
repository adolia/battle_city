import QtQuick 2.4
import QtMultimedia 5.4

AnimatedImage
{
    height: 38
    width: 34
    fillMode: Image.Stretch
    source: "qrc:/resources/img/tank_explosion.gif"
    playing: false
    visible: playing

    property bool solid: false
    property bool isExplosion: true
    property int player: -1

    signal finishedAnimation()

    function startAnimation()
    {
        if(!playing)
        {
            playing = true;
            explosionTimer.restart();
        }
    }

    Timer
    {
        id: explosionTimer
        interval: 800
        running: false
        repeat: false
        onTriggered:
        {
            visible = false
            finishedAnimation()

        }
    }
}
