//
// Created by Sergey Murtazin on 24/01/2020.
//

#pragma once
#include <vector>

using namespace std;


template <class T>
class Stack {
private:
    vector<T> elems;    // elements

public:
    Stack();

    Stack(const vector<T> &elems);

    void push(T const&);  // push element
    void pop();               // pop element
    T top() const;            // return top element

    bool empty() const {      // return true if empty.
        return elems.empty();
    }
};

