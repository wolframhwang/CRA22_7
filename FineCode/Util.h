#pragma once
#include <string>
using namespace std;

enum class EInfoType {
    employeeNumber,
    name,
    cl,
    phoneNum,
    birthday,
    certi,
};

typedef struct Employee {
    int employeeNumber;
    string name;
    string cl;
    string phoneNum;
    string birthday;
    string certi;
};

typedef enum CL {
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
    int body;
    int tail;
};

typedef struct Name {
    string first;
    string last;
};

struct Date {
    int year;
    int month;
    int day;
};

typedef struct EmployeeInfo {
    int employeeNumber;
    Name name;
    CL cl;
    PhoneNum phoneNum;
    Date birth;
    Grade certi;
};