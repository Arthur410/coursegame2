
#ifndef INC_2COURSEGAME_CELLVIEW_H
#define INC_2COURSEGAME_CELLVIEW_H

#include <iostream>
#include "../Cell/Cell.h"

class CellView {
    Cell cell_instance;
public:

    explicit CellView(Cell instance);

    void cellView();

};


#endif //INC_2COURSEGAME_CELLVIEW_H
