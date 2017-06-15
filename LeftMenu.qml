import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.2


Item {
    Rectangle {
//        anchors.fill: parent
        width: parent.width
        height: parent.height

        color: Material.color(Material.Indigo)

        ColumnLayout {
            spacing: 30

            width: parent.width

            ColumnLayout {

                width: parent.width

                spacing: 10

                Image {
                    height: 32
                    width: 32
                    anchors.centerIn: parent

                    source: "icons/text_24dp.png"
                }

                Text {
                    text: "База знаний"
//                    anchors.centerIn: parent
                }

            }
        }
    }
}
