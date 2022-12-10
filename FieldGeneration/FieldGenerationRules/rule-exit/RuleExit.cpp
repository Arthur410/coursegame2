//
// Created by arthu on 10.12.2022.
//
#include "../../../Event/CellEvent/CellChangeToExit/CellChangeToExit.h"

#include "RuleExit.h"
void RuleExit::generate(Player *player, Cell **field_instance,  std::pair<int,int> playerPos) {
    field_instance[position.first][position.second].setNewEvent(new CellChangeToExit(&field_instance[position.first][position.second]));
}
