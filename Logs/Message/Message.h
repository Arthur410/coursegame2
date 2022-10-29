//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_MESSAGE_H
#define COURSEGAME_MESSAGE_H
#include <iostream>
using namespace std;

class Message {
public:
    enum LogTypes {GAME, INFO, ERROR};
    virtual string getLogMessage() = 0;
    virtual LogTypes getLogType() = 0;
};


#endif //COURSEGAME_MESSAGE_H
