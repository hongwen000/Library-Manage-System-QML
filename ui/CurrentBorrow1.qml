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

Page {
    Component.onCompleted: {
        console.log("File changed to CurrentBorrow1.qml, changing setCurrentControlUser to " + loginBLLIdthis.usrname)
        userModel.setCurrentControlUser(loginBLLIdthis.usrname)

    }id: bookListBase

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
                        source: applicationDirPath + "/img/" + record.isbn + qsTr(".jpg")
                        width: Units.dp(72)
                        height: Units.dp(96)
                        x:bookInfoText.x
                        y:bookInfoText.y - Units.dp(20)
                    }
                    onClicked: {
                        pageStack.push(Qt.resolvedUrl("qrc:/ui/BookInfoBorrowed.qml"),{record:record, index:index})
                    }
                }
            }
        }
    }
}

//BookListBase{

//}
