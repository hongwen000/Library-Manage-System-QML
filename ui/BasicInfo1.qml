import QtQuick 2.4
import QtQuick.Layouts 1.1
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1

Item {
    property var record: undefined
    property var index: undefined
    Component.onCompleted: userModel.setCurrentControlUser(loginBLLIdthis.usrname)

    View {
        anchors.centerIn: parent
        //Component.onCompleted: userModel.setCurrentControlUser(record)
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
                    text: userModel.currentControlUser.id
                }
            }
            ListItem.Standard {

                action: Icon {
                    anchors.centerIn: parent
                    name: "action/account_circle"
                }

                content: TextField {
                    id: nameInput
                    anchors.centerIn: parent
                    width: parent.width

                    text: userModel.currentControlUser.name
                }
            }
            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/https"
                }

                content: TextField {
                    id: passwordInput
                    anchors.centerIn: parent
                    width: parent.width

                    text: userModel.currentControlUser.password
                }
            }



            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "communication/email"
                }

                content: TextField {
                    id: emailInput
                    anchors.centerIn: parent
                    width: parent.width
                    text: userModel.currentControlUser.email
                }
            }
            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "content/flag"
                }

                content: TextField {
                    id: typeInput
                    anchors.centerIn: parent
                    width: parent.width
                    text: userModel.currentControlUser.type
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
                    onClicked: {
                        userModel.currentControlUser.name = nameInput.text
                        userModel.currentControlUser.password = passwordInput.text
                        userModel.currentControlUser.email = emailInput.text
                        showError("提示", "保存成功")
                    }
                }
            }
        }
    }
}
