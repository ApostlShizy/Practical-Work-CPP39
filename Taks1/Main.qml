import QtQuick

Window {
    width: 640
    height: 480
    visible: true

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "InitialStat"

        Rectangle {
            id: moveRectangle
            x: 100
            y: 200
            width: 100
            height: 100
            radius: 5
            color: "lightgrey"
            border.width: 3
            border.color: "black"
            Text {
                anchors.centerIn: parent
                font.pointSize: 15
                text: "move"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    boll.x += 30
                    scene.state = "OtherState"
                    if(boll.x >= returnRactangle.x) {
                        scene.state = "InitialStat"
                    }
                }
            }
        }

        Rectangle {
            id: returnRactangle
            x: parent.width - 200
            y: 200
            width: 100
            height: 100
            radius: 5
            color: "lightgrey"
            border.width: 3
            border.color: "black"
            Text {
                anchors.centerIn: parent
                font.pointSize: 15
                text: "return"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: scene.state = "InitialStat"
            }
        }

        Rectangle {
            id: boll
            x: moveRectangle.x + 5
            y: moveRectangle.y + 5
            width: moveRectangle.width - 10
            height: moveRectangle.height - 10
            radius: width / 2
            color: "green"
        }

        states: [
            State {
                name: "OtherState"
                PropertyChanges {
                    target: boll
                    x: boll.x
                }
            },
            State {
                name: "InitialStat"
                PropertyChanges {
                    target: boll
                    x: moveRectangle.x + 5
                }
            }
        ]

        transitions: [
            Transition {
                from: "OtherState"
                to: "InitialStat"

                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            }
        ]
    }
}
