//
// Created by arthu on 10.12.2022.
//

#ifndef COURSEGAME_RULEHEAL_H
#define COURSEGAME_RULEHEAL_H
#include "../GenerationRule.h"
#include "../../../Event/PlayerEvent/medicalEvent/MedicalEvent.h"

class RuleHeal: public GenerationRule {
public:
    RuleHeal() {
        position.first = rand() % 5 + 2;
        position.second = rand() % 5 + 2;
    }
    void generate(Player *player, Cell **field_instance, std::pair<int,int> playerPos) override;
};


#endif //COURSEGAME_RULEHEAL_H
