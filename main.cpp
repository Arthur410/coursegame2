#include <iostream>
using namespace std;
#include "Cell/Cell.h"
#include "Player/Player.h"
#include "Field/Field.h"
#include "FieldView/FieldView.h"
#include "CommandReader/CommandReader.h"
#include "Controller/Controller.h"

int main() {
    int playerX = 1, playerY = 1, playerBaseStrength = 0, playerBaseSpeed = 0 , playerBaseHP = 0;

    std::pair<int, int> playerStartPosition;
    // first - строчки, second - колонки
    playerStartPosition.first = playerY;
    playerStartPosition.second = playerX;

    int width, height;
    cout << "Enter field width and height" << endl;
    cin >> width >> height;

    Player currentPlayer = Player(playerBaseStrength, playerBaseSpeed, playerBaseHP);
    Field gameField = Field(playerStartPosition, width, height, &currentPlayer);
    FieldView gameFieldView = FieldView(&gameField);
    CommandReader reader = CommandReader();
    Controller controller = Controller(&currentPlayer, &gameField, gameFieldView, reader);
    controller.run();
}
