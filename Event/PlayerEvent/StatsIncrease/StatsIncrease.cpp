//
// Created by arthu on 13.10.2022.
//

#include "StatsIncrease.h"
void StatsIncrease::execute() {
    curPlayer->setSpeed(curPlayer->getSpeed() + 1);
    curPlayer->setStrength(curPlayer->getStrength() + 1);
}