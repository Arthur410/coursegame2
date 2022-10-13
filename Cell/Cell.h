//
// Created by arthu on 24.09.2022.
//

#ifndef INC_2COURSEGAME_CELL_H
#define INC_2COURSEGAME_CELL_H
#include "../Event/IEvent.h"

class Cell {
public:
    enum CellType {WALL, EMPTY, PLAYER, ENEMY, POWER, MEDICAL, MINE};

    explicit Cell(CellType type);

    Cell();

    void setCellContent(CellType newType);

    CellType getCellType();

    void setNewEvent(IEvent *e) {
        event = e;
    }

private:
    IEvent *event;
    CellType type;
};


#endif //INC_2COURSEGAME_CELL_H
