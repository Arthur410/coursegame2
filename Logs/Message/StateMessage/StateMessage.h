//
// Created by arthu on 24.12.2022.
//

#ifndef COURSEGAME_STATEMESSAGE_H
#define COURSEGAME_STATEMESSAGE_H
#include "../Message.h"

class StateMessage:public Message {
public:
    enum messageTypes {SAVED, RESTORED};

    explicit StateMessage(messageTypes type);

    Message::LogTypes getLogType() override;
    string getLogMessage() override;

private:
    messageTypes currentType;
};


#endif //COURSEGAME_STATEMESSAGE_H
