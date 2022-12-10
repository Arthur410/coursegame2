//
// Created by arthu on 09.10.2022.
//
#include "SpeedEvent.h"

void SpeedEvent::interact() {
    if (cell->isPlayerIn) {
        player->setSpeed(player->getSpeed() + 1);
    } else {
        cell->setCellContent(Cell::QUICKNESS);
    }
}

SpeedEvent::SpeedEvent(Player *playerInstance, Cell *cellInstance): player(playerInstance), cell(cellInstance) {};


