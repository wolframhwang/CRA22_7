﻿#pragma once
#include <string>
using namespace std;
enum class EInfoType {
    employeeNum,
    name,
    cl,
    phoneNum,
    birthday,
    certi,
};

typedef struct Employee {
    int employeeNum;
    string name;
    string cl​;
    string phoneNum​;
    string birthday​;
    string certi​;
}​;
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
typedef struct EmployeeInfo {
    unsigned long employeeNum;
    Name name;
    CL cl;
    PhoneNum phoneNum;
    Date birthday;
    Grade certi;
};