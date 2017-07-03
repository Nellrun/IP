import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
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
                id: fileButton
                text: "Файл"

                onClicked: fileMenu.open()

                Menu {
                    id: fileMenu
                    y: fileButton.height

                    MenuItem {
                        text: "Создать..."
                        onTriggered: {
                            startScreen.visible = false
                            editorScreen.visible = true
                        }
                    }

                    MenuItem {
                        text: "Открыть..."
                        onTriggered: {
                            openProjectDialog.open()
                        }
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
                id: editButton
                text: "Редактировать"
                onClicked: editMenu.open()

                Menu {
                    id: editMenu
                    y: editButton.height

                    MenuItem {
                        text: "Шрифт..."
                    }
                }
            }

            ToolButton {
                id: settingsButton
                text: "Настройки"

                onClicked: {
                    settingWindow.visible = true
                }
            }

            ToolButton {
                id: helpButton
                text: "Помощь"

                onClicked: { //helpMenu.open()
                    errorText.addNew("Hello")
                }

                Menu {
                    id: helpMenu
                    y: helpButton.height

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


    SettingsWindow {
        id: settingWindow
        visible: false

        onTChanged: {
            if (t == 0) {
                leftMenu.onlyKnowledgeBase = false;
            }
            else {
                leftMenu.onlyKnowledgeBase = true;
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
            onClicked: {
                startScreen.visible = false
                editorScreen.visible = true
            }
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


    RowLayout {
        id: editorScreen
        visible: false

        anchors.fill: parent

        LeftMenu {
            id: leftMenu
            objectName: "leftMenu"
            width: 64
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            onIndexChanged: {
                sLayout.currentIndex = index
            }
        }

        ListModel {
            id: errorText
            objectName: "errorModel"

    //        ListElement {
    //            i: 0
    //            textError: "expect 123 at line 123 columnt 1231"
    //        }

            function addNew(msg) {
                errorText.append({i : errorText.count, textError: msg})
    //            errorText.sync()
            }
        }

        StackLayout {
            id: sLayout

            Layout.fillHeight: true
            Layout.fillWidth: true

            currentIndex: 0

            TextEditorArea {
                id: textEditor
                objectName: "knowledgeBase"
                textEditorText: "not P(u, z, k(s)) or not P(z, s, w) or not P(u, w, k(s))."
            }

            TextEditorArea {
                textEditorText: "O(E, C).\n# Escort(Mary, z). \n # not P(g(x, y), x, y) or not P(p, f(p, q), q)."
                objectName: "targetStatements"
            }

            TextEditorArea {
                objectName: "outputTextEditor"
                textEditorText: "three"
                onTextEditorTextChanged: {
                    leftMenu.index = 2
                }
            }
        }
    }

    ListView {
        anchors.top: editorScreen.top
        anchors.right: editorScreen.right
        model: errorText
        visible: true

        width: 350
        height: 500

        delegate: Rectangle {
                height: 40
                width: parent.width
                color: "#5FFF0000"

                radius: 5

                Text {
                    anchors.centerIn: parent
                    font.pointSize: 12
                    text: textError
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        errorText.remove(i)
                    }
                }
            }
    }


    FileReader {
        id: fileReader
        onError: {
            console.log(msg);
        }
    }

    FileDialog {
        id: openProjectDialog

        onAccepted: {
            startScreen.visible = false
            editorScreen.visible = true
            fileReader.setSource(fileUrl)
            textEditor.textEditorText = fileReader.read()
        }
    }
}
