import QtQuick.Layouts 1.1
import QtQuick 2.4
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1


Page {
    id: userInfoPage
    property var record: undefined
    property var index: undefined
    title: record.id
    property bool non_editMode: false

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
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: true
                    text: record.id
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

                    text: record.name
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
                    placeholderText: "******"
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
                    text: record.email

                    validator: RegExpValidator { regExp:/^(([^<>()\[\]\.,;:\s@\"]+(\.[^<>()\[\]\.,;:\s@\"]+)*)|(\".+\"))@(([^<>()[\]\.,;:\s@\"]+\.)+[^<>()[\]\.,;:\s@\"]{2,})$/ }
                }
            }

//            ListItem.Standard {
//                action: Icon {
//                    anchors.centerIn: parent
//                    name: "content/flag"
//                }

//                content: TextField {
//                    id: typeInput
//                    anchors.centerIn: parent
//                    width: parent.width
//                    text: record.type
//                }
//            }
            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "content/flag"
                }

                content: MenuField {
                        id: typeInput
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.5 * parent.width
                        model: ["user", "admin"]
                        placeholderText: record.type
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
                        userModel.editUser(record, nameInput.text, passwordInput.text, emailInput.text, typeInput.selectedText)
                        showError("提示", "修改成功")
                    }
                }
                Button {
                    text: "删除"
                    textColor: Theme.primaryColor
                    onClicked: {
                        userModel.removeUser(record)
                        userInfoPage.pop()
                    }
                }
            }
        }
    }
}
