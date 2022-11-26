//
// Created by arthu on 27.10.2022.
//
#include <iostream>
#include "../../Message/Message.h"
#include "FileLog.h"

FileLog::FileLog() : fl(std::ofstream("gamelogs.txt")) {}

FileLog::~FileLog() {
    fl.close();
}

void FileLog::print(Message *message) {
    fl << message << std::endl;
}