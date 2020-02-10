//
// Created by Sergey Murtazin on 31/12/2019.
//

#import "oop_classes/Person.h"
#import "oop_classes/Employee.h"
#include "oop_classes/EmployeeFactory.h"

void oop_ex1() {
//    Person p;
//    p.age = 5;
//    p.name = "Bob";
    Person p(5, "Bob", Person::male);

//    auto *p2 = new Person;
//    p2->age = 6;
//    p2->name = "Dilan";
//    p2->sex = Person::male;
    auto *p2 = new Person(6, "Dilan", Person::male);

    auto *p3 = new Person(7, "Molly", Person::male);
    auto *address = new Address(1, "Pereulok", "Town");
    p3->address = address;


    // copiing
    Person p4(*p3);
//    p4.address->city = "Denver2";
    cout << "p3->address->city: " << p3->address->city << endl;

    p3->address->city = "Denver2";
    cout << "p3->address->city: " << p3->address->city << endl;
    cout << "p4->address->city: " << p4.address->city << endl;

//    p.greet();
//    p2->greet();
//    p3->greet();

    int le = Person::getLifeExpectancy();

    delete p2;
    delete p3;
//    delete p4;
}

void oop_ex2() {
    Employee e(33, "Chris", Person::male, "HR");

    auto u = [](const Person& p){
        cout << p.name << endl;
    };
    u(e);

    Person &pr = e;
//    Employee &e2 = pr;
    Employee &e2 = static_cast<Employee&>(pr);
    cout << e2.department << endl;

    Person *pr2 = new Person(28, "Bridgit", Person::female);
//    Employee &e3 = static_cast<Employee&>(pr2);
//    cout << e3.department << endl;
}

void oop_ex3() {
    Employee em(
            30, "Margarrette",
            Person::female, "engeneering"
            );

    em.greet();

    Person &p = em; // converting sub-class to upper one

    p.greet(); // should use also functionality of
               // sub-class method greed
               // cause it was casted from it
    Employee &em2 = static_cast<Employee&>(p);// cast back
    em2.greet();
}

void oop_Casting_ex4() {
    Person p(33, "Melody", Person::female);

    try{
        Employee &em = dynamic_cast<Employee&>(p);
        cout << em.department << endl;
    } catch (const bad_cast& bce) {
        cout << bce.what() << ": Employee &em3 = dynamic_cast<Employee&>(p3)" << endl;
    }

    Person *p2 = &p;
    Employee *em2 = dynamic_cast<Employee*>(p2);
    if (em2)
        cout << em2->department << endl;
    else
        cout << "Failed to cast poiter" << endl;

}

#include "common.h"

int main(int argc, char **argv) {
//    oop_ex1();
//    oop_ex2();
//    oop_ex3();
    oop_Casting_ex4();

    return EXIT_SUCCESS;
}


