//
// Created by arthu on 24.09.2022.
//

#include "Field.h"

#include "../Event/PlayerEvent/medicalEvent/MedicalEvent.h"
#include "../Event/PlayerEvent/mineEvent/MineEvent.h"
#include "../Event/PlayerEvent/strengthEvent/StrengthEvent.h"
#include "../Event/PlayerEvent/speedEvent/SpeedEvent.h"

#include "../Event/CellEvent/CellChangeToWall/CellChangeToWall.h"
#include "../Event/CellEvent/CellChangeToExit/CellChangeToExit.h"
#include "../FieldGeneration/FieldGenerationRules/rule-exit/RuleExit.h"
#include "../FieldGeneration/FieldGenerationRules/rule-heal/RuleHeal.h"
#include "../FieldGeneration/FieldGenerationRules/rule-mine/RuleMine.h"
#include "../FieldGeneration/FieldGenerationRules/rule-speed/RuleSpeed.h"
#include "../FieldGeneration/FieldGenerationRules/rule-strength/RuleStrength.h"

#include <thread>
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

// конструктор с параметрами
Field::Field(pair<int, int> playerPos, int width, int height, Player *currentPlayer, int logType, int difficulty):
    playerPosition(std::move(playerPos)),
    player(currentPlayer),
    fieldWidth(width),
    fieldHeight(height),
    gameDifficulty(difficulty){

    switch (logType) {
        case 0:
            loggerPoolCount = 0;
            break;
        case 1:
            loggerPoolCount = 1;
            loggers.push_back(new ConsoleLog());
            loggerPool = LoggerPool(loggers, loggerPoolCount);
            break;
        case 2:
            loggerPoolCount = 1;
            loggers.push_back(new FileLog());
            loggerPool = LoggerPool(loggers, loggerPoolCount);
            break;
        case 3:
            loggers.push_back(new ConsoleLog());
            loggers.push_back(new FileLog());
            loggerPoolCount = 2;
            loggerPool = LoggerPool(loggers, loggerPoolCount);
            break;
        default:
            cout << "...";
    }

    if (fieldWidth <= 0 || fieldHeight <= 0) {
        currentMessage = new ErrorMessage(ErrorMessage(ErrorMessage::FIELD_ERROR));
        loggerPool.notify(currentMessage, true, true);
    }

    fieldVariable = new Cell*[fieldWidth];
    for (int i = 0; i < fieldHeight; i++) {
        fieldVariable[i] = new Cell[fieldHeight];
    }

    currentMessage = new InfoMessage(InfoMessage::START);
    loggerPool.notify(currentMessage,false, true);
    currentMessage = nullptr;
}

// конструктор с дефолтными параметрами
Field::Field() {
    std::pair<int, int> defaultPosition;
    defaultPosition.first = 1;
    defaultPosition.second = 1;
    *player = Player(0,0,0);
    setPlayerPosition(defaultPosition);
    fieldWidth = 15;
    fieldHeight = 15;
    fieldVariable = new Cell*[fieldWidth];
    for (int i = 0; i < fieldHeight; i++) {
        fieldVariable[i] = new Cell[fieldHeight];
    }

    currentMessage = new InfoMessage(InfoMessage::START);
    loggerPool.notify(currentMessage, false, true);
    currentMessage = nullptr;
}


Field::~Field() {
    if (fieldVariable) {
        for (int i = 0; i < fieldWidth; i++)
            delete[] fieldVariable[i];
        delete[] fieldVariable;
    }
}

void Field::swap(Field &fieldObj){
    std::swap(fieldHeight, fieldObj.fieldHeight);
    std::swap(fieldWidth, fieldObj.fieldWidth);
    std::swap(fieldVariable, fieldObj.fieldVariable);
    std::swap(playerPosition, fieldObj.playerPosition);
}

// Конструктор копирования
Field::Field(const Field &other):
        playerPosition(other.playerPosition),
        player(other.player),
        fieldWidth(other.fieldWidth),
        fieldHeight(other.fieldHeight),
        fieldVariable(other.fieldVariable){};

Field& Field::operator=(const Field& fieldObj){
    if(this != &fieldObj){
        Field(fieldObj).swap(*this);
    }
    return *this;
}

Field::Field(Field&& fieldObj) noexcept {
    this->swap(fieldObj);
};

Field& Field::operator=(Field&& filedObj) noexcept {
    if (this != &filedObj)
        this->swap(filedObj);
    return *this;
}

