import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.2


Item {
    property int index: 0
    property bool onlyKnowledgeBase: false

    onOnlyKnowledgeBaseChanged: {
        if (onlyKnowledgeBase) {
            secondTab.visible = false
        }
        else {
            secondTab.visible = true
        }

        index = 0
    }

    onIndexChanged: {
        firstTab.selected = false
        secondTab.selected = false
        thirdTab.selected = false

        switch (index) {
        case 0: firstTab.selected = true; break;
        case 1: secondTab.selected = true; break;
        case 2: thirdTab.selected = true; break;
        }
    }

    Rectangle {
        width: parent.width
        height: parent.height

        color: Material.color(Material.Indigo)

        ColumnLayout {
            width: parent.width

            MenuElement {
                id: firstTab
                width: parent.width
                imageSource: "icons/ic_view_headline_white_24dp_2x.png"
                labelText: ""
                onClicked: {
                    index = 0
                }
            }

            MenuElement {
                id: secondTab
                width: parent.width
                imageSource: "icons/ic_create_white_24dp_2x.png"
                labelText: ""
                onClicked: {
                    index = 1
                }
            }

            MenuElement {
                id: thirdTab
                width: parent.width
                imageSource: "icons/ic_format_indent_increase_white_24dp_2x.png"
                labelText: ""
                onClicked: {
                    index = 2
                }
            }

        }

        MenuElement {
            width: parent.width
            imageSource: "icons/ic_play_arrow_white_24dp_2x.png"
            anchors.bottom: parent.bottom
        }
    }
}
