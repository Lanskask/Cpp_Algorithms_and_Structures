//
// Created by Sergey Murtazin on 23/01/2020.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "Structures/CustomArray.h"

TEST_CASE("This is my first catch2 test!") {
    CustomArray<int> arr1;
    arr1.push(1);
    REQUIRE(arr1.pop() == 1);
}