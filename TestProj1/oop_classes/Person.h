//
// Created by Sergey Murtazin on 29/12/2019.
//
#import "Address.h"
#ifndef TESTPROJ1_PERSON_H
#define TESTPROJ1_PERSON_H


class Person {
    static int lifeExpectancy;
public:
    const static int female = 0;
    const static int male = 0;

    int age;
    string name;
    int sex;
    Address *address;

    Person(int age, string name, int sex);
//    Person(int age, string name, int sex, Address address);
    Person(int age, string name, int sex,
            int house_umber, string street_name, string city);

    Person(const Person& p);
    ~Person();

    virtual void greet();

    static int getLifeExpectancy();
};


#endif //TESTPROJ1_PERSON_H
