//
// Created by arthu on 26.11.2022.
//
#pragma once
#ifndef COURSEGAME_COMMANDREADER_H
#define COURSEGAME_COMMANDREADER_H
#include "../FieldView/FieldView.h"

#endif //COURSEGAME_COMMANDREADER_H
#include <iostream>

class CommandReader {
public:
    enum Action {UP, DOWN, RIGHT, LEFT, NONE};
    std::map<string, Action> control;
    virtual Action commandReading(Field *field_instance, FieldView *field_view) = 0;
};
