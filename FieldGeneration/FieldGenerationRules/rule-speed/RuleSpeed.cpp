//
// Created by arthu on 10.12.2022.
//

#include "RuleSpeed.h"
void RuleSpeed::generate(Player *player, Cell **field_instance,  std::pair<int,int> playerPos) {
    field_instance[position.first][position.second].setNewEvent(new SpeedEvent(player, &field_instance[position.first][position.second]));
}