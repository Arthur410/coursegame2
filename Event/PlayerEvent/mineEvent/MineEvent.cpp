//
// Created by arthu on 09.10.2022.
//
#include "MineEvent.h"

void MineEvent::changePlayerStat(Player *player) {
    player->setHp(player->getHp() - 1);
}

int MineEvent::getEventId() {
    return eventId;
}
