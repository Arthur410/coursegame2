//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_MEDICALEVENT_H
#define COURSEGAME_MEDICALEVENT_H
#include "../PlayerEvent.h"

class MedicalEvent: public PlayerEvent {
public:
    Player *player;
    Cell *cell;
    explicit MedicalEvent(Player *player, Cell *cell);
    void interact() override;
    int getEventId() override;
};


#endif //COURSEGAME_MEDICALEVENT_H
