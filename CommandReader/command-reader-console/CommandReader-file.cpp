//
// Created by arthu on 24.09.2022.
//

#include "CommandReader-keyboard.h"
using namespace std;
CommandReaderConsole::Action CommandReaderConsole::commandReading(Field *field_instance, FieldView *field_view) {
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

CommandReaderConsole::CommandReaderConsole() {
    string up = "w", down = "s", left = "a", right = "d";
    cout << "Enter controls for player.";
    cout << "\nYour key for UP is = ";

    cin >> up;

    cout << "\nYour key for DOWN is = ";
    cin >> down;

    cout << "\nYour key for LEFT is = ";
    cin >> left;

    cout << "\nYour key for RIGHT is = ";
    cin >> right;

    control = {
            {up, CommandReader::Action::UP},
            {down, CommandReader::Action::DOWN},
            {right, CommandReader::Action::RIGHT},
            {left, CommandReader::Action::LEFT},
    };
}


