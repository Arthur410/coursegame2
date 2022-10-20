//
// Created by arthu on 24.09.2022.
//

#include "Field.h"
#include "../Event/PlayerEvent/medicalEvent/MedicalEvent.h"
#include "../Event/PlayerEvent/mineEvent/MineEvent.h"
#include "../Event/CellEvent/CellChangeToWall/CellChangeToWall.h"
#include "../Event/CellEvent/CellChangeToExit/CellChangeToExit.h"
#include <thread>
using namespace std;

// конструктор с параметрами
Field::Field(pair<int, int> playerPos, int width, int height, Player *currentPlayer):
    playerPosition(std::move(playerPos)),
    player(currentPlayer),
    fieldWidth(width),
    fieldHeight(height) {
    healPosition.first = 2;
    healPosition.second = 2;

    minePosition.first = 3;
    minePosition.second = 2;

    wallPosition.first = 5;
    wallPosition.second = 5;

    exitPosition.first = fieldWidth - 2;
    exitPosition.second = fieldHeight - 2;

    fieldVariable = new Cell*[fieldWidth];
    for (int i = 0; i < fieldHeight; i++) {
        fieldVariable[i] = new Cell[fieldHeight];
    }
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

    if (playerPos == exitPosition && exitFlag) {
        cout << "Congratulation! You've entered exit!";
        std::chrono::milliseconds timespan(2000);
        std::this_thread::sleep_for(timespan);
        exit(0);

    } else if (player->getHp() < 0) {
        cout << "Oops! You've died\n";
        std::chrono::milliseconds timespan(2000);
        std::this_thread::sleep_for(timespan);
        exit(0);
    }

    increaseFieldTick();
    IEvent* currentEvent = fieldVariable[playerPos.first][playerPos.second].getEvent();

    for (int i = 0; i < fieldWidth; i++) {
        for (int j = 0; j < fieldHeight; j++) {
            if (i == 0 || i == fieldWidth - 1 || j == 0 || j == fieldHeight - 1) {
                fieldVariable[i][j].setNewEvent(new CellChangeToWall(reinterpret_cast<Cell *>(&fieldVariable[wallPosition.first][wallPosition.second])));
            } else {
                fieldVariable[i][j].setNewEvent(nullptr);
            }
            fieldVariable[i][j].isPlayerIn = false;
        }
    }

    if (currentEvent) {
        currentEvent->interact();
        switch (currentEvent->getEventId()) {
            case 0:
                fieldVariable[healPosition.first][healPosition.second].setNewEvent(nullptr);
                medicalFlag = false;
                break;
            case 1:
                fieldVariable[minePosition.first][minePosition.second].setNewEvent(nullptr);
                mineFlag = false;
                break;
            case 2:
                fieldVariable[exitPosition.first][exitPosition.second].setNewEvent(nullptr);
                exitFlag = false;
                break;
            case 3:
                fieldVariable[wallPosition.first][wallPosition.second].setNewEvent(nullptr);
                wallFlag = false;
                break;
        }
    }

    if (getFieldTicks() % 100 == 0) {
        medicalFlag = true;
        mineFlag = true;
    }

    if ((getFieldTicks() + 1) % 200 == 0) {
        exitFlag = true;
    }

    if (medicalFlag) {
        fieldVariable[healPosition.first][healPosition.second].setNewEvent(new MedicalEvent(player, reinterpret_cast<Cell *>(&fieldVariable[healPosition.first][healPosition.second])));
    }

    if (mineFlag) {
        fieldVariable[minePosition.first][minePosition.second].setNewEvent(new MineEvent(player, reinterpret_cast<Cell *>(&fieldVariable[minePosition.first][minePosition.second])));
    }

    if (exitFlag) {
        fieldVariable[exitPosition.first][exitPosition.second].setNewEvent(new CellChangeToExit(reinterpret_cast<Cell *>(&fieldVariable[exitPosition.first][exitPosition.second])));
    }

    if (wallFlag) {
        fieldVariable[wallPosition.first][wallPosition.second].setNewEvent(new CellChangeToWall(reinterpret_cast<Cell *>(&fieldVariable[wallPosition.first][wallPosition.second])));
    }

    fieldVariable[playerPos.first][playerPos.second].isPlayerIn = true;
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