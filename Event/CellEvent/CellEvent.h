//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_CELLEVENT_H
#define COURSEGAME_CELLEVENT_H
#include "../IEvent.h"
#include "../../Cell/Cell.h"

class CellEvent: public IEvent {
public:
    int eventGroupId = 0;
    virtual void changeCellType(class Cell *cell) = 0;
};


#endif //COURSEGAME_CELLEVENT_H
