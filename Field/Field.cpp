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
    if (playerPos == exitPosition) {
        cout << "Congratulation! You've entered exit!";
        std::chrono::milliseconds timespan(2000);
        std::this_thread::sleep_for(timespan);
        exit(0);
    } else if (player->getHp() < 0) {
        cout << "Oops! You've died\n"
                "____________$$$$$$$\n"
                "_________$$$$$$$$$$$$$\n"
                "________$$$$$$$$$$$$$$$\n"
                "_______$$$$$$$$$$$$$$$$$\n"
                "_______$$$$$$$$$$$$$$$$$\n"
                "_______$$$$$$$$$$$$$$$$$\n"
                "_______$$$$$$$$$$$$$$$$$\n"
                "_______$$$$$__$$$__$$$$$\n"
                "_______$$$$$__$$$__$$$$$\n"
                "________$$$$$$$$$$$$$$$\n"
                "_________$$$$$$$$$$$$$\n"
                "_________$$$$$$$$$$$$$\n"
                "___________$$$$$$$$$\n"
                "___________$$$$$$$$$\n"
                "____$$$_____$$$$$$$_____$$$\n"
                "____$$$$$____$$$$$____$$$$$\n"
                "____$$$$$$$_________$$$$$$$\n"
                "___$$$$$$$$$$$$_$$$$$$$$$$$$\n"
                "___$$$$$$$$$$$$$$$$$$$$$$$$$\n"
                "___________$$$$$$$$\n"
                "_________$$$$$$$$$$$$$\n"
                "_____$$$$$$$$$$_$$$$$$$$$$\n"
                "___$$$$$$$$$$_____$$$$$$$$$$\n"
                "___$$$$$$$$_________$$$$$$$$\n"
                "___$$$$$$$___________$$$$$$$\n"
                "______$$$_____________$$$";
        std::chrono::milliseconds timespan(2000);
        std::this_thread::sleep_for(timespan);
        exit(0);
    }
    increaseStepsCounter();
    PlayerEvent* currentPlayerEvent = fieldVariable[playerPos.first][playerPos.second].getPlayerEvent();

    if (currentPlayerEvent) {
        int eventId = currentPlayerEvent->getEventId();
        currentPlayerEvent->changePlayerStat(player);
        switch (eventId){
            // Medical
            case 0:
                fieldVariable[healPosition.first][healPosition.second].setCellContent(Cell::Cell::EMPTY);
                fieldVariable[healPosition.first][healPosition.second].setNewPlayerEvent(nullptr);
                medical = false;
                break;
            // Mine
            case 1:
                fieldVariable[minePosition.first][minePosition.second].setCellContent(Cell::Cell::EMPTY);
                fieldVariable[minePosition.first][minePosition.second].setNewPlayerEvent(nullptr);
                mine = false;
                break;
            default:
                cout <<"oh no cringe";
        }
    }
    for (int i = 0; i < fieldWidth; i++) {
        for (int j = 0; j < fieldHeight; j++) {
            if (i == 0 || i == fieldWidth - 1 || j == 0 || j == fieldHeight - 1) {
                fieldVariable[i][j].setCellContent(Cell::CellType::WALL);
            } else {
                fieldVariable[i][j].setCellContent(Cell::CellType::EMPTY);
            }
        }
    }

    // Событие хилки
    if (medical) {
        PlayerEvent *healEvent = new MedicalEvent();
        fieldVariable[healPosition.first][healPosition.second].setCellContent(Cell::Cell::MEDICAL);
        fieldVariable[healPosition.first][healPosition.second].setNewPlayerEvent(healEvent);
    }

    // событие мины
    if (mine) {
        PlayerEvent *mineEvent = new MineEvent();
        fieldVariable[minePosition.first][minePosition.second].setCellContent(Cell::Cell::MINE);
        fieldVariable[minePosition.first][minePosition.second].setNewPlayerEvent(mineEvent);
    }

    // Рандомная стена (пока что не рандомная)
    CellEvent *wallEvent = new CellChangeToWall();
    fieldVariable[wallPosition.first][wallPosition.second].setNewCellEvent(wallEvent);
    CellEvent *randomWall = fieldVariable[wallPosition.first][wallPosition.second].getCellEvent();
    randomWall->changeCellType(&fieldVariable[wallPosition.first][wallPosition.second]);

    // Рандомный выход (пока что не рандомный)
    CellEvent *exitEvent = new CellChangeToExit();
    fieldVariable[exitPosition.first][exitPosition.second].setNewCellEvent(exitEvent);
    CellEvent *randomExit = fieldVariable[exitPosition.first][exitPosition.second].getCellEvent();
    randomExit->changeCellType(&fieldVariable[exitPosition.first][exitPosition.second]);

    if (getStepsCounter() % 100 == 0) {
        medical = true;
        mine = true;
    }

    fieldVariable[playerPos.first][playerPos.second].setCellContent(Cell::Cell::PLAYER);
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

int Field::getStepsCounter() const {
    return stepsCounter;
}

void Field::increaseStepsCounter() {
    stepsCounter += 1;
}