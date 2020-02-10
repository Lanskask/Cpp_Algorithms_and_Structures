//
// Created by Sergey Murtazin on 10/02/2020.
//

#include <iostream>

#include "Simple.h"

using namespace std;

void run() {
    Simple<int> simple;
    simple.push(5);
    cout << simple.pop() << endl;
}

int main(int argc, char **argv) {
    run();

    return EXIT_SUCCESS;
}