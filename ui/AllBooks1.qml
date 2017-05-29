import QtQuick 2.0
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1
import Backend 1.0
import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3 as QuickControls
import "../"

BookListBase{
    Component.onCompleted: userModel.setCurrentControlUser("virutalUser_AllBooks")
}


