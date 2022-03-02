#pragma once
#include <vector>

#include "common.h"

using namespace std;

class IDB {
public:
    virtual int add(Employee& employee) = 0;
    virtual vector<Employee>& retrieve(enum Column, string tobe) = 0;
    virtual int remove(vector<int> employeeNums) = 0; // 삭제된 사원 수 반환. (음수 에러)​
    virtual int modify(vector<int> employeeNums, enum Column, string tobe) = 0;// 수정된 사원 수 반환(음수 에러)
};