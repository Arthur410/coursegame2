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
};

std::ostream& operator << (std::ostream out, Message *message);

#endif //COURSEGAME_LOGGER_H
