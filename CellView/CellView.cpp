//
// Created by arthu on 24.09.2022.
//

#include "CellView.h"
#include "../Cell/Cell.h"
CellView::CellView(Cell instance) {
    cell_instance = instance;
}

void CellView::cellView() {
    Cell::CellType currentType = cell_instance.getCellType();
    if (currentType == Cell::WALL) {
        std::cout << "#";
    } else if (currentType == Cell::EMPTY) {
        std::cout << " ";
    } else if (currentType == Cell::PLAYER) {
        std::cout << "0";
    } else if (currentType == Cell::ENEMY) {
        std::cout << "E";
    } else if (currentType == Cell::POWER) {
        std::cout << "P";
    } else if (currentType == Cell::MEDICAL) {
        std::cout << "+";
    } else if (currentType == Cell::MINE) {
        std::cout << "x";
    }
}