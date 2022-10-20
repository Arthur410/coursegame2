//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_MINEEVENT_H
#define COURSEGAME_MINEEVENT_H
#include "../PlayerEvent.h"


class MineEvent: public PlayerEvent {
public:
    Player *player;
    Cell *cell;
    explicit MineEvent(Player *playerInstance, Cell *cellInstance);
    void interact() override;
    int getEventId() override;
};


#endif //COURSEGAME_MINEEVENT_H
