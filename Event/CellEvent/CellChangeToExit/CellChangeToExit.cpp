//
// Created by arthu on 14.10.2022.
//

#include "CellChangeToExit.h"

void CellChangeToExit::changeCellType(Cell *cell) {
    cell->setCellContent(Cell::EXIT);
}

int CellChangeToExit::getEventId() {
    return 4;
}
