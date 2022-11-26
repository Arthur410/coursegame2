//
// Created by arthu on 24.09.2022.
//

#include "CommandReader-console.h"

void CommandReaderConsole::commandReading(Field *field_instance, FieldView *field_view) {
    // Переменная для rage
    char lastCommand;
    currentPosition = field_instance->getPlayerPosition();
    int rageSteps = 0;
    if (_kbhit()) {
        field_view->fieldView();
        switch(_getch()) {
            case 'r':
                field_instance->player->rage();
                while (rageSteps != 5) {
                    move(field_instance, currentPosition, lastDirection);
                    rageSteps += 1;
                }
                field_instance->player->rage();
                field_instance->setNewMessage(new GameMessage(GameMessage::RAGE));
                std::cout << field_instance->player->isRage;
                field_view->fieldView();
                break;
            case 'w':
                move(field_instance, currentPosition, UP);
                field_view->fieldView();
                break;
            case 'a':
                move(field_instance, currentPosition, LEFT);
                field_view->fieldView();
                break;
            case 's':
                move(field_instance, currentPosition, DOWN);
                field_view->fieldView();
                break;
            case 'd':
                move(field_instance, currentPosition, RIGHT);
                field_view->fieldView();
                break;
            case 'x':
                exit(0);
        }
        field_view->fieldView();
    }
}

void CommandReaderConsole::move(Field *field_instance, std::pair<int, int> curPos, Direction nextDir) {
    lastDirection = nextDir;
    std::pair<int, int> newPos;
    newPos = curPos;
    if (nextDir == UP) {
        if (curPos.first - 1 == 0) {
            newPos.first = field_instance->getHeight() - 2;
        } else {
            newPos.first = curPos.first - 1;
        }
    } else if (nextDir == DOWN) {
        if (curPos.first + 1 == field_instance->getHeight() - 1) {
            newPos.first = 1;
        } else {
            newPos.first = curPos.first + 1;
        }
    } else if (nextDir == RIGHT) {
        if (curPos.second + 1 == field_instance->getWidth() - 1) {
            newPos.second = 1;
        } else {
            newPos.second = curPos.second + 1;
        }
    } else if (nextDir == LEFT) {
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
    currentPosition = newPos;
}

