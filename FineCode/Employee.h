#pragma once
#include <string>
#include <vector>
#include "Condition.h"
using namespace std;

struct Employee {
    ConditionEmployeeNum employeeNum;
    ConditionName name;
    ConditionCl cl;
    ConditionPhoneNum phoneNum;
    ConditionBirthday birthday;
    ConditionCerti certi;

    Employee(unsigned long _employeeNum, Name _name, CL _cl, 
        PhoneNum _phoneNum, Date _birthday, Grade _certi) : 
        employeeNum(_employeeNum), name(_name), cl(_cl), 
        phoneNum(_phoneNum), birthday(_birthday), certi(_certi) {
    }

    Employee(const vector<string>& params) : 
        employeeNum(params[0]), name(params[1]), cl(params[2]), phoneNum(params[3]), birthday(params[4]), certi(params[5]) {
    }

    bool operator<(const Employee& other) const {
        return employeeNum > other.employeeNum;
    }

    bool operator==(const Employee& other) const {
        return employeeNum == other.employeeNum;
    }

    string toString(void) const {
        string result;
        result += string(employeeNum) + ",";
        result += string(name) + ",";
        result += string(cl) + ",";
        result += string(phoneNum) + ",";
        result += string(birthday) + ",";
        result += string(certi);
        return result;
    }
};

using EmployeePtr = shared_ptr<Employee>;