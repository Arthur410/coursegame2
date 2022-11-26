//
// Created by arthu on 26.11.2022.
//

#ifndef COURSEGAME_COMMANDREADER_FILE_H
#define COURSEGAME_COMMANDREADER_FILE_H
#include <iostream>
#include <conio.h>
#include "../../Player/Player.h"
#include "../../Field/Field.h"
#include "../CommandReader.h"
class CommandReaderFile: public CommandReader {
public:
    std::pair<int, int> currentPosition;
    void commandReading(Field *field_instance, FieldView *field_view) override;

    void move(Field *field_instance, std::pair<int, int> curPos, Direction nextDir) override;
private:
    Direction lastDirection = DOWN;
};


#endif //COURSEGAME_COMMANDREADER_FILE_H
