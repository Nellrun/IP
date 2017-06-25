import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0


    ApplicationWindow {
        id: settings

        title: "Настройки"

        width: 640
        height: 240
        visible: false

        property bool autocomplete: false
        property int t: 0
        property int constantStyle: 0

        onClosing: {
            visible = false
        }

        ColumnLayout {

            spacing: 10
            anchors.left: parent.left
            anchors.right: parent.right

            CheckBox {
                id: autoCheckBox
                text: "Автоматически подставлять \"->\""
            }

            RowLayout {
                spacing: 10
                Layout.leftMargin: 10
                Layout.rightMargin: 10
                Layout.fillWidth: true

                Label {
                    width: 200
                    text: "Выводимые высказывания в:"
                }

                ComboBox {
                    id: tComboBox
                    Layout.fillWidth: true
                    model: ["отдельном файле", "в конце базы знаний"]
                }
            }

            RowLayout {
                spacing: 10
                Layout.leftMargin: 10
                Layout.rightMargin: 10
                Layout.fillWidth: true

                Label {
                    width: 200
                    text: "Константы начинаются с:"
                }

                ComboBox {
                    id: constantComboBox
                    Layout.fillWidth: true
                    model: ["прописной буквы", "строчной буквы"]
                }
            }

            RowLayout {
                anchors.right: parent.right
                Layout.rightMargin: 10

                spacing: 20

                Button {
                    text: "Ok"

                    onClicked: {
                        settings.visible = false
                        constantStyle = constantComboBox.currentIndex
                        t = tComboBox.currentIndex
                        autocomplete = autoCheckBox.pressed
                    }
                }

                Button {
                    text: "Отмена"

                    onClicked: {
                        settings.visible = false
                        constantComboBox.currentIndex = constantStyle
                        tComboBox.currentIndex = t
                        if (autoCheckBox.pressed() != autocomplete) autoCheckBox.toggle()
//                        autoCheckBox.pressed = autocomplete
                    }
                }
            }

        }

    }
//}
