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

std::string Cell::getCellSymbol() {
    return cellToSymbol[getCellType()];
}

void Cell::setNewEvent(IEvent *e) {
    event = e;
}

IEvent* Cell::getEvent() {
    return event;
}
