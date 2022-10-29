//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_LOGGERPOOL_H
#define COURSEGAME_LOGGERPOOL_H
#include "../Logger/Logger.h"
#include <iostream>
#include <vector>

class LoggerPool {
public:
    LoggerPool();
    explicit LoggerPool(std::vector<Logger *> ls);
    std::vector<Logger *> getLoggers();
    void changeLogger(std::vector<Logger *> anotherLogger);
private:
    std::vector<Logger *> loggers = {};
};


#endif //COURSEGAME_LOGGERPOOL_H
