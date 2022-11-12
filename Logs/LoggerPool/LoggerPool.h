//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_LOGGERPOOL_H
#define COURSEGAME_LOGGERPOOL_H
#include "../Logger/Logger.h"
#include "../Message/Message.h"
#include <iostream>
#include <vector>

class LoggerPool {
public:
    LoggerPool();
    explicit LoggerPool(std::vector<Logger *> ls, int counter);
    void notify(Message* printMessage, int exitFlag, int delayFlag);

    std::vector<Logger *> getLoggers();
    int getCounter() const;
private:
    int counter;
    std::vector<Logger *> loggers = {};
};


#endif //COURSEGAME_LOGGERPOOL_H
