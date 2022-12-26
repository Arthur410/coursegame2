//
// Created by arthu on 23.12.2022.
//

#include "ExceptionOnOpenFile.h"

std::string  ExceptionOnOpenFile::what() {
    return "Can't open file. Error message: \n" + message;
}