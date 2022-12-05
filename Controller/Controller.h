//
// Created by arthu on 24.09.2022.
//


#ifndef COURSEGAME_CONTROLLER_H
#define COURSEGAME_CONTROLLER_H

#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../FieldView/FieldView.h"
#include "../CommandReader/command-reader-console/CommandReader-keyboard.h"

class Controller {
public:
    Controller(Player *playerInstance, Field *fieldInstance, FieldView *gameFieldView, CommandReader *commandReader);

    void doAction(Field *field_instance, std::pair<int, int> curPos, CommandReader::Action nextDir);
    void run();
private:
    Player *currentPlayer;
    CommandReader::Action lastAction = CommandReader::Action::DOWN;
    Field *gameField;
    FieldView *gameFieldView;
    CommandReader* reader;
};


#endif //COURSEGAME_CONTROLLER_H
