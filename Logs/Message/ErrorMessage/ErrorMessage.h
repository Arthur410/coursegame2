//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_ERRORMESSAGE_H
#define COURSEGAME_ERRORMESSAGE_H
#include "../Message.h"

class ErrorMessage: public Message {
public:
    enum InfoMessageTypes {FIELD_ERROR, CANT_GO};

    explicit ErrorMessage(InfoMessageTypes type);

    Message::LogTypes getLogType() override;
    string getLogMessage() override;

private:
    InfoMessageTypes currentType;
};


#endif //COURSEGAME_ERRORMESSAGE_H
