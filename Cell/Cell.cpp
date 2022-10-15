//
// Created by arthu on 24.09.2022.
//

#include "Cell.h"
Cell::Cell(Cell::CellType currentType) {
    type = currentType;
}
Cell::Cell() {
    type = WALL;
}

void Cell::setCellContent(CellType newType) {
    type = newType;
}

Cell::CellType Cell::getCellType() const {
    return type;
};

void Cell::setNewCellEvent(CellEvent *e) {
    cellEvent = e;
}

void Cell::setNewPlayerEvent(PlayerEvent *e) {
    playerEvent = e;
}

class PlayerEvent* Cell::getPlayerEvent() {
    return playerEvent;
}

class CellEvent *Cell::getCellEvent() {
    return cellEvent;
}
