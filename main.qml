import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.1
import QtQuick.Dialogs 1.2
import FileReader 1.0

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


                    MenuSeparator {

                    }

                    MenuItem {
                        text: "Сохранить"
                    }

                    MenuItem {
                        text: "Сохранить как..."
                    }

                    MenuSeparator {

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
        visible: true

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


//    LeftMenu {
//        width: 70
//        height: 480
//    }


    ColumnLayout {
        id: editorScreen
        visible: false

        anchors.fill: parent

        TextEditorArea {
            id: textEditor
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    FileReader {
        id: fileReader
        onError: {
            console.log(msg);
            console.log(source);
        }
    }

    FileDialog {
        id: openProjectDialog

        onAccepted: {
            startScreen.visible = false
            editorScreen.visible = true
            fileReader.setSource(fileUrl)
//            fileReader.setSource(Qt.)
//            fileReader.setSource("/home/nellrun/!/c++/build-IP-Desktop_Qt_5_9_0_GCC_64bit-Debug/Makefile")
            textEditor.textEditorText = fileReader.read()
        }
    }
}
