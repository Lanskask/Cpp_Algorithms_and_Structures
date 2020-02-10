//
// Created by Sergey Murtazin on 29/12/2019.
//

#include "../common.h"
#include "Address.h"
#include "Person.h"

#include <utility>

void Person::greet() {
    cout << "My name is " << name
         << " and I am " << age << " years old."
         << endl;

    if(address) {
        cout << "\tI live in a " << address->house_number << " house "
        << " on the " << address->street_name << " street "
        << " in " << address->city << endl;
    }
}

int Person::getLifeExpectancy() {
    return lifeExpectancy;
}

int Person::lifeExpectancy = 80;

Person::Person(int age, string name, int sex)
    : age(age), name(move(name)), sex(sex) {
    address = nullptr;
}

Person::Person(int age, string name, int sex,
        int house_umber, string street_name, string city)
    : Person(age, move(name), sex) {

    if(address != nullptr) delete address;

    address = new Address(house_umber, street_name, city);
}

Person::~Person() {
    if(address != nullptr) {
        delete address;
        address = nullptr;
    };
}

Person::Person(const Person &p)
    : age(p.age), name(p.name), sex(p.sex) {
    auto *a = p.address;
    address = new Address(a->house_number, a->street_name, a->city);
}
//Person::Person(int age, string name, int sex, Address address)
//    : age(age), name(move(name)), sex(sex), address(address){
//
//}
