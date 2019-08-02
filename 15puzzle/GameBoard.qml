import QtQuick 2.0
import Game 1.0

GridView {
    id: root

    cellHeight: height / model.dimension
    cellWidth: width / model.dimension

    model: GameBoardModel {

    }

    delegate: Item {
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight

        Tile {
            id: _internalTile
            visible: display != model.dimension * model.dimension
            displayText: display
            anchors.fill: _backgroundDelegate
            anchors.margins: 5
        }
        MouseArea {
            anchors.fill: _internalTile
            onClicked: {
                root.model.move(index);
            }
        }
    }

    GameBoardModel {
        id: _gameController
    }
}
