//
// Created by arthu on 24.09.2022.
//

#include "Player.h"
Player::Player(int st, int sp, int hp) {
    strength = st;
    speed = sp;
    health = hp;
}

void Player::rage() {
    isRage = !isRage;
}

int Player::getStrength() const {
    return strength;
};

void Player::setStrength(int newStrength) {
    strength = newStrength;
};

int Player::getSpeed() const {
    return speed;
};

void Player::setSpeed(int newSpeed) {
    speed = newSpeed;
};

int Player::getHp() {
    return health;
};

void Player::setHp(int newHp) {
    health = newHp;
};
