import QtQuick 2.4
import QtQuick.Layouts 1.1
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1
Item {
    property var non_editMode: false
    function isValidIsbn (str) {
        var sum,
            weight,
            digit,
            check,
            i;

        str = str.replace(/[^0-9X]/gi, '');

        if (str.length != 10 && str.length != 13) {
            return false;
        }

        if (str.length == 13) {
            sum = 0;
            for (i = 0; i < 12; i++) {
                digit = parseInt(str[i]);
                if (i % 2 == 1) {
                    sum += 3*digit;
                } else {
                    sum += digit;
                }
            }
            check = (10 - (sum % 10)) % 10;
            return (check == str[str.length-1]);
        }

        if (str.length == 10) {
            weight = 10;
            sum = 0;
            for (i = 0; i < 9; i++) {
                digit = parseInt(str[i]);
                sum += weight*digit;
                weight--;
            }
            check = 11 - (sum % 11);
            if (check == 10) {
                check = 'X';
            }
            return (check == str[str.length-1].toUpperCase());
        }
    }
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
                    maximumLength: 256
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
                    maximumLength: 256
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
                    maximumLength: 13
                    validator: RegExpValidator {regExp: /[0-9]+/}
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
                            if(!isValidIsbn(isbnInput.text))
                                showError("提示", "提交失败，ISBN不合法")
                            else
                                userModel.addBook(booknameInput.text, authorInput.text, isbnInput.text, totalstockInput.text, datePicker.selectedDate)
                        }
                    }
            }
        }
    }
}
