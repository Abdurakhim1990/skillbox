import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: win
    width: 600
    height: 500
    minimumHeight: 500
    minimumWidth: 600
    visible: true
    title: qsTr("PLAYER")

    Rectangle {
        id: name
        width: parent.width - 10
        height: parent.height - 100
        x: 0
        y: 5
        color: "dimgray"
        anchors.horizontalCenter: parent.horizontalCenter
        Button {
            id: icon
            text: "\u25b6"
            font.pointSize: 60
            width: 150
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            background: Rectangle {
                color: "silver"
            }
        }
    }

    Rectangle {
        width: 480
        height: 30
        x: 0
        y: parent.height - 80
        anchors.horizontalCenter: parent.horizontalCenter
        Button {
            id: play
            text: "\u25b6"
            font.pointSize: 25
            width: 50
            height: 30
            x: 160
        }

        Button {
            id: pause
            text: "\u25ae\u25ae"
            font.pointSize: 15
            width: 50
            height: 30
            x: 220
        }

        Button {
            id: stop
            text: "\uffed"
            font.pointSize: 30
            width: 50
            height: 30
            x: 280
        }

        Button {
            id: rewind_right
            text: "\u25b6\u25b6"
            font.pointSize: 25
            width: 50
            height: 30
            x: 340
        }

        Button {
            id: forward_right
            text: "\u25b6\u25b6\u25b6"
            font.pointSize: 15
            width: 50
            height: 30
            x: 400
        }

        Button {
            id: rewind_left
            text: "\u25c0\u25c0"
            font.pointSize: 25
            width: 50
            height: 30
            x: 100
        }

        Button {
            id: forward_left
            text: "\u25c0\u25c0\u25c0"
            font.pointSize: 15
            width: 50
            height: 30
            x: 30
        }
    }



    Slider {
        value: 0
        width: parent.width - 10
        height: 10
        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height - 35
    }
}
