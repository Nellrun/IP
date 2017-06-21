import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0


Item {

    property string textEditorText: ""

    RowLayout {
        spacing: 10

        anchors.fill: parent

        ListView {
            id: lineCount
            Layout.fillHeight: true

            Layout.topMargin: 7
            Layout.rightMargin: 15
            Layout.leftMargin: 5

            model: lineCountModel
            delegate: Text {
                font: textEditor.font
                text: num
            }
        }

        ListModel {
            id: lineCountModel

            ListElement {
                num : "1"
            }

        }

        TextArea {
            id: textEditor

            text: textEditorText

            Layout.fillWidth: true
            Layout.fillHeight: true

            onLineCountChanged: {
                lineCountModel.clear()
                for (var i = 1; i <= textEditor.lineCount; i++) {
                    lineCountModel.append({num : String(i)});
                }
            }
        }
    }
}
