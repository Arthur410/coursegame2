//
// Created by arthu on 24.09.2022.
//
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Controller.h"
Controller::Controller(Player *playerInstance, Field *fieldInstance, FieldView gameFieldView, CommandReader* commandReader, bool inf): gameFieldView(gameFieldView) {
    currentPlayer = playerInstance;
    gameField = fieldInstance;
    reader = commandReader;
    infinity = inf;
}

void Controller::run() {
    if (infinity) {
        while (1) {
            reader->commandReading(gameField, &gameFieldView);
        }
    } else {
        reader->commandReading(gameField, &gameFieldView);
    }
}

