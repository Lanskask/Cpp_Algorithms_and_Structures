//
// Created by Sergey Murtazin on 19/11/2019.
//
#include "Person.h"

//bool Person::operator<(Person const& p) const {
//    return arbitrarynumber < p.arbitrarynumber;
//}
//
//bool Person::operator<(int i) const {
//    return arbitrarynumber < i;
//}

Person::Person(std::string first, std::string last, int arbitrary) {
    Person::firstname = std::move(first);
    Person::lastname = std::move(last);
    Person::arbitrarynumber = arbitrary;
}

Person::~Person() = default;

std::string Person::GetName() const {
    return std::string(Person::firstname + " " + Person::lastname);
}

//Person::Person(std::string first, std::string last, int arbitrary) : first(first), last(last), arbitrary(arbitrary) {}

//bool operator<(int i, Person const& p) {
//    return i < p.GetNumber();
//}
