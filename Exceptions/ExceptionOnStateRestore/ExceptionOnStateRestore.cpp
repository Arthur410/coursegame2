//
// Created by arthu on 23.12.2022.
//

#include "ExceptionOnStateRestore.h"

std::string  ExceptionOnStateRestore::what() {
    return "Can't load save. Error message: \n" + message;
}