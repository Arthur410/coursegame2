//
// Created by arthu on 14.10.2022.
//

#ifndef COURSEGAME_CELLCHANGETOEXIT_H
#define COURSEGAME_CELLCHANGETOEXIT_H
#include "../CellEvent.h"
class CellEvent;

class CellChangeToExit: public CellEvent {
public:
    Cell *cell;
    explicit CellChangeToExit(Cell *instance);
    void interact() override;
    int getEventId() override;
};


#endif //COURSEGAME_CELLCHANGETOEXIT_H
