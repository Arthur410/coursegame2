//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_PLAYEREVENT_H
#define COURSEGAME_PLAYEREVENT_H
#include "../../Player/Player.h"
#include "../IEvent.h"

class PlayerEvent: public IEvent {
public:
    void execute() override = 0;
    Player *player;
};


#endif //COURSEGAME_PLAYEREVENT_H
