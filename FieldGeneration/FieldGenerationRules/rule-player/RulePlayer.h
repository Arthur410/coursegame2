//
// Created by arthu on 10.12.2022.
//

#ifndef COURSEGAME_RULEPLAYER_H
#define COURSEGAME_RULEPLAYER_H

#include "../GenerationRule.h"
class RulePlayer: public GenerationRule {
public:
    RulePlayer() {
        position.first = rand() % 5 + 5;
        position.second = rand() % 5 + 5;
    }
    void generate(Player *player, Cell **field_instance, std::pair<int,int> playerPos) override;
};


#endif //COURSEGAME_RULEPLAYER_H
