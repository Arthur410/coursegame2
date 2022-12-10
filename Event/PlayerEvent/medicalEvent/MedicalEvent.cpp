//
// Created by arthu on 09.10.2022.
//
#include "MedicalEvent.h"
#include <iostream>
void MedicalEvent::interact() {
    if (cell->isPlayerIn && player->getHp() < 100) {
        player->setHp(player->getHp() + 1);
    } else {
        cell->setCellContent(Cell::MEDICAL);
    }
}


MedicalEvent::MedicalEvent(Player *playerInstance, Cell *cellInstance): player(playerInstance), cell(cellInstance) {};


