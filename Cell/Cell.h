//
// Created by arthu on 24.09.2022.
//

#ifndef INC_2COURSEGAME_CELL_H
#define INC_2COURSEGAME_CELL_H
#include "../Event/Event.h"

class Cell {
public:
    enum CellType {WALL, EMPTY, PLAYER, ENEMY, POWER, MEDICAL};

    explicit Cell(CellType type);

    Cell();

    void setCellContent(CellType newType);

    CellType getCellType();

    // метод из пустого абстр. класса
    void setNewEvent(Event *e) {
        event = e;
    }

private:
    Event *event;
    CellType type;
};


#endif //INC_2COURSEGAME_CELL_H
