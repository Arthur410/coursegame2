//
// Created by arthu on 23.12.2022.
//

#include "Memento.h"
#include "../../Exceptions/ExceptionOnSaveState/ExceptionOnSaveState.h"
#include "../../Exceptions/ExceptionOnOpenFile/ExceptionOnOpenFile.h"
#include <fstream>
#include <iostream>

void Memento::saveState(const std::string& state, const std::string& filename) {
    std::fstream fileSave;
    fileSave.open(filename, std::ios::out);
    if (!fileSave.is_open())
        throw ExceptionOnOpenFile("Cannot open file " + filename + " for save state :(\n");
    fileSave << state;
    fileSave.close();
}

std::string Memento::restoreState(const std::string& filename) {
    std::fstream fileSave;
    fileSave.open(filename);
    if(!fileSave.is_open())
        throw ExceptionOnOpenFile("Cannot open file " + filename + " for restore state :(\n");
    std::string data;
    std::string line;
    while (getline(fileSave, line)){
        data+=line;
        data+="\n";
    }
    return data;
}