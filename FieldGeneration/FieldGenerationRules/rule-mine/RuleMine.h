//
// Created by arthu on 10.12.2022.
//

#ifndef COURSEGAME_RULEMINE_H
#define COURSEGAME_RULEMINE_H
#include "../GenerationRule.h"
#include "../../../Event/PlayerEvent/mineEvent/MineEvent.h"

class RuleMine: public GenerationRule {
public:
    RuleMine() {
        position.first = rand() % 5 + 5;
        position.second = rand() % 5 + 5;
    }
    void generate(Player *player, Cell **field_instance, std::pair<int,int> playerPos) override;
};


#endif //COURSEGAME_RULEMINE_H
