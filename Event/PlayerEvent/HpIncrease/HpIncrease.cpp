//
// Created by arthu on 09.10.2022.
//

#include "HpIncrease.h"

void HpIncrease::execute(Player *curPlayer) {
    curPlayer->setHp(curPlayer->getHp() + 1);
}
