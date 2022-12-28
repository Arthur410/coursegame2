//
// Created by arthu on 24.09.2022.
//

#ifndef INC_2COURSEGAME_PLAYER_H
#define INC_2COURSEGAME_PLAYER_H

#include "../Event/IEvent.h"
#include "../Save/Originator/Originator.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include "functional"
#include "../Exceptions/ExceptionOnSaveState/ExceptionOnSaveState.h"
#include "../Exceptions/ExceptionOnStateRestore/ExceptionOnStateRestore.h"
#include "../Exceptions/ExceptionOnOpenFile/ExceptionOnOpenFile.h"

class Player {
public:
    bool isRage = false;

    std::vector<int> restoredData;

    Player(int st, int sp, int hp);

    void rage();

    int getStrength() const;

    void setStrength(int newStrength);

    int getSpeed() const;

    void setSpeed(int newSpeed);

    int getHp();

    void setHp(int newHp);

private:
    int strength{};
    int speed{};
    int health{};
};




#endif //INC_2COURSEGAME_PLAYER_H
