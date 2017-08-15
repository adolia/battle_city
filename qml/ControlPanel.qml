import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    id: panel
    color: "darkGray"

    // Should be binded to player.lives property
    property int livesCount
    // Should be set by a BattleField
    property int enemiesLeft


        Text {
            id: txt
            anchors.top: parent.top
            anchors.topMargin: parent.height / 8
            anchors.horizontalCenter: parent.horizontalCenter
            text: "IP x" + panel.livesCount
            color: "#fbe323"
            font.pixelSize: 22
        }
        Image {
            width: 20
            height: 20
            anchors.top: txt.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/resources/img/user_tank.png"
        }

        Grid {
            anchors.centerIn: parent

            EnemyFlag { number:  0; spawnValue: panel.enemiesLeft }
            EnemyFlag { number:  1; spawnValue: panel.enemiesLeft }
            EnemyFlag { number:  2; spawnValue: panel.enemiesLeft }
            EnemyFlag { number:  3; spawnValue: panel.enemiesLeft }
            EnemyFlag { number:  4; spawnValue: panel.enemiesLeft }
            EnemyFlag { number:  5; spawnValue: panel.enemiesLeft }
            EnemyFlag { number:  6; spawnValue: panel.enemiesLeft }
            EnemyFlag { number:  7; spawnValue: panel.enemiesLeft }
            EnemyFlag { number:  8; spawnValue: panel.enemiesLeft }
            EnemyFlag { number:  9; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 10; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 11; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 12; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 13; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 14; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 15; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 16; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 17; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 18; spawnValue: panel.enemiesLeft }
            EnemyFlag { number: 19; spawnValue: panel.enemiesLeft }
        }
}
