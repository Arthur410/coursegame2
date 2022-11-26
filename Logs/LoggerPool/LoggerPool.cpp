//
// Created by arthu on 27.10.2022.
//

#include "LoggerPool.h"
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

LoggerPool::LoggerPool() = default;

LoggerPool::LoggerPool(std::vector<Logger *> ls, int counter): loggers(std::move(ls)), counter(counter) {}

std::vector<Logger *> LoggerPool::getLoggers() {
    return loggers;
}

void LoggerPool::notify(Message *printMessage, int exitFlag, int delayFlag) {
    if (exitFlag) {
        system("cls");
        for (int i = 0; i < counter; i++) {
            loggers[i]->print(printMessage);
        }
        Sleep(500);
        exit(0);
    }
    if (delayFlag) {
        system("cls");
        for (int i = 0; i < counter; i++) {
            loggers[i]->print(printMessage);
        }
        Sleep(500);
    } else {
        for (int i = 0; i < counter; i++) {
            loggers[i]->print(printMessage);
        }
    }
}

int LoggerPool::getCounter() const {
    return counter;
}
