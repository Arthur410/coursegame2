//
// Created by arthu on 24.09.2022.
//

#include "CommandReader-file.h"

CommandReaderFile::Action CommandReaderFile::commandReading(Field *field_instance, FieldView *field_view) {
    if (_kbhit()) {
        field_view->fieldView();
        char currentKeyChar =  static_cast<char>(getch());
        string currentKeyString = string() + currentKeyChar;
        switch(currentKeyChar) {
            case 'r':
                field_instance->player->rage();
                return lastAction;
            case 'x':
                exit(0);
            default:
                lastAction = control[currentKeyString];
                return control[currentKeyString];
        }
    }
    return NONE;
}

CommandReaderFile::CommandReaderFile() {
    string up = "w", down = "s", left = "a", right = "d";
    string line;
    int counter = 0;
    std::ifstream in;
    in.open(R"(C:\Users\arthu\CLionProjects\coursegame\CommandReader\command-reader-console\controls.txt)"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line)) {
            counter++;
        }
    }
    in.close();
    in.open(R"(C:\Users\arthu\CLionProjects\coursegame\CommandReader\command-reader-file\controls.txt)");
    if (in.is_open() && counter == 4)
    {
        for (int i = 0; i < counter; i++) {
            if (i == 0) {
                getline(in, up);
            } else if (i == 1) {
                getline(in, down);
            } else if (i == 2) {
                getline(in, left);
            } else if (i == 3) {
                getline(in, right);
            }
        }
    }
    in.close();     // закрываем файл
    control = {
            {up, CommandReader::Action::UP},
            {down, CommandReader::Action::DOWN},
            {right, CommandReader::Action::RIGHT},
            {left, CommandReader::Action::LEFT},
    };
}


