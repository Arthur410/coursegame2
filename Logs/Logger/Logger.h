//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_LOGGER_H
#define COURSEGAME_LOGGER_H
#include <iostream>
using namespace std;

class Logger {
public:
    virtual void print(string output) = 0;
};

#endif //COURSEGAME_LOGGER_H
