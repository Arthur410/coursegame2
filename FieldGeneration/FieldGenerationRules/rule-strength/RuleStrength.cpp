//
// Created by arthu on 10.12.2022.
//

#include "RuleStrength.h"
void RuleStrength::generate(Player *player, Cell **field_instance,  std::pair<int,int> playerPos) {
    field_instance[position.first][position.second].setNewEvent(new StrengthEvent(player, &field_instance[position.first][position.second]));
}