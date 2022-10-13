//
// Created by arthu on 09.10.2022.
//

#include "HpDecrease.h"

void HpDecrease::execute(Player *curPlayer) {
    curPlayer->setHp(curPlayer->getHp() - 1);
}
