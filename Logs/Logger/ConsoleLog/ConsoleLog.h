//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_CONSOLELOG_H
#define COURSEGAME_CONSOLELOG_H
#include "../Logger.h"
#include "../../Message/Message.h"

class ConsoleLog: public Logger {
public:
    ~ConsoleLog();
    void print(Message *message) override;
};


#endif //COURSEGAME_CONSOLELOG_H
