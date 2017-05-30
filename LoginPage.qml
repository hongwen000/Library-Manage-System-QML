import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import Login 1.0
Page {
    property alias quitButton: quitButton
    property alias regButton: regButton
    property alias loginButton: loginButton
    property alias loginBLL: loginBLL

    height: main.height
    width: main.width
    font.family: "思源宋体"
    function logout() {
        parent.pop()
    }
    GridLayout {
        rows: 3
        columns: 2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: - parent.height / 8
        anchors.verticalCenter: parent.verticalCenter

        Label {
            id: usrnamelabel
            text: qsTr("用户名：")
            Layout.preferredHeight: 36
            Layout.preferredWidth: 82
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            fontSizeMode: Text.Fit
        }

        TextField {
            id: usrnameInput
            font.pointSize: 14
            Layout.preferredHeight: 40
            Layout.preferredWidth: 220
            placeholderText: qsTr("请输入用户名")

        }

        Label {
            id: pwdlabel
            text: qsTr("密码：")
            Layout.preferredHeight: 40
            Layout.preferredWidth: 82
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            fontSizeMode: Text.Fit
        }

        TextField {
            id: pwdInput
            font.pointSize: 14
            Layout.preferredHeight: 40
            Layout.preferredWidth: 220
            placeholderText: qsTr("请输入密码")
            echoMode: "Password"
        }

        RowLayout {
            Layout.columnSpan: 2
            Layout.preferredHeight: 48
            Layout.preferredWidth: 359

            Button {
                id: regButton
                text: qsTr("注册")
                onClicked: {
                    showError("提示","本系统不允许个人注册账号，请联系管理员进行注册")
                }
            }

            Button {
                id: loginButton
                text: qsTr("登陆")

                onClicked: {
                    loginBLLIdthis.setSecurityDB(login.securityDB)
                    loginBLLIdthis.auth()
                }

            }

            Button {
                id: quitButton
                text: qsTr("退出")
                onClicked: {
                    close();
                }
            }
            Login {
                id:loginBLL
                usrname: usrnameInput.text
                password: pwdInput.text
                usrLogined: false
                adminLogined: false
                onUsrAuthSucc: {
                    loginPage.visible = false
                    main.usrLogined = true
                }
                onAdminAuthSucc:{
                    loginPage.visible = false
                    main.adminLogined = true
                }
                onAuthFail: {
                    loginPage.visible = false
                    main.adminLogined = true
                    //showError("提示","用户名或密码错误")
                }
            }
        }
    }
}

