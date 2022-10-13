//
// Created by arthu on 12.10.2022.
//

#ifndef COURSEGAME_CELLCHANGETOWALL_H
#define COURSEGAME_CELLCHANGETOWALL_H
#include "../FieldEvent.h"

class CellChangeToWall: public FieldEvent {
    void execute() override;
};


#endif //COURSEGAME_CELLCHANGETOWALL_H
