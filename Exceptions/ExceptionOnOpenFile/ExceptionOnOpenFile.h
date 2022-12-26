//
// Created by arthu on 23.12.2022.
//

#ifndef COURSEGAME_EXCEPTIONONOPENFILE_H
#define COURSEGAME_EXCEPTIONONOPENFILE_H


#include "../Exception.h"

class ExceptionOnOpenFile: public Exception {
public:
    using Exception::Exception;
    std::string what() final;
};


#endif //COURSEGAME_EXCEPTIONONOPENFILE_H
