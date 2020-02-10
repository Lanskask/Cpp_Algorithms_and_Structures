//
// Created by Sergey Murtazin on 19/11/2019.
//

#include "Monster.h"

Monster::Monster(int size, int power, const std::string &name) : size(size), power(power), name(name) {}

Monster::~Monster() {

}

int Monster::getSize() const {
    return size;
}

void Monster::setSize(int size) {
    Monster::size = size;
}

int Monster::getPower() const {
    return power;
}

void Monster::setPower(int power) {
    Monster::power = power;
}

const std::string &Monster::getName() const {
    return name;
}

void Monster::setName(const std::string &name) {
    Monster::name = name;
}
