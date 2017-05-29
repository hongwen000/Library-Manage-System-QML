import QtQuick 2.4
import QtQuick.Controls 1.3 as QuickControls
import Material 0.2
import Material.Extras 0.1
 Dialog {
    Component.onCompleted: show()
    height: Units.dp(200)
    width: Units.dp(320)
     id: textFieldDialog
     title: "请输入关键字"
     hasActions: true
     visible: true
     TextField {
         id: optionText
         width: parent.width
         placeholderText: ""
     }
     property Item object : optionText
     function getObj() { return optionText.text }

    signal clicked(var keyword)
     onAccepted: {
         clicked(optionText.text)
      }
 }

