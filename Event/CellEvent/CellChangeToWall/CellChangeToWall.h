//
// Created by arthu on 12.10.2022.
//

#ifndef COURSEGAME_CELLCHANGETOWALL_H
#define COURSEGAME_CELLCHANGETOWALL_H
#include "../CellEvent.h"

class CellChangeToWall: public CellEvent {
    int getEventId() override;
    void changeCellType(Cell *cell) override;
};


#endif //COURSEGAME_CELLCHANGETOWALL_H
