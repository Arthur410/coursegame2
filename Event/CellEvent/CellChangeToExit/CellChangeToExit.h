//
// Created by arthu on 14.10.2022.
//

#ifndef COURSEGAME_CELLCHANGETOEXIT_H
#define COURSEGAME_CELLCHANGETOEXIT_H
#include "../CellEvent.h"
class CellEvent;

class CellChangeToExit: public CellEvent {
    int getEventId() override;
    void changeCellType(Cell *cell) override;
};


#endif //COURSEGAME_CELLCHANGETOEXIT_H
