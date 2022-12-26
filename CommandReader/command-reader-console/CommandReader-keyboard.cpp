//
// Created by arthu on 24.09.2022.
//
#include "CommandReader-keyboard.h"
using namespace std;
CommandReaderConsole::Action CommandReaderConsole::commandReading(Field *field_instance, FieldView *field_view) {
    char currentKeyChar;
    if (first) {
        char anyKey;
        cin >> anyKey;
        first = false;
        return NONE;
    } else {
        cin >> currentKeyChar;
    }
    if (currentKeyChar != 'x') {
        string currentKeyString = string() + currentKeyChar;
        if (currentKeyChar == 'r') {
            field_instance->player->rage();
            return lastAction;
        } else {
            lastAction = control[currentKeyString];
            return control[currentKeyString];
        }
    } else {
        field_instance->getLoggerPool().notify(new InfoMessage(InfoMessage::EXIT), false, true);
        exit(0);
    }
}

CommandReaderConsole::CommandReaderConsole(int flag) {
    string up = "w", down = "s", left = "a", right = "d", save = "z", restore = "c";
    if (flag) {
        control = {
                {up, CommandReader::Action::UP},
                {down, CommandReader::Action::DOWN},
                {right, CommandReader::Action::RIGHT},
                {left, CommandReader::Action::LEFT},
                {save, CommandReader::Action::SAVE},
                {restore, CommandReader::Action::RESTORE},
        };
    } else {
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
                {save, CommandReader::Action::SAVE},
                {restore, CommandReader::Action::RESTORE},
        };
    }
}


