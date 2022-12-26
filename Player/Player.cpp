//
// Created by arthu on 24.09.2022.
//

#include "Player.h"
Player::Player(int st, int sp, int hp) {
    if (st < 0 || sp < 0 || hp < 0) {
        throw std::invalid_argument("Incorrect player stats");
    }
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

Memento Player::saveState() {
    Memento playerMemento;
    std::string playerState = createSaveState();
    playerMemento.saveState(playerState, "player_save.txt");
    return playerMemento;
}

void Player::restoreState(Memento playerMemento) {
    std::string playerStateHash = playerMemento.restoreState("player_save.txt");
    restoreData(playerStateHash);
}

std::string Player::createSaveState() {
    std::string playerParameters = std::to_string(hash(health, speed, strength));
    for (const auto& parameter: parameters){
        playerParameters+="\n";
        playerParameters+=std::to_string(getValue.at(parameter)());
    }
    return playerParameters;
}

void Player::restoreData(const std::string& str) {
    auto ss = std::stringstream{str};
    std::vector<int> data;
    std::string hashFromFile;
    bool isReadHash = true;
    int cntLine = 0;
    std::string tmpLine;
    try{
        for (std::string line; std::getline(ss, line, '\n');){
            tmpLine = line;
            if (isReadHash){
                hashFromFile = line;
                isReadHash = false;
            } else data.push_back(std::stoi(line));
            ++cntLine;
        }
    } catch (...) {
        throw ExceptionOnOpenFile("Data for player incorrect at line " + std::to_string(cntLine) + " >> " + tmpLine);
    }

    size_t playerHash = hash(data[0], data[1], data[2]);
    if (std::to_string(playerHash) != hashFromFile){
        throw ExceptionOnStateRestore("Player file data has been changed. Hash of restored data " + std::to_string(playerHash) + " not equal " + hashFromFile);
    } else {
        restoredData = data;
    }
}


size_t Player::hash(int hp, int sp, int st) {
    size_t hashHealth = std::hash<int>()(hp);
    size_t hashShield = std::hash<int>()(sp);
    size_t hashSt = std::hash<int>()(st);
    return hashHealth xor ( (hashShield << hashShield%10) xor ( (hashSt << hashSt%10)));
}

void Player::restoreCorrectState() {
    health = restoredData[0];
    speed = restoredData[1];
    strength = restoredData[2];
}
