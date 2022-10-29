//
// Created by arthu on 27.10.2022.
//

#include "LoggerPool.h"

#include <utility>

LoggerPool::LoggerPool() = default;

LoggerPool::LoggerPool(std::vector<Logger *> ls): loggers(std::move(ls)) {}

void LoggerPool::changeLogger(std::vector<Logger *> anotherLogger) {
    loggers = std::move(anotherLogger);
}

std::vector<Logger *> LoggerPool::getLoggers() {
    return loggers;
}