#include <iostream>
using namespace std;
#include "Cell/Cell.h"
#include "Player/Player.h"
#include "Field/Field.h"
#include "FieldView/FieldView.h"
#include "Controller/Controller.h"

#include "CommandReader/command-reader-file/CommandReaderFile.h"
#include "CommandReader/command-reader-console/CommandReader-keyboard.h"

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
    std::ofstream out;          // поток для записи
    int controlsFlag;
    cout << "Do you want to change controls? (0 or 1)\n";
    cin >> controlsFlag;

    CommandReader *reader;
    if (controlsFlag) {
        int controlsTypeFlag;
        cout << "How do you want to change your contorls (in console or you can write your control keyboards in file named controls.txt (0 or 1)\n";
        cin >> controlsTypeFlag;
        if (controlsTypeFlag) {
            reader = new CommandReaderFile();
        } else {
            reader = new CommandReaderConsole(0);
        }
    } else {
        reader = new CommandReaderConsole(1);
    }

    cout << "Please, enter difficulty level (0 - easy, 1 - you can die!!!!)";
    int difficultyFlag;
    cin >> difficultyFlag;
    if (difficultyFlag) {
        // hard
    } else {
        // easy without mines
    }
    Player currentPlayer = Player(playerBaseStrength, playerBaseSpeed, playerBaseHP);
    Field gameField = Field(playerStartPosition, width, height, &currentPlayer, logType, difficultyFlag);
    FieldView gameFieldView = FieldView(&gameField);
    Controller controller = Controller(&currentPlayer, &gameField, &gameFieldView, reader);
    controller.run();
}
