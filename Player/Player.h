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

class Player: public Originator {
public:
    bool isRage = false;

    std::vector<int> restoredData;

    std::vector<std::string> parameters = {"health", "speed", "strength"};

    std::map<std::string, std::function<int()>> getValue {
            {"health", [this](){return this->health;}},
            {"speed", [this](){return this->speed;}},
            {"strength", [this](){return this->strength;}},
    };

    Player(int st, int sp, int hp);

    // Способность, при которой игрок без контроля движется в определенном направлении, при этой способности +10 к силе
    void rage();

    int getStrength() const;

    void setStrength(int newStrength);

    int getSpeed() const;

    void setSpeed(int newSpeed);

    int getHp();

    void setHp(int newHp);

    Memento saveState() final;

    void restoreState(Memento) final;

    void restoreCorrectState() final;

    std::string createSaveState();

    void restoreData(const std::string &str);

    static size_t hash(int hp, int sp, int st);

private:
    int strength{};
    int speed{};
    int health{};


};




#endif //INC_2COURSEGAME_PLAYER_H
