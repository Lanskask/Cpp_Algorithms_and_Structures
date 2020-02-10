
#include <iostream>
#include "Planet.h"

Planet::Planet(int size, int dencity, const std::string &name) : size(size), dencity(dencity), name(name) {}

Planet::~Planet() {
    std::cout << "Planet is destroyed!" << std::endl;
}

int Planet::getSize() const {
    return size;
}

void Planet::setSize(int size) {
    Planet::size = size;
}

int Planet::getDencity() const {
    return dencity;
}

void Planet::setDencity(int dencity) {
    Planet::dencity = dencity;
}

const std::string &Planet::getName() const {
    return name;
}

void Planet::setName(const std::string &name) {
    Planet::name = name;
}
