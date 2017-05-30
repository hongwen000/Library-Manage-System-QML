import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Login 1.0
import Backend 1.0
ApplicationWindow {
    id: main
    visible: true
    width: 640
    height: 480
    title: qsTr("图书管理系统")
    property alias loginBLLIdthis: loginPage.loginBLL

    theme {
        primaryColor: "blue"
        accentColor: "red"
        tabHighlightColor: "white"
    }
    property var currentBorrow: [
        qsTr("CurrentBorrow")/*, qsTr("HistoryBorrow"), qsTr("Appointment"), qsTr("Overdue")*/
    ]

    property var newBorrow: [
        qsTr("AllBooks")/*, qsTr("ChineseBooks"), qsTr("ForeignBooks"), qsTr("Subscriptions")*/
    ]

    property var personalInfo: [
        qsTr("BasicInfo")/*, qsTr("ContactInfo"), qsTr("ManageMentInfo")*/
    ]

    property var bookManage: [
        qsTr("NewBook"), qsTr("ManageAll")/*, qsTr("ManageChs"), qsTr("ManageFori"), qsTr("ManageSub")*/
    ]

    property var userManage: [
        qsTr("NewUser"),qsTr("ManageUser"), qsTr("HelpReturn")
    ]

    property var usrSections: [ newBorrow, currentBorrow, personalInfo ]

    property var adminSections: [newBorrow, currentBorrow, personalInfo,bookManage,userManage]

    property bool usrLogined: loginBLLIdthis.usrLogined

    property bool adminLogined: loginBLLIdthis.adminLogined


    function getRealsections() {

        if(usrLogined) {

            return usrSections;
        }
        else if(adminLogined) {


            return adminSections;
        }
        else {


            return []
        }
    }

    property var realsections: getRealsections()

    property var usrSectionTitles: [qsTr("图书借阅"), qsTr("借阅管理"), qsTr("个人信息")]

    property var adminSectionTitles: [qsTr("图书借阅"), qsTr("借阅管理"), qsTr("个人信息"), qsTr("馆藏管理"), qsTr("用户管理")]

    property var realSectionTitles: usrLogined ? usrSectionTitles : (adminLogined ? adminSectionTitles : [])


    function safeGetComp() {
        console.log(realsections[0][0])
        return realsections[0][0]
    }

    property var selectedComponent: (usrLogined || adminLogined) ? realsections[0][0] :""


    initialPage:TabbedPage {
        id: page
        title: getTrans(selectedComponent)
        property alias pagethis: page
        actionBar.maxActionCount: navDrawer.enabled ? 3 : 4
        actions: [
            Action {
                iconName: "alert/warning"
                name: "Dummy error"
                onTriggered: main.showError("遇到问题？", "请联系hongwen000@outlook.com", "关闭")
            },

            Action {
                iconName: "image/color_lens"
                name: "Colors"
                onTriggered: colorPicker.show()
            },

            Action {
                iconName: "action/settings"
                name: "Settings"
                hoverAnimation: true
                onTriggered: showError("提示","本程序完整功能仍在建设中")
            },

            Action {
                iconName: "alert/warning"
                name: "THIS SHOULD BE HIDDEN!"
                visible: false
            },

            Action {
                iconName: "action/exit_to_app"
                name: "退出"
                enabled: true
                onTriggered: Qt.quit()
            }

/*            Action {
                iconName: "action/account_circle"
                name: "注销"
                onTriggered: {
                main.usrLogined = false
                main.adminLogined = false
                smallLoader.active = false
                loginPage.visible = true
                //iLoginPage.logout()
                }

            }
            */
        ]

        backAction: navDrawer.action

        LoginPage  {
            id:loginPage
        }
//        Loader {
//            id: example
//            anchors.fill: parent
//            asynchronous: true
//            visible: status == Loader.Ready
//            // selectedComponent will always be valid, as it defaults to the first component
//            source: {
//                if (navDrawer.enabled) {
//                    return Qt.resolvedUrl("qrc:/ui/%1.qml").arg(main.selectedComponent.replace(" ", ""))
//                } else {
//                    return Qt.resolvedUrl("qrc:/ui/%1.qml").arg(selectedComponent.replace(" ", ""))
//                }
//            }
//        }

//        ProgressCircle {
//            anchors.centerIn: parent
//            visible: example.status == Loader.Loading
//        }

//        NavigationDrmawer {
//            id: navDrawer
//            enabled: true//page.width < Units.dp(500)




//            onEnabledChanged: smallLoader.active = enabled

//            Flickable {
//                anchors.fill: parent
//                id : iamgood


//                contentHeight: Math.max(content.implicitHeight, height)

//                Column {
//                    id: content
//                    anchors.fill: parent

//                    Repeater {
//                        //model: sections
//                        model: realsections
//                        delegate: Column {
//                            width: parent.width

//                            ListItem.Subheader {
//                                text: (usrLogined || adminLogined) ? realSectionTitles[index] : ""
//                            }

//                            Repeater {

//                                model: modelData
//                                delegate: ListItem.Standard {
//                                    function getRightSource() {
//                                        if (navDrawer.enabled) {
//                                            return Qt.resolvedUrl("qrc:/ui/%1.qml").arg(main.selectedComponent.replace(" ", ""))
//                                        } else {
//                                            return Qt.resolvedUrl("qrc:/ui/%1.qml").arg(selectedComponent.replace(" ", ""))
//                                        }
//                                    }
//                                    text: getTrans(modelData)
//                                    selected: modelData == main.selectedComponent
//                                    onClicked: {
//                                        console.log("at line 207, changing source to " + getRightSource())
//                                        main.selectedComponent = modelData
//                                        example.source = ""
//                                        example.source = getRightSource()
//                                        navDrawer.close()
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//            Flickable {

//                id: flickable
//                anchors {
//                    left: sidebar.right
//                    right: parent.right
//                    top: parent.top

//                    bottom: parent.bottom
//                    //fill: parent
//                }
//                clip: true
//                contentHeight: Math.max(example.implicitHeight + 40, height)
//            }
//            Scrollbar {
//                flickableItem: flickable
//            }

//        }
        NavigationDrawer {
            id: navDrawer
            enabled: page.width < Units.dp(500)

            onEnabledChanged: smallLoader.active = enabled

            Flickable {
                anchors.fill: parent

                contentHeight: Math.max(content.implicitHeight, height)

                Column {
                    id: content
                    anchors.fill: parent

                    Repeater {
                        //model: sections
                        model: realsections
                        delegate: Column {
                            width: parent.width

                            ListItem.Subheader {
                                text: realSectionTitles[index]
                            }

                            Repeater {
                                model: modelData
                                delegate: ListItem.Standard {
                                    text: modelData
                                    selected: modelData == demo.selectedComponent
                                    onClicked: {
                                        demo.selectedComponent = modelData
                                        navDrawer.close()
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        Repeater {
            //model: !navDrawer.enabled ? sections : 0
            model:  !navDrawer.enabled ? realsections : 0
            delegate: Tab {
                title: (usrLogined || adminLogined) ? realSectionTitles[index] :""

                property string selectedComponent: modelData[0]
                property var section: modelData

                sourceComponent: tabDelegate
            }
        }

        Loader {
            id: smallLoader
            anchors.fill: parent
            sourceComponent: tabDelegate

            property var section: []
            visible: active
            active: false


        }


    }

    Dialog {

        id: colorPicker
        title: "切换主题颜色"

        positiveButtonText: "Done"

        MenuField {
            id: selection
            model: ["主颜色", "按钮字体颜色", "背景颜色"]
            width: Units.dp(160)
        }

        Grid {
            columns: 7
            spacing: Units.dp(8)

            Repeater {
                model: [
                    "red", "pink", "purple", "deepPurple", "indigo",
                    "blue", "lightBlue", "cyan", "teal", "green",
                    "lightGreen", "lime", "yellow", "amber", "orange",
                    "deepOrange", "grey", "blueGrey", "brown", "black",
                    "white"
                ]

                Rectangle {
                    width: Units.dp(30)
                    height: Units.dp(30)
                    radius: Units.dp(2)
                    color: Palette.colors[modelData]["500"]
                    border.width: modelData === "white" ? Units.dp(2) : 0
                    border.color: Theme.alpha("#000", 0.26)

                    Ink {
                        anchors.fill: parent

                        onPressed: {
                            switch(selection.selectedIndex) {
                            case 0:
                                theme.primaryColor = parent.color
                                break;
                            case 1:
                                theme.accentColor = parent.color
                                break;
                            case 2:
                                theme.backgroundColor = parent.color
                                break;
                            }
                        }
                    }
                }
            }
        }

        onRejected: {
            // TODO set default colors again but we currently don't know what that is
        }
    }

    function getTrans(name) {

        if(name == 'CurrentBorrow')
            return '目前借阅'
        else if(name == 'HistoryBorrow')
            return '借阅历史 '
        else if(name == 'Appointment')
            return '预约请求 '
        else if(name == 'Overdue')
            return '当前过期外借欠款'
        else if(name == 'AllBooks')
            return '全部文献 '
        else if(name == 'ChineseBooks')
            return '中文目录 '
        else if(name == 'ForeignBooks')
            return '西文目录 '
        else if(name == 'Subscriptions')
            return '征订目录'
        else if(name == 'BasicInfo')
            return '基本信息 '
        else if(name == 'ContactInfo')
            return '联系方式 '
        else if(name == 'ManageMentInfo')
            return '管理信息'
        else if(name == 'NewBook')
            return '上架新书 '
        else if(name == 'ManageAll')
            return '全部文献管理 '
        else if(name == 'ManageChs')
            return '中文目录管理 '
        else if(name == 'ManageFori')
            return '西文目录管理 '
        else if(name == 'ManageSub')
            return '征订目录管理'
        else if(name == 'NewUser')
            return '新增用户'
        else if(name == 'ManageUser')
            return '管理用户 '
        else if(name == 'HelpReturn')
            return '帮助还书'
        else return ''
    }
    Component {
        id: tabDelegate
        Item {
            function getRightSource() {
                if (navDrawer.enabled) {
                    return Qt.resolvedUrl("qrc:/ui/%1.qml").arg(main.selectedComponent.replace(" ", ""))
                } else {
                    return Qt.resolvedUrl("qrc:/ui/%1.qml").arg(selectedComponent.replace(" ", ""))
                }
            }
            Sidebar {
                id: sidebar

                expanded: true

                Column {
                    width: parent.width

                    Repeater {
                        model: section
                        delegate: ListItem.Standard {
                            text: getTrans(modelData)
                            selected: modelData == selectedComponent
                            id: magicOperate
                            onClicked: {
                                console.log("at line 345")
                                selectedComponent = modelData
                                example.source = ""
                                example.source = getRightSource()
                                console.log(getTrans(modelData))
                            }
                        }
                    }
                }
            }
            property alias example: example
            Flickable {

                id: flickable
                anchors {
                    left: sidebar.right
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                }
                clip: true
                contentHeight: Math.max(example.implicitHeight + 40, height)
                Loader {
                    id: example
                    anchors.fill: parent
                    asynchronous: true
                    visible: status == Loader.Ready
                    // selectedComponent will always be valid, as it defaults to the first component
                    source: {
                        if (navDrawer.enabled) {
                            return Qt.resolvedUrl("qrc:/ui/%1.qml").arg(main.selectedComponent.replace(" ", ""))
                        } else {
                            return Qt.resolvedUrl("qrc:/ui/%1.qml").arg(selectedComponent.replace(" ", ""))
                        }
                    }
                }

                ProgressCircle {
                    anchors.centerIn: parent
                    visible: example.status == Loader.Loading
                }
            }
            Scrollbar {
                flickableItem: flickable
            }
        }
    }
}
