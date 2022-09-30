//
// Created by arthu on 24.09.2022.
//

#include "Controller.h"
Controller::Controller(Player *playerInstance, Field *fieldInstance, FieldView gameFieldView, CommandReader commandReader): gameFieldView(gameFieldView) {
    currentPlayer = playerInstance;
    gameField = fieldInstance;
    reader = commandReader;
}

void Controller::run() {
    while (1) {
        reader.commandReading(gameField);
        gameFieldView.fieldView();
    }
}

