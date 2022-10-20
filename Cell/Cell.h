//
// Created by arthu on 24.09.2022.
//

#ifndef INC_2COURSEGAME_CELL_H
#define INC_2COURSEGAME_CELL_H
#include "../Event/IEvent.h"

class Cell {
public:
    bool isPlayerIn = false;
    enum CellType {WALL, EMPTY, MEDICAL, MINE, EXIT};

    explicit Cell(CellType type);

    Cell();

    void setCellContent(CellType newType);

    CellType getCellType() const;

    void setNewEvent(IEvent *e);

    IEvent* getEvent();

private:
    IEvent *event;
    CellType type;
};


#endif //INC_2COURSEGAME_CELL_H
