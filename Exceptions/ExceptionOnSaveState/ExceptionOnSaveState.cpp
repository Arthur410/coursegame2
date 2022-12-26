//
// Created by arthu on 23.12.2022.
//

#include "ExceptionOnSaveState.h"

std::string  ExceptionOnSaveState::what() {
    return "Can't save current game. Error message: \n" + message;
}