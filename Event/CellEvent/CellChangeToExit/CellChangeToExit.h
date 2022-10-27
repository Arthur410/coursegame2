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
    explicit CellChangeToExit(Cell *cellInstance);
    void interact() override;
};


#endif //COURSEGAME_CELLCHANGETOEXIT_H
