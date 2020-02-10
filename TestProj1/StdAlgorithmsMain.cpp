//
// Created by Sergey Murtazin on 04/01/2020.
//

#include "stdlyb_common.h"

struct Person {
    string name;
    int age;

    friend ostream& operator<<(ostream& os, const Person& p) {
        return os << p.name << " is " << p.age << " age old.";
    }
};

void simple_ex1() {
    vector<Person> people{
        {"John", 5},
        {"Lucy",6},
        {"Margarette",7}
    };

    auto print_all = [&](){
        cout << people.size() << " people: " << endl;

        for_each(begin(people), end(people),
            [](const Person& p) { cout << p << endl; }
        );
    };

    print_all();

    auto oldest_person = *max_element(people.begin(),people.end(),
            [](const Person& a, const Person& b){
       return a.age < b.age;
    });
    cout << "The oldest persons is " << oldest_person.name << endl;

    auto john = find_if(people.begin(), people.end(),
            [](const Person& p){
        return p.name == string("John");
    });
    if (john != people.end())
        cout << "Found " << john->name << " who is "
            << john->age << endl;

    auto yungerThan30 = count_if(people.begin(), people.end(),
            [](const Person& p){
        return p.age < 30;
    });
    cout << "There are " << yungerThan30 << " people yunger than 30." << endl;

    sort(people.begin(),people.end(), [](const Person& a, const Person& b) {
        return a.age < b.age;
    });

    cout << "Sorted persons: " << endl;
    print_all();

    cout << endl << "replacing with new Person" << endl;
    Person jill{"Jill", 32};
    replace_if(people.begin(), people.end(), [](const Person& p) {
        return p.name == string("John");
    },jill);
    print_all();
}

int main(int argc, char **argv) {
    simple_ex1();

    return EXIT_SUCCESS;
}
