//
// Created by arthu on 09.10.2022.
//
#include "StrengthEvent.h"

void StrengthEvent::interact() {
    if (cell->isPlayerIn) {
        player->setStrength(player->getStrength() + 1);
    } else {
        cell->setCellContent(Cell::STRENGTH);
    }
}

StrengthEvent::StrengthEvent(Player *playerInstance, Cell *cellInstance): player(playerInstance), cell(cellInstance) {};


