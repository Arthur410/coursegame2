//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_HPINCREASE_H
#define COURSEGAME_HPINCREASE_H
#include "../PlayerEvent.h"

class HpIncrease: public PlayerEvent {
    void execute(Player *curPlayer) override;
};


#endif //COURSEGAME_HPINCREASE_H
