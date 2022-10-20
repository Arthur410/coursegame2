//
// Created by arthu on 12.10.2022.
//
#include "CellChangeToWall.h"

int CellChangeToWall::getEventId() {
    return 3;
}

void CellChangeToWall::interact() {
    cell->setCellContent(Cell::WALL);
}


CellChangeToWall::CellChangeToWall(Cell *instance):cell(instance) {};
