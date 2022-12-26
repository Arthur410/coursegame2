//
// Created by arthu on 27.10.2022.
//

#include "GameMessage.h"

Message::LogTypes GameMessage::getLogType() {
    return Message::GAME;
}

string GameMessage::getLogMessage() {
    string text;
    if (currentType == messageTypes::MINE_TAKEN) {
        text = "OUCH! I STEPPED ON THE MINE";
    } else if (currentType == messageTypes::HEAL_TAKEN) {
        text = "NICE! +1 HP ADDED";
    }  else if (currentType == messageTypes::EXIT_TAKEN) {
        text = "WOOHOOO! THE EXIT";
    } else if (currentType == messageTypes::PLAYER_DIED) {
        text =" __        ___    ____ _____ _____ ____  \n"
               " \\ \\      / / \\  / ___|_   _| ____|  _ \\ \n"
               "  \\ \\ /\\ / / _ \\ \\___ \\ | | |  _| | | | |\n"
               "   \\ V  V / ___ \\ ___) || | | |___| |_| |\n"
               "    \\_/\\_/_/   \\_\\____/ |_| |_____|____/ \n"
               "                                         ";
    } else if (currentType == messageTypes::RAGE) {
        text = "ARRAHGHGHRHHGH";
    } else if (currentType == messageTypes::STRENGTH_TAKEN) {
        text = "I BECAME STRONGER!";
    } else if (currentType == messageTypes::QUICKNESS_TAKEN) {
        text = "I BECAME FASTER";
    } else if (currentType == messageTypes::NOTHING) {
        text = "Nothing happens...";
    }
    return text;
}

GameMessage::GameMessage(GameMessage::messageTypes type): currentType(type) {}