//
// Created by arthu on 09.10.2022.
//
#include "MineEvent.h"

int MineEvent::getEventId() {
    return 1;
}

void MineEvent::interact() {
    cell->setCellContent(Cell::MINE);
    player->setHp(player->getHp() - 1);
}

MineEvent::MineEvent(Player *playerInstance, Cell *cellInstance): player(playerInstance), cell(cellInstance) {};

