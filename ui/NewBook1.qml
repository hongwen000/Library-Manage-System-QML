import QtQuick 2.4
import QtQuick.Layouts 1.1
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1
Item {
    property var non_editMode: false
    View {
        anchors.centerIn: parent
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

            Dialog {
                id: datePickerDialog
                hasActions: true
                contentMargins: 0
                floatingActions: true

                DatePicker {
                    id:datePicker
                    frameVisible: false
                    dayAreaBottomMargin : Units.dp(48)
                }

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
                       id:booknameInput
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: non_editMode
                    placeholderText: "请输入新书书名"
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/account_circle"
                }

                content: TextField {
                       id: authorInput
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: non_editMode
                    placeholderText: "请输入新书作者"
                }
            }


            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/view_headline"
                }

                content: TextField {
                    id:isbnInput
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: non_editMode
                    placeholderText: "请输入新书ISBN"
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "image/looks_5"
                }
                content: TextField {
                    id:totalstockInput
                    anchors.centerIn: parent
                    width: parent.width
                    readOnly: non_editMode
                    placeholderText: "请输入新书库存量"
                    validator: IntValidator {bottom: 1; top:1000;} //前天上书上了四百本“美国宪法发展的里程碑案例...所以对我们这种世界一流大学(o_ _)ﾉ...1000是相对合适的...”
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/schedule"
                }
                content: Button {
                    anchors.centerIn: parent
                    width: parent.width * 0.5
                    anchors.left: parent
                    text: "点此选择日期"
                    onClicked: datePickerDialog.show()
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

                    onClicked: {
                            userModel.addBook(booknameInput.text, authorInput.text, isbnInput.text, totalstockInput.text, datePicker.selectedDate)
                        }
                    }
            }
        }
    }
}
