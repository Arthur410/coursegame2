//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_FILELOG_H
#define COURSEGAME_FILELOG_H
#include "../Logger.h"
#include <fstream>
#include <iostream>


class FileLog: public Logger {
    std::ofstream fl;
public:
    FileLog();
    ~FileLog();
    void print(Message *message) override;
};


#endif //COURSEGAME_FILELOG_H
