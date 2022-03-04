#pragma once
#include <string>
using namespace std;

const unsigned MAX_LINE_SIZE = 512;

enum class EInfoType {
    employeeNum,
    name,
    cl,
    phoneNum,
    birthday,
    certi,
};

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
typedef struct Employee {
    unsigned long employeeNum;
    Name name;
    CL cl;
    PhoneNum phoneNum;
    Date birthday;
    Grade certi;
};

// for avoiding build error temporary
class Cmd {
    int dummy_;
};