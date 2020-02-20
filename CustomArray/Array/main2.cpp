//
// Created by Sergey Murtazin on 24/01/2020.
//

#include <iostream>
#include "Array.h"
#include "Array.cpp"

using namespace std;

void ArrayTest() {
    Array<int> arr;

    arr.setValue(5);
    cout << "value: " << arr.getValue() << endl;
}

int main() {
    ArrayTest();

    return 0;
}
