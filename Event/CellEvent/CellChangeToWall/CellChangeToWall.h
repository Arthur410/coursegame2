//
// Created by arthu on 12.10.2022.
//

#ifndef COURSEGAME_CELLCHANGETOWALL_H
#define COURSEGAME_CELLCHANGETOWALL_H
#include "../CellEvent.h"

class CellChangeToWall: public CellEvent {
public:
    Cell *cell;
    explicit CellChangeToWall(Cell *instance);
    void interact() override;
    int getEventId() override;
};


#endif //COURSEGAME_CELLCHANGETOWALL_H
