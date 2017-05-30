import QtQuick 2.4
import QtQuick.Layouts 1.1
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1

Item {
    property var record: undefined
    property var index: undefined

    View {
        anchors.centerIn: parent
        Component.onCompleted: userModel.setCurrentControlUser(record)
        width: Units.dp(350)
        height: column.implicitHeight + Units.dp(32)

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
                text: "个人信息"
            }

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: Units.dp(8)
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/code"
                }

                content: TextField {
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: true
                    text: userModel.setCurrentControlUser.id
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

                    text: userModel.setCurrentControlUser.name
                }
            }
            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/https"
                }

                content: TextField {
                    anchors.centerIn: parent
                    width: parent.width

                    text: userModel.setCurrentControlUser.password
                }
            }



            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "communication/email"
                }

                content: TextField {
                    anchors.centerIn: parent
                    width: parent.width
                    text: userModel.setCurrentControlUser.email
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
                    text: "修改"
                    textColor: Theme.primaryColor

                }
            }
        }
    }
}
