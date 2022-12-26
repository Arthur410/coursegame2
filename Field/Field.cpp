//
// Created by arthu on 24.09.2022.
//
#include "Field.h"

#include "../Event/PlayerEvent/medicalEvent/MedicalEvent.h"
#include "../Event/PlayerEvent/mineEvent/MineEvent.h"
#include "../Event/PlayerEvent/strengthEvent/StrengthEvent.h"
#include "../Event/PlayerEvent/speedEvent/SpeedEvent.h"
#include "../CellView/CellView.h"

#include <thread>
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#include <sstream>
#include <unordered_map>
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
            loggerPool = LoggerPool(loggers, loggerPoolCount);
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
            throw std::invalid_argument("Incorrect logType value");
    }

    if (fieldWidth < 15 || fieldHeight < 15 || fieldWidth > 50 || fieldHeight > 50 || fieldWidth != fieldHeight) {
        currentMessage = new ErrorMessage(ErrorMessage(ErrorMessage::FIELD_ERROR));
        loggerPool.notify(currentMessage, true, true);
        throw std::invalid_argument("Incorrect field size");
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
    if (player->getHp() < 0) {
        currentMessage = new GameMessage(GameMessage::PLAYER_DIED);
        loggerPool.notify(currentMessage, true, true);
        currentMessage = nullptr;
    }

    for (int i = 0; i < fieldWidth; i++) {
        for (int j = 0; j < fieldHeight; j++) {
            if (i == 0 || i == fieldWidth - 1 || j == 0 || j == fieldHeight - 1) {
                fieldVariable[i][j].setNewEvent(new CellChangeToWall(&fieldVariable[i][j]));
            } else {
                if (!fieldVariable[i][j].getEvent() || getFieldTicks() % 100 == 0) {
                    fieldVariable[i][j].setNewEvent(nullptr);
                }
            }
            fieldVariable[i][j].isPlayerIn = false;
        }
    }

    if (getFieldTicks() % 100 == 0) {
        if (gameDifficulty == 0) {
            FieldGeneration<RuleHeal *, RuleExit *, RuleSpeed *, RuleStrength *> gen = FieldGeneration<RuleHeal *, RuleExit *, RuleSpeed *, RuleStrength *>(player, fieldVariable, playerPos);
            gen.rulesGeneration(new RuleHeal(), new RuleExit(), new RuleSpeed(), new RuleStrength());
        } else {
            FieldGeneration<RuleMine *, RuleHeal *, RuleExit *, RuleSpeed *, RuleStrength *> gen = FieldGeneration<RuleMine *, RuleHeal *, RuleExit *, RuleSpeed *, RuleStrength *>(player, fieldVariable, playerPos);
            gen.rulesGeneration(new RuleMine(), new RuleHeal(), new RuleExit(), new RuleSpeed(), new RuleStrength());
        }
    }

    increaseFieldTick();

    fieldVariable[playerPos.first][playerPos.second].isPlayerIn = true;
    for (int i = 0; i < fieldWidth; i++) {
        for (int j = 0; j < fieldHeight; j++) {
            if (fieldVariable[i][j].getEvent()) {
                if (playerPos.first == i && playerPos.second == j) {
                    IEvent* currentEvent = fieldVariable[i][j].getEvent();
                    if (currentEvent) {
                        currentEvent->interact();

                        if (fieldVariable[i][j].getCellType() == Cell::MEDICAL) {
                            currentMessage = new GameMessage(GameMessage::HEAL_TAKEN);
                            fieldVariable[i][j].setNewEvent(nullptr);
                        } else if (fieldVariable[i][j].getCellType() == Cell::MINE) {
                            currentMessage = new GameMessage(GameMessage::MINE_TAKEN);
                            fieldVariable[i][j].setNewEvent(nullptr);
                        } else if (fieldVariable[i][j].getCellType() == Cell::EXIT) {
                            currentMessage = new InfoMessage(InfoMessage::END);
                            loggerPool.notify(currentMessage, false, true);
                            currentMessage = nullptr;
                            exit(0);
                        } else if (fieldVariable[i][j].getCellType() == Cell::STRENGTH) {
                            currentMessage = new GameMessage(GameMessage::STRENGTH_TAKEN);
                            fieldVariable[i][j].setNewEvent(nullptr);
                        } else if (fieldVariable[i][j].getCellType() == Cell::QUICKNESS) {
                            currentMessage = new GameMessage(GameMessage::QUICKNESS_TAKEN);
                            fieldVariable[i][j].setNewEvent(nullptr);
                        }
                    }
                } else {
                    fieldVariable[i][j].getEvent()->interact();
                }
            }
        }
    }
    if (currentMessage) {
        loggerPool.notify(currentMessage, false, false);
    }
}


int Field::getWidth() const {
    return fieldWidth;
}

int Field::getHeight() const {
    return fieldHeight;
}

