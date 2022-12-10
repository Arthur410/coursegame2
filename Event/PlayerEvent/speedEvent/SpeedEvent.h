//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_SPEEDEVENT_H
#define COURSEGAME_SPEEDEVENT_H
#include "../PlayerEvent.h"


class SpeedEvent: public PlayerEvent {
public:
    Player *player;
    Cell *cell;
    explicit SpeedEvent(Player *playerInstance, Cell *cellInstance);
    void interact() override;
};


#endif //COURSEGAME_SPEEDEVENT_H
