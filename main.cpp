#include <iostream>
using namespace std;
#include "Cell/Cell.h"
#include "Player/Player.h"
#include "Field/Field.h"
#include "FieldView/FieldView.h"
#include "Controller/Controller.h"
#include "CommandReader/command-reader-console/CommandReader-console.h"
#include "CommandReader/command-reader-file/CommandReader-file.h"

int main() {
    int playerX = 1, playerY = 1, playerBaseStrength = 0, playerBaseSpeed = 0 , playerBaseHP = 0;

    std::pair<int, int> playerStartPosition;
    // first - строчки, second - колонки
    playerStartPosition.first = playerY;
    playerStartPosition.second = playerX;

    int width, height;
    cout << "Enter field width and height" << endl;
    cin >> width >> height;

    int logType;
    cout << "Enter also log type (0 - don't need, 1 - in console, 2 - in file, 3 - in console and file)" << endl;
    cin >> logType;

    int commandReaderType;
    cout << "Enter command reader type (0 - you can play with keyboard or 1 - write commands in file)" << endl;
    cin >> commandReaderType;

    Player currentPlayer = Player(playerBaseStrength, playerBaseSpeed, playerBaseHP);
    Field gameField = Field(playerStartPosition, width, height, &currentPlayer, logType);
    FieldView gameFieldView = FieldView(&gameField);
    CommandReader *reader;
    switch(commandReaderType) {
        case 0:
            reader = new CommandReaderConsole();
            break;
        case 1:
            reader = new CommandReaderFile();
            break;
        default:
            reader = new CommandReaderConsole();
    }
    Controller controller = Controller(&currentPlayer, &gameField, gameFieldView, reader, !commandReaderType);
    controller.run();
}
