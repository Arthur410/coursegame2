//
// Created by arthu on 10.12.2022.
//

#include "RuleHeal.h"
#include <iostream>

void RuleHeal::generate(Player *player, Cell **field_instance,  std::pair<int,int> playerPos) {
    field_instance[position.first][position.second].setNewEvent(new MedicalEvent(player, &field_instance[position.first][position.second]));
}

