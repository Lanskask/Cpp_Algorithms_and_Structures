//
// Created by Sergey Murtazin on 29/12/2019.
//

#ifndef TESTPROJ1_ADDRESS_H
#define TESTPROJ1_ADDRESS_H
#include "../common.h"

class Address {
public:
    int house_number;
    string street_name;
    string city;

    Address(
            int houseNumber,
            const string &streetName,
            const string &city)
        : house_number(houseNumber),
          street_name(streetName),
          city(city) {

    }

};

#endif //TESTPROJ1_ADDRESS_H
