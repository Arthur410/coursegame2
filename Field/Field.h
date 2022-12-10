//
// Created by arthu on 24.09.2022.
//



#ifndef INC_2COURSEGAME_FIELD_H
#define INC_2COURSEGAME_FIELD_H
#include <iostream>

#include "../Player/Player.h"
#include "../Cell/Cell.h"
#include "../FieldGeneration/FieldGeneration.h"
#include "../FieldGeneration/FieldGenerationRules/GenerationRule.h"

#include "../Logs/LoggerPool/LoggerPool.h"
#include "../Logs/Logger/ConsoleLog/ConsoleLog.h"
#include "../Logs/Logger/FileLog/FileLog.h"

#include "../Logs/Message/Message.h"
#include "../Logs/Message/ErrorMessage/ErrorMessage.h"
#include "../Logs/Message/InfoMessage/InfoMessage.h"
#include "../Logs/Message/GameMessage/GameMessage.h"
#include "../Logs/Logger/Logger.h"

#include <utility>

class Field{

public:
    bool exitFlag = false;
    Player *player{};

    explicit Field(std::pair<int, int> playerPos, int width, int height, Player *currentPlayer, int logType, int difficulty);

    Field();

    Field(const Field &other);

    Field& operator=(const Field& fieldObj);

    Field (Field&& fieldObj) noexcept;

    Field& operator=(Field&& filedObj) noexcept ;

    void swap(Field &fieldObj);

    ~Field();

    int getWidth() const ;

    int getHeight() const ;

    Cell getCell(int x, int y);

    void fieldUpdate();

    std::pair<int, int> getPlayerPosition() {
        return playerPosition;
    }

    void setPlayerPosition(std::pair<int, int> currentPos);

    int getFieldTicks() const;

    void increaseFieldTick();

    void setNewMessage(Message * newMsg);

    int getLoggerPoolCount() const;

    LoggerPool getLoggerPool();

    Message *getCurrentMessage();

private:
    std::pair<int, int> playerPosition;
    int tickCounter = 0;
    int fieldWidth{};
    int fieldHeight{};
    int gameDifficulty;
    Cell **fieldVariable{};
    LoggerPool loggerPool;
    std::vector<Logger *> loggers;
    int loggerPoolCount;
    Message *currentMessage;

};



#endif //INC_2COURSEGAME_FIELD_H
