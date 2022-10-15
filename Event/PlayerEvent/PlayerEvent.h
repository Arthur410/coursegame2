//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_PLAYEREVENT_H
#define COURSEGAME_PLAYEREVENT_H
#include "../../Player/Player.h"
#include "../IEvent.h"

class PlayerEvent: public IEvent {
public:
    int eventGroupId = 1;
    virtual void changePlayerStat(Player *player) = 0;
};


#endif //COURSEGAME_PLAYEREVENT_H
