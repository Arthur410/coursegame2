//
// Created by arthu on 24.09.2022.
//

#ifndef COURSEGAME_IEVENT_H
#define COURSEGAME_IEVENT_H
#include "../Player/Player.h"

class IEvent {
public:
    virtual int getEventId() = 0;
    virtual ~IEvent() = default;
};


#endif //COURSEGAME_IEVENT_H
