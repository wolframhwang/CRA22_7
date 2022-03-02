#pragma once
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
