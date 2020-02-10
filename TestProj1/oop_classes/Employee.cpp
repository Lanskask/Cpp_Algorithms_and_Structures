//
// Created by Sergey Murtazin on 30/12/2019.
//

#include "../common.h"
#include "Address.h"
#include "Person.h"
#include "Employee.h"

void Employee::greet() {
    Person::greet();

    cout << "By the way i'm working in "
        << department << " department." << endl;
}
