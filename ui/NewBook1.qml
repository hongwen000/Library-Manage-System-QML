import QtQuick 2.4
import QtQuick.Layouts 1.1
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1
Item {
    View {
        anchors.centerIn: parent
        Component.onCompleted: userModel.setCurrentControlUser(loginBLLIdthis.usrname)
        width: Units.dp(350)
        height: column.implicitHeight + Units.dp(32)
        property var non_editMode: false
        elevation: 1
        radius: Units.dp(2)
        ColumnLayout {
            id: column

            anchors {
                fill: parent
                topMargin: Units.dp(16)
                bottomMargin: Units.dp(16)
            }

            Label {
                id: titleLabel

                anchors {
                    left: parent.left
                    right: parent.right
                    margins: Units.dp(16)
                }

                style: "title"
                text: "书籍信息"
            }

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: Units.dp(8)
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/book"
                }

                content: TextField {
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: non_editMode
                    text: record.bookName
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/account_circle"
                }

                content: TextField {
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: non_editMode
                    text: record.author
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/schedule"
                }

                content: TextField {
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: non_editMode
                    text: record.publishDate.toLocaleString(Qt.locale("zh_CN"), "yyyy-MM-dd")
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/view_headline"
                }

                content: TextField {
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: non_editMode
                    text: record.isbn
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/watch_later"
                }

                content: TextField {
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: non_editMode

                    placeholderText: "还书日期"
                }
            }

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: Units.dp(8)
            }

            RowLayout {
                Layout.alignment: Qt.AlignRight
                spacing: Units.dp(8)

                anchors {
                    right: parent.right
                    margins: Units.dp(16)
                }

                Button {
                    text: "上架"
                    textColor: Theme.primaryColor
                }
            }
        }
    }
}
