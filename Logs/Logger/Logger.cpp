//
// Created by arthu on 12.11.2022.
//
#include <iostream>
#include "Logger.h"
std::ostream& operator<<(std::ostream& out, Message *message){
    std::string prefix;
    switch (message->getLogType()) {
        case Message::INFO:
            prefix = "[INFO]";
            break;
        case Message::GAME:
            prefix = "[GAME]";
            break;
        case Message::ERROR:
            prefix = "[ERROR]";
            break;
    }
    out << prefix << message->getLogMessage();
    return out;
}
