//
// Created by arthu on 09.12.2022.
//
#ifndef COURSEGAME_GENERATIONRULE_H
#define COURSEGAME_GENERATIONRULE_H
#include "../../Cell/Cell.h"
#include "../../Player/Player.h"
#include <iostream>
#include <cstdlib>
class Field;

class GenerationRule {
public:
    bool firstSteps = true;
    bool flag = true;
    std::pair<int,int> position;
    int ticks = 0;
    virtual void generate(Player *player, Cell **field_instance, std::pair<int,int> playerPos) = 0;
};


#endif //COURSEGAME_GENERATIONRULE_H
