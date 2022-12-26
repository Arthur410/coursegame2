//
// Created by arthu on 23.12.2022.
//

#ifndef COURSEGAME_EXCEPTION_H
#define COURSEGAME_EXCEPTION_H


#include <exception>
#include <string>

class Exception: public std::exception {
protected:
    std::string message;
public:
    explicit Exception(std::string);
    virtual std::string what() = 0;
};


#endif //COURSEGAME_EXCEPTION_H
