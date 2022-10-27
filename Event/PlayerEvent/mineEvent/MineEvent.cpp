//
// Created by arthu on 09.10.2022.
//
#include "MineEvent.h"

void MineEvent::interact() {
    if (cell->isPlayerIn) {
        player->setHp(player->getHp() - 1);
    } else {
        cell->setCellContent(Cell::MINE);
    }
}

MineEvent::MineEvent(Player *playerInstance, Cell *cellInstance): player(playerInstance), cell(cellInstance) {};

