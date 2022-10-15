//
// Created by arthu on 24.09.2022.
//

#ifndef INC_2COURSEGAME_CELL_H
#define INC_2COURSEGAME_CELL_H
#include "../Event/IEvent.h"
#include "../Event/PlayerEvent/PlayerEvent.h"
#include "../Event/CellEvent/CellEvent.h"

class Cell {
public:
    enum CellType {WALL, EMPTY, PLAYER, ENEMY, POWER, MEDICAL, MINE, EXIT};

    explicit Cell(CellType type);

    Cell();

    void setCellContent(CellType newType);

    CellType getCellType() const;

    class PlayerEvent* getPlayerEvent();

    class CellEvent* getCellEvent();

    void setNewPlayerEvent(PlayerEvent *e);

    void setNewCellEvent(CellEvent *e);

private:
    PlayerEvent *playerEvent;
    CellEvent *cellEvent;
    CellType type;
};


#endif //INC_2COURSEGAME_CELL_H
