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
    bool medicalFlag = true, mineFlag = true, exitFlag = false, wallFlag = true;
    Player *player{};

    explicit Field(std::pair<int, int> playerPos, int width, int height, Player *currentPlayer);

    Field();

    Field(const Field &other);

    Field& operator=(const Field& fieldObj);

    Field (Field&& fieldObj) noexcept;

    Field& operator=(Field&& filedObj) noexcept ;

    void swap(Field &fieldObj);

    ~Field();

    int getWidth() const ;

    int getHeight() const ;

    Cell getCell(int x, int y);

    void fieldUpdate();

    std::pair<int, int> getPlayerPosition() {
        return playerPosition;
    }

    void setPlayerPosition(std::pair<int, int> currentPos);

    int getFieldTicks() const;

    void increaseFieldTick();


private:
    std::pair<int ,int> healPosition;
    std::pair<int ,int> minePosition;
    std::pair<int ,int> wallPosition;
    std::pair<int ,int> exitPosition;
    std::pair<int, int> playerPosition;
    int tickCounter = 0;
    int fieldWidth{};
    int fieldHeight{};
    Cell **fieldVariable{};
};



#endif //INC_2COURSEGAME_FIELD_H
