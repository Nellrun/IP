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
            width: parent.width

            MenuElement {
                width: parent.width
                imageSource: "icons/ic_view_headline_white_24dp_2x.png"
                labelText: ""
            }

            MenuElement {
                width: parent.width
                imageSource: "icons/ic_create_white_24dp_2x.png"
                labelText: ""
            }

            MenuElement {
                width: parent.width
                imageSource: "icons/ic_format_indent_increase_white_24dp_2x.png"
                labelText: ""
            }

        }

        MenuElement {
            width: parent.width
            imageSource: "icons/ic_play_arrow_white_24dp_2x.png"
            anchors.bottom: parent.bottom
        }
    }
}
