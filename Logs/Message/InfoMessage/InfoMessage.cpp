//
// Created by arthu on 27.10.2022.
//

#include "InfoMessage.h"

Message::LogTypes InfoMessage::getLogType() {
    return Message::INFO;
}

string InfoMessage::getLogMessage() {
    string text;
    if (currentType == messageTypes::START) {
        text =  "   ____    _    __  __ _____   ____ _____  _    ____ _____ _____ ____  \n"
               "  / ___|  / \\  |  \\/  | ____| / ___|_   _|/ \\  |  _ \\_   _| ____|  _ \\ \n"
               " | |  _  / _ \\ | |\\/| |  _|   \\___ \\ | | / _ \\ | |_) || | |  _| | | | |\n"
               " | |_| |/ ___ \\| |  | | |___   ___) || |/ ___ \\|  _ < | | | |___| |_| |\n"
               "  \\____/_/   \\_\\_|  |_|_____| |____/ |_/_/   \\_\\_| \\_\\|_| |_____|____/ \n"
               "                                                                       ";
    } else if (currentType == messageTypes::END) {
        text = "                                                             \n"
               ",--------.,--.  ,--.,------.    ,------.,--.  ,--.,------.   \n"
               "'--.  .--'|  '--'  ||  .---'    |  .---'|  ,'.|  ||  .-.  \\  \n"
               "   |  |   |  .--.  ||  `--,     |  `--, |  |' '  ||  |  \\  : \n"
               "   |  |   |  |  |  ||  `---.    |  `---.|  | `   ||  '--'  / \n"
               "   `--'   `--'  `--'`------'    `------'`--'  `--'`-------'  \n"
               "                                                             ";
    }
    return text;
}

InfoMessage::InfoMessage(InfoMessage::messageTypes type): currentType(type) {}