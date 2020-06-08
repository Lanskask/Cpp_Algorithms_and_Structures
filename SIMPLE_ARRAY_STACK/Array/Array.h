//
// Created by Sergey Murtazin on 24/01/2020.
//

#ifndef CUSTOMARRAY_ARRAY_H
#define CUSTOMARRAY_ARRAY_H

template <typename T>
class Array {
public:
    Array();
    virtual ~Array();

    void setValue(T value);
    T getValue() const;

private:
    T value;
};


#endif //CUSTOMARRAY_ARRAY_H
