//
// Created by Sergey Murtazin on 10/02/2020.
//

#ifndef CUSTOMARRAY_SIMPLE_H
#define CUSTOMARRAY_SIMPLE_H

#include <vector>
using namespace std;

template <typename T>
class Simple {
private:
    vector<T> storage;
public:
    void push(T el);
    T pop();
};


#endif //CUSTOMARRAY_SIMPLE_H
