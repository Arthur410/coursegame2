//
// Created by arthu on 23.12.2022.
//

#ifndef COURSEGAME_MEMENTO_H
#define COURSEGAME_MEMENTO_H
#include <string>


class Memento {
public:
    void saveState(const std::string&, const std::string&);
    std::string restoreState(const std::string&);
};

#endif //COURSEGAME_MEMENTO_H
