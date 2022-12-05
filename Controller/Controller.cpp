//
// Created by arthu on 24.09.2022.
//
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Controller.h"
Controller::Controller(Player *playerInstance, Field *fieldInstance, FieldView *gameFieldView, CommandReader* commandReader): gameFieldView(gameFieldView) {
    currentPlayer = playerInstance;
    gameField = fieldInstance;
    reader = commandReader;
}

void Controller::run() {
    while (1) {
        CommandReader::Action currentKey = reader->commandReading(gameField, gameFieldView);
        if (gameField->player->isRage) {
            int rageSteps = 0;
            while (rageSteps < 5) {
                doAction(gameField, gameField->getPlayerPosition(), currentKey);
                rageSteps++;
            }
            gameField->player->rage();
        } else {
            doAction(gameField, gameField->getPlayerPosition(), currentKey);
        }
    }
}

void Controller::doAction(Field *field_instance, std::pair<int, int> curPos, CommandReader::Action nextAction) {
    lastAction = nextAction;
    std::pair<int, int> newPos;
    newPos = curPos;
    if (nextAction == CommandReader::Action::UP) {
        if (curPos.first - 1 == 0) {
            newPos.first = field_instance->getHeight() - 2;
        } else {
            newPos.first = curPos.first - 1;
        }
    } else if (nextAction == CommandReader::Action::DOWN) {
        if (curPos.first + 1 == field_instance->getHeight() - 1) {
            newPos.first = 1;
        } else {
            newPos.first = curPos.first + 1;
        }
    } else if (nextAction == CommandReader::Action::RIGHT) {
        if (curPos.second + 1 == field_instance->getWidth() - 1) {
            newPos.second = 1;
        } else {
            newPos.second = curPos.second + 1;
        }
    } else if (nextAction == CommandReader::Action::LEFT) {
        if (curPos.second - 1 == 0) {
            newPos.second = field_instance->getWidth() - 2;
        } else {
            newPos.second = curPos.second - 1;
        }
    }
    if (field_instance->getCell(newPos.first, newPos.second).getEvent()) {
        if (field_instance->getCell(newPos.first, newPos.second).getCellType() != Cell::WALL) {
            field_instance->setPlayerPosition(newPos);
        } else {
            field_instance->setNewMessage(new ErrorMessage(ErrorMessage::CANT_GO));
            for (int i = 0; i < field_instance->getLoggerPoolCount(); i++) {
                field_instance->getLoggerPool().getLoggers()[i]->print(field_instance->getCurrentMessage());
            }
        }
    } else {
        field_instance->setPlayerPosition(newPos);
    }
    gameFieldView->fieldView();
}
