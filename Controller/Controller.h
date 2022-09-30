//
// Created by arthu on 24.09.2022.
//


#ifndef COURSEGAME_CONTROLLER_H
#define COURSEGAME_CONTROLLER_H

#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../FieldView/FieldView.h"
#include "../CommandReader/CommandReader.h"

class Controller {
public:
    Controller(Player *playerInstance, Field *fieldInstance, FieldView gameFieldView, CommandReader commandReader);

    void run();
private:
    Player *currentPlayer;
    Field *gameField;
    FieldView gameFieldView;
    CommandReader reader;
};


#endif //COURSEGAME_CONTROLLER_H
