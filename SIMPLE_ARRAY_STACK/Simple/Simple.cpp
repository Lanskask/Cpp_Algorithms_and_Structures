//
// Created by Sergey Murtazin on 10/02/2020.
//

#include <vector>
#include "Simple.h"

//vector<int> *storage = new vector<int>();

template <typename T>
void Simple<T>::push(T el) {
    storage.push_back(el);
}

template <typename T>
T Simple<T>::pop() {
    return storage.front();
}