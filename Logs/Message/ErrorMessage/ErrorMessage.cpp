//
// Created by arthu on 27.10.2022.
//

#include "ErrorMessage.h"

Message::LogTypes ErrorMessage::getLogType() {
    return Message::ERR;
}

string ErrorMessage::getLogMessage() {
    string text;
    if (currentType == messageTypes::FIELD_ERROR) {
        text = "YOU ENTERED SOMETHING WRONG IN THE FIELD WIDTH AND HEIGHT PARAMETERS :(";
    } else if (currentType == messageTypes::CANT_GO) {
        text = "SOMETHING BLOCKING ME!!!";
    } else if (currentType == messageTypes::UNKNOWN) {
        text = "Unknown error";
    }
    return text;
}

ErrorMessage::ErrorMessage(ErrorMessage::messageTypes type): currentType(type) {}
