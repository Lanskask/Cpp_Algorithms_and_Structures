//
// Created by Sergey Murtazin on 18/01/2020.
//

#ifndef ALGORITHMS_CUSTOMARRAY_H
#define ALGORITHMS_CUSTOMARRAY_H
#pragma once

#include <cstddef>

static const int MIN_CAPACITY = 10;
static const float GROWTH_FACTOR = 0.5;

template <typename T>
class CustomArray {
public:
    CustomArray();
    ~CustomArray();

    void push(T value);
    T pop();
    void set(size_t index, T value);
    T get(size_t index);

    size_t size();
    size_t capacity();
    void print();
    int is_empty();

private:
    size_t m_size;
    size_t m_capacity;
    T* m_data;
    size_t resize();
};

#endif //ALGORITHMS_CUSTOMARRAY_H
