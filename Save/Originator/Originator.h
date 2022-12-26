//
// Created by arthu on 23.12.2022.
//

#ifndef COURSEGAME_ORIGINATOR_H
#define COURSEGAME_ORIGINATOR_H


#include "../Memento/Memento.h"

class Originator {
public:
    virtual Memento saveState() = 0;
    virtual void restoreState(Memento) = 0;
    virtual void restoreCorrectState() = 0;
};


#endif //COURSEGAME_ORIGINATOR_H
