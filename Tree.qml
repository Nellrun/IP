import QtQuick 2.0
import QtQuick.Controls 1.4
import TreeModel 1.0

Item {

    TreeModel {
        id: myTreeModel
    }

    TreeView {
        model: myTreeModel

        TableViewColumn {
            title: "Name"
            role: "DisplayRole"
            width: 300
        }
    }
}
