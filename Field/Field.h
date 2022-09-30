//
// Created by arthu on 24.09.2022.
//



#ifndef INC_2COURSEGAME_FIELD_H
#define INC_2COURSEGAME_FIELD_H
#include <iostream>
#include "../Player/Player.h"
#include "../Cell/Cell.h"
#include <utility>

class Field{

public:
    Player *player{};

    explicit Field(std::pair<int, int> playerPos, int width, int height, Player *currentPlayer);

    Field();
//    // Написать конструктор перемещения и оператор, копирования и оператор, удаления, по умолчанию (без пар.)
    Field(const Field &other);
//
//    Field &operator=(const Field &other);

    ~Field();

    int getWidth() const ;

    int getHeight() const ;

    Cell getCell(int x, int y);

    void fieldUpdate();

    std::pair<int, int> getPlayerPosition() {
        return playerPosition;
    }

    void setPlayerPosition(std::pair<int, int> currentPos) {
        playerPosition = currentPos;
    }



private:
    std::pair<int, int> playerPosition;
    int fieldWidth{};
    int fieldHeight{};
    Cell **fieldVariable{};
};



#endif //INC_2COURSEGAME_FIELD_H
