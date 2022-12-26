//
// Created by arthu on 24.09.2022.
//

#ifndef INC_2COURSEGAME_CELL_H
#define INC_2COURSEGAME_CELL_H
#include "../Event/IEvent.h"
#include <memory>
#include <iostream>
#include <map>

class Cell {
public:
    bool isPlayerIn = false;
    enum CellType {WALL, EMPTY, MEDICAL, MINE, EXIT, STRENGTH, QUICKNESS};

    std::map<CellType, std::string> cellToSymbol = {
            {CellType::WALL, "#"},
            {CellType::EMPTY, " "},
            {CellType::MEDICAL, "+"},
            {CellType::MINE, "x"},
            {CellType::EXIT, "H"},
            {CellType::STRENGTH, "S"},
            {CellType::QUICKNESS, "Q"},
    };

    explicit Cell(CellType type);

    Cell();

    void setCellContent(CellType newType);

    CellType getCellType() const;

    std::string getCellSymbol();

    void setNewEvent(IEvent *e);

    IEvent* getEvent();

private:
    IEvent *event;
    CellType type;
    size_t hashCode;
};


#endif //INC_2COURSEGAME_CELL_H
