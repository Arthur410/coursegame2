//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_LOGGER_H
#define COURSEGAME_LOGGER_H
#include <iostream>
#include <utility>
#include "../Message/Message.h"
using namespace std;

class Logger {
public:
    virtual void print(Message *message) = 0;
    friend std::ostream& operator<<(std::ostream& out, Message *message){
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
        out << prefix << message->getLogMessage() << endl;
        return out;
    }
};

std::ostream& operator << (std::ostream out, Message *message);

#endif //COURSEGAME_LOGGER_H
