#include <iostream>
#include <vector>
#include<cstdlib>
#include <random>

using namespace std;

vector<vector<int>> matrix;

#include "Structures/CustomArray.h"


//void fill_matrix(int size) {
//    std::random_device dev;
//    std::mt19937 engine3(dev()); // Good
//
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            matrix[i][j] = rand() % max;
//        }
//    }
//}

void CustoMarrayTest() {
    CustomArray<int> arr;

    for (int i=0; i<10; i++)
        arr.push(10-i);

    arr.print();
    std::cout << "Popping.. " << arr.pop() << "\n";
    std::cout << "Setting pos 2 to 99 ... \n";
    arr.push(123123);
    arr.set(2, 99999);
    arr.print();
}


int main() {
    CustoMarrayTest();
    
    return 0;
}