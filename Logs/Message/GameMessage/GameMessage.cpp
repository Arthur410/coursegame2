//
// Created by arthu on 27.10.2022.
//

#include "GameMessage.h"

Message::LogTypes GameMessage::getLogType() {
    return Message::GAME;
}

string GameMessage::getLogMessage() {
    string text;
    if (currentType == InfoMessageTypes::MINE_TAKEN) {
        text = "OUCH! I STEPPED ON THE MINE";
    } else if (currentType == InfoMessageTypes::HEAL_TAKEN) {
        text = "NICE! +1 HP ADDED";
    }  else if (currentType == InfoMessageTypes::EXIT_TAKEN) {
        text = "WOOHOOO! THE EXIT";
    }
    return text;
}

GameMessage::GameMessage(GameMessage::InfoMessageTypes type): currentType(type) {}