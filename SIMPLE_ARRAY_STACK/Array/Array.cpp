//
// Created by Sergey Murtazin on 24/01/2020.
//

#include "Array.h"

template <class T>
Array<T>::Array() {}

template<class T>
Array<T>::~Array() {

}

template<class T>
void Array<T>::setValue(T value) {
    Array::value = value;
}

template<class T>
T Array<T>::getValue() const {
    return value;
}
