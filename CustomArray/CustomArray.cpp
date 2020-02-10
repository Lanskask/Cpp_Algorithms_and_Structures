//
// Created by Sergey Murtazin on 18/01/2020.
//

#include <new>
#include "CustomArray.h"

template <class T>
CustomArray<T>::CustomArray() {
    m_capacity = MIN_CAPACITY;
    m_size = 0;
    m_data = (T*) malloc(m_capacity * sizeof(*m_data));
    if (!m_data) throw std::bad_alloc();
}

template <class T>
CustomArray<T>::~CustomArray() {
    free(m_data);
}

template <class T>
void CustomArray<T>::push(T value) {
    if(m_size > m_capacity) resize();
    *(m_data + m_size++) = value;
}

template <class T>
T CustomArray<T>::pop() {
    return *(m_data + --m_size);
}

template <class T>
void CustomArray<T>::set(size_t index, T value) {
    while(index >= m_size) this->push(0); // porque 0?
    *(m_data + index) = value;
}

template <class T>
T CustomArray<T>::get(size_t index) {
    return *(m_data + index);
}

template <class T>
size_t CustomArray<T>::resize() {
    size_t capacity = m_capacity*GROWTH_FACTOR;
    T* tmp = (T*) realloc(m_data, capacity * sizeof(*m_data));
    if(!tmp) throw std::bad_alloc();
    m_data = tmp;
    m_capacity = capacity;
}

