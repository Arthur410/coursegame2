//
// Created by arthu on 23.12.2022.
//

#include "Exception.h"

Exception::Exception(std::string errorMessage) {
    message = std::move(errorMessage);
}