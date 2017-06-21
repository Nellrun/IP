import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.2


Item {
    Rectangle {
        width: parent.width
        height: parent.height

        color: Material.color(Material.Indigo)

        ColumnLayout {
//            spacing: 20
            width: parent.width

//            ColumnLayout {
//                width: parent.width
////                anchors.centerIn: parent

//                spacing: 15

//                Image {
//                    source: "icons/text_24dp_w.png"
//                    anchors.centerIn: parent
//                }

//                Text {
//                    color: "white"
//                    text: "База знаний"
//                }
//            }

            MenuElement {
                width: parent.width
                imageSource: "icons/text_24dp_w.png"
                labelText: "База знаний"
            }

            MenuElement {
                width: parent.width
                imageSource: "icons/text_24dp_w.png"
                labelText: "Вывод"
            }

            MenuElement {
                width: parent.width
                imageSource: "icons/text_24dp_w.png"
                labelText: "Результат"
            }

//            MenuElement {
////                height: 100
//                imageSource: "icons/text_24dp_w.png"
//                labelText: "Вывод"
//            }
        }
    }
}
