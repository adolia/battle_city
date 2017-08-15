import QtQuick 2.0
import QtMultimedia 5.5

Rectangle {
    width: 900
    height: 700
    color: "black"

    PlayerTank {
        id: player
        x: 380
        y: 520
        width: 50
        height: 50
        direction: PlayerTank.UP
        onPlayerIsDead: {
            var goScreen = Qt.createComponent("GameOverScreen.qml");
            var obj = goScreen.createObject(parent);
            obj.visible = true;
        }
    }

    PlayerBase {
            anchors.left: left_base_wall.right
            anchors.bottom: parent.bottom
            anchors.leftMargin: 4
            width: height
            height: left_base_wall.height
    }
    property int wallSpace: (player.width + (player.width / 5))

    BrickWall {
        id: top_left_aligned_wall
        anchors.left: parent.left
        anchors.leftMargin: wallSpace
        anchors.top: parent.top
        anchors.topMargin: wallSpace
        width: player.width + player.width / 5
        height: 210
    }
    BrickWall {
        id: next_top_left_aligned_wall
        anchors.left: top_left_aligned_wall.right
        anchors.leftMargin: wallSpace
        anchors.top: parent.top
        anchors.topMargin: wallSpace
        width: player.width + player.width / 5
        height: 210
    }
    BrickWall {
        id: top_mid_left_aligned_wall
        anchors.left: next_top_left_aligned_wall.right
        anchors.leftMargin: wallSpace
        anchors.top: parent.top
        anchors.topMargin: wallSpace
        width: player.width + player.width / 5
        height: 170
    }

    BrickWall {
        id: bottom_left_aligned_wall
        anchors.left: parent.left
        anchors.leftMargin: wallSpace
        anchors.bottom: parent.bottom
        anchors.bottomMargin: wallSpace
        width: player.width + player.width / 5
        height: 210
    }
    BrickWall {
        id: next_bottom_left_aligned_wall
        anchors.left: bottom_left_aligned_wall.right
        anchors.leftMargin: wallSpace
        anchors.bottom: parent.bottom
        anchors.bottomMargin: wallSpace
        width: player.width + player.width / 5
        height: 210
    }
    BrickWall {
        id: top_right_aligned_wall
        anchors.right: control.left
        anchors.rightMargin: wallSpace
        anchors.top: parent.top
        anchors.topMargin: wallSpace
        width: player.width + player.width / 5
        height: 210
    }
    BrickWall {
        id: next_top_right_aligned_wall
        anchors.right: top_right_aligned_wall.left
        anchors.rightMargin: wallSpace
        anchors.top: parent.top
        anchors.topMargin: wallSpace
        width: player.width + player.width / 5
        height: 210
    }
    BrickWall {
        id: top_mid_right_aligned_wall
        anchors.right: next_top_right_aligned_wall.left
        anchors.rightMargin: wallSpace
        anchors.top: parent.top
        anchors.topMargin: wallSpace
        width: player.width + player.width / 5
        height: 170
    }
    ArmorWall {
        anchors.left: top_mid_left_aligned_wall.right
        anchors.right: top_mid_right_aligned_wall.left
        anchors.top: parent.top
        anchors.topMargin: wallSpace + 90
        width: wallSpace
        height: 50
    }
    BrickWall {
        id: bottom_mid_left_aligned_wall
        anchors.left: next_bottom_left_aligned_wall.right
        anchors.leftMargin: wallSpace
        anchors.bottom: top_base_wall.top
        anchors.bottomMargin: wallSpace
        width: player.width + player.width / 5
        height: 150
    }
    BrickWall {
        id: bottom_mid_right_aligned_wall
        anchors.right: next_bottom_right_aligned_wall.left
        anchors.rightMargin: wallSpace
        anchors.bottom: top_base_wall.top
        anchors.bottomMargin: wallSpace
        width: player.width + player.width / 5
        height: 150
    }
    BrickWall {
        id: bottom_mid_wall
        anchors.right: bottom_mid_right_aligned_wall.left
        anchors.left: bottom_mid_left_aligned_wall.right
        anchors.bottom: top_base_wall.top
        anchors.bottomMargin: 130
        width: 60
        height: player.width
    }

    BrickWall {
        anchors.right: bottom_mid_left_aligned_wall.right
        anchors.bottom: bottom_mid_left_aligned_wall.top
        anchors.bottomMargin: wallSpace
        width: player.width + player.width / 5
        height: player.width
    }
    BrickWall {
        anchors.left: bottom_mid_right_aligned_wall.left
        anchors.bottom: bottom_mid_right_aligned_wall.top
        anchors.bottomMargin: wallSpace
        width: player.width + player.width / 5
        height: player.width
    }

    BrickWall {
        anchors.right: next_bottom_left_aligned_wall.right
        anchors.bottom: next_bottom_left_aligned_wall.top
        anchors.top: next_top_left_aligned_wall.bottom
        anchors.bottomMargin: wallSpace
        anchors.topMargin: wallSpace
        width: 100
        height: player.width
    }
    BrickWall {
        anchors.left: next_bottom_right_aligned_wall.left
        anchors.bottom: next_bottom_right_aligned_wall.top
        anchors.top: next_top_right_aligned_wall.bottom
        anchors.bottomMargin: wallSpace
        anchors.topMargin: wallSpace
        width: 100
        height: player.width
    }

    ArmorWall {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 340
        width: 50
        height: 20
    }
    ArmorWall {
        anchors.right: control.left
        anchors.top: parent.top
        anchors.topMargin: 340
        width: 50
        height: 20
    }

    BrickWall {
        id: bottom_right_aligned_wall
        anchors.right: control.left
        anchors.rightMargin: wallSpace
        anchors.bottom: parent.bottom
        anchors.bottomMargin: wallSpace
        width: player.width + player.width / 5
        height: 210
    }
    BrickWall {
        id: next_bottom_right_aligned_wall
        anchors.right: bottom_right_aligned_wall.left
        anchors.rightMargin: wallSpace
        anchors.bottom: parent.bottom
        anchors.bottomMargin: wallSpace
        width: player.width + player.width / 5
        height: 210
    }

    BrickWall {
        id: left_base_wall
        x: 345
        anchors.bottom: parent.bottom
        width: player.width / 2
        height: player.height + player.height / 5
    }

    BrickWall {
        id: right_base_wall
        x: 440
        anchors.bottom: parent.bottom
        width: player.width / 2
        height: player.height + player.height / 5
    }

    BrickWall {
        id: top_base_wall
        x: 345
        anchors.bottom: left_base_wall.top
        width: 120
        height: player.height / 2
    }

    ControlPanel {
        id: control
        objectName: "controlPanel"
        livesCount: player.lives
        visible: true
        width: 100
        height: parent.height
        anchors.top: parent.top
        anchors.right: parent.right
    }
    Item {
        id: screen
        objectName: "win_screen"
        visible: false
        width: parent.width
        height: parent.height
        anchors.verticalCenter: parent.verticalCenter
        Image {
            id: img
            visible: true
            anchors.fill: parent
            source: "qrc:/resources/img/win_screen.png"
        }
    }

}