Cell Field::getCell(int x, int y) {
    try {
        return fieldVariable[x][y];
    }
    catch (...) {
        throw std::invalid_argument("Incorrect cell coordinates");
    }
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

Memento Field::saveState() {
    Memento fieldMemento;
    std::string fieldState = createSaveState();
    fieldMemento.saveState(fieldState, "field_save.txt");
    return fieldMemento;
}

void Field::restoreState(Memento fieldMemento) {
    std::string fieldStateHash = fieldMemento.restoreState("field_save.txt");
    restoreData(fieldStateHash);
}

std::string Field::createSaveState() {
    std::string fieldParameters = std::to_string(hash(fieldWidth, fieldHeight,  playerPosition, fieldVariable));
    fieldParameters += "\n" + std::to_string(fieldWidth) + "\n" + std::to_string(fieldHeight);
    fieldParameters += "\n" + std::to_string(playerPosition.first) + "\n" + std::to_string(playerPosition.second);
    for (int i = 0; i < fieldWidth; i++) {
        for (int j = 0; j < fieldHeight; j++) {
            fieldParameters += "\n" + to_string(i) + " " + to_string(j);
            if (fieldVariable[i][j].getEvent()) {
                fieldParameters += "\n" + fieldVariable[i][j].getCellSymbol();
            } else {
                fieldParameters += "\nNone";
            }
        }
    }
    return fieldParameters;
}

void Field::restoreCorrectState() {
    Cell **tempField = std::get<3>(restoredData);
    int tempWidth = std::get<0>(restoredData);
    int tempHeight = std::get<1>(restoredData);
    fieldWidth = tempWidth;
    fieldHeight = tempHeight;
    fieldVariable = tempField;
    setPlayerPosition(std::get<2>(restoredData));
    Sleep(1000);
}



void Field::restoreData(const std::string &str) {
    auto ss = std::stringstream{str};
    std::vector<int> data;
    std::string hashFromFile;
    bool isReadHash = true;
    int cntLine = 0;
    int cntTotalLine = 1;
    bool isCellType = true;
    int width = 0;
    int height = 0;
    Cell **tmpField;
    std::string tmpLine;
    int onFirst = 1;
    try {
        for (std::string line; std::getline(ss, line, '\n');) {
            tmpLine = line;
            if (isReadHash) {
                hashFromFile = line;
                isReadHash = false;
            } else {
                if (cntLine < 4)
                    data.push_back(std::stoi(line));
                else {
                    if (onFirst) {
                        tmpField = new Cell*[data[0]];
                        for (int i = 0; i < data[1]; i++) {
                            tmpField[i] = new Cell[data[1]];
                        }
                        onFirst = 0;
                    }
                    if (isCellType) {
                        //
                    } else {
                        if (line != "None") {
                            if (line == "#") {
                                tmpField[width][height].setNewEvent(new CellChangeToWall(&tmpField[width][height]));
                            } else if (line == "+") {
                                tmpField[width][height].setNewEvent(new MedicalEvent(player, &tmpField[width][height]));
                                tmpField[width][height].setCellContent(Cell::MEDICAL);
                            } else if (line == "S") {
                                tmpField[width][height].setNewEvent(new StrengthEvent(player, &tmpField[width][height]));
                                tmpField[width][height].setCellContent(Cell::STRENGTH);
                            } else if (line == "Q") {
                                tmpField[width][height].setNewEvent(new SpeedEvent(player, &tmpField[width][height]));
                                tmpField[width][height].setCellContent(Cell::QUICKNESS);
                            } else if (line == "H") {
                                tmpField[width][height].setNewEvent(new CellChangeToExit(&tmpField[width][height]));
                                tmpField[width][height].setCellContent(Cell::EXIT);
                            } else if (line == "x") {
                                tmpField[width][height].setNewEvent(new MineEvent(player, &tmpField[width][height]));
                                tmpField[width][height].setCellContent(Cell::MINE);
                            }
                        } else {
                            tmpField[width][height].setNewEvent(nullptr);
                            tmpField[width][height].setCellContent(Cell::EMPTY);
                        }
                        ++width;
                    }

                    height += width / data[0];
                    width %= data[0];
                    isCellType = !isCellType;
                }
                ++cntLine;
            }
            ++cntTotalLine;
        }
    } catch (...) {
        throw ExceptionOnOpenFile("Field file data incorrect at line " + std::to_string(cntTotalLine) + " >> " + tmpLine + "\n");
    }
    size_t fieldHash = hash(data[0], data[1], std::pair<int, int>(data[2], data[3]), tmpField);

    if (std::to_string(fieldHash) != hashFromFile){
        throw ExceptionOnStateRestore("Field file data has been changed. Hash of restored data " + std::to_string(fieldHash) + "not equal " + hashFromFile + "\n");
    } else {
        restoredData = std::make_tuple(data[0],
                                       data[1],
                                       std::pair<int, int>(data[2], data[3]),
                                       tmpField);
    }

}

long long hashTwoNumbers(int a, int b)
{
    auto A = (long long)(a >= 0 ? 2 * (long)a : -2 * (long)a - 1);
    auto B = (long long)(b >= 0 ? 2 * (long)b : -2 * (long)b - 1);
    auto C = (long long)((A >= B ? A * A + A + B : A + B * B) / 2);
    return a < 0 && b < 0 || a >= 0 && b >= 0 ? C : -C - 1;
}

size_t Field::hash(int width, int height, std::pair<int,int> playerPos, Cell **field) {
    size_t hashSize = std::hash<int>()(width) xor std::hash<int>()(height << 1);
    size_t hashPlayerPosition = std::hash<int>()(playerPos.first) xor std::hash<int>()(playerPos.second << 1);
    ::hash<string> eventHasher;
    auto hashField = size_t(0);
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            hashField += hashTwoNumbers(i, j);
            if (field[i][j].getEvent()) {
                hashField += eventHasher(to_string(field[i][j].getCellType()));
            }
        }
    }


    return hashField xor ( (hashPlayerPosition << 1) xor (hashSize << 2));
}
