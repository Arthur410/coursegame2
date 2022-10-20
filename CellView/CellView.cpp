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
        } else if (currentEvent->getEventId() == 0) {
            std::cout << "+";
        } else if (currentEvent->getEventId() == 1) {
            std::cout << "x";
        } else if (currentEvent->getEventId() == 2) {
            std::cout << "H";
        } else if (currentEvent->getEventId() == 3) {
            std::cout << "#";
        }
    }
}