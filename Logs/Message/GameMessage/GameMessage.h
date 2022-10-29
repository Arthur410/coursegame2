//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_GAMEMESSAGE_H
#define COURSEGAME_GAMEMESSAGE_H
#include "../Message.h"

class GameMessage: public Message {
public:
    enum InfoMessageTypes {HEAL_TAKEN, MINE_TAKEN, EXIT_TAKEN};

    explicit GameMessage(InfoMessageTypes type);
    Message::LogTypes getLogType() override;
    string getLogMessage() override;
private:
    InfoMessageTypes currentType;
};


#endif //COURSEGAME_GAMEMESSAGE_H
