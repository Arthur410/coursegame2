//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_CONSOLELOG_H
#define COURSEGAME_CONSOLELOG_H
#include "../Logger.h"

class ConsoleLog: public Logger {
public:
    void print(string output) override;
};


#endif //COURSEGAME_CONSOLELOG_H
