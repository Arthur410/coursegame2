//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_INFOMESSAGE_H
#define COURSEGAME_INFOMESSAGE_H
#include "../Message.h"

class InfoMessage: public Message {
public:
    enum InfoMessageTypes {START, END};

    explicit InfoMessage(InfoMessageTypes type);

    Message::LogTypes getLogType() override;
    string getLogMessage() override;

private:
    InfoMessageTypes currentType;
};


#endif //COURSEGAME_INFOMESSAGE_H
