//
// Created by arthu on 24.09.2022.
//

#include "FieldView.h"
#include "../CellView/CellView.h"
FieldView::FieldView(Field *instance) {
    field_instance = instance;
}

void FieldView::fieldView() const {
    system("cls");
    field_instance->fieldUpdate();
    for (int i = 0; i < field_instance->getHeight(); i++) {
        for (int j = 0; j < field_instance->getWidth(); j++) {
            CellView currentCell = CellView(field_instance->getCell(i, j));
            currentCell.cellView();
        }
        cout << endl;
    }
    cout << "Strength: " << field_instance->player->getStrength() << endl;
    cout << "Health: " << field_instance->player->getHp() << endl;
    cout << "Speed: " << field_instance->player->getSpeed() << endl;
}