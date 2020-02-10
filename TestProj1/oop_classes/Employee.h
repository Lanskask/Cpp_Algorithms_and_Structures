//
// Created by Sergey Murtazin on 30/12/2019.
//

#ifndef TESTPROJ1_EMPLOYEE_H
#define TESTPROJ1_EMPLOYEE_H


class Employee : public Person {
    friend class EmployeeFactory;
    int taxId;
public:
    string department;

    Employee() : Person(0, "", 0) {}

    Employee(
            int age, string const& name, int sex,
            string department = string()
    ) : Person(age, name, sex), department(department) {

    }

    void greet() override;
};


#endif //TESTPROJ1_EMPLOYEE_H
