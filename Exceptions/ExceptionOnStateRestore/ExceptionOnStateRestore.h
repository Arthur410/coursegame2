//
// Created by arthu on 23.12.2022.
//

#ifndef COURSEGAME_EXCEPTIONONSTATERESTORE_H
#define COURSEGAME_EXCEPTIONONSTATERESTORE_H

#include "../Exception.h"
class ExceptionOnStateRestore: public Exception{
public:
    using Exception::Exception;
    std::string what() final;
};


#endif //COURSEGAME_EXCEPTIONONSTATERESTORE_H
