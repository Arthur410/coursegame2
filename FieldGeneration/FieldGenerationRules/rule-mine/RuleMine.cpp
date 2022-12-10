//
// Created by arthu on 10.12.2022.
//

#include "RuleMine.h"

void RuleMine::generate(Player *player, Cell **field_instance,  std::pair<int,int> playerPos) {
    field_instance[position.first][position.second].setNewEvent(new MineEvent(player, &field_instance[position.first][position.second]));
}