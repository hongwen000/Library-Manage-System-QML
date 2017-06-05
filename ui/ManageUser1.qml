import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1
import Backend 1.0
import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3 as QuickControls
import User 1.0

Page {
    //property alias searchbox: searchPage.searchboxout
    id: allUserPage
    View {
        anchors {
            fill: parent
            margins: Units.dp(32)
        }
        elevation: 1


        Loader {
            id: loader
        }

        Column {
            anchors.fill: parent
            Repeater {
                model: userModel.userList
                delegate:
                    ListItem.Subtitled {
                    property var record: userModel.userList[index]
                    maximumLineCount: 8
                    Text {
                        id: bookInfoText
                        text:index  + 1 + qsTr(" : ") + record.id + " " + record.password
                        leftPadding: Units.dp(32)
                        topPadding: Units.dp(32)
                        property alias bookInfoText: bookInfoText
                    }
                    onClicked: {
                        pageStack.push(Qt.resolvedUrl("qrc:/ui/ManageUsers.qml"),{record:record, index:index})
                    }
                }
            }

        }
    }
}
