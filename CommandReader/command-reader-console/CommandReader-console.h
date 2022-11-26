//
// Created by arthu on 24.09.2022.
//


#ifndef INC_2COURSEGAME_COMMANDREADER_H
#define INC_2COURSEGAME_COMMANDREADER_H
#include <iostream>
#include <conio.h>
#include "../../Player/Player.h"
#include "../../Field/Field.h"
#include "../CommandReader.h"
class CommandReaderConsole: public CommandReader {
public:
    std::pair<int, int> currentPosition;
    void commandReading(Field *field_instance, FieldView *field_view) override;

    void move(Field *field_instance, std::pair<int, int> curPos, Direction nextDir) override;
private:
    Direction lastDirection = DOWN;
};

#endif //INC_2COURSEGAME_COMMANDREADER_H
