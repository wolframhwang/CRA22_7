#pragma once
#include <string>
using namespace std;

enum class CL {
    CL1,
    CL2,
    CL3,
    CL4,
};

enum class Grade {
    ADV,
    PRO,
    EX,
};

struct PhoneNum {
    int mid;
    int end;
};

struct Name {
    string first;
    string last;
};

struct Date {
    int year;
    int month;
    int day;
};

struct Employee {
    unsigned long employeeNum;
    Name name;
    CL cl;
    PhoneNum phoneNum;
    Date birthday;
    Grade certi;

    bool operator<(const Employee& other) const {
        return employeeNum < other.employeeNum;
    }

    string toString(void) const {
        string result;
        result += toStringEmployeeNum() + ",";
        result += name.first + " " + name.last + ",";
        result += toStringCl() + ",";
        result += "010-" + toStringNum(phoneNum.mid, 4) + "-" + toStringNum(phoneNum.end, 4) + ",";
        result += toStringNum(birthday.year, 4) + toStringNum(birthday.month, 2) + toStringNum(birthday.day, 2) + ",";
        result += toStringCerti();
        return result;
    }

private:
    string toStringEmployeeNum(void) const {
        auto result = to_string(employeeNum);
        return string(result.c_str() + 2, 8);
    }

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