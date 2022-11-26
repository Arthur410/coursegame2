//
// Created by arthu on 27.10.2022.
//

#ifndef COURSEGAME_MESSAGE_H
#define COURSEGAME_MESSAGE_H
#include <iostream>
#include <map>

using namespace std;

template<typename T> struct map_init_helper
{
    T& data;
    explicit map_init_helper(T& d) : data(d) {}
    map_init_helper& operator() (typename T::key_type const& key, typename T::mapped_type const& value)
    {
        data[key] = value;
        return *this;
    }
};

template<typename T> map_init_helper<T> map_init(T& item)
{
    return map_init_helper<T>(item);
}

class Message {
public:
    enum LogTypes {GAME, INFO, ERR};
    virtual string getLogMessage() = 0;
    virtual LogTypes getLogType() = 0;

    friend ostream& operator << (ostream& os, Message* message)
    {
        Message::LogTypes currentLogType = message->getLogType();
        std::map<Message::LogTypes, const char*> MyMap;
        map_init(MyMap)
                (Message::GAME, "[GAME]")
                (Message::INFO, "[INFO]")
                (Message::ERR, "[ERROR]")
                ;

        os << MyMap[currentLogType]  << message->getLogMessage();
        return os;
    }
};



#endif //COURSEGAME_MESSAGE_H
