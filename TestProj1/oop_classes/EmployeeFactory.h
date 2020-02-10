//
// Created by Sergey Murtazin on 31/12/2019.
//

#pragma once
#ifndef TESTPROJ1_EMPLOYEEFACTORY_H
#define TESTPROJ1_EMPLOYEEFACTORY_H


#include "Employee.h"

class EmployeeFactory {
public:
    Employee makeEmployee(int id){
        Employee emp;
        emp.taxId = id;
        return emp;
    }
};


#endif //TESTPROJ1_EMPLOYEEFACTORY_H
