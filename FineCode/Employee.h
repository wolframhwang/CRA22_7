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
        // TODO: 구현 필요
        return "";
    }
};