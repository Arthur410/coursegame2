//
// Created by arthu on 27.10.2022.
//

#include "FileLog.h"
#include <iostream>
#include <fstream>

void FileLog::print(string output) {
    std::ofstream out;
    out.open("./gamelogs.txt", std::ios::app);
    if (out.is_open()) {
        out << output << std::endl;
    }
}
