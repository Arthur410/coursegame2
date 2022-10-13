//
// Created by arthu on 09.10.2022.
//

#ifndef COURSEGAME_HPDECREASE_H
#define COURSEGAME_HPDECREASE_H
#include "../PlayerEvent.h"

class HpDecrease: public PlayerEvent {
    void execute(Player *curPlayer) override;
};


#endif //COURSEGAME_HPDECREASE_H
