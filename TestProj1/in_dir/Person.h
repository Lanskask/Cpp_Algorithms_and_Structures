//
// Created by Sergey Murtazin on 19/11/2019.
//

#ifndef TESTPROJ1_PERSON_H
#define TESTPROJ1_PERSON_H

#include <string>

class Person {
private:
    std::string firstname;
    std::string lastname;
    int arbitrarynumber;

public:
    Person(std::string first,
            std::string last,
            int arbitrary);
    ~Person();

    [[nodiscard]] std::string GetName() const;

    int GetNumber() const {
        return arbitrarynumber;
    }

    void SetNumber(int number) {
        arbitrarynumber = number;
    }

//    bool operator<(Person const& p) const;
//    bool operator<(int i) const;
};
//bool operator<(int i, Person const& p);

#endif //TESTPROJ1_PERSON_H
