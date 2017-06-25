import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0

Item {
    property string imageSource: ""
    property string labelText: ""

    signal clicked

    id: root
    height: 64

    Rectangle {
        id: glowBlock
        width: parent.width
        height: parent.height
        color: "#00FFFFFF"

        ColumnLayout {
            anchors.fill: parent
//            anchors.centerIn: parent

            Image {
                width: 32
                height: 32
                source: imageSource
                anchors.centerIn: parent
            }

            Text {
                text: labelText
                color: "white"
                horizontalAlignment: Text.AlignHCenter

//                anchors.centerIn: parent
//                anchors.horizontalCenter: parent
            }
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onEntered: {
                onEnterGlow.start()
            }

            onExited: {
                onExitGlow.start()
            }

            onClicked: root.clicked()
        }
    }

    PropertyAnimation {
        id: onEnterGlow
        target: glowBlock
        properties: "color"
        from: "#00FFFFFF"
        to: "#2FFFFFFF"
        duration: 250
    }

    PropertyAnimation {
        id: onExitGlow
        target: glowBlock
        properties: "color"
        from: "#2FFFFFFF"
        to: "#00FFFFFF"
        duration: 250
    }

}
