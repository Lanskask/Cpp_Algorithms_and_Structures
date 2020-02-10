//
// Created by Sergey Murtazin on 30/10/2019.
//

#ifndef TESTPROJ1_CAR_H
#define TESTPROJ1_CAR_H

#include <string>


class Car {
    int num_of_weels;
    std::string name;
    std::string manufacturer;

    std::string to_string(int num_of_weels, std::string name, std::string manufacturer);
};


#endif //TESTPROJ1_CAR_H
