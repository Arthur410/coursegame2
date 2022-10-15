//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_MEDICALEVENT_H
#define COURSEGAME_MEDICALEVENT_H
#include "../PlayerEvent.h"

class MedicalEvent: public PlayerEvent {
public:
    int eventId = 0;
    int getEventId() override;
    void changePlayerStat(Player *player) override;
};


#endif //COURSEGAME_MEDICALEVENT_H
