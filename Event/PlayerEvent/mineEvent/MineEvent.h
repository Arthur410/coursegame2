//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_MINEEVENT_H
#define COURSEGAME_MINEEVENT_H
#include "../PlayerEvent.h"

class MineEvent: public PlayerEvent {
public:
    int eventId = 1;
    int getEventId() override;
    void changePlayerStat(Player *player) override;
};


#endif //COURSEGAME_MINEEVENT_H
