//
// Created by arthu on 09.12.2022.
//

#ifndef COURSEGAME_FIELDGENERATION_H
#define COURSEGAME_FIELDGENERATION_H
#include <iostream>
#include <utility>
#include "./FieldGenerationRules/GenerationRule.h"
#include "FieldGenerationRules/rule-heal/RuleHeal.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
class Field;

template <class... Rules>
class FieldGeneration {
public:
    static const int size = sizeof...(Rules);

    Cell **field_instance;
    Player *player;
    std::pair<int,int> playerPosition;
    FieldGeneration(Player *playerInstance, Cell **field_inst, std::pair<int,int> playerPos): player(playerInstance), field_instance(field_inst), playerPosition(std::move(playerPos)) {};

    void rulesGeneration(Rules... rules) {
        (gen(rules), ...);
    }

    void gen(GenerationRule *rule) {
        rule->generate(player, field_instance, playerPosition);
    }
};




#endif //COURSEGAME_FIELDGENERATION_H
