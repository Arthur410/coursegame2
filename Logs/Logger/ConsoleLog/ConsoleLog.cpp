//
// Created by arthu on 27.10.2022.
//

#include "ConsoleLog.h"
#include <iostream>

void ConsoleLog::print(Message *message) {
    std::cout << message->getLogMessage() << endl;
}

