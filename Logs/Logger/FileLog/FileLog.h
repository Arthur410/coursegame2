//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_FILELOG_H
#define COURSEGAME_FILELOG_H
#include "../Logger.h"

class FileLog: public Logger {
public:
    void print(string output) override;
};


#endif //COURSEGAME_FILELOG_H
