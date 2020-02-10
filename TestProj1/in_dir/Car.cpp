//
// Created by Sergey Murtazin on 30/10/2019.
//

#include <string>
#include "Car.h"

std::string Car::to_string(int num_of_weels, std::string name, std::string manufacturer) {
    return "num_of_weels: " + std::to_string(num_of_weels) + ", name: " + name + ", manufacturer: " + manufacturer;
}