void Field::fieldUpdate() {
    std::pair<int, int> playerPos = getPlayerPosition();

    if (exitFlag) {
        currentMessage = new InfoMessage(InfoMessage::END);
        loggerPool.notify(currentMessage, true, true);
        currentMessage = nullptr;
    } else if (player->getHp() < 0) {
        currentMessage = new GameMessage(GameMessage::PLAYER_DIED);
        loggerPool.notify(currentMessage, true, true);
        currentMessage = nullptr;
    }

    for (int i = 0; i < fieldWidth; i++) {
        for (int j = 0; j < fieldHeight; j++) {
            if (i == 0 || i == fieldWidth - 1 || j == 0 || j == fieldHeight - 1) {
                fieldVariable[i][j].setNewEvent(new CellChangeToWall(&fieldVariable[i][j]));
            } else {
                fieldVariable[i][j].setNewEvent(nullptr);
            }
            fieldVariable[i][j].isPlayerIn = false;
        }
    }

    if (gameDifficulty == 0) {
        FieldGeneration<RuleHeal *, RuleExit *, RuleSpeed *, RuleStrength *> gen = FieldGeneration<RuleHeal *, RuleExit *, RuleSpeed *, RuleStrength *>(player, fieldVariable, playerPos);
        gen.rulesGeneration(new RuleHeal(), new RuleExit(), new RuleSpeed(), new RuleStrength());
    } else {
        FieldGeneration<RuleMine *, RuleHeal *, RuleExit *, RuleSpeed *, RuleStrength *> gen = FieldGeneration<RuleMine *, RuleHeal *, RuleExit *, RuleSpeed *, RuleStrength *>(player, fieldVariable, playerPos);
        gen.rulesGeneration(new RuleMine(), new RuleHeal(), new RuleExit(), new RuleSpeed(), new RuleStrength());
    }

    increaseFieldTick();

    if (currentMessage) {
        loggerPool.notify(currentMessage, false, false);
    }

    fieldVariable[playerPos.first][playerPos.second].isPlayerIn = true;
    for (int i = 0; i < fieldWidth; i++) {
        for (int j = 0; j < fieldHeight; j++) {
            if (fieldVariable[i][j].getEvent()) {
                if (playerPos.first == i && playerPos.second == j) {
                    Cell cellWithPlayer = fieldVariable[i][j];
                    IEvent* currentEvent = cellWithPlayer.getEvent();
                    if (currentEvent) {
                        currentEvent->interact();
                        if (cellWithPlayer.getCellType() == Cell::MEDICAL) {
                            currentMessage = new GameMessage(GameMessage::HEAL_TAKEN);

                            cellWithPlayer.setNewEvent(nullptr);
                        } else if (cellWithPlayer.getCellType() == Cell::MINE) {
                            currentMessage = new GameMessage(GameMessage::MINE_TAKEN);

                            cellWithPlayer.setNewEvent(nullptr);
                        } else if (cellWithPlayer.getCellType() == Cell::EXIT) {
                            currentMessage = new GameMessage(GameMessage::EXIT_TAKEN);
                            exitFlag = true;
                            cellWithPlayer.setNewEvent(nullptr);
                        } else if (cellWithPlayer.getCellType() == Cell::STRENGTH) {
                            currentMessage = new GameMessage(GameMessage::STRENGTH_TAKEN);

                            cellWithPlayer.setNewEvent(nullptr);
                        } else if (cellWithPlayer.getCellType() == Cell::QUICKNESS) {
                            currentMessage = new GameMessage(GameMessage::QUICKNESS_TAKEN);

                            cellWithPlayer.setNewEvent(nullptr);
                        }
                    }
                } else {
                    fieldVariable[i][j].getEvent()->interact();
                }
            }
        }
    }
}


int Field::getWidth() const {
    return fieldWidth;
}

int Field::getHeight() const {
    return fieldHeight;
}

Cell Field::getCell(int x, int y) {
    if (fieldVariable) {
        return fieldVariable[x][y];
    }
    return Cell(Cell::CellType::EMPTY);
}

void Field::setPlayerPosition(std::pair<int, int> currentPos) {
    playerPosition = currentPos;
}

int Field::getFieldTicks() const {
    return tickCounter;
}

void Field::increaseFieldTick() {
    tickCounter += 1;
}

void Field::setNewMessage(Message * newMsg) {
    currentMessage = newMsg;
}

int Field::getLoggerPoolCount() const {
    return loggerPoolCount;
}

LoggerPool Field::getLoggerPool() {
    return loggerPool;
}

Message *Field::getCurrentMessage() {
    return currentMessage;
}
