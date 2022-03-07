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
    Date birthday;
    Grade certi;

    Employee(unsigned long _employeeNum, Name _name, CL _cl, 
        PhoneNum _phoneNum, Date _birthday, Grade _certi) : 
        employeeNum(_employeeNum), name(_name), cl(_cl), 
        phoneNum(_phoneNum), birthday(_birthday), certi(_certi) {
    }

    Employee(const vector<string>& params) : employeeNum(params[0]), name(params[1]), cl(params[2]), phoneNum(params[3]) {
        auto paramBirthday = params[4];
        birthday.year  = stoi(string(paramBirthday.c_str(), 4));
        birthday.month = stoi(string(paramBirthday.c_str() + 4, 2));
        birthday.day   = stoi(string(paramBirthday.c_str() + 6, 2));

        auto paramCerti = params[5];
        certi = Grade::ADV;
        if (paramCerti == "ADV") {
            certi = Grade::ADV;
        }
        else if (paramCerti == "PRO") {
            certi = Grade::PRO;
        }
        else if (paramCerti == "EX") {
            certi = Grade::EX;
        }
    }

    bool operator<(const Employee& other) const {
        return employeeNum < other.employeeNum;
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
        result += toStringNum(birthday.year, 4) + toStringNum(birthday.month, 2) + toStringNum(birthday.day, 2) + ",";
        result += toStringCerti();
        return result;
    }

private:
    string toStringCerti(void) const {
        switch (certi) {
        case Grade::ADV:
            return "ADV";
        case Grade::PRO:
            return "PRO";
        case Grade::EX:
            return "EX";
        }
    }

    string toStringNum(int num, int length) const {
        auto result = to_string(num);
        while (result.length() < length) {
            result = "0" + result;
        }
        return result;
    }
};