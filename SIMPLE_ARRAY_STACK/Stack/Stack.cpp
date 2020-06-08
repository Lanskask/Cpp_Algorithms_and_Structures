//
// Created by Sergey Murtazin on 24/01/2020.
//


#include <iostream>
#include <stdexcept>

#include "Stack.h"

using namespace std;


template <class T>
void Stack<T>::push (T const& elem) {
    // append copy of passed element
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop () {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }

    // remove last element
    elems.pop_back();
}

template <class T>
T Stack<T>::top () const {
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }

    // return copy of last element
    return elems.back();
}

template<class T>
Stack<T>::Stack() {}

template<class T>
Stack<T>::Stack(const vector<T> &elems):elems(elems) {}


