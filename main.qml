import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.1
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Исчисление предикатов")

    header: ToolBar {
        RowLayout {

            ToolButton {
                text: "Файл"

                onClicked: fileMenu.open()

                Menu {
                    id: fileMenu

                    MenuItem {
                        text: "Создать..."
                        onTriggered: createButton.toggle()
                    }
                    MenuItem {
                        text: "Открыть..."
                        onTriggered: openButton.toggle()
                    }

                    MenuItem {
                        text: "Выход"
                        onClicked: Qt.quit()
                    }
                }
            }

            ToolButton {
                text: "Редактировать"
                onClicked: editMenu.open()

                Menu {
                    id: editMenu

                    MenuItem {
                        text: "Шрифт..."
                    }
                }
            }

            ToolButton {
                id: settingsMenu
                text: "Настройки"
            }

            ToolButton {
                text: "Помощь"

                onClicked: helpMenu.open()

                Menu {
                    id: helpMenu

                    MenuItem {
                        text: "Помощь..."
                    }

                    MenuItem {
                        text: "О программе..."
                    }
                }
            }
        }
    }

    ColumnLayout {
        id: startScreen

        anchors.centerIn: parent

        Label {
            text: qsTr("Создайте новый проект или откройте уже существующий")
        }

        Button {
            id: createButton

            text: qsTr("Создать проект...")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: openButton

            text: qsTr("Открыть проект...")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: openProjectDialog.open()
        }
    }

    FileDialog {
        id: openProjectDialog
    }
}
