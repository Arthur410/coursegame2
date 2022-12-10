//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_STRENGTHEVENT_H
#define COURSEGAME_STRENGTHEVENT_H

#include "../PlayerEvent.h"

class StrengthEvent: public PlayerEvent {
public:
    Player *player;
    Cell *cell;
    explicit StrengthEvent(Player *playerInstance, Cell *cellInstance);
    void interact() override;
};


#endif //COURSEGAME_STRENGTHEVENT_H
