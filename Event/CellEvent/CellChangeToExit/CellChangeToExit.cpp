//
// Created by arthu on 14.10.2022.
//

#include "CellChangeToExit.h"

int CellChangeToExit::getEventId() {
    return 2;
}

void CellChangeToExit::interact() {
    cell->setCellContent(Cell::EXIT);
}

CellChangeToExit::CellChangeToExit(Cell *instance): cell(instance) {};
