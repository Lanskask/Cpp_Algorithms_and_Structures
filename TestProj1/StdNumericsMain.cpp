//
// Created by Sergey Murtazin on 04/01/2020.
//

#include <math.h>
#include <complex>
#include <random>
#include "stdlyb_common.h"

void numerical_limits_ex1() {
    cout << "Max for int: " << numeric_limits<int>::max() << endl;
}

void simple_math() {
    cout << sin(M_PI / 2 ) << endl;
}

void permutations_ex3() {
    vector<int> v{1,2,3,4,5};
    next_permutation(v.begin(),v.end());
    for(auto i : v )
        cout << i << ", ";
    cout << endl;
}

void complex_ex4() {
    complex<float> cf(4.3, 5.6);
    cout << cf*cf << endl;
}

void random_ex5() {
    srand((unsigned) time(nullptr));
    for (int i = 0; i < 100; ++i) {
        cout << rand() % 10 << ", ";
        if (i % 10 == 0 ) cout << endl;
    }
    cout << endl;

    auto seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    normal_distribution<float> nd;
    for (int j = 0; j < 100; ++j) {
        cout << nd(gen) << ", ";
        if (j % 10 == 0 ) cout << endl;
    }
}

int main(int argc, char **argv) {
//    numerical_limits_ex1();
//    simple_math();
//    permutations_ex3();
//    complex_ex4();
    random_ex5();

    return EXIT_SUCCESS;
}