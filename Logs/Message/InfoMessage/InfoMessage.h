//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_INFOMESSAGE_H
#define COURSEGAME_INFOMESSAGE_H
#include "../Message.h"

class InfoMessage: public Message {
public:
    enum messageTypes {START, END, EXIT};

    explicit InfoMessage(messageTypes type);

    Message::LogTypes getLogType() override;
    string getLogMessage() override;

private:
    messageTypes currentType;
};


#endif //COURSEGAME_INFOMESSAGE_H
