//
// Created by arthu on 12.10.2022.
//
#include <iostream>
using namespace std;
#include "CellChangeToWall.h"

void CellChangeToWall::changeCellType(Cell *cell) {
    cell->setCellContent(Cell::WALL);
}

int CellChangeToWall::getEventId() {
    return 3;
}
