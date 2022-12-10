//
// Created by arthu on 10.12.2022.
//

#ifndef COURSEGAME_RULESPEED_H
#define COURSEGAME_RULESPEED_H
#include "../GenerationRule.h"
#include "../../../Event/PlayerEvent/speedEvent/SpeedEvent.h"


class RuleSpeed: public GenerationRule{
public:
    RuleSpeed() {
        position.first = rand() % 5 + 6;
        position.second = rand() % 5 + 6;
    }
    void generate(Player *player, Cell **field_instance, std::pair<int,int> playerPos) override;
};


#endif //COURSEGAME_RULESPEED_H
