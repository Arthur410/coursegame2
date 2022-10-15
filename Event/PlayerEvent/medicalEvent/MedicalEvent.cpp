//
// Created by arthu on 09.10.2022.
//
#include "MedicalEvent.h"

void MedicalEvent::changePlayerStat(Player *player) {
    if (player->getHp() < 100) {
        player->setHp(player->getHp() + 1);
    }
}

int MedicalEvent::getEventId() {
    return eventId;
}
