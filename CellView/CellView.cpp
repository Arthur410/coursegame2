//
// Created by arthu on 24.09.2022.
//

#include "CellView.h"
#include "../Cell/Cell.h"
CellView::CellView(Cell instance) {
    cell_instance = instance;
}

void CellView::cellView() {
    IEvent* currentEvent = cell_instance.getEvent();
    if (cell_instance.isPlayerIn) {
        std::cout << "0";
    } else {
        if (!currentEvent) {
            std::cout << " ";
        } else if (cell_instance.getCellType() == Cell::MEDICAL) {
            std::cout << "+";
        } else if (cell_instance.getCellType() == Cell::MINE) {
            std::cout << "x";
        } else if (cell_instance.getCellType() == Cell::EXIT) {
            std::cout << "H";
        } else if (cell_instance.getCellType() == Cell::WALL) {
            std::cout << "#";
        } else if (cell_instance.getCellType() == Cell::STRENGTH) {
            std::cout << "S";
        } else if (cell_instance.getCellType() == Cell::QUICKNESS) {
            std::cout << "Q";
        }
    }
}