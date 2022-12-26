//
// Created by arthu on 24.12.2022.
//

#include "StateMessage.h"

Message::LogTypes StateMessage::getLogType() {
    return Message::STATE;
}

string StateMessage::getLogMessage() {
    string text;
    if (currentType == messageTypes::SAVED) {
        text = "Game was saved";
    } else if (currentType == messageTypes::RESTORED) {
        text = "Previous game was restored";
    }
    return text;
}

StateMessage::StateMessage(StateMessage::messageTypes type): currentType(type) {}