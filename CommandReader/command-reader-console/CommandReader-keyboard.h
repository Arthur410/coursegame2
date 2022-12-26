//
// Created by arthu on 24.09.2022.
//
#pragma once
#include <iostream>
#include <conio.h>
#include "../../Player/Player.h"
#include "../../Field/Field.h"
#include "../CommandReader.h"
class CommandReaderConsole: public CommandReader {
public:
    boolean first = true;
    explicit CommandReaderConsole(int flag);
    CommandReader::Action lastAction = Action::DOWN;
    std::pair<int, int> currentPosition;
    Action commandReading(Field *field_instance, FieldView *field_view) override;
};

