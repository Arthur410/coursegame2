//
// Created by arthu on 09.10.2022.
//
#include "MedicalEvent.h"

int MedicalEvent::getEventId() {
    return 0;
}

void MedicalEvent::interact() {
    if (player->getHp() < 100) {
        cell->setCellContent(Cell::MEDICAL);
        player->setHp(player->getHp() + 1);
    }
}

MedicalEvent::MedicalEvent(Player *playerInstance, Cell *cellInstance): player(playerInstance), cell(cellInstance) {};


