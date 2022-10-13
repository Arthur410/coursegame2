//
// Created by arthu on 24.09.2022.
//

#ifndef INC_2COURSEGAME_PLAYER_H
#define INC_2COURSEGAME_PLAYER_H

#include "../Event/IEvent.h"

class Player {
public:
    bool isRage = false;
    Player(int st, int sp, int hp);

    // Способность, при которой игрок без контроля движется в определенном направлении, при этой способности +10 к силе
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
