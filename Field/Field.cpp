//
// Created by arthu on 24.09.2022.
//

#include "Field.h"
#include <iostream>
using namespace std;

// конструктор с параметрами
Field::Field(pair<int, int> playerPos, int width, int height, Player *currentPlayer):
    playerPosition(std::move(playerPos)),
    player(currentPlayer),
    fieldWidth(width),
    fieldHeight(height) {

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
    if (fieldVariable) {
        for (int i = 0; i < fieldWidth; i++) {
            for (int j = 0; j < fieldHeight; j++) {
                if (i == 0 || i == fieldWidth - 1 || j == 0 || j == fieldHeight - 1) {
                    fieldVariable[i][j].setCellContent(Cell::CellType::WALL);
                }  else {
                    fieldVariable[i][j].setCellContent(Cell::CellType::EMPTY);
                }
            }
        }
        fieldVariable[playerPos.first][playerPos.second].setCellContent(Cell::CellType::PLAYER);
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
