import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: mainWindow
    title: qsTr("CyclingApp")
    width: 640
    height: 480

    signal importTriggered()

    Action {
        id: quitAction
        text: qsTr("&Quit")
        shortcut: "Ctrl+Q"
        iconSource: "application-exit.png"
        iconName: "application-exit"
        onTriggered: Qt.quit()
    }
    Action {
        id: importAction
        text: "Import"
        shortcut: "Ctrl+I"
        onTriggered: mainWindow.importTriggered()
    }
    Action {
        id: aboutAction
        text: qsTr("About CyclingApp")
        onTriggered: mainWindow.aboutTriggered()
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem { action: importAction }
            MenuSeparator { }
            MenuItem { action: quitAction }
        }
        Menu {
            title: qsTr("&Help")
            MenuItem { action: aboutAction }
        }
    }

    toolBar: ToolBar {
        ToolButton { action: importAction }
    }


    SplitView {
        id: splitView1
        anchors.fill: parent

        ScrollView {
            ListView {
                id: listView1
                y: 0
                width: 189
                height: 480
                focus: true
                highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                anchors.left: parent.left
                anchors.leftMargin: 0
                delegate: Item {
                    x: 5
                    height: 40
                    Row {
                        id: row1
                        spacing: 10
                        Rectangle {
                            width: 40
                            height: 40
                            color: colorCode
                        }

                        Text {
                            text: name
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                        }
                    }
                }
                model: ListModel {
                    ListElement {
                        name: "Grey"
                        colorCode: "grey"
                    }

                    ListElement {
                        name: "Red"
                        colorCode: "red"
                    }

                    ListElement {
                        name: "Blue"
                        colorCode: "blue"
                    }

                    ListElement {
                        name: "Green"
                        colorCode: "green"
                    }
                }
            }
        }

        ListView {
            id: listView2
            x: 188
            y: 0
            width: 452
            height: 480
            delegate: Item {
                x: 5
                height: 40
                Row {
                    id: row2
                    spacing: 10
                    Rectangle {
                        width: 40
                        height: 40
                        color: colorCode
                    }

                    Text {
                        text: name
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                }
            }
            model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }

        }


    }
}
