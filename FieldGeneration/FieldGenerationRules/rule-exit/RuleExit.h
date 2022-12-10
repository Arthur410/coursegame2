//
// Created by arthu on 10.12.2022.
//

#ifndef COURSEGAME_RULEEXIT_H
#define COURSEGAME_RULEEXIT_H
#include "../GenerationRule.h"

class RuleExit: public GenerationRule {
public:
    RuleExit() {
        position.first = rand() % 4 + 10;
        position.second = rand() % 4 + 10;
    }
    void generate(Player *player, Cell **field_instance, std::pair<int,int> playerPos) override;
};


#endif //COURSEGAME_RULEEXIT_H
