//
// Created by arthu on 24.09.2022.
//


#ifndef INC_2COURSEGAME_COMMANDREADER_H
#define INC_2COURSEGAME_COMMANDREADER_H
#include <iostream>
#include <conio.h>
#include "../Player/Player.h"
#include "../Field/Field.h"

class CommandReader {
public:
    std::pair<int, int> currentPosition;
    enum Direction {UP, DOWN, RIGHT, LEFT};
    void commandReading(Field *field_instance);

    void move(Field *field_instance, std::pair<int, int> curPos, Direction nextDir);
private:
    Direction lastDirection = DOWN;
};

#endif //INC_2COURSEGAME_COMMANDREADER_H
