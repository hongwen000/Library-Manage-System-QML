import QtQuick 2.4
import QtQuick.Layouts 1.1
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1

Item {
    View {
        anchors.centerIn: parent
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
                    id: idInput
                    anchors.centerIn: parent
                    width: parent.width
                    //readOnly: true
                    //text: userModel.currentControlUser.id
                    placeholderText: "请输入新用户id"
                    maximumLength: 16
                    validator: RegExpValidator {regExp: /[a-zA-Z_0-9]+/}
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
                    placeholderText: "请输入新用户昵称"
                    maximumLength: 32
//                    validator: RegExpValidator {regExp: /[a-zA-Z_0-9]+/}
                    //text: userModel.currentControlUser.name
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
                    placeholderText: "请输入新用户密码"
                    maximumLength: 32
                    //text: userModel.currentControlUser.password
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
                    placeholderText: "请输入新用户邮箱"
                    validator: RegExpValidator { regExp:/\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*/ }
                    //text: userModel.currentControlUser.email
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "content/flag"
                }

                content: MenuField {
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.5 * parent.width

                        model: ["User", "Admin"]
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
                    text: "新建"
                    textColor: Theme.primaryColor
                    onClicked: {
                        userModel.addUser(idInput.text, nameInput.text, passwordInput.text, emailInput.text)
                        showError("提示", "成功建立新用户")
                    }

                }
            }
        }
    }
}
