import QtQuick 2.0
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1
import Backend 1.0
import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3 as QuickControls
import "../"

ColumnLayout {
    Component.onCompleted: userModel.setCurrentControlUser("virutalUser_AllBooks")

    id: bookListBase
    View {
        anchors {
            fill: parent
            margins: Units.dp(32)
        }

        elevation: 1

        Loader {
            id: loader
        }


        ActionButton {

            anchors {
                right: parent.right
                bottom: parent.bottom
                margins: Units.dp(32)
            }

            action: Action {
                id: search
                function receiveKeyword(skeyword) {
                    userModel.searcher = skeyword
                    userModel.searcherChanged()
                    loader.active = false
                }

                onTriggered:{
                    loader.active = true
                    loader.source = ""
                    loader.source = "qrc:/ui/SearchBox.qml"
                    loader.item.clicked.connect(receiveKeyword)
                }
                iconName: "action/search"
            }
        }

        Column {
            anchors.fill: parent
            Repeater {
                model: userModel.currentControlUser.record
                delegate:
                    ListItem.Subtitled {
                    property var record: userModel.currentControlUser.record[index]
                    maximumLineCount: 8
                    Text {
                        id: bookInfoText
                        text:index  + 1 + qsTr(" : ") + record.bookName
                        leftPadding: Units.dp(128)
                        topPadding: Units.dp(32)
                        property alias bookInfoText: bookInfoText
                    }

                    action: Image {
                        source: applicationDirPath + "/img/" + record.isbn + ".jpg"
                        width: Units.dp(72)
                        height: Units.dp(96)
                        x:bookInfoText.x
                        y:bookInfoText.y - Units.dp(20)
                    }
                    onClicked: {
                        pageStack.push(Qt.resolvedUrl("qrc:/ui/BookInfoBase.qml"),{record:record, index:index})
                    }
                }
            }
        }
    }
}
