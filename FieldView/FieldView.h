//
// Created by arthu on 24.09.2022.
//

#ifndef INC_2COURSEGAME_FIELDVIEW_H
#define INC_2COURSEGAME_FIELDVIEW_H

#include "../Field/Field.h"
#include <iostream>
using namespace std;

class FieldView {
public:
    Field *field_instance;

    explicit FieldView(Field *instance);

    void fieldView() const;
};


#endif //INC_2COURSEGAME_FIELDVIEW_H
