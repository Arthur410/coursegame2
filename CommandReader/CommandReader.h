//
// Created by arthu on 26.11.2022.
//
#pragma once
#ifndef COURSEGAME_COMMANDREADER_H
#define COURSEGAME_COMMANDREADER_H
#include "../FieldView/FieldView.h"

#endif //COURSEGAME_COMMANDREADER_H
class CommandReader {
public:
    enum Direction {UP, DOWN, RIGHT, LEFT};
    virtual void commandReading(Field *field_instance, FieldView *field_view) = 0;
    virtual void move(Field *field_instance, std::pair<int, int> curPos, Direction nextDir) = 0;
};