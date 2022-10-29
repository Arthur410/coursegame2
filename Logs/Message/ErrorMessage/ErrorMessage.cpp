//
// Created by arthu on 27.10.2022.
//

#include "ErrorMessage.h"

Message::LogTypes ErrorMessage::getLogType() {
    return Message::ERROR;
}

string ErrorMessage::getLogMessage() {
    string text;
    if (currentType == InfoMessageTypes::FIELD_ERROR) {
        text = "YOU ENTERED SOMETHING WRONG IN THE FIELD WIDTH AND HEIGHT PARAMETERS :(";
    } else if (currentType == InfoMessageTypes::CANT_GO) {
        text = "SOMETHING BLOCKING ME!!!";
    }
    return text;
}

ErrorMessage::ErrorMessage(ErrorMessage::InfoMessageTypes type): currentType(type) {}
