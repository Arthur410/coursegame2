//
// Created by arthu on 12.10.2022.
//
#include "CellChangeToWall.h"
#include "../../../Field/Field.h"
void CellChangeToWall::interact() {
    cell->setCellContent(Cell::WALL);
}

CellChangeToWall::CellChangeToWall(Cell *cellInstance):cell(cellInstance) {};
