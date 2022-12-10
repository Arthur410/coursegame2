//
// Created by arthu on 10.12.2022.
//

#ifndef COURSEGAME_RULESTRENGTH_H
#define COURSEGAME_RULESTRENGTH_H
#include "../GenerationRule.h"
#include "../../../Event/PlayerEvent/strengthEvent/StrengthEvent.h"


class RuleStrength: public GenerationRule {
public:
    RuleStrength() {
        position.first = rand() % 5 + 7;
        position.second = rand() % 5 + 7;
    }
    void generate(Player *player, Cell **field_instance, std::pair<int,int> playerPos) override;
};


#endif //COURSEGAME_RULESTRENGTH_H
