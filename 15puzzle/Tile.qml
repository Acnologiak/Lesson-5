import QtQuick 2.0

Rectangle {
    id: root

    property string displayText

    color: "lightgreen"
    border.color: "black"
    border.width: 2

    Text {
        id: _text
        text: root.displayText
        anchors.centerIn: root
        font.bold: true
        font.pointSize: root.height < root.width ?
                                                 root.height * 0.2
                                                 : root.width * 0.2
    }
}
