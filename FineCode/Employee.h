#pragma once
#include <string>
#include <vector>
#include "Condition.h"
using namespace std;

struct Employee {
    ConditionEmployeeNum employeeNum;
    ConditionName name;
    CL cl;
    PhoneNum phoneNum;
    Date birthday;
    Grade certi;

    Employee(unsigned long _employeeNum, Name _name, CL _cl, 
        PhoneNum _phoneNum, Date _birthday, Grade _certi) : 
        employeeNum(_employeeNum), name(_name), cl(_cl), 
        phoneNum(_phoneNum), birthday(_birthday), certi(_certi) {
    }

    Employee(const vector<string>& params) : employeeNum(params[0]), name(params[1]) {
        auto paramCl = params[2];
        cl = CL::CL1;
        switch (paramCl[2]) {
        case '1':
            cl = CL::CL1;
            break;
        case '2':
            cl = CL::CL2;
            break;
        case '3':
            cl = CL::CL3;
            break;
        case '4':
            cl = CL::CL4;
            break;
        }

        auto paramPhoneNum = params[3];
        phoneNum.mid = stoi(string(paramPhoneNum.c_str() + 4, 4));
        phoneNum.end = stoi(string(paramPhoneNum.c_str() + 9, 4));

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
        result += toStringCl() + ",";
        result += "010-" + toStringNum(phoneNum.mid, 4) + "-" + toStringNum(phoneNum.end, 4) + ",";
        result += toStringNum(birthday.year, 4) + toStringNum(birthday.month, 2) + toStringNum(birthday.day, 2) + ",";
        result += toStringCerti();
        return result;
    }

private:
    string toStringCl(void) const {
        switch (cl) {
        case CL::CL1:
            return "CL1";
        case CL::CL2:
            return "CL2";
        case CL::CL3:
            return "CL3";
        case CL::CL4:
            return "CL4";
        }
    }

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