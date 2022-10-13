//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_FIELDEVENT_H
#define COURSEGAME_FIELDEVENT_H
#include "../IEvent.h"
#include "../../Cell/Cell.h"

class FieldEvent: public IEvent {
public:
    void execute() override = 0;
    Cell **field;
};


#endif //COURSEGAME_FIELDEVENT_H
