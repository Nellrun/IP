import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0


Rectangle {
        id: root
        width: parent.width
        height: 64
        color: "#00FFFFFF"

        property string imageSource: ""
        property string labelText: ""
        property bool selected: false

        signal clicked

        onSelectedChanged: {
            if (selected) {
                onSelectedGlow.start()
            }
            else {
                root.color = "#00FFFFFF"
            }
        }

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
                if (!selected)
                    onEnterGlow.start()
            }

            onExited: {
                if (!selected)
                    onExitGlow.start()
            }

            onClicked: {

//                root.color = "#5F000000"

                root.clicked()
            }
        }

        PropertyAnimation {
            id: onEnterGlow
            target: root
            properties: "color"
            from: "#00FFFFFF"
            to: "#2FFFFFFF"
            duration: 250
        }

        PropertyAnimation {
            id: onExitGlow
            target: root
            properties: "color"
            from: "#2FFFFFFF"
            to: "#00FFFFFF"
            duration: 250
        }

        PropertyAnimation {
            id: onSelectedGlow
            target: root
            properties: "color"
            to: "#5F000000"
            duration: 250
        }
    }
