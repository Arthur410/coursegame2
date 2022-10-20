//
// Created by arthu on 24.09.2022.
//

#ifndef COURSEGAME_IEVENT_H
#define COURSEGAME_IEVENT_H

class IEvent {
public:
    virtual void interact() = 0;
    virtual int getEventId() = 0;
    virtual ~IEvent() = default;
};

// 0 - хилка, 1 - мина, 2 - выход, 3 - стена


#endif //COURSEGAME_IEVENT_H
