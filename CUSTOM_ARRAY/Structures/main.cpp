#include <iostream>

using namespace std;

#include "CustomArray.h"


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