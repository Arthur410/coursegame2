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

int Player::getStrength() {
    return strength;
};

void Player::addStrength() {
    strength += 1;
};

int Player::getSpeed() {
    return speed;
};

void Player::addSpeed() {
    speed += 1;
};

int Player::getHp() {
    return health;
};

void Player::addHp() {
    health += 1;
};
