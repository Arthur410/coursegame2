//
// Created by arthu on 23.12.2022.
//

#ifndef COURSEGAME_EXCEPTIONONSAVESTATE_H
#define COURSEGAME_EXCEPTIONONSAVESTATE_H

#include "../Exception.h"

class ExceptionOnSaveState: public Exception{
public:
    using Exception::Exception;
    std::string what() final;
};


#endif //COURSEGAME_EXCEPTIONONSAVESTATE_H
