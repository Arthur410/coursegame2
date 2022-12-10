//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_GAMEMESSAGE_H
#define COURSEGAME_GAMEMESSAGE_H
#include "../Message.h"

class GameMessage: public Message {
public:
    enum messageTypes {HEAL_TAKEN, MINE_TAKEN, EXIT_TAKEN, PLAYER_DIED, RAGE, STRENGTH_TAKEN, QUICKNESS_TAKEN};

    explicit GameMessage(messageTypes type);
    Message::LogTypes getLogType() override;
    string getLogMessage() override;
private:
    messageTypes currentType;
};


#endif //COURSEGAME_GAMEMESSAGE_H
