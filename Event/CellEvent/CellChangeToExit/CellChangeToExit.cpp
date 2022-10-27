//
// Created by arthu on 14.10.2022.
//

#include "CellChangeToExit.h"

void CellChangeToExit::interact() {
    cell->setCellContent(Cell::EXIT);
}

CellChangeToExit::CellChangeToExit(Cell *cellInstance): cell(cellInstance) {};
